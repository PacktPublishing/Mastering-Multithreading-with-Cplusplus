/*
	abstractrequest.h - header file for the AbstractRequest class.
*/

#pragma once
#ifndef ABSTRACT_REQUEST_H
#define ABSTRACT_REQUEST_H

class AbstractRequest {
	//

public:
	virtual void setValue(int value) = 0;
	virtual void process() = 0;
	virtual void finish() = 0;
};

#endif
