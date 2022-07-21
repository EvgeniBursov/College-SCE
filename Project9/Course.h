#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Course
{
private:
	char* _nameC;
	char* _lecturer;
	int _grade;



public:
	//Course() { _nameC = NULL; _lecturer = NULL; _grade = 0; }
	Course(char* nameC, char* lecturer, int grade);
	Course(const Course& other);
	virtual ~Course() { delete[]_nameC; delete[]_lecturer; }
	////////////////////////////////////////////////////////////////////////
	int getGrade() { return this->_grade; }
	char* getNameCourse() { return this->_nameC; cout << _nameC; }
	char* getNameLecturer() { return this->_lecturer; cout << _lecturer; }
	//////////////////////////////////////////////////////////////////////////
	void setGrade(int grade) { _grade = grade; }
	void setLecturer(char* lecturer);
	void setCourse(char* course);
	/////////////////////////////////////////////////////////////////////////
	void printCourse();


	//float averageGrade();



}; 
