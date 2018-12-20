#include <iostream>
#include <thread>
#include <chrono>

#include "cv.hpp"
#include "sharedlock.hpp"

int main(){
	std::cout << "Two readers reading from file." << std::endl;
	std::cout << "A writer competes with them" << std::endl;
	std::thread reader1(read, 1);
	std::thread reader2(read, 2);
	std::thread writer(write);
	reader1.join();
	reader2.join();
	writer.join();
	std::cout << "The first few operations to file are done" << std::endl;;
	reader1 = std::thread(read, 3);
	reader1.join();
	return 0;
}
