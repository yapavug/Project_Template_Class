#include <iostream>
#include <string>
using namespace std;

//Шаблон класса--------------------------------------------------------------------
template <typename T>
class SizeType
{
public:
	SizeType(T value)
	{
		this->value = value;
	}
	void SizePrint()
	{
		cout << "Размер переданного аргумента:\t" << sizeof(value) << endl;
	}

protected:
	T value;
};
//---------------------------------------------------------------------------------


//Наследование шаблона класса--------------------------------------------------------------------
template <typename T>
class TypeName : public SizeType<T>
{
public:
	TypeName(T value) : SizeType<T>(value)
	{

	}

	void TypeId()
	{
		cout << "Тип переданного аргумента:\t" << typeid(this->value).name() << endl;
	}

private:

};
//---------------------------------------------------------------------------------

//Спецификация шаблона класса---------------------------------------------------------------
template <typename T>
class Printer
{
public:

	void Print(T value)
	{
		cout << "Пепредано значение:\t" << value << endl;
	}
};

template <>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "Пепредано значение:\t" << value << " \"\_\"" << endl;
	}
};


//---------------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "ru");
	//int a = 3;
	//double b = 9.91;
	//cout << "\t\t---Работа с шаблонным классом---" << endl;
	//SizeType<double> ex1(b);
	//ex1.SizePrint();

	//cout << "\t\t---Работа с наследником шаблона класса---" << endl;
	//TypeName<int> ex2(a);
	//ex2.SizePrint();
	//ex2.TypeId();

	cout << "\t\t---Работа со спецификацией шаблона класса---" << endl;

	Printer<string> per;
	per.Print("Hello");
	return 0;
}