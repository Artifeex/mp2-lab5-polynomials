#pragma once
#include "List.h"
#include <string>
#include <iostream>
using namespace std;

class Polynom
{
private:
	List monoms;
public:
	Polynom(){}
	Polynom(const List& _monoms): monoms(_monoms){}
	Polynom(const Polynom& _polynom): monoms(_polynom.monoms){}
	Polynom(const string& str)
	{
		string copyStr = str;
		copyStr.erase(remove_if(copyStr.begin(), copyStr.end(), isspace), copyStr.end());
		int startIndex = 0;
		int endIndex = 0;
		bool isStarted = false;
		bool isClosed = false;
		int i = 0;
		for (i = 0; i < copyStr.size(); i++)
		{
			if (copyStr[i] == '+' || copyStr[i] == '-')
			{
				if (i == 0)//если первый моном начался со знака
					continue;
				endIndex = i-1;
				string monom = copyStr.substr(startIndex, endIndex - startIndex + 1);
				monoms.InsertEnd(Monom(monom));
				startIndex = endIndex + 1;
			}
		}
		string lastMonom = copyStr.substr(startIndex, copyStr.size());
		monoms.InsertEnd(Monom(lastMonom));
	}

	void BringingSimilarMembers()
	{
		for (size_t i = 0; i < monoms.GetCountElem(); i++)
		{
			for (size_t j = i + 1; j < monoms.GetCountElem(); j++)
			{
				Monom& m1 = monoms.GetByIndex(i);
				Monom& m2 = monoms.GetByIndex(j);
				if (m1.GetPow() == m2.GetPow())
				{
					m1 = m1 + m2;
					monoms.DeleteByIndex(j);
				}
			}
		}

		for (size_t i = 0; i < monoms.GetCountElem(); i++)
		{
			if (monoms.GetForRead(i).GetCoef() == 0)
			{
				monoms.DeleteByIndex(i);
				i = i - 1;
			}
		}
	}

	void SortByPows()
	{
		monoms.Sort();
	}

	void AddMonom(const Monom& monom)
	{
		monoms.InsertEnd(monom);
	}

	bool operator==(const Polynom& other) const
	{
		return monoms == other.monoms;
	}

	Polynom operator+(Polynom& other)
	{
		Polynom result(*this);
		for (size_t i = 0; i < other.monoms.GetCountElem(); i++)
		{
			result.AddMonom(other.monoms.GetByIndex(i));
		}
		result.BringingSimilarMembers();
		if (result.monoms.GetCountElem() == 0)
			return Polynom("0");
		result.SortByPows();
		return result;
	}

	inline friend ostream& operator<<(ostream& out,const Polynom& polynom);

	Polynom operator*(Polynom& other)
	{
		Polynom result;
		for (size_t i = 0; i < monoms.GetCountElem(); i++)
		{
			for (size_t j = 0; j < other.monoms.GetCountElem(); j++)
			{
				result.AddMonom(monoms.GetByIndex(i) * other.monoms.GetByIndex(j));
			}
		}
		result.BringingSimilarMembers();
		result.SortByPows();
		return result;
	}
};

ostream& operator<<(ostream& out,const Polynom& polynom)
{
	for (size_t i = 0; i < polynom.monoms.GetCountElem(); i++)
	{
		out << polynom.monoms.GetForRead(i);
	}
	return out;
}

