#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "file.cpp"
#include "data.h"

using namespace std;
int ForMain = 0;
int main()
{
    ForMain++;
    car obj;
    if (ForMain == 1)
    {
        file();
    }
    switch (main_menu()){
    case 1:
        // car* ppt = reg(&obj, 1);
        cars.push_back(*(reg(&obj, 1)));
        fileIn();
        cout << "\n\nFor the main menu, ";
        system("pause");
        main();
        break;
    case 2:
        search();
        break;
    case 3:
        display(1);
        break;
    case 4:
        edit();
        break;
    case 5:
        fileIn();
        exit(1);
        break;
    }
}

void fill(int num, char space = ' ')
{
    for (int i = 0; i < num; i++)
    {
        cout << space;
    }
}

void fill2(string name, char space2 = ' ')
{
    int der = (def/2) - (ceil((name.length())/2));
    fill(der, ' ');
    cout << name <<endl;
}

void header(string name3, char space3 = '-')
{
    fill(def, space3);
    cout << endl;
    fill2(name3, ' ');
    fill(def, space3);
    cout <<"\n\n\n";
}

int cheker(string chek)
{
    int conv, ret, i;
    char temp;
    for (i = 0; i <= (chek.length()-1); i++)
    {
        temp = chek[i];
        conv = int(temp) - 48;
        if (conv <= 9 && conv == -48)
        {
            continue;
        }
        else if (conv > 9)
        {
            return 0;
        }
    }
    if (i == chek.length())
    { 
        return 1; 
    }
}

// -----------------------------------------------------------------------------------------------

int main_menu()
{
    int ans;
    system(sys);
    header("Trafic managment", '-');
    // cout << temp;
    fill2("1. Register Accident");
    fill2("2. Search");
    fill2("3. Display data");
    fill2("4. Edit");
    // cout << "\n";
    fill2("5. Exit");
    cout << "\n";

    fill(def/2 - 2);
    cout << "> ";
    cin >> ans;

    return ans;

}

