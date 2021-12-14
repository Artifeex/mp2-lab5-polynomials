#pragma once
#include "Polynom.h"
#include <fstream>
#include <vector>

class Manager
{
private:
	vector<Polynom> polynoms;
	int countPolynoms;
public:
	Manager() :countPolynoms(0) {}
	Polynom GetPolynomForRead(int index);
	Polynom& GetPolynom(int index);
	int GetCountPolynoms();
	void AppendPolynom(const Polynom& p);
	void AppendPolynom(const string& strPolynom);
	void DeletePolynom(int index);
	bool IsEmpty();
	void Clear();
	void SaveInFile();
	void GetFromFile();
	Polynom Derivative(Arguments arg, int index);
	void PrintConsole();
	double CalculateInPoint(double x, double y, double z, int index);
};

