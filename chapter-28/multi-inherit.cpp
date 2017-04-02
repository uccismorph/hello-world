#include <iostream>

class A {
public:
	virtual foo1()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
protected:
	int a = 1;
};

class B {
public:
	virtual foo1() 
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
protected:
	int b = 2;
};

class inherit_AB: public A, public B{
public:
	virtual foo1()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	void print_a() 
	{
		std::cout << a << std::endl;
	}
};

int main()
{
	A *obj = new inherit_AB();
	obj->foo1();

	A *obj_a = (obj);
	obj_a->foo1();

	
	return 0;
}