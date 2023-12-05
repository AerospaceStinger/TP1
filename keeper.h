#pragma once
#include <fstream>
#include "student.h"
#include <iostream>
#include "prof.h"
#include "student.cpp"
#include "admin.h"
#include "admin.cpp"
#include "teacher.h"
#include "teacher.cpp"
using namespace std;
class keeper
{
private:
    class base
    {
    public:
        prof* value;
        base* previous;
        base(prof* val, base* prev = nullptr, base* ne = nullptr) {
            this->value = val;
            this->previous = prev;
        };
        ~base() {
            delete this->value;
        };     
    protected:
        
    };
    int count;
    base* head;
    base* res;
public:
    keeper() {
        count = 0;
        head = nullptr;
        res = nullptr;
    };
    ~keeper() {
        while (head != nullptr && count != 0) {
            res = head;
            head = head->previous;
            delete res;
            count--;
        }
        delete head;
    };
    int getNum() { return count; };
    prof& getOne(int cn) {
        int all_c = getNum();
        base* pointer;
        pointer = this->head;
        while (pointer != nullptr || all_c!=0) {
            if (all_c == cn) {
                return  *(pointer->value);
            }
            pointer = pointer->previous;
            all_c--;
        }
    };
    void addElement(prof* x) {
        if (head == nullptr) {
            head = new base(x);
            head->value = x;
        }
        else {
            res = new base(x);
            res->previous = head;
            head = res;
            head->value = x;
        }
        count++;
    }
    void deleteElement(const int index) {	//

        if (getNum() == 1) {	//1 elem = head
            delete this->head;
            head = nullptr;
            count--;
        }
        else if (index == getNum()) {	//last
            base* cur = this->head;
            head = head->previous;
            delete cur;
            count--;
        }
        else {		//not last and >1 elem
            base* cur = this->head;
            base* current1 = this->head;
            int c = getNum();
            bool flag = 0;
            while (flag != 1) {
                if (c == index) {
                    int r = getNum();
                    while (r != (c + 1)) {
                        current1 = current1->previous;
                        r--;
                    }
                    base* temp = cur;
                    cur = cur->previous;
                    current1->previous = cur;
                    delete temp;
                    flag = 1;
                    count--;

                }
                else {
                    cur = cur->previous;
                    c--;
                }
            }
        }
    }
    void displayKeep() {
        if (getNum() == 0) { system("cls"); cout << "No elements found"; getchar(); }
        else{
            std::cout << "\nAll Elements" << std::endl;
        res = head;
        int i = getNum();
        while (res != nullptr && i != 0) {

            std::cout << "-------Element # " << i << "-------" << std::endl;
            (res->value)->display();
            res = res->previous;
            i--;
        }
        std::cout << "\nCount of Elements: " << getNum() << std::endl << std::endl;
        }
    }
    void fileDisplayKeep() {
        std::ofstream out;          
        out.open("out.txt", std::ios::out);         

        if (!out.is_open()) { system("cls"); cout << "File doesn't open\n"; system("pause"); };
            if (getNum() == 0) out << "Keeper is empty\n";
            else {
                std::cout << "No problems\n";
                out << getNum()<<"\n";
                for (int i = 1; i < getNum() + 1; ++i) {
                    getOne(i).fOut(out);
                    out << '\n';
                }
            }
        out.close();
    }
    void fileSetDataKeep() {
        int countElementFile = 0;
        student* st;
        teacher* te;
        admin* ad;
        std::string str;
        std::ifstream in;
        in.open("in.txt");

        try {
            if (!in.is_open()) throw std::exception("File don't open\n");
            if (in.eof()) throw std::exception("File is empty\n");
            in >> countElementFile;
            for (int i = 0; i < countElementFile; i++) {

                in >> str;
                cout << str;
                if (str == "Student") {
                    cout << "Found student!\n";
                    st = new student;
                    st->fIn(in);
                    this->addElement(st);
                }
                else if (str == "Teacher") {
                    te = new teacher;
                    te->fIn(in);
                    this->addElement(te);
                }
                else if (str=="Admin"){
                    ad = new admin;
                    ad->fIn(in);
                    this->addElement(ad);
                }

            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what();
        }
        in.close();
    };
};