car* reg(car *p, int j)
{
    system(sys);
    header("Register");
    fill2("Enter the name of the driver: ");
    nameOwner:
    fill(def/2-10);
    cout << "> ";
    cin.ignore();
    getline(cin, p-> nameOwner);
    if (cheker(p -> nameOwner) == 1 || p -> nameOwner == " ")
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto nameOwner;
    }
    int nam = 0;
    for (nam; nam <= p->nameOwner.size()-1; nam++)
    {
        if (p->nameOwner[nam] == ' ' && p->nameOwner[nam+1])
        {
            nam = -1;
            break;
        }
    }
    if (nam != -1)
    {
        fill2("please enter your full name");
        goto nameOwner;
    }
    cout << "\n";

    fill2("Enter the license number of the driver");
    LisenceNo:
    fill(def/2-10);
    cout << "> ";
    cin >> p -> LisenceNo;
    if (p -> LisenceNo == " " || cheker(p -> LisenceNo) == 0 || p -> LisenceNo.size() != 10)
    {
        cout << "\n";
        fill2("please enter the correct input. Make sure it is 10 digits.");
        goto LisenceNo;
    }
    cout << "\n";
    
    fill2("Enter the plate number:");
    plateNo:
    fill(def/2-10);
    cout << "> ";
    cin >> p -> plateNo;
    if (p -> plateNo == " ")
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto plateNo;
    }

    
    if (int (p -> plateNo[0]) < 68 && int (p -> plateNo[0]) > 64)
    {
        if (p -> plateNo[0] == 'A' ||p -> plateNo[0] == 'B'||p -> plateNo[0] == 'C')
        {
            if ((p -> plateNo.size()) != 6)
            {
                cout << "\n";
                fill2("Make sure you entered 5 digits after the letter.");
                goto plateNo;
            }
        }
    }
    else if ( (int (p -> plateNo[0])) > 67 && (int (p -> plateNo[0])) < 65)
    {
        cout << "\n";
        fill2("please enter the correct letter:  A, B or C");
        goto plateNo;
    }

    else if ( (int (p -> plateNo[0])) > 96 && (int (p -> plateNo[0])) < 122)
    {
        cout << "\n";
        fill2("please enter the correct letter:  A, B or C");
        goto plateNo;
    }
    
    
    if (int(p -> plateNo[0]) - 48 < 9 && int(p -> plateNo[0]) - 48 > 0)
    {
        if (p -> plateNo.size() != 5)
        {
            cout << "\n";
            fill2("please enter the correct input. 5 digits.");
            goto plateNo;
        }
        
    }
    

    
    
    cout << "\n";

    fill2("Which type of insurance does the driver have?");
    fill2("1. First person,  2. Third person,  3. Both ,  4. None");
    insurance:
    fill(def/2-10);
    cout << "> ";
    string filling;
    cin >> filling;
    if (filling == " " || cheker(filling) == 0)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto insurance;
    }
    int temp = stoi(filling);
    if (temp > 4 || temp < 1)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto insurance;
    }
    p -> insur =  insurace[temp - 1];
    cout << "\n";

    fill2("Enter the car description");
    carDescription:
    fill(def/2-10);
    cout << "> ";
    cin.ignore();
    getline(cin, p-> carDescription);
    if (p -> carDescription == "" || p -> carDescription == " " || cheker(p -> carDescription)== 1)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto carDescription;
    }
    else if (p -> carDescription.size() < 10)
    {
        cout << "\n";
        fill2("input is too short, please try again");
        goto carDescription;
    }
    cout << "\n";

    fill2("Enter the place this happned in:");
    region:
    fill(def/2-10);
    cout << "> ";
    cin >> p -> region;
    if (p -> region == "" || p -> region == " " ||cheker(p -> region) == 1)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto region;
    }
    else if (p -> region.size() < 2)
    {
        cout << "\n";
        fill2("input is too short, please try again");
        goto region;
    }
    cout << "\n";

    fill2("Is the person- ");
    fill2("1) A victim    2) A commiter?   3) Unknown:");
    type:
    fill(def/2-10);
    cout << "> ";
    string typeAns;
    cin >> typeAns;
    // int toInt = stoi(typeAns);
    int toInt = int(typeAns[0]) - 48;
    if (typeAns == "" || typeAns == " " ||cheker(typeAns) == 0)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto type;
    }
    if (cheker(typeAns) == 1)
    {
        if (toInt == 1 || toInt == 2 || toInt == 3){ p -> type = crime[toInt - 1];}
        else if (toInt >3 || toInt <1){
            fill2("please enter the correct input");
            goto type;
        }
    }
    cout << "\n";

    fill2("How many people were injured in the car?");
    inside:
    fill(def/2-10);
    cout << "> ";
    cin >> p -> populationInCar;
    if (p -> populationInCar == "" || p -> populationInCar == " " ||cheker(p -> populationInCar) == 0)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto inside;
    }
    cout << "\n";

    fill2("How many people were injured outside the car?");
    outside:
    fill(def/2-10);
    cout << "> ";
    cin >> p -> populationOut;
    if (p -> populationOut == "" || p -> populationOut == " " ||cheker(p -> populationOut) == 0)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto outside;
    }
    cout << "\n";

    fill2("What was the cause of the accident?");
    cause:
    fill(def/2-10);
    cout << "> ";
    cin.ignore();
    getline(cin, p -> cause);
    if (p -> cause == "" || p -> cause == " " ||cheker(p -> cause) == 1)
    {
        cout << "\n";
        fill2("please enter the correct input");
        goto cause;
    }
    else if (p -> cause.size() < 5)
    {
        cout << "\n";
        fill2("input is too short, please try again");
        goto cause;
    }
    cout << "\n";
    return p;
}

