#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "admin.h"
#include <fstream>
#include <iostream>
#include "prof.h"
using namespace std;
admin::admin() {
	name = new char[100];
	pos = new char[100];
	num = new char[100];
	field = new char[100];
	cnt = 0;
}
admin::~admin() {
	//cout << "admin destroyed";
}
void admin::display() {
	cout << "Name of Administrator\t:\t" << name << "\nPost\t:\t" << pos << "\nPhone number\t:\t" << num << "\nArea of responsibility\t:\t" << field<<"\n";
}
void admin::setData() {
	char res[] = "beta";
	cout << "Name of Administrator:\t"; cin >> name; cout <<"Post:\t"; cin >> pos; cout << "Phone number:\t"; cin >> num; cout << "Area of responsibility:\t"; cin >> field;

}
void admin::fOut(ofstream& out) {
	out << "Admin\n" << name << "\n" << pos << "\n" << num << "\n" << field;
}
void admin::fIn(ifstream& in) {

}
int admin::getCnt() {
	return cnt;
}