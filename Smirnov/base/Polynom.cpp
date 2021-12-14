#include "Polynom.h"

bool Polynom::IsEmpty()
{
	if (monoms.IsEmpty())
		return true;
	else
		return false;
}

void Polynom::BringingSimilarMembers()
{
	for (size_t i = 0; i < monoms.GetCountElem(); i++)
	{
		for (size_t j = i + 1; j < monoms.GetCountElem(); j++)
		{
			Monom& m1 = monoms.GetByIndex(i);
			Monom& m2 = monoms.GetByIndex(j);
			if (m1.GetDegree() == m2.GetDegree())
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

void Polynom::SortByDegrees()
{
	monoms.Sort();
}

void Polynom::AppendMonom(const Monom& monom)
{
	monoms.InsertEnd(monom);
}

double Polynom::CalculateInPoint(double x, double y, double z)
{
	double result = 0;
	for (size_t i = 0; i < monoms.GetCountElem(); i++)
	{
		result += monoms.GetForRead(i).CalculateInPoint(x, y, z);
	}
	return result;
}

Polynom Polynom::Derivative(Arguments arg)
{
	Polynom result;
	for (size_t i = 0; i < monoms.GetCountElem(); i++)
	{
		result.AppendMonom(monoms.GetForRead(i).Derivative(arg));
	}
	return result;
}

bool Polynom::operator==(const Polynom& other) const
{
	return monoms == other.monoms;
}

Polynom Polynom::operator+(const Polynom& other)
{
	Polynom result(*this);
	for (size_t i = 0; i < other.monoms.GetCountElem(); i++)
	{
		result.AppendMonom(other.monoms.GetForRead(i));
	}
	result.BringingSimilarMembers();
	if (result.monoms.GetCountElem() == 0)
		return Polynom("0");
	result.SortByDegrees();
	return result;
}

Polynom Polynom::operator-(const Polynom& other)
{
	Polynom result(*this);
	for (size_t i = 0; i < other.monoms.GetCountElem(); i++)
	{
		result.AppendMonom(-other.monoms.GetForRead(i));
	}
	result.BringingSimilarMembers();
	if (result.monoms.GetCountElem() == 0)
		return Polynom("0");
	result.SortByDegrees();
	return result;
}

Polynom Polynom::operator*(const Polynom& other)
{
	Polynom result;
	for (size_t i = 0; i < monoms.GetCountElem(); i++)
	{
		for (size_t j = 0; j < other.monoms.GetCountElem(); j++)
		{
			result.AppendMonom(monoms.GetByIndex(i) * other.monoms.GetForRead(j));
		}
	}
	result.BringingSimilarMembers();
	result.SortByDegrees();
	return result;
}
