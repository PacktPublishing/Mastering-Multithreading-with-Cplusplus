/*
	worker.cpp - Implementation of the Worker class.
*/

#include "worker.h"
#include "dispatcher.h"
#include <chrono>

using namespace std;

void Worker::getCondition(condition_variable* &cv) {
	cv = &(this)->cv;
}

void Worker::run() {
	while (running) {
		if (ready) {
			// Execute the request.
			ready = false;
			request->process();
			request->finish();
		}

		if (Dispatcher::addWorker(this)) {
			  // Use the ready loop to deal with spurious wake-ups.
			while (!ready && running) {
				if (cv.wait_for(ulock, chrono::seconds(1)) == cv_status::timeout) {
					 // We timed out, but we keep waiting unless the worker is
					 // stopped by the dispatcher.
				}
			}
		}
	}
}
