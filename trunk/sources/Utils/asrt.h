/**
 * @file: asrt.h 
 * Assertion related routines of Utils library for scheme compiler project
 * @defgroup Asserts Assertions
 * @brief Assertion routines/macros
 * @ingroup Utils
 */
/*
 * Copyright (C) 2012  MIPT Scheme Compiler team, Compiler Prototype team
 */
#pragma once

#include <boost/assert.hpp>

#ifndef ASRT_H
#define ASRT_H

/** 
 * Simple assert macro
 * @ingroup Asserts
 */
#if !defined(ASSERT)
#  ifndef NO_DEBUG
#    define ASSERT(cond) BOOST_ASSERT(cond)
#  else
#    define ASSERT(cond)
#  endif
#endif

/**
 * @brief Assert macro with description
 * @ingroup Asserts
 * @param cond The condition
 * @param where Description of functionality where failure occured
 * @param what Error message explaining what happened
 *
 * Assertion that in case of failure provides additional info about what happened,
 * TODO: should be rewritten as it was originally created for use with 3-parameter QT assert.
 * Boost's assert only accepts two.
 */
#if !defined(ASSERT_X)
#  ifndef NO_DEBUG
#    define ASSERT_X(cond, where, what) BOOST_ASSERT_MSG(cond, where": "what)
#  else
#    define ASSERT_X(cond, where, what)
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
#    define ASSERTD(cond)
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
#    define ASSERT_XD(cond, where, what)
#  endif
#endif

#endif /* ASRT_H */

