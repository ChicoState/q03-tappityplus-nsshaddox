/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
#include <cmath>
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

/* TESTING LENGTH DIFFERENCE FUNCTION */
TEST(tappityTest, len_diff_0_same_string){
	std::string ref = "test string";
	std::string inp = ref;
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, 0);
}

TEST(tappityTest, len_diff_0_diff_string){
	std::string ref = "one string";
	std::string inp = "two string";
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, 0);
}

TEST(tappityTest, len_diff_1_ref_smaller){
	std::string ref = "first string";
	std::string inp = "second string";
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, 1);
}

TEST(tappityTest, len_diff_1_inp_smaller){
	std::string ref = "first string";
	std::string inp = "scnd string";
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, 1);
}

TEST(tappityTest, len_diff_empty_input){
	std::string ref = "first string";
	std::string inp = "";
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, ref.size());
}

TEST(tappityTest, len_diff_empty_ref){
	std::string ref = "";
	std::string inp = "second string";
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, inp.size());
}

TEST(tappityTest, len_diff_both_empty){
	std::string ref = "";
	std::string inp = "";
	tappity t(ref);
	t.entry(inp);
	int actual_diff = t.length_difference();
	ASSERT_EQ(actual_diff, 0);
}


/* TESTING ACCURACY FUNCTION */
TEST(tappityTest, acc_with_both_empty){
	std::string ref = "";
	std::string inp = "";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 100.0);
}

TEST(tappityTest, acc_empty_ref_small_input){
	std::string ref = "";
	std::string inp = "1";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 0.0);
}

TEST(tappityTest, acc_empty_input_small_ref){
	std::string ref = "1";
	std::string inp = "";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 0.0);
}

TEST(tappityTest, acc_small_ref_large_input_0_matching){
	std::string ref = "1";
	std::string inp = "2345";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 0.0);
}

TEST(tappityTest, acc_large_ref_small_input_0_matching){
	std::string ref = "2345";
	std::string inp = "1";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 0.0);
}

TEST(tappityTest, acc_small_ref_large_input_25percent_matching){
	std::string ref = "1";
	std::string inp = "1345";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 25.0);
}

TEST(tappityTest, acc_large_ref_small_input_25percent_matching){
	std::string ref = "1345";
	std::string inp = "1";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 25.0);
}

TEST(tappityTest, acc_1_3rd_percent_matching){
	std::string ref = "134";
	std::string inp = "1";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	double cmd = (1.0/3.0) * 100.0;
	ASSERT_EQ(actual_diff, cmd);
}

TEST(tappityTest, acc_case_sensitive){
	std::string ref = "aaa";
	std::string inp = "AAA";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_EQ(actual_diff, 0.0);
}

TEST(tappityTest, acc_case_sensitive_with_matching_space){
	std::string ref = "aaa bbb";
	std::string inp = "AAA BBB";
	tappity t(ref);
	t.entry(inp);
	double actual_diff = t.accuracy();
	ASSERT_NE(actual_diff, 0.0);
}
