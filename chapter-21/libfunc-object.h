#ifndef _21_LIBFUNC_OBJECT_
#define _21_LIBFUNC_OBJECT_

#include <iostream>

class Intcomp {
public:
	Intcomp(int (*f0)(int), int (*g0)(int)): 
		fp(f0), gp(g0) {}
	int operator()(int n) const {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return fp(gp(n));
	}
private:
	int (*fp)(int);
	int (*gp)(int);
};

template<class F, class G, class X, class Y>
class Comp {
public:
	Comp(F f0, G g0): f(f0), g(g0) {}
	Y operator()(X x) const {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return f(g(x));
	}
private:
	F f;
	G g;
};

template<class X, class Y>
class CompBase {
public:
	virtual Y operator()(X) const = 0;
	virtual CompBase *clone() const = 0;
	virtual ~CompBase(){}
};

template<class F, class G, class X, class Y>
class CompInheritent: public CompBase<X, Y> {
public:
	CompInheritent(F f0, G g0): f(f0), g(g0) {}
	Y operator()(X x) const {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return f(g(x));
	}
	CompBase<X, Y> *clone() const {
		return new CompInheritent(*this);
	}
private:
	F f;
	G g;
};

template<class X, class Y>
class Composition {
public:
	template<class F, class G> Composition(F f, G g): 
		p(new CompInheritent<F, G, X, Y>(f, g)) {}
	Composition(const Composition &c):
		p(c.p->clone()) {}
	Composition &operator=(const Composition &c){
		if(this != &c){
			delete p;
			p = c.p->clone();
		}
		return *this;
	}
	Y operator()(X x) const {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return (*p)(x);
	}
	~Composition() {}
private:
	CompBase<X, Y> *p;
};
#endif