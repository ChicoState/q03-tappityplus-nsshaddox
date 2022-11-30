/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, verify_constructor_input){
	std::string ref = "test words";
	tappity t(ref);
	std::string actual = t.get_ref();
	ASSERT_EQ(actual, ref);
}