#include <iostream>
#include <memory>


class A {
public:
	A(int a) : m_a(a) {
		std::cout << "Class A Construct with m_a: " << m_a << std::endl;

	}

	virtual ~A(){
		std::cout << "Class A Destruct with m_a: " << m_a << std::endl;
	}

private:
	int m_a;
};

int main(int argc, char** argv) {
	{
		A* a = new A(1);
	}

	{
		std::shared_ptr<A> aptr = std::make_shared<A>(2);
	}

	{
		A* a = new A(3);
		std::shared_ptr<A> aptr;
		aptr.reset(a);
	}
}
