#pragma once
#include <fstream>
#include <iostream>
using namespace std;
teacher::teacher() {
	name = new char[100];
	groups = new char[100];
	subj_name = new char[100];
	cnt = 0;
}
teacher::~teacher() {
	//cout << "teacher destroyed";
}
void teacher::display() {
	cout << "Name of teacher\t:\t" << name << "\nHis groups\t:\t" << groups << "\nSubject name\t:\t" << subj_name << "\n";
}
void teacher::setData() {
	cout << "Name of teacher\t:\t"; cin >> name; cout << "His groups\t:\t"; cin >> groups; cout << "Subject Name\t:\t"; cin >> subj_name;cout << "\n";
}
void teacher::fOut(ofstream& out) {
	out <<"Teacher\n"<<name << "\n" << groups << "\n" << subj_name;
}
void teacher::fIn(ifstream& in) {
	in >> name >> groups >> subj_name;
}
int teacher::getCnt() {
	return cnt;
}