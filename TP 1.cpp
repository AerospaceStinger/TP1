#define _CRT_SECURE_NO_WARNINGS
#include "prof.h"
#include "keeper.h"
#include "admin.cpp"
#include "teacher.h"
#include "student.h"
#include "admin.h"
#include "teacher.cpp"
#include "student.cpp"
#include "base.h"
#include <iostream>
using namespace std;
void sub_menu(keeper* keep) {
    int sub_choice = -1;
    int beta = -1;
    int reserve = 0;
    admin ad;
    while (beta != 0) {
        cout << "Menu of adding element. Where do you want to put your data?\n[1].Students.\n[2].Teachers.\n[3].Administration personal\n[0].Get back\n";
        cin >> sub_choice;
        system("cls");
        switch (sub_choice) {
            student* stud;
            teacher* teac;
            admin* adm;
        case(0):
            beta = 0;
            break;
        case(1):
            stud = new student;
            stud->setData();
            keep->addElement(stud);
            system("pause");
            system("cls");
            break;
        case(2):
            teac = new teacher;
            teac->setData();
            keep->addElement(teac);
            system("pause");
            system("cls");
            break;
        case(3):
            adm = new admin;
            adm->setData();
            keep->addElement(adm);
            system("pause");
            system("cls");
            break;
        }
    } 
}
int main()
{
    keeper* keep = new keeper;
    int a = -1;
    int reserve = 0;
    int choice = -1;
    while (a != 0) {
        cout << "Select area of usage:\n[1].Add element.\n[2].Delete element.\n[3].Show all data.\n[4].Save all data to file.\n[5].Extract all data from file.\n[0].Exit.\n";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 0:
            a = 0;
            break;
        case 1:
            sub_menu(keep);
            break;
        case 2:
            if (keep->getNum() == 0) { cout << "There is no data about admin"; }
            else {
                reserve = 0;
                std::cout << "Index of Element to delete: ";
                while (!(std::cin >> reserve)) {
                    std::cout << "Trouble maaaann. Index of Elemnt to delete: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    if (std::cin >> reserve)
                        break;
                }
                if (reserve <= 0) { cout << "There is no data about this element"; };
                if (keep->getNum() < reserve) { cout << "There is no data about this element"; };
                keep->getOne(reserve).display();
                keep->deleteElement(reserve);
            };
            system("pause");
            system("cls");
            break;
        case 3:
            keep->displayKeep();
            system("pause");
            system("cls");
            break;
        case 4:
            keep->fileDisplayKeep();
            system("pause");
            system("cls");
            break;
        case 5:
            keep->fileSetDataKeep();
            system("pause");
            system("cls");
            break;
        }
    }
}