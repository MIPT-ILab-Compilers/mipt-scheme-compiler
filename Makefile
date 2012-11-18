#
# @file Makefile
# Makefile for compiler-prototype project
# @author Boris Shurygin
#
# Main targets are:
#   all - build all targets in debug and release modes
#   debug (not yet implemented) - build debug vesion of all targets
#   release - build release version all targets
#   doc - run doxygen to generate documentation from source code
#
#   targets are buit in two steps:
#     1. Generate additional .dep files
#     2. Compile all .cpp to .o
#     3. Link .o files into targets
#

# Tools
export CC      = gcc
export CXX     = g++
export PERL     = perl
export MKDIR   = mkdir
export RM      = rm
export GREP    = grep
export TOUCH   = touch
export DOXYGEN = doxygen
export LEX     = flex++

#Directories
export BIN_DIR := bin
export BUILD_DIR := build
export OBJECT_DIR := $(BUILD_DIR)/objects
export SOURCES := sources
export DEBUG_OBJECTS_DIR := $(OBJECT_DIR)/debug
export RELEASE_OBJECTS_DIR := $(OBJECT_DIR)/release
export LEX_TARGET_DIR = $(BUILD_DIR)/lex_targets

#Source files excluded from build.
#Use carefully each file name matches as a substring, specify directory for better results
EXCLUDED_CPP= Interpreter/spirit-parser.cpp

#Macros for fitering, example $(call FILTER_OUT,g, seven eight nine ten)
FIND_SOURCES = $(shell find $(SOURCES) $(1) | grep -v "\#")
FILTER = $(foreach filter,$(1),$(foreach substr,$(2),$(if $(findstring $(filter),$(substr)),$(substr),)))
FILTER_OUT = $(filter-out $(call FILTER,$(1),$(2)),$(2))

#Includes
DEFAULT_INCLUDE_DIRS := -I. -I.. -I../..
RELEASE_INCLUDE_FLAGS = $(DEFAULT_INCLUDE_DIRS)
DEBUG_INCLUDE_FLAGS = $(DEFAULT_INCLUDE_DIRS)

# Final debug and release flags
DEBUG_OPT_FLAGS = -g -O0 -D_DEBUG -MMD -MP
RELEASE_OPT_FLAGS = -O3 -MMD -MP

DEBUG_CPPFLAGS = $(DEBUG_OPT_FLAGS) $(DEBUG_INCLUDE_FLAGS)
RELEASE_CPPFLAGS = $(RELEASE_OPT_FLAGS) $(RELEASE_INCLUDE_FLAGS)

# Library sets for debug and release
DEBUG_LIB_NAMES = 
RELEASE_LIB_NAMES =

DEBUG_LIB_DIRS = -L/usr/lib
RELEASE_LIB_DIRS = -L/usr/lib

# Needed for unit testing targets only
BOOST_UTF_LIB = -lboost_unit_test_framework

DEBUG_LIBS = $(addprefix -l, $(DEBUG_LIB_NAMES))
DEBUG_LIB_FLAGS =
RELEASE_LIBS = $(addprefix -l, $(RELEASE_LIB_NAMES))
RELEASE_LIB_FLAGS =

# Contains all names of .lex files
LEX_FILES:=$(wildcard $(SOURCES)/**/*.lex)
# Change suffix .lex to _lex.cpp, this creates .cpp targets so flex-generated
# sources could be updated once we modify .lex files
LEX_TARGETS=$(LEX_FILES:.lex=_lex.cpp)

# Uses wildecard to create a string containing all the project headers with their relative paths	
HEADERS:= $(call FIND_SOURCES,-name *.hpp -or -name *.h)

# Obtain string with all the *.cpp/*.c source files in project
SOURCES_CPP_ALL:= $(call FIND_SOURCES,-name *.cpp -or -name *.c)
SOURCES_CPP_WO_LEX:=$(call FILTER_OUT,$(LEX_TARGETS),$(SOURCES_CPP_ALL))
SOURCES_CPP:= $(call FILTER_OUT,$(EXCLUDED_CPP),$(SOURCES_CPP_WO_LEX)) $(LEX_TARGETS)

# Target directories
TARGET_DIRS:= UnitTest interpreter

DEBUG_SRC_NAMES= $(patsubst $(SOURCES)/%,$(DEBUG_OBJECTS_DIR)/%,$(SOURCES_CPP))
DEBUG_OBJS = $(DEBUG_SRC_NAMES:.cpp=.o)
DEBUG_DEPS = $(DEBUG_SRC_NAMES:.cpp=.d)
DEBUG_LIB_OBJS = $(call FILTER_OUT,$(TARGET_DIRS),$(DEBUG_OBJS))

RELEASE_SRC_NAMES= $(patsubst $(SOURCES)/%,$(RELEASE_OBJECTS_DIR)/%,$(SOURCES_CPP))
RELEASE_OBJS = $(RELEASE_SRC_NAMES:.cpp=.o)
RELEASE_DEPS = $(RELEASE_SRC_NAMES:.cpp=.d)
RELEASE_LIB_OBJS = $(call FILTER_OUT,$(TARGET_DIRS),$(RELEASE_OBJS))

# All build targets
all: debug release

# Run interpreter in debug mode
#run: interpreterd
#	./$(BIN_DIR)/interpreterd

