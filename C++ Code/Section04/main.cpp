/*
	main.cpp - Main file for the Dispatcher demo application.
*/

#include "dispatcher.h"
#include "request.h"

#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include <chrono>

using namespace std;

sig_atomic_t signal_caught = 0;
mutex logMutex;

void sigint_handler(int sig) {
	  signal_caught = 1;
}

void logFnc(string text) {
	  logMutex.lock();
	  cout << text << "\n";
	  logMutex.unlock();
}


int main() {
		signal(SIGINT, &sigint_handler);
	  Dispatcher::init(10);
	  cout << "Initialised.\n";
        int cycles = 0;
	  Request* rq = 0;
		while (!signal_caught && cycles < 50) {
		    rq = new Request();
				rq->setValue(cycles);
				rq->setOutput(&logFnc);
				Dispatcher::addRequest(rq);
				cycles++;
	}

				this_thread::sleep_for(chrono::seconds(5));
				// Cleanup.
				Dispatcher::stop();
		cout << "Clean-up done.\n";
		return 0;
}
