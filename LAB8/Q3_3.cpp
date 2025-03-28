#include <iostream>

//Question 3
//A friend function cannot access any members of the class that it si friends with unless provided with a specific instance of that class. It is then able to access that object's private, protected, as well as its public members.


class Test
{
	int member;

	public:
	Test (int member) : member(member) {}

	friend void printMember (Test& t);
};

void printMember (Test& t)
{
	std::cout <<"Member: " <<  t.member << std::endl;
}

int main ()
{
	Test t(1010);

	printMember(t);
}
