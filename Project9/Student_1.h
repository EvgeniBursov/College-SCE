#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
#include"Course.h"
class Student_1 :public Student
{
private:
	int _year;
	Course** _courses;
	int _sizeCours;

public:
	Student_1(char* name, long id, int year, Course** courses, int sizeC);
	virtual ~Student_1();

public:
	virtual bool excellent() const;
	virtual void print() const;
	float averageGrade() const;
	Course** getCourse() { return this->_courses; }
	int getSizeCourses() { return this->_sizeCours; }
	bool setCourse(char* nameC, char* nameL, int grade);

};