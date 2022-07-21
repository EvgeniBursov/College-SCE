#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
class Student_2 :public Student
{
private:
	char* _thesis;
	char* _superVisor;


public:
	Student_2(char* name, long id, char* thesis, char* visor);
	virtual ~Student_2() { delete[]_thesis; delete[]_superVisor; }

public:
	virtual bool excellent() const { return true; }
	virtual void print() const;
	char* getVisor() { return _superVisor; }



};