#include "List.h"

void List::InsertEnd(Monom monom)
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

void List::Sort()
{
	List temp(*this);
	List result;
	while (temp.countElem != 1)
	{
		Monom max = temp.GetByIndex(0);
		int maxIndex = 0;
		for (size_t j = 1; j < temp.countElem; j++)
		{
			if (max < temp.GetByIndex(j))
			{
				max = temp.GetByIndex(j);
				maxIndex = j;
			}

		}
		result.InsertEnd(max);
		temp.DeleteByIndex(maxIndex);
	}
	result.InsertEnd(temp.GetByIndex(0));
	*this = result;
}

void List::InsertByIndex(int index, Monom monom)
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

Monom List::GetForRead(int index) const
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

Monom& List::GetByIndex(int index)
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

void List::InsertFront(Monom monom)
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

void List::DeleteFront()
{
	if (pFirst == nullptr)
		throw string("Попытка удалить не существующий элемент");
	Node* temp = pFirst->pNext;
	delete pFirst;
	pFirst = temp;
	countElem--;
}

void List::DeleteEnd()
{
	if(pLast == nullptr)
		throw string("Попытка удалить не существующий элемент");
	Node* p;
	for (p = pFirst; p->pNext != pLast; p = p->pNext)
		;
	p->pNext = nullptr;
	delete pLast;
	pLast = p;
	countElem--;
}

void List::DeleteByIndex(int index)
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
		Node* prev = nullptr;
		int i = 0;
		for (p = pFirst; i != index; prev = p, p = p->pNext, i++)
			;
		prev->pNext = p->pNext;
		delete p;
		countElem--;
	}
}

List& List::operator=(const List& anotherList)
{
	if (this == &anotherList)
		return *this;
	else
	{
		List temp(anotherList);
		Swap(*this, temp);
		return *this;
	}
}

bool List::operator==(const List& anotherList) const
{
	if (countElem != anotherList.countElem)
		return false;
	if (pFirst == nullptr && anotherList.pFirst == nullptr)
		return true;
	Node* p;
	Node* a;
	for (p = pFirst, a = anotherList.pFirst; p != nullptr; p = p->pNext, a = a->pNext)
	{
		if (p->monom != a->monom)
			return false;
	}
	return true;
}

bool List::operator!=(const List& anotherList) const
{
	return !(*this == anotherList);
}
