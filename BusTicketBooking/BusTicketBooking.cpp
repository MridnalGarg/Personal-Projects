#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

char i=':';
char chEmpty[]="Empty";
struct time{
 int iHrs,iMins;
};

static int Num=0;
struct node{
 int bus_no;
 int iBusNum;
 int iBusCode;
 char chSeat[8][4][20];
 char chDrivers_Name[20];
 struct time stDeparture_Time, stArrival_Time;
 char chGoesTo[20];
 char chGoesFrom[20];
 float fFare;
 int iTicketSold;
 struct node *next;
}*p;

int cunt(struct node *q);
void line();
void srch(int num);
void Delete(int num);
void insert(int x);
void Print(struct node *q);
void reservation(struct node *q);
void cancel();
void daily_profit();


int main(){
int A;
while(1){
     line();
     cout << "\n1.ADD NEW BUS";
     cout << "\n2.REMOVE A BUS";
     cout << "\n3.SHOW ALL THE BUSES";
     cout << "\n4.TOTAL NUMBER OF BUSES";
     cout << "\n5.SEARCH BUS";
     cout << "\n6.Reservation of seats";
     cout << "\n7.Cancel a reservation";
     cout << "\n8.Daily profit";
     cout << "\n0.EXIT";
     cout << "\n\nEnter your choice here : ";

     cin >> A;
     switch(A){
        case 1:{
                int x,n,i;
                line();
                cout << "Enter bus code : ";
                cin >> x;
                insert(x);
                break;
                }
        case 2:{
                line();
                cout << "\n Enter Bus code : ";
                int num;
                cin >> num;
                Delete(num);
                Print(p);
                }
        case 3:{
                line();
                Print(p);
                break;
                }
        case 4:{
                line();
                cout << "Total number of Buses are \n" << cunt(p);
                break;
                }
        case 5:{
                int num;
                line();
                cout << "Enter Bus number : ";
                cin >> num;
                if(num>cunt(p)||num<1){
                    cout << "Invalid number !! \n";
                    main();
                }
                srch(num);
                break;
                }
        case 6:{
                line();
                reservation(p);
                break;
                }
        case 7:{
                line();
                cancel();
                break;
                }
        case 8:{
                line();
                daily_profit();
                break;
                }
        case 0:{
                line();
                exit(1);
                break;
                 }
        default:{
                cout << "\n\nWrong choice...";
                break;
                }
        }
     }
}

//counting total number of buses
int cunt(struct node *q){
     struct node *temp;
     temp=q;
     int tot=0;
     while(temp!=NULL) {
        tot++;
        temp=temp->next;
     }
     return (tot);
}

void line(){
     int i;
     cout << endl;
     for(i=0;i<60;i++){
        cout << "*";
     }
     cout << endl;
}

//Searching a Bus its bus number
void srch(int num){
     struct node *r;
     r=p;
     if(num==1) {
        cout << "\nBus code -> " << r->bus_no;
        cout << "\tDriver's name -> " << r->chDrivers_Name;
        cout << "\nArrival time -> " << r->stArrival_Time.iHrs << i << r->stArrival_Time.iMins;
        cout << "\tDeparture time -> " << r->stDeparture_Time.iHrs << i << r->stDeparture_Time.iMins;
        cout << "\nFrom -> " << r->chGoesFrom;
        cout << "\t To -> " << r->chGoesTo;
        cout << "\nFare -> " << r->fFare;
        cout << "\t Tickets sold -> %d" << r->iTicketSold;

        int index=0;
        for(int i=0;i<8;i++){
            cout << endl;
            for(int j=0;j<4;j++){
                index++;
                cout << index << "." << r->chSeat[i][j];
            }
        }
     }
     else if(num <= cunt(p)){
        int i;
        for(i=1;i<num;i++){
            r=r->next;
        }
        cout << "\nBus code -> " << r->bus_no;
        cout << "\tDriver's name -> " << r->chDrivers_Name;
        cout << "\nArrival time -> " <<  r->stArrival_Time.iHrs << i << r->stArrival_Time.iMins;
        cout << "\tDeparture time -> %d%c%d" << r->stDeparture_Time.iHrs << i << r->stDeparture_Time.iMins;
        cout << "\nFrom -> " << r->chGoesFrom;
        cout << "\t To -> " << r->chGoesTo;
        cout << "\nFare -> " << r->fFare;
        cout << "\t Tickets sold -> " << r->iTicketSold;
        int index=0;

        for(int i=0;i<8;i++){
            cout << endl;
            for(int j=0;j<4;j++){
                index++;
                cout << index << "." << r->chSeat[i][j];
            }
        }
     }
     else{
     cout << "\n Wrong Bus number input (Please Enter Bus Number only!)\n";
     }
}

