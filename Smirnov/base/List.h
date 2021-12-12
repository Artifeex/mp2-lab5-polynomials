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
		while (p->pNext != nullptr)
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

	void InsertEnd(Monom monom)
	{
		Node* p = new Node{ monom, nullptr };
		countElem++;
		if (pFirst == nullptr)
		{
			pLast = pFirst = p;
			return;
		}
		else
		{
			pLast->pNext = p;
			pLast = p;
		}
	}

	void InsertByIndex(int index, Monom monom)
	{
		if (index > countElem)
			throw string("Индекс превышает число элементов");
		else if (index < 0)
			throw string("Индекс меньше нуля");
		if (pFirst == nullptr)
		{
			InsertFront(monom);
			return;
		}
		else if (index == countElem)
		{
			InsertEnd(monom);
		}
		else
		{
			Node* p = pFirst;
			int i = 0;
			for (p; i != index - 1; p = p->pNext, i++)
				;
			Node* added = new Node{ monom, p->pNext };
			p->pNext = added;
			countElem++;
		}

	}

	Monom& GetByIndex(int index)
	{
		if (index >= countElem)
			throw string("Попытка получить не существующий элемент");
		else if (index < 0)
			throw string("Индекс меньше нуля");
		if (index == countElem - 1)
			return pLast->monom;
		Node* p = pFirst;
		int i = 0;
		for (p; i != index; p = p->pNext, i++)
			;
		return p->monom;
	}

	bool IsEmpty()
	{
		return countElem == 0;
	}

	int GetCountElem()
	{
		return countElem;
	}

	void InsertFront(Monom monom)
	{
		Node* p = new Node{ monom, pFirst };
		countElem++;
		if (pFirst == nullptr)
		{
			pLast = pFirst = p;
			return;
		}
		pFirst = p;
	}

	void DeleteFront()
	{
		if (pFirst == nullptr)
			throw string("Попытка удалить не существующий элемент");
		Node* temp = pFirst->pNext;
		delete pFirst;
		pFirst = temp;
		countElem--;
	}

	void DeleteEnd()
	{
		if (pLast == nullptr)
			throw string("Попытка удалить не существующий элемент");
		Node* p;
		for (p = pFirst; p->pNext != pLast; p = p->pNext)
			;
		p->pNext = nullptr;
		delete pLast;
		pLast = p;
		countElem--;
	}

	void DeleteByIndex(int index)
	{
		if (index >= countElem)
			throw string("Попытка удалить не существующий элемент");
		else if (index < 0)
			throw string("Индекс меньше нуля");
		if (index == 0)
			DeleteFront();
		else if (index == countElem - 1)
			DeleteEnd();
		else
		{
			Node* p;
			Node* prev;
			int i = 0;
			for (p = pFirst; i != index; prev = p, p = p->pNext,i++)
				;
			prev->pNext = p->pNext;
			delete p;
			countElem--;
		}
	}

	inline friend void Swap(List& first, List& second);

	List& operator=(const List& anotherList)
	{
		if (this == &anotherList)
			return *this;
		else
		{
			List temp(anotherList);
			Swap(*this, temp);
		}
	}

	bool operator==(const List& anotherList) const
	{
		if (countElem != anotherList.countElem)
			return false;
		if (pFirst == nullptr && anotherList.pFirst == nullptr)
			return true;
		Node* p;
		Node* a;
		for (p = pFirst, a=anotherList.pFirst; p != nullptr; p = p->pNext, a = a->pNext)
		{
			if (p->monom != a->monom)
				return false;
		}
		return true;
	}

	bool operator !=(const List& anotherList) const
	{
		return !(*this == anotherList);
	}
};

void Swap(List& first, List& second)
{
	std::swap(first.pFirst, second.pFirst);
	std::swap(first.pLast, second.pLast);
	std::swap(first.countElem, second.countElem);
}



