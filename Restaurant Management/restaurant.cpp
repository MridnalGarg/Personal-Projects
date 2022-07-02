#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;

struct items{
    char dish[50];
    int key;
    float price;
}r;

class restaurant
{
public:
    void create();  //Add a dish to the menu
    void query();   //Show details at a key value
    void display(); //display menu
    void update();  //update menu items
    void delet();   //delete menu items
    void admin();   //admin portal
};

class customer:public restaurant
{
public:
    void order();       //Customer menu to order
    void showbill();    //display bill information
    void dish_menu();   // prints Food menu
};

void restaurant::create()
{
    char a;
    int k;
    fstream obj;
    top:
    do {
        obj.open("Item List.txt",ios::in|ios::binary);
        cout<<"Enter the dish key: ";
        cin>>k;
         while(obj.read((char*)&r,sizeof(r)))
            {
                if(r.key==k)
                {
                    cout<<"Key is already exist..."<<endl;
                    obj.close();
                goto top;
                }
            }
        obj.close();
        obj.open("Item List.txt",ios::app|ios::binary);
        r.key=k;
        cin.ignore();
        cout<<"ENTER THE DISH NAME: ";
        gets(r.dish);
        cout<<"ENTER THE DISH PRICE: ";
        cin>>r.price;
        obj.write((char*)&r,sizeof(r));
        cout<<"Do you want to add any other dish?[y/n]:";
        cin>>a;
        obj.close();
    }
    while(a!='n');
}

void restaurant::display()
{
    int c=0;
    fstream obj;
    obj.open("Item List.txt",ios::in|ios::binary);
    cout<<"\t\t\t\t\t|||||||||||||||||||FOOD MENU||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t\t Key\t\tDISH NAME\t\tPRICE"<<endl;
    while(obj.read((char*)&r,sizeof(r)))
    {
            cout<<"\t\t\t\t\t  "<<r.key<<"\t\t"<<r.dish<<"\t\t\tRs."<<r.price<<endl;
            c++;
    }
    if(c==0)
    {
        cout<<"List is empty"<<endl;
    }
    cout<<"\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    obj.close();
}

void restaurant::query()
{
    int a,c=0;
    fstream obj;
    obj.open("Item List.txt",ios::in);
    cout<<"Enter the dish key: ";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.key==a)
           {
            cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\tRs."<<r.price<<endl;
            c++;
           }
    }
    if(c==0)
    {
        cout<<"Key not found..."<<endl;
    }
    obj.close();
}

void restaurant::update()
{
    int a,p,c=0;
    fstream obj;
    obj.open("Item List.txt",ios::in|ios::out|ios::binary);
    display();
    cout<<"\nENTER DETAILS TO UPDATE";
    cout<<"\nEnter the dish key: ";
    cin>>a;
    obj.seekg(0);
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.key==a)
        {
            cout<<"\nRecord to be updated: "<<endl;
            cout<<"\nKEY: "<<r.key;
            cout<<"\nDISH NAME: "<<r.dish;
            cout<<"\nPRICE: Rs."<<r.price<<endl;
            p = obj.tellg()-(sizeof(r));
            obj.seekp(p);
            cout<<"\nENTER THE DISH KEY: ";
            cin>>r.key;
            cin.ignore();
            cout<<"ENTER THE DISH NAME: ";
             gets(r.dish);
            cout<<"ENTER THE DISH PRICE: ";
            cin>>r.price;
            obj.write((char*)&r,sizeof(r));
            c++;
           }

        }
        if(c==0)
        {
            cout<<"Key not found..."<<endl;
        }
    obj.close();

}

void restaurant::delet()
{
     int a,c;
     fstream obj,obj1;
     obj.open("Item List.txt",ios::in|ios::binary);
     obj1.open("temp.txt",ios::app|ios::binary);
    cout<<"Enter the dish key: ";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.key==a)
        {
            c++;
            cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\t"<<r.price<<endl;
            cout<<"Record is deleted"<<endl;
        }
        if(r.key!=a)
        {
            obj1.write((char*)&r,sizeof(r));
           }
    }
    obj.close();
    obj1.close();
    if(c==0)
       {
         cout<<"not found"<<endl;
       }
    remove("Item List.txt");
    rename("temp.txt","Item List.txt");
}

 void restaurant::admin()
{
char a;
    do{
            cout<<"\n\n\t\t\t\t\t\t|||||||||||||||||||||||||"<<endl;
            cout<<"\t\t\t\t\t\t||||    ADMIN MENU   ||||"<<endl;
            cout<<"\t\t\t\t\t\t|||||||||||||||||||||||||"<<endl;
            cout<<"\t\t\t\t\t\t|                       |"<<endl;
            cout<<"\t\t\t\t\t\t|  1) ADD DISH          |"<<endl;
            cout<<"\t\t\t\t\t\t|  2) Display           |"<<endl;
            cout<<"\t\t\t\t\t\t|  3) QUERY             |"<<endl;
            cout<<"\t\t\t\t\t\t|  4) UPDATE            |"<<endl;
            cout<<"\t\t\t\t\t\t|  5) DELETE            |"<<endl;
            cout<<"\t\t\t\t\t\t|  0) EXIT TO MAIN MANU |"<<endl;
            cout<<"\t\t\t\t\t\t|                       |"<<endl;
            cout<<"\t\t\t\t\t\t|||||||||||||||||||||||||"<<endl;
            cout<<"\n\t\t\t\t\t\tSelect an option: ";
            cin>>a;
            switch(a)
            {
            case '0':
                system("CLS");
                break;
            case '1':
                system("CLS");
                create();
                break;
            case '2':
                system("CLS");
                display();
                break;
            case '3':
                system("CLS");
                query();
                break;
            case '4':
                system("CLS");
                update();
                break;
            case '5':
                system("CLS");
                delet();
                break;
            default: system("CLS");
            }
    }while(a!='0');
}