void display(int x)
{
    system(sys);
    if (cars.empty())
    {
        header("No data available");
        system("pause");
        main();
    }
    if (cars[0].nameOwner.empty())
    {
        system(sys);
        header("No data available");
        system("pause");
        main();
    }
    header("Available data");
    cout << "\n";
    int holder = ceil(def/3); 
    cout << setw(3) <<left <<"No" <<setw(holder) << left << "NAME" <<setw(holder) <<left << "PLATE NUMBER" <<setw(holder) <<left <<"LICENSE NUMBER";
    cout << "\n\n\n";
    int i = 0;
    for (i; i <= cars.size()-1; i++)
    {
        cout << setw(3) <<left <<i+1 << setw(holder) << left << cars[i].nameOwner <<setw(holder) <<left << cars[i].plateNo <<setw(holder) <<left <<cars[i].LisenceNo <<"\n";   
    }

    if (x == 1){
        cout << "\n\n";
        fill2("Enter the number(No) to access more data about the person");
        fill2("Or press Enter go back to main menue");
        string displayAns = "";
        displaying:
        fill(def/2);
        cout << "> ";
        cin.ignore();
        getline(cin,displayAns);

        
        if ( displayAns == "" || displayAns == " ")
        {
            main();
        }
        else if (cheker(displayAns) == 0)
        {
            cout << "please enter the correct input";
            goto displaying;
        }
        else{
            int disp = stoi(displayAns);
            moreInfo(&disp);
        }
    }
}

void moreInfo(int *more)
{
    system(sys);
    header(cars[*more - 1].nameOwner);
    int holder;
    cout << "\t" <<cars[*more - 1].type <<endl;
    cout << "\tNAME:                " << cars[*more - 1].nameOwner <<endl;
    cout << "\tPLATE NUMBER:        " << cars[*more - 1].plateNo << endl;
    cout << "\tLICENSE NUMBER:      " << cars[*more - 1].LisenceNo <<endl;
    cout << "\tINSURANCE:           ";
    if (cars[*more - 1].insur == "both")
    {
        cout << "yes\n";
    }
    else if (cars[*more - 1].insur != "both")
    {
        if (cars[*more - 1].insur == "third person")
        {
            cout << "Third person\n";
        }
        if (cars[*more - 1].insur == "first person")
        {
            cout << "first person\n";
        }
        if (cars[*more - 1].insur == "None")
        {
            cout << "None\n";
        }
    }
    cout << "\tREGION:              " <<cars[*more - 1].region <<endl;
    cout << "\n\tPeople hurt-\n";
    cout << "\tINSIDE THE CAR:      " <<cars[*more - 1].populationInCar <<endl;
    cout << "\tOUTSIDE THE CAR:     " <<cars[*more - 1].populationOut <<"\n\n";
    cout << "\tCAR DESCRIPTION:     " <<cars[*more - 1].carDescription<<endl;
    cout << "\tCAUSE OF ACCIDENT:   " <<cars[*more - 1].cause <<endl;

    system("pause");
    main();
}

void edit()
{
    system(sys);
    header("Edit");
    display(2);
    edit:
    cout << "\n\n";
    fill2("enter the number or the full name of the person you want to edit.");
    fill2("Press enter to go back.");
    fill(def/2 - 3);
    cout << ">  ";
    string editAns;
    cin.ignore();
    getline(cin,editAns);
    // cout << editAns;

    if (editAns == "All" || editAns == "all")
    {
        string all;
        fill2("Are you sure you want to delete the whole data?  y or n");
        fill(def/2 - 3);
        cout << ">  ";
        cin >> all;
        if (all == "y" || all == "n")
        {
            if (all == "y")
            {
                cars.clear();
                fill2("Data erased......press enter to continue");
                system("pause>nul");
                main();
            }
            if (all == "n")
            {
                fill2("press enter to continue");
                system("pause>nul");
                main();
            }
        }
        else {
            fill2("enter the correct input please");
            goto edit;
        }
    }

    if ( editAns == "" || editAns == " ")
    {
        main();
    }
    if (cheker(editAns) == 1)
    {
        int conv = (stoi(editAns)) - 1;
        edit2(&conv);
    }
    else if (cheker(editAns) == 0)
    {
        int count = 0;
        while(editAns != cars[count].nameOwner)
        {
            count++;
            if (count == cars.size()-1 && editAns != cars[count].nameOwner)
            {
                fill2("the name doesnt exist, please make sure you enteresd the correct input");
                goto edit;
            }
        }
        edit2(&count);
    }


}

