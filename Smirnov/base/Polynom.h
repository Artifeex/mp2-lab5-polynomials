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
	void BringingSimilarMembers();
	void SortByDegrees();
	void AddMonom(const Monom& monom);
	
	Polynom operator+(const Polynom& other);
	Polynom operator*(const Polynom& other);

	bool operator==(const Polynom& other) const;

	inline friend ostream& operator<<(ostream& out,const Polynom& polynom);
	inline friend istream& operator>>(istream& in, Polynom& polynom);
};

ostream& operator<<(ostream& out,const Polynom& polynom)
{
	for (size_t i = 0; i < polynom.monoms.GetCountElem(); i++)
	{
		out << polynom.monoms.GetForRead(i);
	}
	return out;
}

istream& operator>>(istream& in, Polynom& polynom)
{
	string strPolynom;
	getline(in, strPolynom);
	Polynom result(strPolynom);
	polynom = result;
	return in;
}

