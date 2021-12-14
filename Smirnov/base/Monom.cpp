#include "Monom.h"

bool Monom::IsDigit(const char& str)
{
	if (str == '\0' || str > '9' || str < '0')
		return false;
	else
		return true;
}

bool Monom::IsOverFlow(int pow1, int pow2)
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

int Monom::GetDegreeStr(const string& str, int& startIndex)
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
	else if (countDigits == 0)
		resultStr = "1";
	return int(stod(resultStr));
}

void Monom::StrToMonom(const string& str, double& _coef, int& _pow)
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
			degree += 100 * GetDegreeStr(str, i);
		}
		else if (str[i] == 'y')
		{
			degree += 10 * GetDegreeStr(str, i);
		}
		else if (str[i] == 'z')
		{
			degree += GetDegreeStr(str, i);
		}
	}
}

double Monom::CalculateInPoint(double x, double y, double z)
{
	int xDegree = degree / 100;
	int zDegree = degree % 10;
	int yDegree = (degree % 100 - zDegree) / 10;
	double result = coef * pow(x, xDegree) * pow(y, yDegree) * pow(z, zDegree);
	return result;
}

Monom Monom::operator+(const Monom& secondOperand)
{
	if (degree == secondOperand.degree)
	{
		Monom result(coef + secondOperand.coef, degree);
		return result;
	}
	else
	{
		throw string("Ќевозможно сложить мономы с разными степен€ми");
	}
}

Monom Monom::operator-(const Monom& secondOperand)
{
	if (degree == secondOperand.degree)
	{
		Monom result(coef - secondOperand.coef, degree);
		return result;
	}
	else
	{
		throw string("Ќевозможно вычесть мономы с разными степен€ми");

	}
}

Monom Monom::operator*(const Monom& secondOperand)
{
	if (IsOverFlow(degree, secondOperand.degree))
		throw string("ѕри умножении мономов получилась степень, превышающа€ максимально допустимую");
	else
	{
		Monom result(coef * secondOperand.coef, degree + secondOperand.degree);
		return result;
	}
}

Monom Monom::operator-() const
{
	return Monom(-this->coef, this->degree);
	
}

bool Monom::operator<(const Monom& secondOperand) const
{
	if (degree < secondOperand.degree)
		return true;
	else
		return false;
}

bool Monom::operator>(const Monom& secondOperand) const
{
	return !(*this < secondOperand);
}

bool Monom::operator==(const Monom& secondOperand) const
{
	if (coef == secondOperand.coef && degree == secondOperand.degree)
		return true;
	else
		return false;
}

bool Monom::operator!=(const Monom& secondOperand) const
{
	return !(*this == secondOperand);
}


