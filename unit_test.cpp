#include "gtest/gtest.h"

#include "op_test.hpp"

#include "parse.hpp"

//#include "main.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//adding tests
TEST(AddParseTest, AddTwoPos){
	Parse p;
	Base* res;
	char* test_val[4]; 
	test_val[0] = "./calculator"; test_val[1] = "4"; test_val[2] = "+"; test_val[3] = "2";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ("(4.000000 + 2.000000)", res->stringify()); 
	EXPECT_EQ(6, res->evaluate());
}

TEST(AddParseTest, AddPosNegatives){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] - "./calculator"; test_val[1] = "-3"; test_val[2] = "+"; test_val[3] = "-4"; test_val[4] = "+"; test_val[5] = "3";
	res = p.parse(test_val+1, 5);
	EXPECT_EQ("((-3.000000 + -4.000000) + 3.000000)", res->stringify());
	EXPECT_EQ(-4, res->evaluate());
}

TEST(AddParseTest, AddDecPosNeg){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] = "./calculator"; test_val[1] = "1.5"; test_val[2] = "+"; test_val[3] = "0.8"; test_val[4] = "+"; test_val[5] = "-6.7";
	res = p.parse(test_val+1, 5);
	EXPECT_EQ("((1.500000 + 0.800000) + -6.700000)", res->stringify()); 
	EXPECT_EQ(-4.4, res->evaluate());
}

TEST(AddParseTest, AddZero){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "2.9"; test_val[2] = "+"; test_val[3] = "0.0";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ("(2.900000 + 0.000000)", res->stringify());
	EXPECT_EQ(2.9, res->evaluate());
}

//Subtraction Tests

TEST(SubParseTest, SubPos){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "15"; test_val[2] = "-"; test_val[3] = "25";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ("(15.000000 - 25.000000)", res->stringify());
	EXPECT_EQ(-10, res->evaluate());
}

TEST(SubParseTest, SubNeg){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "-4"; test_val[2] = "-"; test_val[3] = "-10";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ("(-4.000000 - -10.000000)", res->stringify());
	EXPECT_EQ(6, res->evaluate());
}

TEST(SubParseTest, SubPosNeg){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "35"; test_val[2] = "-"; test_val[3] = "-2";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ("(35.000000 - -2.000000)", res->stringify());
	EXPECT_EQ(37, res->evaluate()); 
}

TEST(SubParseTest, SubDecPosNeg){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] = "./calculator"; test_val[1] = "3.67"; test_val[2] = "-"; test_val[3] = "1.24"; test_val[4] = "-"; test_val[5] = "5.00";
	res = p.parse(test_val+1, 5);
	EXPECT_EQ("((3.670000 - 1.240000) - 5.000000)", res->stringify());
}


//Multiply tests

TEST(MultiplyTest, MultTwoPos){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "\*"; test_val[3] = "3";
	res = p.parse(test_val + 1, 3);
	EXPECT_EQ("(2.000000 * 3.000000)", res->stringify());
	EXPECT_EQ(6, res->evaluate());
}

TEST(MultiplyTest, MultTwoNeg){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "-2"; test_val[2] = "\*"; test_val[3] = "-12";
	res = p.parse(test_val +1, 3);
	EXPECT_EQ("(-2.000000 * -12.000000)", res->stringify());
	EXPECT_EQ(24, res->evaluate());
}

TEST(MultiplyTest, MultPosNeg){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] = "./calculator"; test_val[1] = "-1"; test_val[2] = "\*"; test_val[3] = "4"; test_val[4] = "\*"; test_val[5] = "-13";
	res = p.parse(test_val + 1, 5);
        EXPECT_EQ("((-1.000000 * 4.000000) * -13.000000)", res->stringify());
	EXPECT_EQ(52, res->evaluate());
}

//Division Tests

TEST(DivTest, DivPos){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "/"; test_val[3] = "3";
	res = p.parse(test_val + 1, 3);
	EXPECT_EQ("(3.000000 / 3.000000)", res->stringify());
	EXPECT_EQ(1, res->evaluate());
}

TEST(DivTest, DivNeg){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "-3"; test_val[2] = "/"; test_val[3] = "2";
	res = p.parse(test_val +1, 3);
	EXPECT_EQ("(-3.000000 / 2.000000)", res->stringify());
	EXPECT_EQ(-1.5, res->evaluate());
}

TEST(DivTest, DivZero){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "0"; test_val[2] = "/"; test_val[3] = "0";
	res = p.parse(test_val+1, 3);
	ASSERT_EXIT(res->evaluate(), ::testing::ExitedWithCode(1), "Error Zero Denominator");
	EXPECT_EQ(res->stringify(), "(0.000000 / 0.000000)");
}

//Below are the tests for combinations

TEST(ComboTest, AddMult){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "+"; test_val[3] = "2"; test_val[4] = "\*"; test_val[5] = "6";
	res = p.parse(test_val+1, 5);
	EXPECT_EQ("((3.000000 + 2.000000) * 6.000000)", res->stringify());
	EXPECT_EQ(30, res->evaluate());
}

TEST(ComboTest, SubMult){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] = "./calculator"; test_val[1] = "1"; test_val[2] = "-" ; test_val[3] = "5"; test_val[4] = "\*"; test_val[5] = "12";
	res = p.parse(test_val + 1, 5);
	EXPECT_EQ("((1.000000 - 5.000000) * 12.000000)", res->stringify());
	EXPECT_EQ(-48, res->evaluate());
}

TEST(ComboTest, SubMultDiv){
	Parse p;
	Base* res;
	char* test_val[8];
	test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "-"; test_val[3] = "1"; test_val[4] = "\*"; test_val[5] = "-15"; 
	test_val[6] = "/"; test_val[7] = "6";
	res = p.parse(test_val+1, 7);
	EXPECT_EQ("(((3.000000 - 1.000000) * -15.000000) / 6.000000)", res->stringify());
	EXPECT_EQ(-5, res->evaluate());
}

TEST(ComboTest, MultZeroAdd){
	Parse p;
	Base* res;
	char* test_val[6];
	test_val[0] = "./calculator"; test_val[1] = "36"; test_val[2] = "\*"; test_val[3] = "0"; test_val[4] = "+"; test_val[5] = "90";
	res = p.parse(test_val+1, 5);
	EXPECT_EQ("((36.000000 * 0.000000) + 90.000000)", res->stringify());
	EXPECT_EQ(90.000000, res->evaluate());
}

//Below are the tests for invalid inputs

TEST(InvalidTest, notEnoughArg){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "4"; test_val[2] = "+"; 
	res = p.parse(test_val+1, 3);
	EXPECT_EQ(nullptr, res);
}

TEST(InvalidTest,wrongLetter){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0] = "./calculator"; test_val[1] = "a"; test_val[2] = "+"; test_val[3] = "9";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ(nullptr, res);
}

TEST(InvalidTest, wrongOp){
	Parse p;
	Base* res;
	char* test_val[4];
	test_val[0]= "./calculator"; test_val[1] = "2"; test_val[2] = "$"; test_val[3] = "4";
	res = p.parse(test_val+1, 3);
	EXPECT_EQ(nullptr, res);
}  
