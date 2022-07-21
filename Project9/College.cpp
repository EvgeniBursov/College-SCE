#include"College.h"
#include<typeinfo>
#include<string>
char buffer_1[20] = { '\0' };
char buffer_2[20] = { '\0' };
long id;
int grade;

	
College::College(const College& college)
{
	_sizeStudent = college._sizeStudent;
	_students = new Student * [college._sizeStudent];
	for (int i = 0; i < college._sizeStudent; i++)
	{
		_students[i] = college._students[i];
	}
}

College::~College()
{
	for (int i = 0; i < _sizeStudent; i++)
		delete _students[i];
	delete[]_students;
}

bool College::add_Student()
{
	char name[20]={ '\0'};
	char thesis[20] = {};
	char visor[20]= {};
	long id;
	int type, year;
	bool typeM;
	cout << "Enter id of the student: ";
	cin >> id;
	if (this->_students)
	{
		
		for (int i = 0; i < _sizeStudent; i++)
		{
			if (this->_students[i]->getID()==id)
				return false;
		}
	}

	
	cout << "Enter the type of student" << endl;
	cout << "0 - Mehina" << endl << "1 - Bachelor" << endl << "2 - Master's" << endl;
	cin >> type;
	cout << "Enter name: ";
	cin >> name;
	

	Student** students = new Student * [++_sizeStudent];
	for (int i = 0; i < _sizeStudent-1; i++)
	{
		students[i] = this->_students[i];
	}
	delete[]_students; ////////////////////////////////////////
	_students = students;
	if (type == 0)
	{
		cout << endl << "Enter 1 - for short mehina or 2 - for long mehina: ";
		cin >> type;
		if (type == 1)
			typeM = 0;
		if (type == 2)
			typeM = 1;
		_students[_sizeStudent - 1] = new Student_0(name, id, typeM);
		return true;
	}
	else if (type == 1)
	{

		cout << endl << "Enter the student year: ";
		cin >> year;
		Course** courses = NULL;
		int sizeC = 0;
		_students[_sizeStudent - 1] = new Student_1(name, id, year, courses, sizeC);
		return true;
	}
	else if (type == 2)
	{
		cout << endl << "Enter the theme of thesis: ";
		cin >> thesis;
		cout << endl << "Enter the name of visor: ";
		cin >> visor;
		_students[_sizeStudent - 1] = new Student_2(name, id, thesis, visor);
		return true;
	}
	else
		return false;


}

bool College::add_Grade(long id, char* nameC, char* nameL, int grade)
{
	if (_students)
	{
		for (int i = 0; i < _sizeStudent; i++)
		{
			//typeid(_students[i]) == typeid(Student_1) && && (typeid(_students[i]) == typeid(Student_1)))
			if (id == _students[i]->getID())
			{
				if (typeid(*_students[i]) == typeid(Student_1))
				{
					Student_1* student = (Student_1*)this->_students[i];
					for (int i = 0; i < student->getSizeCourses(); i++)
					{
						if (strcmp(student->getCourse()[i]->getNameCourse(), nameC) == 0)
						{
							student->getCourse()[i]->setGrade(grade);
							student->getCourse()[i]->setLecturer(nameL);
							return true;
						}
					}
					if (student->setCourse(nameC, nameL, grade))
						return true;
					else
						return false;
				}
			}
		}
		return false;
	}
	else
		return false;
}

void College::print_All()
{
	for (int i = 0; i < _sizeStudent; i++)
	{
		this->_students[i]->print();
	}
}

void College::print_Excellent()
{

	for (int i = 0; i < _sizeStudent; i++)
	{
		if (_students[i]->excellent())
			_students[i]->print();
	}
}

void College::find_Types(Student** students, int sizeS, int &Meh,int &BSc,int &Mas)
{
	for (int i = 0; i < sizeS; i++)
	{
		if (students)
		{
			if (typeid(*students[i]) == typeid(Student_0))
			{
				Meh++;
			}
			else if (typeid(*students[i]) == typeid(Student_1))
			{
				BSc++;
			}
			else
				Mas++;
		}
	}

}

int College::superVisor(char* supervisor)
{
	int count = 0;
	for (int i = 0; i < _sizeStudent; i++)
	{
		if (typeid(*_students[i]) == typeid(Student_2))
		{
			Student_2* student = (Student_2*)_students[i];
			if (strcmp(student->getVisor(), supervisor) == 0)
			{
				_students[i]->print();
				count++;
			}
		}
	}
	return count;
}

void College::menu()
{
	int Exitflag = 1;
	int choise;
	while (Exitflag)
	{
		cout << "Choose your prefered option" << endl;
		cout << "1. Add student " << endl;
		cout << "2. Add grade" << endl;
		cout << "3. Print all" << endl;
		cout << "4. Print excellent" << endl;
		cout << "5. Types of student" << endl;
		cout << "6. Supervisor" << endl;
		cout << "7. Quit" << endl;
		cin >> choise;
		while ((choise < 1) || (choise > 7))
		{
			cout << "The option you choose isnt listed above, please try again" << endl;
			cout << "Please choose your prefered option" << endl;
			cout << "1. Add student " << endl;
			cout << "2. Add grade" << endl;
			cout << "3. Print all" << endl;
			cout << "4. Print excellent" << endl;
			cout << "5. Types of student" << endl;
			cout << "6. Supervisor" << endl;
			cout << "7. Quit" << endl;
			cin >> choise;
		}
		switch (choise)
		{
		case 1:
		{
			add_Student();
			break;
		}
		case 2:
		{
			cout << "Enter id: ";
			cin >> id;
			cout << endl << "Enter the name of course: ";
			cin >> buffer_1;
			cout << endl << "Enter the name of lecture: ";
			cin >> buffer_2;
			cout << endl << "Enter grade: ";
			cin >> grade;
			add_Grade(id, buffer_1, buffer_2, grade);
			break;
		}
		case 3:
		{
			print_All();
			break;
		}
		case 4:
		{
			print_Excellent();
			break;
		}
		case 5:
		{
			int Meh = 0, BSc = 0, Mas = 0;
			find_Types(_students, _sizeStudent, Meh, BSc, Mas);

			cout << "The num of student learn in mehina: " << Meh << endl;
			cout << "The num of student learn in Toar 1: " << BSc << endl;
			cout << "The num of student learn in Toar 2: " << Mas << endl;
			break;
		}
		case 6:
		{
			int count;
			cout << endl << "Enter the name of visor: ";
			cin >> buffer_2;
			count=superVisor(buffer_2);
			cout << "The num of student: " << count <<endl;
			break;
		}
		case 7:
		{
			cout << endl << "Goodbye";
			Exitflag = 0;
			break;
		}
		break;
		}

	}
}