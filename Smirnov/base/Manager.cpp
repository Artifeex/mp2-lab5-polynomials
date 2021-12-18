#include "Manager.h"

void Manager::AppendPolynom(const string& strPolynom)
{
	Polynom p(strPolynom);
	if (p.IsEmpty())
	{
		return;
	}
	polynoms.push_back(p);
	countPolynoms++;
}

Polynom Manager::GetPolynomForRead(int index)
{
	if (index >= countPolynoms)
		throw string("Слишком большой индекс");
	else if (index < 0)
		throw string("Слишком маленький индекс");
	return polynoms[index];
}

Polynom& Manager::GetPolynom(int index)
{
	if (index >= countPolynoms)
		throw string("Слишком большой индекс");
	else if (index < 0)
		throw string("Слишком маленький индекс");
	return polynoms[index];
}

void Manager::SaveInFile()
{
	string nameFile = "Polynoms.txt";
	ofstream outf;
	outf.open(nameFile);
	if (outf.is_open())
	{
		int i = 0;
		while (i < countPolynoms)
		{
			outf << polynoms[i] << endl;
			i++;
		}
	}
	else
	{
		throw string("Ошибка открытия файла");
	}
	outf.close();
}

int Manager::GetCountPolynoms()
{
	return countPolynoms;
}

void Manager::AppendPolynom(const Polynom& p)
{
	polynoms.push_back(p);
	countPolynoms++;
}

void Manager::GetFromFile()
{
	string nameFile = "Polynoms.txt";
	ifstream inf;
	inf.open(nameFile);
	if (inf.is_open())
	{
		while (inf)
		{
			string strPolynom;
			getline(inf, strPolynom);
			if (strPolynom == "")
				continue;
			Polynom p(strPolynom);
			polynoms.push_back(p);
			countPolynoms++;
		}
		inf.close();
	}
	else
	{
		throw string("Ошибка открытия файла");
	}
}

Polynom Manager::Derivative(Arguments arg, int index)
{
	if (index >= countPolynoms)
		throw string("Слишком большой индекс");
	else if (index < 0)
		throw string("Слишком маленький индекс");
	return polynoms[index].Derivative(arg);
}

void Manager::PrintConsole()
{
	for (size_t i = 0; i < polynoms.size(); i++)
	{
		cout << i << ": " << polynoms[i] << endl;
	}
}

double Manager::CalculateInPoint(double x, double y, double z, int index)
{
	if (index >= countPolynoms)
		throw string("Слишком большой индекс");
	else if (index < 0)
		throw string("Слишком маленький индекс");
	return polynoms[index].CalculateInPoint(x, y, z);
}

void Manager::DeletePolynom(int index)
{
	if (index >= countPolynoms)
		throw string("Слишком большой индекс");
	else if (index < 0)
		throw string("Слишком маленький индекс");
	polynoms.erase(polynoms.begin() + index);
	countPolynoms--;
}

bool Manager::IsEmpty()
{
	if (countPolynoms == 0)
		return true;
	else
		return false;
}

void Manager::Clear()
{
	polynoms.clear();
	countPolynoms = 0;
}
