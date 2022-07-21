#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Student
{
protected:
	char* _nameS;
	long _id;

public:
	Student(char* name, long id);
	Student(const Student& student);
	virtual ~Student() { delete[] _nameS; }


public:
	virtual bool excellent() const = 0;
	virtual void print() const ;
	long getID() const { return this->_id; }
	char* getName() { return this->_nameS; }




};