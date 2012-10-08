/**
 * @file: ir_iface.hpp
 * Interface of IR library
 * @defgroup IR Intermediate Representation
 */

#pragma once 
#include "ir_deps.hpp"

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


