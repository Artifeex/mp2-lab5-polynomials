#include "pch.h"
#include "../base/Monom.h"

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

TEST(monom_test, can_create_monom_in_error_sequency)
{
	string str = "3z3x2y4";

	Monom m(3, 243);

	EXPECT_EQ(m, Monom(str));
}

TEST(monom_test, can_create_monom_without_pow)
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

TEST(monom_test, can_create_monom_with_zero_pow)
{
	string str = "3z1x0y2";

	Monom m(3, 21);

	EXPECT_EQ(m, Monom(str));
}