//deleting a bus entry by its Bus code by its value
void Delete(int num){
     struct node *temp,*r;
     r=p;
     while(r!=NULL){
        if(r->bus_no==num){
            if(r==p){
                p=r->next;
                free(r);
                return;
            }
            else{
                temp->next=r->next;
                free(r);
                return;
            }
        }
        else{
            temp=r;
            r=r->next;
        }
     }
    cout << "No such Bus code found.\n";
}

void insert(int x){
     struct node *temp,*m;
     m = p;
     temp =(struct node *)malloc(sizeof(struct node));
     temp->bus_no=x;
     Num++;
     temp->iBusNum=Num;

     dname:
     cout << "Enter driver's name : ";
     fflush(stdin);
     gets(temp->chDrivers_Name);
     if(strlen(temp->chDrivers_Name)>20){
     cout << "Maximum 20 characters are allowed";
     goto dname;
     }

     aTime:
     printf("Enter arrival time : ");
     fflush(stdin);
     scanf("%d%c%d",&temp->stArrival_Time.iHrs,&i,&temp->stArrival_Time.iMins);
     if(temp->stArrival_Time.iHrs == 0){
     cout << "\nInvalid time.";
     goto aTime;
     }
     if((i!=':')||(temp->stArrival_Time.iHrs>=24)||(temp->stArrival_Time.iHrs<0)
        ||(temp->stArrival_Time.iMins>=60)||(temp->stArrival_Time.iMins<0)){
        cout << "\nInvalid time !\n\t\tOnly format HH:MM accepted\n";
        goto aTime;
     }

     dTime:
     cout << "Enter departure time : ";
     fflush(stdin);
     scanf("%d%c%d",&temp->stDeparture_Time.iHrs,&i,&temp->stDeparture_Time.iMins);
     if(temp->stDeparture_Time.iHrs==0){
        cout << "\nInvalid time.";
        goto dTime;
     }
     if((i!=':')||(temp->stDeparture_Time.iHrs>=24)||(temp->stDeparture_Time.iHrs<0)
        ||(temp->stDeparture_Time.iMins>=60)||(temp->stDeparture_Time.iMins<0)){
     cout << "\nInvalid time !\n\t\tOnly format HH:MM accepted\n";
     goto dTime;
     }

    to:
     cout << "Enter destination : ";
     fflush(stdin);
     gets(temp->chGoesTo);
     if(strlen(temp->chGoesTo)>20){
     cout << "\nOnly 20 characters or less";
     goto to;
     }

    from:
     cout << "Enter starting place : ";
     fflush(stdin);
     gets(temp->chGoesFrom);
     if(strlen(temp->chGoesFrom)>20){
     cout << "\nOnly 20 characters or less";
     goto from;
     }
     cout << "Enter fare of one ticket : ";
     fflush(stdin);
     cin >> temp->fFare;
     temp->iTicketSold=0;
     int i1,i2;
     for(i1=0;i1<8;i1++){
        for(i2=0;i2<4;i2++){
            strcpy(temp->chSeat[i1][i2],chEmpty);
        }
     }
     if(p==NULL){
        p=temp;
        p->next=NULL;
     }
     else{
        while(m->next!=NULL)
             m=m->next;
             m->next=temp;
             m=temp;
             m->next=NULL;
        }
}