void edit2(int *o)
{
    top:
    system(sys);
    header("Edit");
    fill2("1. Change information");
    fill2("2. Delete");
    string choice;
    choices:
    fill(def/2 -3);
    cout << ">  ";
    cin >> choice;
    if (cheker(choice) == 0)
    {
        fill2("enter the correct input");
        goto choices;
    }

    else if(cheker(choice) == 1 && choice == "1")
    {
        system(sys);
        header("Edit");
        cout <<"\n";
        fill2("Do you want to edit the--");
        fill(def/2 - 11);
        cout << "1. name\n";
        fill(def/2 - 11);
        cout << "2. plate number\n";
        fill(def/2 - 11);
        cout << "3. license number\n";
        fill(def/2 - 11);
        cout << "4. insurance type\n";
        fill(def/2 - 11);
        cout << "5. population unside the car\n";
        fill(def/2 - 11);
        cout << "6. population outside the car\n";
        fill(def/2 - 11);
        cout << "7. car description\n";
        fill(def/2 - 11);
        cout << "8. cause of accident\n";
        fill(def/2 - 11);
        cout << "9. Region\n";
        fill(def/2 - 11);
        cout << "0. All\n\n";

        string edit2Ans;
        edit2:
        fill(def/2 - 11);
        cout << ">  ";
        cin >> edit2Ans;
        int conv = stoi(edit2Ans);
        if (cheker(edit2Ans) == 0 || conv > 9)
        {
            fill2("enter the correct input");
            goto edit2;
        }
        else if (cheker(edit2Ans) == 1)
        {
            string temp;
            switch (conv){
                case 1:
                    cout << "\n\n";
                    fill2(cars[*o].nameOwner);
                    fill2("will be changed into----");
                    tempo:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin.ignore();
                    getline(cin,temp);
                    if (cheker(temp)==1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo;
                    }
                    cars[*o].nameOwner = temp;
                    break;

                case 2:
                    cout << "\n\n";
                    fill2(cars[*o].plateNo);
                    fill2("will be changed into----");
                    tempo2:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 0 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo2;
                    }
                    cars[*o].plateNo = temp;
                    break;

                case 3:
                    cout << "\n\n";
                    fill2(cars[*o].LisenceNo);
                    fill2("will be changed into----");
                    tempo3:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 0 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo3;
                    }
                    cars[*o].LisenceNo = temp;
                    break;
                    
                case 4:
                    cout << "\n\n";
                    fill2(cars[*o].insur);
                    fill2("first person, third person, both or None----");
                    fill2("will be changed into----");
                    tempo4:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo4;
                    }
                    cars[*o].insur = temp;
                    break;
                    
                case 5:
                    cout << "\n\n";
                    fill2(cars[*o].populationInCar);
                    fill2("will be changed into----");
                    tempo5:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo5;
                    }
                    cars[*o].populationInCar = temp;
                    break;
                    
                case 6:
                    cout << "\n\n";
                    fill2(cars[*o].populationOut);
                    fill2("will be changed into----");
                    tempo6:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo6;
                    }
                    cars[*o].populationOut = temp;
                    break;
                    
                case 7:
                    cout << "\n\n";
                    fill2(cars[*o].carDescription);
                    fill2("will be changed into----");
                    tempo7:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo7;
                    }
                    cars[*o].carDescription = temp;
                    break;
                    
                case 8:
                    cout << "\n\n";
                    fill2(cars[*o].cause);
                    fill2("will be changed into----");
                    tempo8:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin.ignore();
                    getline(cin, temp);
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo8;
                    }
                    cars[*o].cause = temp;
                    break;
                case 9:
                    cout << "\n\n";
                    fill2(cars[*o].region);
                    fill2("will be changed into----");
                    tempo9:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin.ignore();
                    getline(cin, temp);
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo9;
                    }
                    cars[*o].region = temp;
                    break;
                case 0:    
                    cout << "\n\n";
                    fill2(cars[*o].nameOwner);
                    fill2("will be changed into----");
                    tempo01:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin.ignore();
                    getline(cin,temp);
                    if (cheker(temp)==1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo01;
                    }
                    cars[*o].nameOwner = temp;

                    cout << "\n\n";
                    fill2(cars[*o].plateNo);
                    fill2("will be changed into----");
                    tempo02:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 0 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo02;
                    }
                    cars[*o].plateNo = temp;

                    cout << "\n\n";
                    fill2(cars[*o].LisenceNo);
                    fill2("will be changed into----");
                    tempo03:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 0 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo03;
                    }
                    cars[*o].LisenceNo = temp;
                    
                    cout << "\n\n";
                    fill2(cars[*o].insur);
                    fill2("first person, third person, both or None----");
                    fill2("will be changed into----");
                    tempo04:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo04;
                    }
                    cars[*o].insur = temp;
                    
                    cout << "\n\n";
                    fill2(cars[*o].type);
                    fill2("will be changed into----");
                    tempo05:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo05;
                    }
                    cars[*o].type = temp;
                    
                    cout << "\n\n";
                    fill2(cars[*o].populationInCar);
                    fill2("will be changed into----");
                    tempo06:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo06;
                    }
                    cars[*o].populationInCar = temp;
                    
                    cout << "\n\n";
                    fill2(cars[*o].populationOut);
                    fill2("will be changed into----");
                    tempo07:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo07;
                    }
                    cars[*o].populationOut = temp;

                    cout << "\n\n";
                    fill2(cars[*o].carDescription);
                    fill2("will be changed into----");
                    tempo007:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin >> temp;
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo007;
                    }
                    cars[*o].carDescription = temp;
                    
                    cout << "\n\n";
                    fill2(cars[*o].cause);
                    fill2("will be changed into----");
                    tempo08:
                    fill(def/2 - 10);
                    cout << ">  ";
                    cin.ignore();
                    getline(cin, temp);
                    if (cheker(temp)== 1 || temp == "" || temp == " ")
                    {
                        fill2("enter the correct input");
                        goto tempo08;
                    }
                    cars[*o].cause = temp;

                    break;
                default:
                    cout << "defult reached";
            }
        }
    }
    else if (cheker(choice) == 1 && choice == "2")
    {
        system(sys);
        header("Edit");
        fill2("Are you sure you want to delete the data? y or n");
        string choice2;
        del:
        fill(def/2 -3);
        cout << ">  ";
        cin >> choice2;
        if (cheker(choice2) == 0 && choice2 == "y" || choice2 == "Y")
        {
            int here = *o;
            cars.erase(cars.begin() + here);
            fill2("deleted");
            system("pause");
            main();
        }
        else if (cheker(choice2) == 0 && choice2 == "n" || choice2 == "N")
        {
            system("pause");
            main();
        }
        else {
            fill2("please enter the correct input");
            goto del;
        }
    }

    cout << "\n\n";
    fill2("To alter another data from the same person enter 1");
    fill2("To alter data of another person enter 2");
    fill2("To go back to the main menue enter 3");

    string next;
    nextt:
    fill(def/2 - 3);
    cout << ">  ";
    cin >> next;
    int text = stoi(next);
    if ( cheker(next) == 0)
    {
        fill2("please enter the correct input");
        goto nextt;
    }
    else if (cheker(next)==1)
    {
        if (text == 1)
        {
            goto top;
        }
        else if (text == 2)
        {
            edit();
        }
        else if (text == 3)
        {
            main();
        }
    }
}

void search()
{
    if (cars.empty())
    {
        system(sys);
        header("No data available");
        system("pause");
        main();
    }
    if (cars[0].nameOwner.empty())
    {
        system(sys);
        header("No data available");
        system("pause");
        main();
    }
    system(sys);
    header("Search");
    // display(2);
    int i;
    search:
    cout << "\n\n";
    fill2("enter the full name of the person. Or press enter to go back");
    fill(def/2 - 3);
    cout << ">  ";
    string editAns = "";
    cin.ignore();
    getline(cin,editAns);
    if ( editAns == "" || editAns == " ")
    {
        main();
    }
    if (cheker(editAns) == 1)
    {
        fill2("please enter the correct input");
        goto search;
    }
    else if (cheker(editAns) == 0)
    {
        i = 0;
        for (i; i <= cars.size()-1; i++)
        {
            if (editAns == cars[i].nameOwner)
            {
                int news = i + 1;
                moreInfo(&news);
                break;
            }
            if (i == cars.size()-1)
            {
                if (editAns != cars[i].nameOwner)
                {
                    fill2("the name doesnt exist");
                    // goto search;
                }
            }
        }
    }
    cout << "For main menu ";
    system("pause");
    main();
}
