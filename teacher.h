#pragma once
#include <fstream>
#include <iostream>
#include "keeper.h"
using namespace std;
class teacher :public prof {
private:
	char* name;
	char* groups;
	char* subj_name;
public:
	teacher();
	~teacher();
	void display() override;
	void setData() override;
	int getCnt() override;
	void fOut(ofstream& out);
	void fIn(ifstream& in);
};