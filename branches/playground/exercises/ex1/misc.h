/**
 * @file: ex1/misc.h
 * Miscellaneous routines for exercise 1
 * @author Boris Shurygin
 */
#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

/* String for build mode identification */
const string mode 
#ifdef _DEBUG
	("debug");
#else
	("release");
#endif

/*
  The ASSERT macro calls this this function when the test fails.
*/
inline void fatalAssert(const char *assertion, const char *file, int line)
{
    cerr << "ASSERT: " << assertion << " in file " << file << "line " << line << endl;
    abort();
}

/*
  The ASSERT_X macro calls this this function when the test fails.
*/
inline void fatalAssertWithMess(const char *where, const char *what, const char *file, int line)
{
    cerr << "ASSERT failure in "<< where <<": \""<< what <<"\", file "<< file <<", line " << line << endl;
    abort();
}


/* Empty function */
inline void noop() {}

/** 
 * Simple assert macro
 * @ingroup Asserts
 */
#if !defined(ASSERT)
#  ifndef NO_DEBUG
#    define ASSERT(cond) ((!(cond)) ? fatalAssert(#cond,__FILE__,__LINE__) : noop())
#  else
#    define ASSERT(cond) noop()
#  endif
#endif

/**
 * @brief Assert macro with description
 * @ingroup Asserts
 * @param cond The condition
 * @param where Description of functionality where failure occured
 * @param what Error message explaining what happened
 *
 * Assertion that in case of failure provides additional info about what happened
 */
#if !defined(ASSERT_X)
#  ifndef NO_DEBUG
#    define ASSERT_X(cond, where, what) ((!(cond)) ? fatalAssertWithMess(where, what,__FILE__,__LINE__) : noop())
#  else
#    define ASSERT_X(cond, where, what) noop()
#  endif
#endif


/**
 * Assert macro that works only in debug version
 * @ingroup Asserts
 */
#if !defined(ASSERTD)
#  ifdef _DEBUG
#    define ASSERTD(cond) ASSERT(cond)
#  else
#    define ASSERTD(cond) noop()
#  endif
#endif

/**
 * @brief Assert macro with description that works only in debug version
 * @ingroup Asserts
 * @param cond The condition
 * @param where Description of functionality where failure occured
 * @param what Error message explaining what happened
 *
 * Assertion that in case of failure provides additional info about what happened
 */
#if !defined(ASSERT_XD)
#  ifdef _DEBUG
#    define ASSERT_XD(cond, where, what) ASSERT_X(cond, where, what)
#  else
#    define ASSERT_XD(cond, where, what) noop()
#  endif
#endif