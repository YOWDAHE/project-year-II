#include<iostream>
#include<string>
#include<vector>
#include<fstream>
// #include<algorithm>
#include"data.h"

fstream one;
fstream two;
car obj2;
void file()
{
    one.open("text.txt", ios::in);
    int l = 0;
    while(!one.eof())
    {
        
        for (int i = 0; i<10; i++)
        {
            string holder = "";
            if (i <9)
            {
                getline(one, holder, ',');
                if (holder == "" || holder == " ")
                {
                    continue;
                }
            }
            if (i == 9)
            {
                getline(one, holder, '\n');
                if (holder == "" || holder == " ")
                {
                    continue;
                }
            }
            insert(&i, &holder);
        }
        cars.push_back(obj2);
        l++;
    }    
    one.close();

}


void insert(int *m, string *remp)
{
    switch (*m)
    {
        case 0:
            obj2.nameOwner = *remp;
            break;
        case 1:
            obj2.LisenceNo = *remp;
            break;
        case 2:
            obj2.insur = *remp;
            break;
        case 3:
            obj2.carDescription = *remp;
            break;
        case 4:
            obj2.region = *remp;
            break;
        case 5:
            obj2.plateNo = *remp;
            break;
        case 6:
            obj2.type = *remp;
            break;
        case 7:
            obj2.populationInCar = *remp;
            break;
        case 8:
            obj2.populationOut = *remp;
            break;
        case 9:
            obj2.cause = *remp;
            break;
    }

}

void fileIn()
{
    if (!cars.empty())
    {
        one.open("text.txt",ios::out);
        if (one.is_open())
        {
            // one << "--enter\n";
            // one << "--name, licence number, insurance type(first/third person or both), car description, place, plate number, victm/commiter/unknown, population inside the car, population outside, cause of accident\n\n";
            for (int i = 0; i <= cars.size()-1 ; i++)
            {
                if (i == 0)
                {
                    one << cars[i].nameOwner << "," << cars[i].LisenceNo << "," << cars[i].insur << "," << cars[i].carDescription << "," << cars[i].region << "," << cars[i].plateNo << "," << cars[i].type << "," << cars[i].populationInCar << "," << cars[i].populationOut << "," << cars[i].cause;
                }
                if (i > 0)
                {
                     one << endl <<cars[i].nameOwner << "," << cars[i].LisenceNo << "," << cars[i].insur << "," << cars[i].carDescription << "," << cars[i].region << "," << cars[i].plateNo << "," << cars[i].type << "," << cars[i].populationInCar << "," << cars[i].populationOut << "," << cars[i].cause;
                }
                
            }
        }
    }
}