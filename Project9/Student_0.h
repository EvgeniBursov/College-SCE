#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
class Student_0 :public Student
{
private:
	bool isShort;

public:
	Student_0(char* name, long id, bool typeM);
	virtual ~Student_0() {}


public:
	virtual bool excellent() const { return false; }
	virtual void print() const;






};