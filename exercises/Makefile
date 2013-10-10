#
# @file Makefile
# Makefile for exercise projects
# @author Boris Shurygin
#
# Main targets are:
#   all - build all targets in debug and release modes
#   debug - build debug vesion of all targets
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
export SOURCES := .
export DEBUG_OBJECTS_DIR := $(OBJECT_DIR)/debug
export RELEASE_OBJECTS_DIR := $(OBJECT_DIR)/release
export LEX_TARGET_DIR = $(BUILD_DIR)/lex_targets

#Source files excluded from build.
#Use carefully each file name matches as a substring, specify directory for better results
EXCLUDED_CPP= 

#Macros for fitering, example $(call FILTER_OUT,g, seven eight nine ten)
FIND_SOURCES = $(shell find $(SOURCES) $(1) | grep -v "\#")
FILTER = $(foreach filter,$(1),$(foreach substr,$(2),$(if $(findstring $(filter),$(substr)),$(substr),)))
FILTER_OUT = $(filter-out $(call FILTER,$(1),$(2)),$(2))

#Includes
DEFAULT_INCLUDE_DIRS := -I.
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

DEBUG_LIBS = $(addprefix -l, $(DEBUG_LIB_NAMES))
DEBUG_LIB_FLAGS =

RELEASE_LIBS = $(addprefix -l, $(RELEASE_LIB_NAMES))
RELEASE_LIB_FLAGS =

# Uses wildecard to create a string containing all the project headers with their relative paths	
HEADERS:= $(call FIND_SOURCES,-name *.hpp -or -name *.h)

# Obtain string with all the *.cpp/*.c source files in project
SOURCES_CPP:= $(call FIND_SOURCES,-name *.cpp -or -name *.c)

# Target directories
TARGET_DIRS:= ex1

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
.PHONY: clean clean_bin clean_objs

clean:  clean_bin clean_objs
clean_bin:
	-$(RM) -rf $(BIN_DIR)
clean_objs:
	-$(RM) -rf $(OBJECT_DIR)

# Debug targets
debug: ex1d

# Release targets
release: ex1

#
# Linking targets for debug and release modes
#
ex1d: $(call FILTER,ex1,$(DEBUG_OBJS)) $(DEBUG_LIB_OBJS)
	@echo [linking] $(BIN_DIR)/ex1d
	@$(MKDIR) -p $(BIN_DIR)
	$(CXX) $(DEBUG_LIB_FLAGS) -o $(BIN_DIR)/ex1d $(DEBUG_LIB_OBJS) $(call FILTER,ex1,$(DEBUG_OBJS)) $(DEBUG_LIB_DIRS) $(DEBUG_LIBS)

ex1: $(RELEASE_LIB_OBJS) $(call FILTER,ex1,$(RELEASE_OBJS))
	@echo [linking] $(BIN_DIR)/ex1
	@$(MKDIR) -p $(BIN_DIR)
	$(CXX) $(RELEASE_LIB_FLAGS) -o $(BIN_DIR)/ex1  $(RELEASE_LIB_OBJS) $(call FILTER,ex1,$(RELEASE_OBJS)) $(RELEASE_LIB_DIRS) $(RELEASE_LIBS)

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