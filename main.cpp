#include <iostream>
#include <string>
using namespace std;

//������ ������--------------------------------------------------------------------
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
		cout << "������ ����������� ���������:\t" << sizeof(value) << endl;
	}

protected:
	T value;
};
//---------------------------------------------------------------------------------


//������������ ������� ������--------------------------------------------------------------------
template <typename T>
class TypeName : public SizeType<T>
{
public:
	TypeName(T value) : SizeType<T>(value)
	{

	}

	void TypeId()
	{
		cout << "��� ����������� ���������:\t" << typeid(this->value).name() << endl;
	}

private:

};
//---------------------------------------------------------------------------------

//������������ ������� ������---------------------------------------------------------------
template <typename T>
class Printer
{
public:

	void Print(T value)
	{
		cout << "��������� ��������:\t" << value << endl;
	}
};

template <>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "��������� ��������:\t" << value << " \"\_\"" << endl;
	}
};


//---------------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "ru");
	//int a = 3;
	//double b = 9.91;
	//cout << "\t\t---������ � ��������� �������---" << endl;
	//SizeType<double> ex1(b);
	//ex1.SizePrint();

	//cout << "\t\t---������ � ����������� ������� ������---" << endl;
	//TypeName<int> ex2(a);
	//ex2.SizePrint();
	//ex2.TypeId();

	cout << "\t\t---������ �� ������������� ������� ������---" << endl;

	Printer<string> per;
	per.Print("Hello");
	return 0;
}