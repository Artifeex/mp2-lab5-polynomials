#pragma once
#include <string>
#include <iostream>
#include <cmath>
const int MaxDegree = 999;
using namespace std;

class Monom
{
private:
	double coef;
	int degree;

	bool IsDigit(const char& str);
	bool IsOverFlow(int degree1, int degree2);
public:
	Monom(double _coef = 0, int _degree = 0) : coef(_coef)
	{
		if (_degree > MaxDegree)
			throw string("Степень превышает максимально допустимую");
		else if (_degree < 0)
			throw string("Степень меньше нуля");
		degree = _degree;
	}

	Monom(const string& str) :coef(0), degree(0)
	{
		StrToMonom(str, coef, degree);
		if(degree > MaxDegree)
			throw string("Степень превышает максимально допустимую");
		else if (degree < 0)
			throw string("Степень меньше нуля");
	}

	int GetDegreeStr(const string& str, int& startIndex);
	void StrToMonom(const string& str, double& _coef, int& _pow);
	int GetDegree() { return degree; }
	double GetCoef() { return coef; }
	double CalculateInPoint(double x, double y, double z);

	Monom operator+(const Monom& secondOperand);
	Monom operator-(const Monom& secondOperand);
	Monom operator*(const Monom& secondOperand);
	
	bool operator<(const Monom& secondOperand) const;
	bool operator>(const Monom& secondOperand) const;
	bool operator==(const Monom& secondOperand) const;
	bool operator!=(const Monom& secondOperand) const;

	inline friend ostream& operator<<(ostream& out, const Monom& monom);
	inline friend istream& operator>>(istream& in, Monom& monom);
};

ostream& operator<<(ostream& out, const Monom& monom)
{
	string result;
	string sign;
	if (monom.coef > 0)
		sign = "+";
	int xDegree = monom.degree / 100;
	int zDegree = monom.degree % 10;
	int yDegree = (monom.degree % 100 - zDegree) / 10;
	if (xDegree == 0)
		result += "";
	else if (xDegree == 1)
		result += "x";
	else
		result += "x" + to_string(xDegree);
	if (yDegree == 0)
		result += "";
	else if (yDegree == 1)
		result += "y";
	else
		result += "y" + to_string(yDegree);
	if (zDegree == 0)
		result += "";
	else if (zDegree == 1)
		result += "z";
	else
		result += "z" + to_string(zDegree);
	if (monom.coef == 1)
	{
		out << sign << result;
		return out;
	}	
	out << sign << round(monom.coef * 100) / 100 << result;
	return out;
}

istream& operator>>(istream& in, Monom& monom)
{
	string strMonom;
	getline(in, strMonom);
	Monom result(strMonom);
	monom = result;
	return in;
}
