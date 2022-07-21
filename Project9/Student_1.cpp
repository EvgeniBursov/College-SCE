#include"Student_1.h"
Student_1::Student_1(char* name, long id, int year, Course** courses, int sizeC) :Student(name, id)
{
	_year = year;
	_sizeCours = sizeC;
	_courses = new Course * [_sizeCours];
	for (int i = 0; i < sizeC; i++)
	{
		_courses[i] = courses[i];
	}

}

Student_1::~Student_1()
{
	for (int i = 0; i < _sizeCours; i++)
	{
		delete _courses[i];
	}
	delete[] _courses;
}


bool Student_1::excellent() const
{
	float avrg = averageGrade();
	if (this->_year == 1 || this->_year == 2)
	{
		if (avrg >= 90)
			return true;
		else
			return false;
	}
	if (this->_year == 3 || this->_year == 4)
	{

		if (avrg >= 85)
			return true;
		else
			return false;
	}
}

void Student_1::print() const
{
	float avr = averageGrade();
	cout <<"The name of student: "<< _nameS <<" and the id is: "<< _id << " learn "<< _year <<" year "<< endl;
	if (avr > 1) {
		cout << "The average: " << avr << endl;
	}
	cout << "The courses a student learn: " << endl;
	for (int i = 0; i < _sizeCours; i++)
	{
		cout << _courses[i]->getNameCourse() << endl;
	}

}

float Student_1::averageGrade() const
{
	float num = 0.0;
	for (int i = 0; i < _sizeCours; i++)
	{
		num += _courses[i]->getGrade();
	}
	num = num / _sizeCours;
	return num;
}

bool Student_1::setCourse(char* nameC, char* nameL, int grade)
{
	Course** courses = new Course * [++_sizeCours];
	for (int i = 0; i < _sizeCours; i++) 
	{
		courses[i] = _courses[i];
	}
	delete[] _courses;
	this->_courses = courses;
	this->_courses[_sizeCours - 1] = new Course(nameC, nameL, grade);
	if (_courses)
		return true;
	else
		return false;
}