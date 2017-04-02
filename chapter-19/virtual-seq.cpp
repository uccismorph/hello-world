#include <iostream>
#include <vector>
#include <algorithm>

/* This seq is arithmetic progression, padding specifies the tolerance */
class ConstantIterator {
public:
	ConstantIterator(int k = 0, int p = 0): data(k), padding(p) {}
	int operator*() const { return data; }
	int get_size() const
	{
		std::cout << "this Iteratot size: ";
		std::cout << size << std::endl;
		return size;
	}
	int get_data() const
	{
		std::cout << "this Iteratot data: ";
		std::cout << data << std::endl;
		return size;
	}
	ConstantIterator &operator++() 
	{
		++size;
		data += padding;
		return *this;
	}
	ConstantIterator operator++(int)
	{
		ConstantIterator res = *this;
		data += padding;
		++size;
		//get_data();
		return res;
	}

private:
	int data; 
	int padding;
	int size;
	friend int operator==(const ConstantIterator &, const ConstantIterator &);
	friend int operator!=(const ConstantIterator &, const ConstantIterator &);
	friend ConstantIterator operator+(const ConstantIterator &, int);
	friend ConstantIterator operator+(int, const ConstantIterator &);
};

ConstantIterator operator+(const ConstantIterator &p, int _size)
{
	ConstantIterator res = p;
	res.size += _size;
	return res;
}

ConstantIterator operator+(int _size, const ConstantIterator &p)
{
	return (p + _size);
}

int operator==(const ConstantIterator &lhs, const ConstantIterator &rhs)
{
	return (lhs.size == rhs.size);
}

int operator!=(const ConstantIterator &lhs, const ConstantIterator &rhs)
{
	return !(lhs == rhs);
}

//be careful to use reference 'Out'
template<class In, class Out>
Out copy_data(In start, In end, Out &dest)
{
	while(start != end){
		*dest++ = *start++;
	}
	return dest;
}

int main()
{
	std::vector<int> x = {0};
	x.reserve(50);
	std::vector<int>::iterator itr_x = x.begin();
	std::cout << x.capacity() << std::endl;
	ConstantIterator c(1, 2);
	copy_data(c, c + 100, itr_x);
	for(int i = 0; i < 100; i++){
		std::cout << *(itr_x - i) << std::endl;
	}
}