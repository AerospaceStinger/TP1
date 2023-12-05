#pragma once
using namespace std;
class admin :public prof {
private:
	char* name;
	char* pos;
	char* num;
	char* field;
public:
	admin();
	~admin();
	void display() override;
	void setData() override;
	int getCnt() override;
	void fOut(ofstream& out) override;
	void fIn(ifstream& in) override;
};