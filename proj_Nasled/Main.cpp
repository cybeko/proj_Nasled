#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Person
{
protected:
	string name;
	int age;
public:
	Person() : name("[unspecified]"), age(NULL){}
	Person(const char* u_name, int u_age) : name(u_name), age(u_age){}
	void Print()
	{
		cout << "\tPerson info" << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	void Input()
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;
	}
};
class Student : public Person
{
private:
	string university;
public:
	Student() : Person(), university("[unspecified]") {}
	Student(const char* u_name, int u_age, const char* u_uni) : Person(u_name, u_age), university(u_uni) {}
	void Print()
	{
		Person::Print();
		cout << "University: " << university << endl;
		cout << endl;
	}
	void Input()
	{
		Person::Input();
		cout << "Enter university: ";
		cin >> university;
	}
	void Input(const char* u_Univer)
	{
		university = u_Univer;
	}
};
class Driver : public Person
{
private:
	string serialNumber;
	string licenseNumber;
	string carNumber;
public:
	Driver() : Person(), carNumber("[unspecified]"), serialNumber("[unspecified]"), licenseNumber("[unspecified]") {}
	Driver(const char* u_name, int u_age, const char* u_serialNumber, 
		const char* u_license, const char* u_carNumber ) : Person(u_name, u_age){}
	void Print()
	{
		Person::Print();
		cout << "Car number: " << carNumber << endl;
		cout << "Serial number: " << serialNumber << endl;
		cout << "License number: " << licenseNumber << endl;
		cout << endl;

	}
	void Input()
	{
		Person::Input();
		cout << "Enter car number: ";
		cin >> carNumber;

		cout << "Enter license number: ";
		cin >> licenseNumber;

		cout << "Enter license number: ";
		cin >> serialNumber;
	}
	void Input(const char* u_carNumber, const char* u_license, const char* u_serialNumber )
	{
		carNumber = u_carNumber;
		licenseNumber = u_license;
		serialNumber = u_serialNumber;
	}
};
class Teacher : public Person
{
private:
	string school;
	double salary;
	int arrSize;
	string* subjects;
public:
	Teacher() : Person(), school("[unspecified]"), salary(NULL), arrSize(NULL), subjects(nullptr){}
	Teacher(const char* u_name, int u_age, const char* u_school, double u_salary, int u_arrSize, const char* u_subjects[]) : Person(u_name, u_age)
	{
		school = u_school;
		salary = u_salary;

		arrSize = u_arrSize;
		subjects = new string[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			subjects[i] = u_subjects[i];
		}
	}
	~Teacher()
	{
		delete[] subjects;
	}
	void Print()
	{
		Person::Print();
		cout << "School: " << school << endl;
		cout << "Salary: " << salary << endl;

		cout << "School subjects: " << endl;
		for (int i = 0; i < arrSize; i++)
		{
			cout <<"  " << subjects[i] << endl;
		}
		cout << endl;
	}
	void Input()
	{
		Person::Input();
		cout << "Enter school: ";
		cin >> school;

		cout << "Enter salary: ";
		cin >> salary;

		cout << "Enter amount of school subjects: ";
		cin >> arrSize;

		delete[] subjects;
		subjects = new string[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			cout << "Enter the name of subject: ";
			cin >> subjects[i];
		}
	}
	void Input(const char* u_school, double u_salary, int u_arrSize, const char* u_subjects[])
	{
		school = u_school;
		salary = u_salary;
		arrSize = u_arrSize;

		delete[] subjects;
		subjects = new string[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			subjects[i] = u_subjects[i];
		}
	}
};
class Doctor : public Person
{
private:
	string specialty;
	int exp;
	bool isFamDoc;
public:
	Doctor() : Person(), specialty("[unspecified]"), exp(NULL), isFamDoc(NULL)
	{}
	Doctor(const char* u_name, int u_age, const char* u_specialty, int u_exp, bool u_isFamDoc) : Person(u_name, u_age)
	{
		specialty = u_specialty;
		exp = u_exp;
		isFamDoc = u_isFamDoc;
	}

	void Print()
	{
		Person::Print();
		cout << "Specialty: " << specialty << endl;
		cout << "Work experience: " << exp << " years" << endl;
		cout << "Is family doctor: ";

		if (isFamDoc)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		cout << endl;
	}
	void Input()
	{
		Person::Input();
		cout << "Enter specialty: ";
		cin >> specialty;

		cout << "Enter work experience: ";
		cin >> exp;

		cout << "Is family doctor: ";
		cin >> isFamDoc;
	}
	void Input(const char* u_specialty, int u_exp, bool u_isFamDoc)
	{
		specialty = u_specialty;
		exp = u_exp;
		isFamDoc = u_isFamDoc;
	}
};

int main()
{
	Student u_st("Billie Jean", 19, "ITSTEP");
	u_st.Print();

	Driver pDriver("Marsha Johnson", 52, "BH2932", "90J", "LK801");
	pDriver.Print();

	const int arrSize = 3;
	const char* subjects[arrSize] = { "Math", "English", "Biology" };
	Teacher pTeacher("Gale Theguy", 20, "Hawkins Elementary", 12000.10, arrSize, subjects);
	pTeacher.Print();

	Doctor pDoctor("Will Wood", 45, "Anesthesiologist", 23, 0 );
	pDoctor.Print();

}
