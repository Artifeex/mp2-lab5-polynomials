#include "pch.h"
#include "../base/List.h"

TEST(list_test, can_create_list)
{
	EXPECT_NO_THROW(List l);
}

TEST(list_test, can_create_list_used_vector)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}

	EXPECT_NO_THROW(List l(monoms));
}

TEST(list_test, can_copy_list)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_NO_THROW(List copy(l));
}

TEST(list_test, copy_list_have_own_mem) //спорно
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);
	List copy(l);

	EXPECT_EQ(true, &copy != &l); 
}

TEST(list_test, can_assign_list)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);
	List l2;
	EXPECT_NO_THROW(l2 = l);
}

TEST(list_test, assigned_list_equal_main)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);
	List l2;
	l2 = l;
	
	EXPECT_EQ(l.GetByIndex(1), l2.GetByIndex(1));
}

TEST(list_test, can_insert_front)
{
	List l;
	Monom m(3, 17);

	EXPECT_NO_THROW(l.InsertFront(m));
}

TEST(list_test, can_insert_end)
{
	List l;
	Monom m(3, 17);

	EXPECT_NO_THROW(l.InsertEnd(m));
}

TEST(list_test, can_get_elem)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_EQ(Monom(2, 2), l.GetByIndex(2));
}

TEST(list_test, throws_with_get_elem_when_list_is_empty)
{
	List l;

	EXPECT_ANY_THROW(l.GetByIndex(0));
}

TEST(list_test, throws_with_get_elem_when_index_is_too_small)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_ANY_THROW(l.GetByIndex(-1));
}

TEST(list_test, throws_with_get_elem_when_index_is_too_big)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_ANY_THROW(l.GetByIndex(size+1));
}

TEST(list_test, can_delete_front)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_NO_THROW(l.DeleteFront());
}

TEST(list_test, throws_with_delete_front_when_list_is_empty)
{
	List l;

	EXPECT_ANY_THROW(l.DeleteFront());
}

TEST(list_test, can_delete_end)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_NO_THROW(l.DeleteEnd());
}

TEST(list_test, throws_with_delete_end_when_list_is_empty)
{
	List l;

	EXPECT_ANY_THROW(l.DeleteEnd());
}

TEST(list_test, can_delete_by_index)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_NO_THROW(l.DeleteByIndex(3));
}

TEST(list_test, throws_with_delete_by_index_when_list_is_empty)
{
	List l;

	EXPECT_ANY_THROW(l.DeleteByIndex(5));
}

TEST(list_test, throws_with_delete_by_index_when_index_is_too_small)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_ANY_THROW(l.DeleteByIndex(-1));
}

TEST(list_test, throws_with_delete_by_index_when_index_is_too_big)
{
	vector<Monom> monoms;
	const int size = 7;
	for (size_t i = 0; i < size; i++)
	{
		monoms.push_back(Monom(i, i));
	}
	List l(monoms);

	EXPECT_ANY_THROW(l.DeleteByIndex(size + 1));
}





