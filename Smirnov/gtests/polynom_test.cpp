#pragma once
#include "pch.h"
#include "../base/Polynom.h"
#include "../base/Polynom.cpp"
TEST(polynom_test, can_create_polynom)
{
	EXPECT_NO_THROW(Polynom p());
}

TEST(polynom_test, can_create_polynom_use_vector_monoms)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List lMonoms(monoms);

	EXPECT_NO_THROW(Polynom p(lMonoms));
}

TEST(polynom_test, can_create_polynom_use_string)
{
	string strPolynom = "3x2y4z5 + 6x4y4z4";
	
	EXPECT_NO_THROW(Polynom p(strPolynom));
}

TEST(polynom_test, can_create_polynom_use_polynom)
{
	string strPolynom = "3x2 - y4 + x5";
	Polynom p1(strPolynom);
	Polynom p2(p1);
	
	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_assign_polynoms)
{
	string strPolynom = "3x2 - y4 + x5";
	Polynom p1(strPolynom);
	Polynom p2 = p1;

	EXPECT_EQ(p2, p1);
}

TEST(polynom_test, can_append_monom)
{
	string monomStr = "3x5y4";
	Monom m(monomStr);
	Polynom polynom;

	EXPECT_NO_THROW(polynom.AppendMonom(m));
}

TEST(polynom_test, create_polynom_use_string_right_work)
{
	string str = "-3x2y4z5 + 6x4y4z4";
	string str1 = "6x4y4z4";
	string str2 = "-3x2y4z5";
	Polynom p1(str);
	Polynom p2;
	p2.AppendMonom(Monom(str1));
	p2.AppendMonom(Monom(str2));

	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_bringing_similar_members)
{
	string str = "3x2y4z5 - 6x4y4z4 + 7x2y4z5";
	string result = "10x2y4z5 -6x4y4z4";
	Polynom p1(str);
	Polynom p2(result);

	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_sort_polynoms_by_degree)
{
	string str = "yz + 3x2y4z5 - 5x4";
	string result = "-5x4 + 3x2y4z5 + yz";
	Polynom p1(str);
	Polynom p2(result);

	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_add_polynoms)
{
	string str1 = "yz + 3x2y4z5 - 5x4 +x";
	string str2 = "yz + 3x2y4z5 - 5x4 - y";
	string result = "2yz + 6x2y4z5 - 10x4 + x -y";
	Polynom p1(str1);
	Polynom p2(str2);
	Polynom p(result);

	EXPECT_EQ(p, p1 + p2);
}

TEST(polynom_test, can_sub_polynoms)
{
	string str1 = "yz + 3x2y4z5 - 5x4 + x";
	string str2 = "yz  - 2x4 - y + 3x2y4z5";
	string result = " -3x4 + x + y";
	Polynom p1(str1);
	Polynom p2(str2);
	Polynom p(result);
}

TEST(polynom_test, can_multiply_polynoms)
{
	string str1 = "3 + 2x4y2z3";
	string str2 = "xy - 3x2y2z2";
	string result = "3xy - 9x2y2z2 + 2x5y3z3 -6x6y4z5";
	Polynom p1(str1);
	Polynom p2(str2);
	Polynom p(result);

	EXPECT_EQ(p, p1 * p2);
}

TEST(polynom_test, throws_when_multiply_polynoms_with_overflow_degree)
{
	string str1 = "x7y2 + 10";
	string str2 = "xyz - x3";
	Polynom p1(str1);
	Polynom p2(str2);

	ASSERT_ANY_THROW(p1 * p2);
}

TEST(polynom_test, can_calculate_polynom_in_point)
{
	string str = "x3 - 3 + z2 - y";
	double x = 2;
	double y = 5;
	double z = 1;
	double result = 8 - 3 + 1 - 5;
	Polynom p(str);

	EXPECT_EQ(p.CalculateInPoint(x, y, z), result);
}

TEST(polynom_test, can_create_polynom_with_double_coef)
{
	string str = "-3,5x5 + 5";

	EXPECT_NO_THROW(Polynom(str));
}

TEST(polynom_test, can_do_derivative)
{
	string str1 = "yz + 3x2y4z5 - 5x4 + x";
	string str2 = "z + 12x2y3z5";
	Polynom m1(str1);
	Polynom result(str2);
	Polynom m2 = m1.Derivative(y);
	
	EXPECT_EQ(result, m2);
}