#
# Cleanup routines
#
.PHONY: clean clean_lex clean_bin clean_objs

clean: clean_lex clean_bin clean_objs
clean_lex:
	$(eval EXISTING_LEX_CPP = $(call FIND_SOURCES, -name *_lex.cpp))
	-$(RM) -f $(EXISTING_LEX_CPP)
clean_bin:
	-$(RM) -rf $(BIN_DIR)
clean_objs:
	-$(RM) -rf $(OBJECT_DIR)

# Debug targets
debug: utestd interpreterd
utestd: gen utestd_link
interpreterd: gen interpreterd_link

# Additional generation target (if ever needed)
gen: lex

# Release targets
release: utest interpreter

utest: gen utest_link
interpreter: gen interpreter_link

#
# Linking targets for debug and release modes
#
utestd_link: $(call FILTER,UnitTest,$(DEBUG_OBJS)) $(DEBUG_LIB_OBJS)
	@echo [linking] $(BIN_DIR)/utestd
	@$(MKDIR) -p $(BIN_DIR)
	@$(CXX) $(DEBUG_LIB_FLAGS) -o $(BIN_DIR)/utestd $(DEBUG_LIB_OBJS) $(call FILTER,UnitTest,$(DEBUG_OBJS)) $(DEBUG_LIB_DIRS) $(DEBUG_LIBS) $(BOOST_UTF_LIB)

utest_link: $(RELEASE_LIB_OBJS) $(call FILTER,UnitTest,$(RELEASE_OBJS))
	@echo [linking] $(BIN_DIR)/utest
	@$(MKDIR) -p $(BIN_DIR)
	@$(CXX) $(RELEASE_LIB_FLAGS) -o $(BIN_DIR)/utest  $(RELEASE_LIB_OBJS) $(call FILTER,UnitTest,$(RELEASE_OBJS)) $(RELEASE_LIB_DIRS) $(RELEASE_LIBS) $(BOOST_UTF_LIB)


interpreterd_link: $(call FILTER,interpreter,$(DEBUG_OBJS)) $(DEBUG_LIB_OBJS)
	@echo [linking] $(BIN_DIR)/interpreterd
	@$(MKDIR) -p $(BIN_DIR)
	@$(CXX) $(DEBUG_LIB_FLAGS) -o $(BIN_DIR)/interpreterd $^ $(DEBUG_LIB_DIRS) $(DEBUG_LIBS) $(BOOST_UTF_LIB)

interpreter_link: $(call FILTER,interpreter,$(RELEASE_OBJS)) $(RELEASE_LIB_OBJS)
	@echo [linking] $(BIN_DIR)/interpreter
	@$(MKDIR) -p $(BIN_DIR)
	@$(CXX) $(DEBUG_LIB_FLAGS) -o $(BIN_DIR)/interpreter $^ $(RELEASE_LIB_DIRS) $(RELEASE_LIBS) $(BOOST_UTF_LIB)

#
# Generation of cpp files with flex
#
lex: $(LEX_TARGETS)

# Rule for flex++ run
$(SOURCES)/%_lex.cpp: $(SOURCES)/%.lex
	@echo [flex++] $*_lex.cpp
	@$(LEX) -o $(SOURCES)/$*_lex.cpp $<
	@$(TOUCH) $@

#
# Rules that run CPP compiler
#
#Dependences generation for debug mode
#$(DEBUG_OBJECTS_DIR)/%.d: $(SOURCES)/%.cpp
#	@echo [generating deps] from $*.cpp to $@
#	@$(MKDIR) -p $(dir $@)
#	@$(CXX) -MM $(DEBUG_CPPFLAGS) $< -MF $@ -MT "$@ $(@:.d=.o)"
#	@$(TOUCH) $@

-include $(DEBUG_DEPS)

#Objects generation for debug mode
$(DEBUG_OBJECTS_DIR)/%.o: $(SOURCES)/%.cpp
	@echo [compiling] $*.cpp to $@
	@$(MKDIR) -p $(dir $@)
	@$(CXX) -c $(DEBUG_CPPFLAGS) $< -o $@
	@$(TOUCH) $@


#Dependences generation for release mode
#$(RELEASE_OBJECTS_DIR)/%.d: $(SOURCES)/%.cpp
#	@echo [generating deps] from $*.cpp to $@
#	@$(MKDIR) -p $(dir $@)
#	@$(CXX) -MM $(RELEASE_CPPFLAGS) $< -MF $@ -MT "$@ $(@:.d=.o)"
#	@$(TOUCH) $@

-include $(RELEASE_DEPS)

#Objects generation for release mode
$(RELEASE_OBJECTS_DIR)/%.o: $(SOURCES)/%.cpp
	@echo [compiling] $*.cpp to $@
	@$(MKDIR) -p $(dir $@)
	@$(CXX) -c $(RELEASE_CPPFLAGS) $< -o $@	
	@$(TOUCH) $@

#
# Documentation
#
doc: 
	@echo [doxygen]
	@cd autodoc;$(DOXYGEN) Doxyfile


#$(eval EXISTING_MOCS = $(wildcard $(SOURCES)/*/*_moc.cpp))
#$(eval EXISTING_RESOURCES = $(RESOURCES:.qrc=.cpp))
#-$(RM) -f $(EXISTING_RESOURCES)
#-$(RM) -f $(EXISTING_MOCS)




