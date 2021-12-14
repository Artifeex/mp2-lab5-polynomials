#include "pch.h"
#include "../base/Monom.h"
#include "../base/Monom.cpp"

TEST(monom_test, can_create_monom)
{
	const double coef = 7.0;
	const int pow = 320;

	ASSERT_NO_THROW(Monom m(coef, pow));
}

TEST(monom_test, can_create_monom_use_string)
{
	string str = "3x2y4z6";

	ASSERT_NO_THROW(Monom m(str));
}

TEST(monom_test, can_assign_monoms)
{
	string str = "3x2y4z6";
	Monom m1(str);
	Monom m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(monom_test, can_create_monom_use_monom)
{
	string str = "3x2y4z6";
	Monom m1(str);
	Monom m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(monom_test, throws_when_pow_is_too_small)
{
	const double coef = 7.0;
	const int pow = -1;

	ASSERT_ANY_THROW(Monom m(coef, pow));
}

TEST(monom_test, throws_when_pow_is_too_small_by_string)
{
	string str = "3x-2y4z6";

	ASSERT_ANY_THROW(Monom m(str));
}

TEST(monom_test, throws_when_pow_is_too_big)
{
	const double coef = 7.0;
	const int pow = 10000;

	ASSERT_ANY_THROW(Monom m(coef, pow));
}

TEST(monom_test, throws_when_pow_is_too_big_by_string)
{
	string str = "3x2y10z6";

	ASSERT_ANY_THROW(Monom m(str));
}

TEST(monom_test, can_create_monom_without_one_argument)
{
	string str = "3x2z3";
	Monom m(3, 203);

	EXPECT_EQ(m, Monom (str));
}

TEST(monom_test, can_create_monom_with_one_argument)
{
	string str = "3x";
	Monom m(3, 100);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_monom_in_error_sequency)
{
	string str = "3z3x2y4";
	Monom m(3, 243);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_monom_without_degree)
{
	string str = "zxy";
	Monom m(1, 111);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_zero)
{
	string str = "0";
	Monom m(0, 0);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_monom_with_zero_coef)
{
	string str = "0zxy";
	Monom m(0, 111);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_monom_with_zero_degree)
{
	string str = "3z1x0y2";
	Monom m(3, 21);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_monom_with_negative_coef)
{
	string str = "-3z1xy2";
	Monom m(-3, 121);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_add_monoms)
{
	string str1 = "3x5y4z3";
	string str2 = "5x5y4z3";
	string resultStr = "8x5y4z3";
	Monom m1(str1);
	Monom m2(str2);
	Monom result(resultStr);

	EXPECT_EQ(m1 + m2, result);
}

TEST(monom_test, throws_when_add_monoms_with_different_degree)
{
	string str1 = "3x5y2z3";
	string str2 = "5x5y4z3";
	Monom m1(str1);
	Monom m2(str2);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(monom_test, can_subtract_monoms)
{
	string str1 = "3x5y4z3";
	string str2 = "5x5y4z3";
	string resultStr = "-2x5y4z3";
	Monom m1(str1);
	Monom m2(str2);
	Monom result(resultStr);

	EXPECT_EQ(m1 - m2, result);
}

TEST(monom_test, can_multiply_monoms)
{
	string str1 = "3x2y4z3";
	string str2 = "-5x5y4z";
	string resultStr = "-15x7y8z4";
	Monom m1(str1);
	Monom m2(str2);
	Monom result(resultStr);

	EXPECT_EQ(m1 * m2, result);
}

TEST(monom_test, throws_when_mulitly_gives_big_degree)
{
	string str1 = "3x2y4z3";
	string str2 = "-5x3y6z4";
	Monom m1(str1);
	Monom m2(str2);

	ASSERT_ANY_THROW(m1 * m2);
}

TEST(monom_test, can_use_unary_minus)
{
	string str1 = "3x2z3";
	string str2 = "-3x2z3";
	Monom m1(str1);
	Monom m2(str2);

	EXPECT_EQ(m2, -m1);
}

TEST(monom_test, can_calculate_monom_in_point)
{
	string str1 = "3x2z3";
	double x = 2;
	double y = 3;
	double z = 1;
	Monom m1(str1);
	double result = 3 * 4;

	EXPECT_EQ(m1.CalculateInPoint(x, y, z), result);
}

TEST(monom_test, can_create_monom_with_double_coef)
{
	string str1 = "3,5x2z3";

	EXPECT_NO_THROW(Monom(str1));
}




