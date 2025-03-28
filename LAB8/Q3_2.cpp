#include <iostream>

//Question 2                                       
//It is possible to overload an operator with one of the operands as a primitive data type. This is possible if the calling (operator overloading) function is a member function AND the second operand is the primitive data type    . Else, if the first/left operand is the primitive data type, then a friend function MUST be used as an operator     overloading member function is called on the left operand.

class Test
{
	int member_1;

	public:
	Test (int member_1) : member_1(member_1) {}

	friend Test operator+ (Test first, int other);

	void display ()
	{
		std::cout << "Member: " << member_1 << std::endl;
	}
};

Test operator+ (Test first, int other)
{
	first.member_1 += other;
	return first;
}

int main ()
{
	Test t1 (25);
	t1.display();

	t1 = t1 + 11;
	t1.display();
};
