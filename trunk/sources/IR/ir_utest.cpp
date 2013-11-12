/**
 * @file ir/ir_utest.cpp
 * Unit testing of IR
 */
#include <boost/test/unit_test.hpp>
#include "ir_iface.hpp"

namespace ir
{

BOOST_AUTO_TEST_SUITE( IR)

BOOST_AUTO_TEST_CASE( ir_basic)
{
    /** Test1 */
    /** Constructor of Object */
    Object t1;
    BOOST_CHECK_EQUAL( t1.id(), -1);
    BOOST_CHECK_EQUAL( t1.type(), OBJ_NAMES_NUM);
    BOOST_CHECK_EQUAL( t1.isVirtual(), true);
    /** Set Object eax */
    t1.setId( 1);
    BOOST_CHECK_EQUAL( t1.id(), 1);
    t1.setType( OBJ_NAME_REG);
    BOOST_CHECK_EQUAL( t1.type(), OBJ_NAME_REG);
    /** Constructor of Operation */
    Operation op1(1);
    BOOST_CHECK_EQUAL( op1.id(), 1);
    BOOST_CHECK_EQUAL( op1.name(), OPERS_NUM);
    /** Set Operation */
    op1.setName( OPER_MOV);
    BOOST_CHECK_EQUAL( op1.name(), OPER_MOV);
    op1.setArgImm( 0, 10);
    BOOST_CHECK_EQUAL( op1.arg( 0).constValue(), 10);
    op1.setResObj( 0, t1);
    /** Out */
    cout << op1 << endl;
}



BOOST_AUTO_TEST_SUITE_END()

}
