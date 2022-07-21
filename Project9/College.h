#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Student.h"
#include"Student_0.h"
#include"Student_1.h"
#include"Student_2.h"
#include<stdio.h>
using namespace std;
class College
{
private:
	Student** _students;
	int _sizeStudent;

public:
	College() { _students = NULL; _sizeStudent = 0; }
	College(const College& college);
	virtual ~College();

public:
	bool add_Student();
	bool add_Grade(long id, char* nameC, char* nameL, int grade);
	void print_All();
	void print_Excellent();
	void find_Types(Student** students, int sizeS,int &Meh,int &BSc,int &Mas);
	int superVisor(char* supervisor);
	void menu();

};