#pragma once
// #ifndef _DATA.H
// #define _DATA.H

#include <iostream>
#include <vector>

using namespace std;


struct car{
    string nameOwner= "";
    string LisenceNo= "";
    string insur = "";  
    string carDescription = ""; 
    string region= "";
    string plateNo= "";
    string type = "";
    string populationInCar = "";
    string populationOut= "";
    string cause ="";
};



void fill(int num, char space);
void fill2(string name, char space2);   
void header(string name3, char space3);
int main_menu();
car* reg(car *p, int j);
void search();
void display(int x);
void moreInfo(int *more);
void edit();
void edit2(int *o);
void search();
void file();
void transfer(string *po);
void insert(int *m, string *remp);
void exchange(car *p);



// void test();


string insurace[4] = {"first person", "third person", "both", "None"};
string crime[3] = {"Victim", "Committer", "Unknown"};
const int def = 100;
const char* sys = "cls";


vector <car> cars;
//  = {{"Abel Aregaw", "1234567890", "both", "yellow Toyota corrola", "Piassa", "A345030", "committer", "2", "0", "drunk driving"}};

// #endif