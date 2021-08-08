#include<iostream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;



class Human
{
	string last_name;
	string first_name;
	unsigned int age;

public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name() const
	{
		return first_name;
	}
	unsigned int get_age() const
	{
		return age;
		}
	void sel_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{

		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//Construcrors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		sel_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	} 

	//Methods
	virtual void print()const
	{
		cout << last_name << " " << first_name<<", "<<" "<<age;
		print_year_suffix(age);
	    cout << endl;
	}
protected:

	void print_year_suffix(unsigned int age) const
	{
		
		if (age % 20 >= 5 && age & 20 <= 20 || age % 10 >= 5 || age % 10 == 0) cout << "���";
			
		else if (age % 10 > 1 && age % 10 < 5) cout << " ����";
		else cout << "���";
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}

	//Construcrors
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) :Human(last_name, first_name, age)
	{

		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//Metohds
	void print()const
	{
		Human:: print();// �������� ���������� ���������
		cout << "�������������" << speciality << "������" << group << "������������" << rating << endl;
		cout << endl;
	}

};
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience() const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	// Constructors
	Teacher
	(
		const string & last_name, const string & first_name, unsigned int age,
		const string & speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	// metohds
	void print()const
	{
		Human::print();
		cout << "�������������:" << speciality << ",���� ������������:" << experience;
		print_year_suffix(experience);
		cout << endl;
	}
};

class Graduate:public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	void set_diploma_theme(const string& diloma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned age,
		const string& speciality, const string& group, double rating,
		const string& get_diploma_theme
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diploma_theme(diploma_theme);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "Gdestructor:\t" << this << endl;
	}

	// Methods
	void print() const
	{
		Student::print();
		cout << "���� ���������� �������:" << diploma_theme << endl;
	}
};

//#define INHERITANCE
#define POLYMORFIZM
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE
	cout << "������������" << endl;
	Human vasya("�������", "�������", 22);
	vasya.print();
	//cout << delimiter << endl;
	Student student("������", "�����", 25, "���", "���_011", 90);
	student.print();
	Teacher teacher("Einstein", "Albert", 142, "Astronomy", 112);
	teacher.print();
	Graduate graduate("Musk", "Elon", 34, " Car building", "VBU_011", 98, "����������� �����");
	graduate.print();
#endif // INHERITANCE

#ifdef POLYMORFIZM
	Human* group[] =
	{
		new Student("��������������", "�������",25, "���"," ���_011", 95),
		new Graduate("�������","�������",27,"���","���_011",95,"��� ��� �����"),
		new Teacher("Einstein","Albert",142, "Astonomy",112),
		new Student("��������","�����",22,"���","���_011",98)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
	}
#endif // POLYMORFIZM
	
#define DataType unsigned long long int
#ifdef TYPE
	//typedef int DataType;// ��������� typedef ������� ��������� ��� ������������� ���� ������
	DataType arr[] = { 3,5,8,13,21,34 };
	for (int i = 0; i < sizeof(arr) / sizeof(DataType); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif // TYPE

}