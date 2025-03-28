#include <iostream>

//Question 1
//Yes, a friend function can be used, but the obj must be passed in by reference

class Test
{
	std::string member_1;

	public:
	Test () {}
	Test (std::string member_1) : member_1(member_1) {}

	void display ()
	{
		std::cout << member_1 << std::endl;
	}

	friend Test& operator+= (Test& lhs, const std::string rhs);
};

	Test& operator+= (Test& lhs, const std::string rhs)
	{
		lhs.member_1 += rhs;
		
		return lhs;
	}

int main ()
{
	Test test ("this is a test");
	test.display();

	test += ", REPEAT, this is a test";
	test.display();
}
