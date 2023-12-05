#pragma once
class student :public prof {
private:
	char* name;
	char* group;
	char* spec_name;
	char* course;
	char* average;
	int cnt;
public:
	student();
	~student();
	void display() override;
	void setData() override;
	int getCnt() override;
	void fOut(ofstream& out);
	void fIn(ifstream& in);
};