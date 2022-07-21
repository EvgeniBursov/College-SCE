#include"Student.h"
#include<cstring>

Student::Student(char* name, long id)
{
	this->_id = id;
	_nameS = new char [strlen(name)+ 1];
	strcpy(_nameS,name);
}

Student::Student(const Student& student)
{
	_id = student._id;
	_nameS = new char[strlen(student._nameS) + 1];
	strcpy(_nameS, student._nameS);
}

void Student::print() const
{
	cout << "Name of student: " << _nameS << " and ID: " << _id << endl;
}

