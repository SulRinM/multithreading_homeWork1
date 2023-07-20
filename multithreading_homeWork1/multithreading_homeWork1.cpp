#define _USE_MATH_DEFINES
#include <iostream>
#include <thread>
#include "Timer.h"

using namespace std;

void client(int& counter) {
	const int maxCounter = 10;	
	while (counter < maxCounter) {
		this_thread::sleep_for(1000ms);
		consol_parameter::SetColor(15, 0);
		counter++;
		cout << counter << " ";
	}		
}

void operat(int& counter) {
	while (counter > 0) {
		this_thread::sleep_for(2000ms);
		consol_parameter::SetColor(10, 0);
		counter--;
		cout << counter << " ";
	}
}

int main() {
	int comCounter = 0;
	thread th1(client, ref(comCounter));
	th1.join();
	thread th2(operat, ref(comCounter));
	th2.join();

	return 0;
}

