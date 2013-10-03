/**
 * @file: utils.cpp
 * Common small various utilites for IR package.
 * @defgroup IR Intermediate Representation
 */

#pragma once
#include "Utils/asrt.h"

/**
 * Debug assert for IR library
 **/
#if !defined(IR_ASSERTD)
#    define IR_ASSERTD(cond) ASSERT_XD(cond, "IR", "")
#endif

/**
 * Debug assert for IR library
 **/
#if !defined(IR_ASSERTXD)
#    define IR_ASSERTXD(cond, what) ASSERT_XD(cond, "IR", what)
#endif
