#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id){
	std::unique_lock<std::mutex> lck(mtx);
	while (!ready) cv.wait(lck);
	std::cout << "thread " << id << std::endl;
}

void go() {
	std::unique_lock<std::mutex> lck(mtx);
	ready = true;
	cv.notify_all();
}

int cargo = 0;

std::condition_variable produce, consume;

void consumer() {
	std::unique_lock<std::mutex> lck(mtx);
	while(cargo == 0) consume.wait(lck);
	std::cout << cargo << std::endl;
	cargo = 0;
	produce.notify_one();
}

void producer(int id) {
	std::unique_lock<std::mutex> lck(mtx);
	while (cargo != 0) {
		produce.wait(lck);
		std::cout << "produce wait" << std::endl;
	}
	cargo = id;
	consume.notify_one();
}

