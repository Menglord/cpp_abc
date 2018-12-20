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
		std::shared_ptr<A> aptr01(a);
		std::cout << "aptr.use_count() = " << aptr.use_count() << '\n';
		std::cout << "aptr01.use_count() = " << aptr01.use_count() << '\n';
		aptr = aptr01;
		std::cout << "aptr.use_count() = " << aptr.use_count() << '\n';
		std::cout << "aptr01.use_count() = " << aptr01.use_count() << '\n';
	}
}