void Print(struct node *q){
     struct node *r;
     r=q;
     int cnt=1;
     while(r!=NULL){
     line();
     cout << "\n\nBus code -> " << r->bus_no;
     cout << "\tBus number -> " << cnt;
     cout << "\tDriver's name -> " << r->chDrivers_Name;
     cout << "\nArrival time -> " << r->stArrival_Time.iHrs << i << r->stArrival_Time.iMins;
     cout << "\tDeparture time -> %d%c%d" << r->stDeparture_Time.iHrs << i << r->stDeparture_Time.iMins;
     cout << "\nFrom -> " << r->chGoesFrom;
     cout << "\t To -> %s" << r->chGoesTo;
     cout << "\nFare -> " << r->fFare;
     cout << "\t Tickets sold -> " << r->iTicketSold;
     cnt++;
     int i,j,index=0;
     for(i=0;i<8;i++){
        cout << endl;
        for(j=0;j<4;j++){
            index++;
            cout << index << "." << r->chSeat[i][j] << "\t";
        }
     }
     r = r->next;
     }
     cout << endl;
}

void reservation(struct node *q){
    struct node *r;
    r=q;
    int num,count=0,Seat;
    res:
    cout << "Enter bus number : ";
    fflush(stdin);
    cin >> num;
    if(num>cunt(q)||(num<1)){
        printf("Sorry, no bus found with the given Bus number.\n");
        goto res;
    }
    while(count<num-1){
        r=r->next;
        count++;
    }
    seat:
    cout << "Enter seat number : ";
    fflush(stdin);
    cin >> Seat;
    char Name[20];
    if(Seat > 32){
        cout << "Only 32 seats are there.\n";
        goto seat;
    }
    else if(Seat<1){
        cout << "Invalid input.\n";
        goto seat;
    }
    else if(strcmp(r->chSeat[Seat/4][Seat%4-1],"Empty")==0){
        cout << "Enter the passenger's name : ";
        name:
        fflush(stdin);
        gets(Name);
    if(strlen(Name)>20){
        cout << "Max 20 characters allowed\n";
        goto name;
     }
    strcpy(r->chSeat[Seat/4][Seat%4-1],Name);
    cout << "\nSeat successfully reserved!\nDo you want to continue reservation ? : ";
    r->iTicketSold++;
    char ch;
    ch=getchar();
    if(ch=='y'||ch=='Y'){
        reservation(q);
    }
    else
    main();
    }
    else{
    cout << "Seat already booked!\n";
    goto seat;
     }
}

void cancel(){
    if(Num==0){
        cout << "Bus list is empty.\n";
        main();
    }
    struct node *r;
    r=p;
    enter:
    cout << "Enter Bus number : ";
    int bus,ind=1;
    fflush(stdin);
    cin >> bus;
    if(bus<1||bus>cunt(p)){
        cout << "\nInvalid input.\n";
        goto enter;
    }
    else{
        while(ind<bus){
            r=r->next;
            ind++;
        }
    }
    cout << "Enter seat number : ";
    int sea;
    scanf("%d",&sea);
    if(strcmp(r->chSeat[sea/4][sea%4-1],"Empty")==0){
     cout << "The seat is already empty !\n";
     goto enter;
     }
     else{
     strcpy(r->chSeat[sea/4][sea%4-1],"Empty");
     cout << "Successfully canceled reservation.\n";
     r->iTicketSold--;
     main();
     }
}

void daily_profit(){
     struct node *r,*s;
     r=p;
     s=p;
     int cnt=0;
     if(cunt(p)==0){
        cout << "No buses are available\n";
     main();
     }
     while(s!=NULL){
     if(s->iTicketSold!=0){
     cnt++;
     }
     s=s->next;
     }
     if(cnt==0){
        cout << "No booking is done yet.\n";
        getch();
        main();
     }
     float Total=0;
     while(r!=NULL){
        Total=Total+(r->iTicketSold*r->fFare);
        r=r->next;
     }
    cout << "The total income of the buses is : " << Total << endl;
    main();
}

