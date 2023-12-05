#pragma once
#include <fstream>
#include <iostream>
student::student() {
	name = new char[100];
	group = new char[100];
	spec_name = new char[100];
	course = new char[100];
	average = new char[100];
	cnt = 0;
}
student::~student() {
	//cout << "student destroyed";
}
void student::display() {
	cout << "Name of student\t:\t" << name << "\nHis group\t:\t" << group << "\nSubject name\t:\t" << spec_name << "\nHis course\t:\t" << course << "\nHis average mark\t:\t" << average << "\n";
}
void student::setData() {
	cout << "Name of student\t:\t"; cin >> name; cout << "His group\t:\t"; cin >> group; cout << "Subject name\t:\t"; cin >> spec_name; cout << "His course\t:\t"; cin >> course; cout << "His average mark\t:"; cin >> average;cout << "\n";
}
void student::fOut(ofstream& out) {
	out << "Student\n" << name << "\n" << group << "\n" << spec_name << "\n"<< course << "\n" << average;
}
void student::fIn(ifstream& in) {
	in >> name >> group >> spec_name >> course >> average ;
}
int student::getCnt() {
	return cnt;
}