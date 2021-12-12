#pragma once
#include "pch.h"
#include "../base/Polynom.h"

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