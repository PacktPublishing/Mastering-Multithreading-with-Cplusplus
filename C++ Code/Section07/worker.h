/*
	worker.h - Header file for the Worker class.
*/

#pragma once
#ifndef WORKER_H
#define WORKER_H

#include "abstract_request.h"
#include <condition_variable>
#include <mutex>

using namespace std;

class Worker {
	condition_variable cv;
	mutex mtx;
	unique_lock<mutex> ulock;
	AbstractRequest* request;
	bool running;
	bool ready;

public:
	Worker() { running = true; ready = false; ulock = unique_lock<mutex>(mtx); }
	void run();
	void stop() { running = false; }
	void setRequest(AbstractRequest* request) { this->request = request; ready = true; }
	void getCondition(condition_variable* &cv);
};

#endif
