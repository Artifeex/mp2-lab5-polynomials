#pragma once
#include "pch.h"
#include "../base/Polynom.h"
#include "../base/Polynom.cpp"
TEST(polynom_test, can_create_polynom)
{
	EXPECT_NO_THROW(Polynom p());
}

TEST(polynom_test, can_create_polynom_use_list_monoms)
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
	string str = "3x2y4z5 + 6x4y4z4";
	
	EXPECT_NO_THROW(Polynom p(str));
}

TEST(polynom_test, create_polynom_use_string_right_work)
{
	string str = "-3x2y4z5 + 6x4y4z4";
	string str1 = "-3x2y4z5";
	string str2 = "6x4y4z4";
	Polynom p1(str);
	Polynom p2;
	p2.AddMonom(Monom(str1));
	p2.AddMonom(Monom(str2));

	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_bringing_similar_members)
{
	string str = "3x2y4z5 - 6x4y4z4 + 7x2y4z5";
	string result = "10x2y4z5 -6x4y4z4";
	Polynom p1(str);
	p1.BringingSimilarMembers();
	Polynom p2(result);

	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_sort_polynoms)
{
	string str = "yz + 3x2y4z5 - 5x4";
	string result = "-5x4 + 3x2y4z5 + yz";
	Polynom p1(str);
	p1.SortByDegrees();
	Polynom p2(result);

	EXPECT_EQ(p1, p2);
}

TEST(polynom_test, can_add_polynoms)
{
	string str1 = "yz + 3x2y4z5 - 5x4";
	string str2 = "yz + 3x2y4z5 - 5x4";
	string result = "2yz + 6x2y4z5 - 10x4";
	Polynom p1(str1);
	Polynom p2(str2);
	Polynom p(result);
	p.SortByDegrees();

	EXPECT_EQ(p, p1 + p2);
}

TEST(polynom_test, can_add_polynoms_1)
{
	string str1 = "7 + 2x3y + 3x2y4z5 - 5x4";
	string str2 = "yz - 5x4 + 3x2y4z5  - 1";
	string result = "yz + 6x2y4z5 - 10x4 + 2x3y + 6";
	Polynom p1(str1);
	Polynom p2(str2);
	Polynom p(result);
	p.SortByDegrees();

	EXPECT_EQ(p, p1 + p2);
}

TEST(polynom_test, can_multiply_polynoms)
{
	string str1 = "3 + 2x4y2z3";
	string str2 = "xy - 3x2y2z2";
	string result = "3xy - 9x2y2z2 + 2x5y3z3 -6x6y4z5";
	Polynom p1(str1);
	Polynom p2(str2);
	Polynom p(result);
	p.SortByDegrees();

	EXPECT_EQ(p, p1 * p2);
}