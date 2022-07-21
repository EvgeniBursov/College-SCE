#include"Student_2.h"
Student_2::Student_2(char* name, long id, char* thesis, char* visor) :Student(name, id)
{
	_thesis = new char[strlen(thesis)+ 1];
	strcpy(_thesis, thesis);

	_superVisor = new char[strlen(visor) + 1];
	strcpy(_superVisor,visor);


}

void Student_2::print()const
{
	cout << "The name: " << _nameS << " ID: " << _id << " Thesis: " << _thesis << " Visor: " << _superVisor << endl;
}

