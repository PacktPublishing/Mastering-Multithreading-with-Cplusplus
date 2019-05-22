/*
	request.cpp - implementation of the Request class.
*/

#include "request.h"
void Request::process() {
	outFnc("Starting processing request " + std::to_string(value) + "...");
	//
}
void Request::finish() {
	outFnc("Finished request " + std::to_string(value));
}
