#include <stdio.h>

int f(int a)
{
	printf("%s\n", __PRETTY_FUNCTION__);
	return a;
}
int g(int a)
{
	printf("%s\n", __PRETTY_FUNCTION__);
	return a;
}
void print(int a)
{
	printf("has number: %d\n", a);
}

int result(int n)
{
	return f(g(n));
}

void apply(void func(int)) //can be declared as void func(int) or void (*func)(int)
{
	int i = 0;
	for(i = 0; i < 10; i++){
		(*func)(i); //can be called as (*func)(i) or func(i)
	}
}

int (*compose(int f(int), int g(int)))(int x)
{
	return result;
}

//int (*h)(int) = compose(f, g); //connot compile in c

int main()
{
	int a = 42;	
	int (*h)(int) = compose(f, g); //in c, need to write this way
	h(a); //P.245 example works

	apply(print);
	return 0;
}