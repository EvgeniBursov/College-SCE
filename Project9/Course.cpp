#include"Course.h"
Course::Course(char* nameC, char* lecturer, int grade) :_grade(grade)
{
	_nameC = new char[strlen(nameC) + 1];
	strcpy(_nameC, nameC);

	_lecturer = new char[strlen(lecturer) + 1];
	strcpy(_lecturer, lecturer);

}

Course::Course(const Course& other):_grade(other._grade)
{
	_nameC = new char[strlen(other._nameC) + 1];
	strcpy(_nameC, other._nameC);
	_lecturer = new char[strlen(other._lecturer) + 1];
	strcpy(_lecturer, other._lecturer);
	
}

void Course::setLecturer(char* lecturer)
{
	_lecturer = new char[strlen(lecturer)+1];
	strcpy(_lecturer, lecturer);
}

void Course::setCourse(char* course)
{
	_nameC = new char[strlen(course) + 1];
	strcpy(_nameC, course); 
}

void Course::printCourse()
{
	cout << "The name of course: " << _nameC << endl;
	cout<< "The name of lecture: " << _lecturer << endl;
	cout << "The grade: " << _grade << endl;

	/*for (int i = 0;; i++)
	{
		cout << _nameC[i];
		if (_nameC[i] == '\0')
			break;
	}
	cout << endl;
	for (int i = 0;; i++)
	{
		cout << _lecturer[i];
		if (_lecturer[i] == '\0')
			break;
	}
	cout << endl << _grade << endl;*/
}
