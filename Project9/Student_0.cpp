#include"Student_0.h"
Student_0::Student_0(char* name, long id, bool typeM) :Student(name, id)
{
	if (typeM == 1)
		isShort = true;
	if (typeM == 2)
		isShort = false;

}

void Student_0::print()const
{
	Student::print();
	if (this->isShort)
	{
		cout << "The student learn a long mehina" << endl;
	}
	else
		cout << "The student learn a short mehina" << endl;

}