struct {
char d[50];
float p,amount;
int qty;
}rd;


void customer::order()
{
     int a,c=0;
     char ch;
     float total=0;
    fstream obj,obj1;
    dish_menu();
    obj1.open("bill.txt",ios::out|ios::binary);
     do{
    obj.open("Item List.txt",ios::in|ios::binary);
    cout<<"Enter the dish key:";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.key==a)
           {
            c++;
            cout<<"Enter the quantity: ";
            cin>>rd.qty;
            rd.amount=rd.qty*r.price;
            cout<<"\t"<<r.dish<<"\t\tRs."<<r.price<<"*"<<rd.qty<<"\t\tRs."<<rd.amount<<endl;
            strcpy(rd.d,r.dish);
            rd.p=r.price;
            obj1.write((char*)&rd,sizeof(rd));
            total=total+rd.amount;
           }
        }
        if(c==0)
     {
        cout<<"Not found"<<endl;
     }

    cout<<"Do you want to order more [y/n]";
    cin>>ch;
    obj.close();
     }
     while(ch!='n');
    obj1.close();
    cout<<endl;
    system("CLS");
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"|||||||||||||||||||||||||||||||||||||||||||||| RESTAURANT BILL |||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    showbill();
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"|||\t\t\t\t\t\t   TOTAL = Rs."<<total<<"\t\t\t\t\t   |||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
}

 void customer::showbill(){
    fstream obj;
    obj.open("bill.txt",ios::in|ios::binary);
    cout<<"\t\t\tDISH NAME\t\tPRICE\t\tQTY\t\tAMOUNT"<<endl;
    while(obj.read((char*)&rd,sizeof(rd)))
    {
            cout<<"\t\t\t"<<rd.d<<"\t\t\tRs."<<rd.p<<"\t\t"<<rd.qty<<"\t\tRs."<<rd.amount<<endl;
    }
    obj.close();
 }

 void customer::dish_menu()
 {
    fstream obj;
    obj.open("Item List.txt",ios::in|ios::binary);
    cout<<"\t\t||||||||||||FOOD MENU||||||||||||";
    cout<<"\n\t\t|| Key\tDISH NAME\tPRICE  ||"<<endl;
    while(obj.read((char*)&r,sizeof(r)))
    {
        cout<<"\t\t|| "<<r.key<<")\t"<<r.dish<<"\t\tRs."<<r.price<<" ||"<<endl;
    }
    cout<<"\t\t|||||||||||||||||||||||||||||||||"<<endl<<endl;

    obj.close();
 }

void intro(){
    cout<<"\t\t\t\t\t";
    cout<<"||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"|| RESTAURANT MANAGEMENT SYSTEM ||"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\n\t\t\t\t\t";
    cout<<"Project Submitted To:"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"Dr.Shruti Jaiswal"<<endl;
    cout<<"\n\t\t\t\t\t";
    cout<<"Project Implemented By:"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"Mridnal Garg  (9919102032)"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"Pranati Tiwari(9919102056)"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"Aryan Verma   (9919102052)"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"Pranjal Shukla(9919102060)"<<endl<<endl;

    system("pause");
    system("cls");
}

int main()
{
    intro();
    char a;
    customer obj;
    do
    {
        cout<<"\n\n\n\t\t\t\t\t\t||||||||||||||||||||"<<endl;
        cout<<"\t\t\t\t\t\t|                  |"<<endl;
        cout<<"\t\t\t\t\t\t|    1)Admin       |"<<endl;
        cout<<"\t\t\t\t\t\t|    2)customer    |"<<endl;
        cout<<"\t\t\t\t\t\t|    0)Exit        |"<<endl;
        cout<<"\t\t\t\t\t\t|                  |"<<endl;
        cout<<"\t\t\t\t\t\t||||||||||||||||||||"<<endl;
        cout<<"\n\t\t\t\t\t\tselect an option: ";
        cin>>a;
        switch(a)
        {
        case '0':
            break;
        case '1':
                system("CLS");
                obj.admin();
                break;
        case '2':
                system("CLS");
                obj.order();
                break;
        }
    }while(a!='0');

}
