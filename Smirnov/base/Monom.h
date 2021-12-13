#pragma once
#include <string>
#include <iostream>
#include <cmath>
const int MaxPow = 999;
using namespace std;

class Monom
{
private:
	double coef;
	int pow;
	bool IsDigit(const char& str)
	{
		if (str == '\0' ||str > '9' || str < '0')
			return false;
		else
			return true;
	}
	bool IsOverFlow(int pow1, int pow2)
	{
		if (pow1 + pow2 > 999)
			return true;
		if ((pow1 % 10 + pow2 % 10) >= 10)
			return true;
		pow1 /= 10;
		pow2 /= 10;
		if ((pow1 % 10 + pow2 % 10) >= 10)
			return true;
		return false;
	}
public:
	Monom(double _coef = 0, int _pow = 0) : coef(_coef)
	{
		if(_pow > MaxPow)
			throw string("—тепень превышает максимально допустимую");
		else if(_pow < 0)
			throw string("—тепень меньше нул€");
		pow = _pow;
	}

	Monom(const string& str) :coef(0), pow(0)
	{
		StrToMonom(str, coef, pow);
		if(pow > MaxPow)
			throw string("—тепень превышает максимально допустимую");
		else if (pow < 0)
			throw string("—тепень меньше нул€");
	}

	int GetPow(const string& str, int& startIndex)
	{
		string resultStr = "";
		int countDigits = 0;
		while (IsDigit(str[++startIndex]))
		{
			resultStr += str[startIndex];
			countDigits++;
		}
		startIndex--;
		if (countDigits > 1)
			throw string("—тепень превышает 9");
		else if (str[startIndex + 1] == '-')
			throw string("ќтрицательна€ степень");
		else if(countDigits == 0)
			resultStr = "1";
		return int(stod(resultStr));
	}

	void StrToMonom(const string& str, double& _coef, int& _pow)
	{
		int i = 0;
		string coefStr;
		for (i; i < str.size(); i++)
		{
			if (str[i] == 'x' || str[i] == 'y' || str[i] == 'z')
				break;
			else
			{
				coefStr += str[i];
			}
		}
		if (coefStr == "")
			coef = 1;
		else if (coefStr == "-")
			coef = -1;
		else if (coefStr == "+")
			coef = 1;
		else
			coef = stod(coefStr);
		for (i; i < str.size(); i++)
		{
			if (str[i] == 'x')
			{
				pow += 100 * GetPow(str, i);
			}
			else if (str[i] == 'y')
			{
				pow += 10 * GetPow(str, i);
			}
			else if (str[i] == 'z')
			{
				pow += GetPow(str, i);
			}
		}
	}

inline	friend ostream& operator<<(std::ostream& out, const Monom& monom);

	string MonomToStr()
	{
		string result;
		int copyPow = pow;
		result = round(coef * 100) / 100;
		int xPow = pow / 100;
		int zPow = pow % 10;
		int yPow = pow - xPow * 100 - zPow * 100;
		if (xPow == 0)
			result += "x";
		else
			result += "x" + to_string(xPow);
		if (yPow == 0)
			result += "y";
		else
			result += "y" + to_string(yPow);
		if (zPow == 0)
			result += "z";
		else
			result += "z" + to_string(zPow);
		return result;
	}

	int GetPow() { return pow; }
	double GetCoef() { return coef; }

	Monom operator+(const Monom& secondOperand)
	{
		if (pow == secondOperand.pow)
		{
			Monom result(coef + secondOperand.coef, pow);
			return result;
		}
		else
		{
			throw string("Ќевозможно сложить мономы с разными степен€ми");
		}
	}
	Monom operator-(const Monom& secondOperand)
	{
		if (pow == secondOperand.pow)
		{
			Monom result(coef - secondOperand.coef, pow);
			return result;
		}
		else
		{
			throw string("Ќевозможно вычесть мономы с разными степен€ми");

		}
	}
	Monom operator*(const Monom& secondOperand)
	{
		if (IsOverFlow(pow, secondOperand.pow))
			throw string("ѕри умножении мономов получилась степень, превышающа€ максимально допустимую");
		else
		{
			Monom result(coef * secondOperand.coef, pow + secondOperand.pow);
			return result;
		}
	}

	bool operator<(const Monom& secondOperand) const
	{
		if (pow < secondOperand.pow)
			return true;
		else
			return false;
	}

	bool operator>(const Monom& secondOperand) const
	{
		return !(*this < secondOperand);
	}

	bool operator==(const Monom& secondOperand) const
	{
		if (coef == secondOperand.coef && pow == secondOperand.pow)
			return true;
		else
			return false;
	}
	bool operator!=(const Monom& secondOperand) const
	{
		return !(*this == secondOperand);
	}
};

ostream& operator<<(ostream& out, const Monom& monom)
{
	string result;
	string sign;
	if (monom.coef > 0)
		sign = "+";
	int xPow = monom.pow / 100;
	int zPow = monom.pow % 10;
	int yPow = (monom.pow - xPow * 100 - zPow) / 10;
	if (xPow == 0)
		result += "";
	else if (xPow == 1)
		result += "x";
	else
		result += "x" + to_string(xPow);
	if (yPow == 0)
		result += "";
	else if (yPow == 1)
		result += "y";
	else
		result += "y" + to_string(yPow);
	if (zPow == 0)
		result += "";
	else if (zPow == 1)
		result += "z";
	else
		result += "z" + to_string(zPow);
	if (monom.coef == 1)
	{
		out << sign << result;
		return out;
	}	
	out << sign << round(monom.coef * 100) / 100 << result;
	return out;
}
