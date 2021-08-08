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
	//����� ����������� �����
	//�� �� ����� ��� ������ ������������ ������������ ��������, ���� �� ������ ����� ������
	//��� ������������ ��������
	//������� ����������� ���� ������� ����������, �� ���� ����� 0
	// ���� � ������ ���� ���� �� ���� ����� ����������� �����, ����� �������� �����������
};
class Cat :public Animal
{
public:
	void sound()
	{
		cout << "���" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "���" << endl;
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
