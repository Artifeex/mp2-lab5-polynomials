#include <iostream>
#include <conio.h>
#include "Manager.h"
using namespace std;
bool showedMenu = false;
Manager manager;
void PrintMenu()
{
	cout << "При вводе вещественных коэффициентов используйте запятую." << endl;
	cout << "Мономы можно вводить в любом порядке, в процессе работы они отсортируются по степеням." << endl;
	cout << "Аргументы с 0 степенью можно не писать. Коэффициенты и степени равные 1 также можно не писать. yxx - преобразуется в x3y" << endl;
	cout << "Пример корренктного ввода: -z + 2,5x2y2" << endl;
	cout << "1. Добавить новый полином." << endl;
	cout << "2. Удалить полином по индексу. " << endl;
	cout << "3. Список полиномов на данный момент." << endl;
	cout << "4. Получить полиномы из файла." << endl;
	cout << "5. Сохранить полиномы в файл." << endl;
	cout << "6. Арифметические операции с полиномами." << endl;
	cout << "7. Расчет в точке." << endl;
	cout << "8. Расчет в производной по аргументу." << endl;
	cout << "0. Очистить список полиномов." << endl;
	cout << "ESC - Выход из программы." << endl;
}

void Start()
{
	int choice = 0;
	bool exitMainMenu = false;
	double xVal = 0;
	double yVal = 0;
	double zVal = 0;
	string strPolynom;
	string operation;
	int index = -1;
	Arguments arg;
	string argString;
	Polynom result;
	while (!exitMainMenu)
	{
		if (!showedMenu)
		{
			PrintMenu();
			showedMenu = true;
		}
		cout << "Выберите пункт меню:";
		choice = _getch();
		cout << endl;
		try
		{
			switch (choice)
			{
			case 27: //ESC
				exitMainMenu = true;
				break;
			case 49: //1
				cout << "Введите полином" << endl;
				getline(cin,strPolynom);
				manager.AppendPolynom(strPolynom);
				if (manager.IsEmpty())
				{
					cout << "Полином равен 0. Добавление не произошло" << endl;
					break;
				}
				cout << "Полином " << manager.GetPolynomForRead(manager.GetCountPolynoms() - 1) << " успешно добавлен." << endl;
				break;
			case 50: //2
				if (manager.IsEmpty())
				{
					cout << "Нечего удалять" << endl;
					break;
				}
				cout << "Введите индекс полинома, который хотите удалить." << endl;
				cin >> index;
				std::cin.ignore(32767, '\n');
				cout << "Вы собираетесь удалить полином:" << manager.GetPolynomForRead(index) << endl;
				cout << "Вы уверены? 1-Да, 2-Нет" << endl;
				cin >> choice;
				std::cin.ignore(32767, '\n');
				if (choice == 1)
				{
					manager.DeletePolynom(index);
					cout << "Полином успешно удален" << endl;
				}
				else
					cout << "Удаление отменено" << endl;
				break;
			case 51: //3
				if (manager.IsEmpty())
				{
					cout << "Список полиномов пуст" << endl;
					break;
				}
				cout << "Список полиномов:" << endl;
				manager.PrintConsole();
				break;
			case 52: //4
				manager.GetFromFile();
				if (manager.IsEmpty())
				{
					cout << "В файле отсутствую полиномы" << endl;
					break;
				}
				cout << "Полиномы из файла успешно добавлены" << endl;
				break;
			case 53: //5
				if (manager.IsEmpty())
				{
					cout << "Список полиномов пуст" << endl;
					break;
				}
				manager.SaveInFile();
				cout << "Полиномы успешно сохранены в файл" << endl;
				break;
			case 54: //6
				if (manager.IsEmpty())
				{
					cout << "Список полиномов пуст" << endl;
					break;
				}
				int index1;
				int index2;
				cout << "Введите индекс двух полиномов, которые будут участвовать в операции" << endl;
				cout << "Индекс первого: ";
				cin >> index1;
				std::cin.ignore(32767, '\n');
				cout << "Индекс второго: ";
				cin >> index2;
				std::cin.ignore(32767, '\n');
				cout << "Введите нужную операцию(+,-,*)" << endl;
				cin >> operation;
				if (operation == "+")
				{
					result = manager.GetPolynomForRead(index1) + manager.GetPolynomForRead(index2);
					if (result.IsEmpty())
					{
						cout << "Результат: 0" << endl;
						break;
					}
					cout << "Результат: " << result << endl;	
				}
				else if (operation == "-")
				{
					if (result.IsEmpty())
					{
						cout << "Результат: 0" << endl;
						break;
					}
					result = manager.GetPolynomForRead(index1) - manager.GetPolynomForRead(index2);
					cout << "Результат: " << result << endl;
				}
				else if (operation == "*")
				{
					result = manager.GetPolynomForRead(index1) * manager.GetPolynomForRead(index2);
					cout << "Результат: " << result << endl;
				}
				cout << "Сохранить результат в список полиномов?(1 - Да, 2 - Нет)" << endl;
				cin >> choice;
				std::cin.ignore(32767, '\n');
				if (choice == 1)
				{
					manager.AppendPolynom(result);
					cout << "Результат успешно записан" << endl;
				}
				break;
			case 55: //7
				if (manager.IsEmpty())
				{
					cout << "Список полиномов пуст" << endl;
					break;
				}
				cout << "Значение переменной x = ";
				cin >> xVal;
				std::cin.ignore(32767, '\n');
				cout << "Значение переменной y = ";
				cin >> yVal;
				std::cin.ignore(32767, '\n');
				cout << "Значение переменной z = ";
				cin >> zVal;
				std::cin.ignore(32767, '\n');
				cout << "Введите индекс полинома: ";
				cin >> index;
				std::cin.ignore(32767, '\n');
				cout << "Значение в точке " << xVal <<", "<< yVal << ", "<< zVal << " = " << manager.CalculateInPoint(xVal, yVal, zVal, index) << endl;
				break;
			case 56: //8
			{
				if (manager.IsEmpty())
				{
					cout << "Список полиномов пуст" << endl;
					break;
				}
				cout << "Введите индекс полинома, по которому необходимо найти производную:";
				cin >> choice;
				std::cin.ignore(32767, '\n');
				cout << "Введите переменную, по которой необходимо найти производную:";
				cin >> argString;
				if (argString == "x")
					arg = x;
				else if(argString == "y")
					arg = y;
				else if (argString == "z")
					arg = z;
				else
				{
					cout << "Переменной данного вида не существует" << endl;
					break;
				}
				result = manager.Derivative(arg, choice);
				if (result.IsEmpty())
				{
					cout << "Результат: 0" << endl;
					break;
				}
				cout << "Результат: " << result << endl;
				cout << "Сохранить результат в список полиномов?(1 - Да, 2 - Нет)" << endl;
				cin >> choice;
				std::cin.ignore(32767, '\n');
				if (choice == 1)
				{
					manager.AppendPolynom(result);
					cout << "Результат успешно записан" << endl;
				}
				break;
			}
			case 48:
				if (manager.IsEmpty())
					cout << "Нечего очищать" << endl;
				else
				{
					cout << "Вы собираетесь очистить список всех полиномов. Вы уверены? 1-Да, 2-Нет" << endl;
					cin >> choice;
					std::cin.ignore(32767, '\n');
					if (choice == 1)
					{
						manager.Clear();
						cout << "Очищено" << endl;
					}
					else
						cout << "Список не был очищен" << endl;
				}
				break;
			}	
		}
		catch (string str)
		{
			cout << str << endl;
			Start();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Start();
}

