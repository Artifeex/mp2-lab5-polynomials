#pragma once
#include <string>
const int MaxPow = 999;
using namespace std;

class Monom
{
private:
	double coef;
	int pow;
	bool isDigit(const char& str)
	{
		if (str == '\0' ||str > '9' || str < '0')
			return false;
		else
			return true;
	}
public:
	Monom(double _coef = 0, int _pow = 0) : coef(_coef)
	{
		if(_pow > MaxPow)
			throw string("������� ��������� ����������� ����������");
		else if(_pow < 0)
			throw string("������� ������ ����");
		pow = _pow;
	}

	Monom(const string& str) :coef(0), pow(0)
	{
		StrToMonom(str, coef, pow);
		if(pow > MaxPow)
			throw string("������� ��������� ����������� ����������");
		else if (pow < 0)
			throw string("������� ������ ����");
	}

	int GetPow(const string& str, int& startIndex)
	{
		string resultStr = "";
		int countDigits = 0;
		while (isDigit(str[++startIndex]))
		{
			resultStr += str[startIndex];
			countDigits++;
		}
		startIndex--;
		if (countDigits > 1)
			throw string("������� ��������� 9");
		else if (str[startIndex + 1] == '-')
			throw string("������������� �������");
		else if(countDigits == 0)
			resultStr = "1";
		return stod(resultStr);
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
			throw string("���������� ������� ������ � ������� ���������");
		}
	}
	Monom operator*(const Monom& secondOperand)
	{
		int resultPow = pow + secondOperand.pow;
		if (resultPow > 999)
			throw string("��� ��������� ������� ���������� �������, ����������� ����������� ����������");
		else
		{
			Monom result(coef * secondOperand.coef, resultPow);
			return result;
		}
	}

	bool operator==(const Monom& secondOperand) const
	{
		if (coef == secondOperand.coef && pow == secondOperand.pow)
			return true;
		else
			return false;
	}
};

