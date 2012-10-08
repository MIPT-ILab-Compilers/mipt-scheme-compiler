/**
 * @file: misc.h 
 * @defgroup Misc Miscellaneous
 * @brief Various auxiliary routines
 * @ingroup Utils
 */
/*
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */
#ifndef MISC_H
#define MISC_H

/**
 * Check if pointer is not null
 * @ingroup Misc
 */
inline bool isNotNullP( const void *pointer)
{
    return pointer != NULL;
}

/**
 * Check if pointer is null
 * @ingroup Misc
 */
inline bool isNullP( const void *pointer)
{
    return pointer == NULL;
}

/**
 * Check if pointers are equal
 * @ingroup Misc
 */
inline bool areEqP( const void *p1, const void *p2)
{
    return p1 == p2;
}

/**
 * Check if pointers are not equal
 * @ingroup Misc
 */
inline bool areNotEqP( const void *p1, const void *p2)
{
    return p1 != p2;
}

/**
 * @brief Get absolute value
 * @ingroup Misc
 * @param Value value type
 * @param val signed value used to get absolute value
 *
 * @par 
 * Returns absolute value for a given signed operand. Note that operators
 * "<" and "-" must be defined for parameter class
 */
template<class Value> inline Value abs( Value val)
{
    if( val < 0)
        return -val;

    return val;
}



/**
 * Conversion of string to signed 32-bit integer with success check
 * @ingroup Misc
 *
 * @param str string to convert
 * @param ok  pointer to bool, used for error check 
 */
inline Int32 convStr2Int32( std::string str, bool *ok = NULL)
{
    bool zero_value = (str == std::string("0"));
    Int32 val = atoi( str.c_str()); // On error returns 0, so we should check if input string is actually "0"
    if ( isNotNullP( ok))
    {
        if ( val == 0 && !zero_value)
        {
            *ok = false;
        } else
        {
            *ok = true;
        }
    }
    return val;
}

/**
 * Conversion of string to signed 64-bit integer with success check
 * @ingroup Misc
 *
 * @param str string to convert
 * @param ok  pointer to bool, used for error check 
 */
inline Int64 convStr2Int64( std::string str, bool *ok = NULL)
{
    bool zero_value = (str == std::string("0"));
    Int64 val = atol( str.c_str());// On error returns 0, so we should check if input string is actually "0"
    if ( isNotNullP( ok))
    {
        if ( val == 0 && !zero_value)
        {
            *ok = false;
        } else
        {
            *ok = true;
        }
    }
    return val;
}

/**
 * Conversion of string to double with success check
 * @ingroup Misc
 *
 * @param str string to convert
 * @param ok  pointer to bool, used for error check 
 */
inline Double convStr2Double( std::string str, bool *ok = NULL)
{
    bool zero_value = ( str == std::string("0")
                        || str == std::string("0.0") );
    Double val = atof( str.c_str());// On error returns 0, so we should check if input string is actually "0"
    if ( isNotNullP( ok))
    {
        if ( val == 0 && !zero_value)
        {
            *ok = false;
        } else
        {
            *ok = true;
        }
    }
    return val;
}

template <class F> 
double 
time_tests(F f) // f is a function that returns its execution time
{ 
    std::vector<double> t; 

    // Store time of 10 executions of f
    unsigned int i;
    for (i = 0; i < 10; ++i) 
        t.push_back(f()); 

    double total_time = std::accumulate(t.begin(), t.end(), 0.0);

    // Keep running until at least 1s of results are available, or 1000 executions
    while ( total_time < 1.0) 
    { 
        t.push_back(f()); 
        total_time += t.back(); 
        ++i; 
    } 
    std::sort(t.begin(), t.end()); 
    t.resize(t.size() * 9 / 10); 
    return std::accumulate(t.begin(), t.end(), 0.0) / t.size(); 
} 


#define TIMED_TEST_CASE( test_name ) \
    double \
    time_test_##test_name() \
    { \
        boost::timer t; \
        { \
            test_name##_impl();  \
        } \
        return t.elapsed(); \
    } 

#define TIMED_AUTO_TEST_CASE( test_name ) \
    void \
    test_name##_impl(); \
    \
    TIMED_TEST_CASE( test_name ) \
    \
    BOOST_AUTO_TEST_CASE( test_name ) \
    { \
        double execution_time = time_test_##test_name(); \
        boost::unit_test::unit_test_log.set_threshold_level( boost::unit_test::log_messages ); \
        BOOST_TEST_MESSAGE(BOOST_TEST_STRINGIZE( test_name ).trim( "\"" ) << " execution time: " << execution_time << "s"); \
        BOOST_CHECK( true ); \
    } \
    \
    inline void test_name##_impl()

#endif
