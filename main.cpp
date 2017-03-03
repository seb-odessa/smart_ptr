#include <iostream>
#include <string>

struct A {
	std::string s;
	A() : s() {std::cout<<"A::A(\"\")\n";}
	A(std::string s) : s{s} {std::cout<<"A::A("<<s<<")\n";}
	A(const A& a) {std::cout<<"A::A(const A&)\n"; s = a.s; }
	A& operator=(const A& a) {std::cout<<"A::operator=(const A&)\n";  s = a.s; return *this;}
	~A(){std::cout<<"A::~A("<<s<<")\n";}
};


template <typename T>
class smart_ptr {
	struct Payload {
		T* _ptr;
		size_t _cnt;
		Payload() : _ptr(0), _cnt(0) {}
		Payload(T *p) : _ptr(p), _cnt(1) {}		
	} *_payload;

public:
	smart_ptr(): _payload(new Payload()) {
		std::cout<<"smart_ptr::smart_ptr()\n";
	}

	smart_ptr(T *p): _payload(new Payload(p)) {
		std::cout<<"smart_ptr::smart_ptr(T*)\n";
	}

	smart_ptr(const smart_ptr &value): _payload(value._payload) {
		std::cout<<"smart_ptr::smart_ptr(const smart_ptr&)\n";
		++_payload->_cnt;
	}

	smart_ptr& operator=(const smart_ptr& value) {
		std::cout<<"smart_ptr::operator=(const smart_ptr&)\n";
		if (&value == this)
			return *this;
		
		if (--_payload->_cnt == 0) {
			delete _payload->_ptr;
			delete _payload;
		}

		_payload=value._payload;
		++_payload->_cnt;
		return *this;
	}

	~smart_ptr() {
		std::cout<<"smart_ptr::~smart_ptr()\n";
		if (--_payload->_cnt == 0) {
			delete _payload->_ptr;
			delete _payload;
		}

	}

};


int main() {

	smart_ptr<A> a(new A("a"));
	{		
		{
			smart_ptr<A> b(new A("b"));
			b = a;
		}
		a = a = a;
		smart_ptr<A> c(a);
		{
			smart_ptr<A> d(c); 
			{
				smart_ptr<A> e(d);
				a = e;
			}
		}
	}
	
	return 0;
}

