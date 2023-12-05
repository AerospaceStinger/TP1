#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class prof abstract{
public:
	virtual void display() = 0;
	virtual void setData() = 0;
	virtual int getCnt() = 0;
	virtual void fOut(ofstream& out) = 0;
	virtual void fIn(ifstream& in) = 0;
	int cnt;
};