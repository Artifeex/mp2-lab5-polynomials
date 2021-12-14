#pragma once
#include "Monom.h"
#include <vector>

struct Node
{
	Monom monom;
	Node* pNext;
};

class List
{
private:
	Node* pFirst;
	Node* pLast;
	int countElem;
public:
	List() :pFirst(nullptr), pLast(nullptr), countElem(0) {}
	List(const List& list):pFirst(nullptr), pLast(nullptr), countElem(0)
	{
		Node* p = list.pFirst;
		while (p != nullptr)
		{
			InsertEnd(p->monom);
			p = p->pNext;
		}
	}
	List(const vector<Monom>& monoms): pFirst(nullptr), pLast(nullptr), countElem(0)
	{
		for (size_t i = 0; i < monoms.size(); i++)
		{
			InsertEnd(monoms[i]);
		}
	}
	int GetCountElem() const { return countElem; }
	Monom GetForRead(int index) const;
	Monom& GetByIndex(int index);
	int GetCountElem() { return countElem; }
	void InsertEnd(Monom monom);
	void InsertFront(Monom monom);
	void InsertByIndex(int index, Monom monom);
	void DeleteFront();
	void DeleteEnd();
	void DeleteByIndex(int index);
	void Sort();
	bool IsEmpty() const { return countElem == 0; }
	
	List& operator=(const List& anotherList);
	bool operator==(const List& anotherList) const;
	bool operator!=(const List& anotherList) const;
	inline friend void Swap(List& first, List& second);
};

void Swap(List& first, List& second)
{
	std::swap(first.pFirst, second.pFirst);
	std::swap(first.pLast, second.pLast);
	std::swap(first.countElem, second.countElem);
}



