#include <iostream>

template<class T>
class Iterator {
public:
	virtual bool valid() const = 0;
	virtual T next() = 0;
	virtual ~Iterator() {}
};

template<class T>
class ArrayIterator: public Iterator<T> {
public:
	ArrayIterator(T *p, int c): data(p), len(c) {}
	bool valid() const { return len > 0; }
	T next() 
	{
		len--;
		return *data++;
	}

private:
	T *data;
	int len;
};

template<class T>
T sum(Iterator<T> &ir)
{
	T result = 0;
	while(ir.valid()){
		result += ir.next();
	}
	return result;
}

#if 0
//todo: such kind of definition is invalid, cannot deduce template parameter T 
template<class Iter, class T>
T sum2(Iter it)
{
	T result = 0;
	while(it.valid()){
		result += it.next();
	}
	return result;
}
#endif

int main()
{
	int x[10];
	for(int i = 0; i < 10; i++){
		x[i] = i;
	}
	ArrayIterator<int> it(x, 10);
	std::cout << sum(it) << std::endl;

	return 0;
}