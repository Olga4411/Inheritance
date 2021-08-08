#include<iostream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Animal
{

public:
	
	virtual void sound() = 0;// Pure Virtual Function
	//„исто виртуальный метод
	//мы не знаем как именно перемещаетс€ транспортное средство, пока не узнаем какое именно
	//это транспортное средство
	//поэтому определение этой функции неизвестно, то есть равно 0
	// если в классе есть хот€ бы один чисто виртуальный метод, класс €вл€етс€ абстрактным
};
class Cat :public Animal
{
public:
	void sound()
	{
		cout << "ћ€у" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "√ав" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	//Animal animal;// can not insstatiate abstract class
	Cat cat;
	cat.sound();
	Dog hot;
	hot.sound();

}
