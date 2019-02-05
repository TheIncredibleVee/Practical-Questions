#include<iostream.h>
#include<dos.h>
#include<iomanip.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

//using namespace std;


struct item{
	int itemno;
	float price;
	item* next;
};

int itempush(item*);
item* itempop();
int itemdisplay();
item* newitem(int, float);
item* top=NULL;
item* tempptr=NULL;
item* t=NULL;
item *ptr;

int main(){
	system("cls");
	char input;
	do{
		system("cls");
		gotoxy(20,1);cout<<"STACK IMPLEMENATION USING LINKED LISTS\n\nNote: Max. size of the array is 5."<<endl;
		gotoxy(20,4);   cout<<" ============================";
		gotoxy(20,5);   cout<<setw(18)<<"MAIN MENU";
		gotoxy(20,6);   cout<<" ============================";
		gotoxy(20,8);   cout<<"      1.PUSH        ";
		gotoxy(20,9);   cout<<"      2.POP          ";
		gotoxy(20,10);  cout<<"      3.DISPLAY           ";
		gotoxy(20,11);  cout<<"      4.EXIT";
		gotoxy(20,14);  cout<<" ============================";
		gotoxy(20,16);  cout<<"     Input Choice - ";
		input= getche() ;
		switch(input){
			case '1':
				int t;
				gotoxy(20,17);cout<<"ENTER itemno TO BE PUSHED"<<endl;
				cin>>t;
				float l;
				gotoxy(20,18);cout<<"ENTER price TO BE PUSHED"<<endl;
				cin>>l;
				item *newptr=newitem(t,l);
				if(itempush(newptr)){
					gotoxy(20,19);cout<<"ELEMENT PUSHED SUCCESSFULLY";
					gotoxy(20,20);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
				}
				break;
			case '2':
				if(top==NULL){
					gotoxy(20,17);cout<<"STACK EMPTY";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
					break;
				}
				item *tem=itempop();
				gotoxy(20,17);cout<<"SUCCESSFULLY POPPED "<<tem->itemno;
				delete tem;
				gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case '3':
				if(itemdisplay()){
					gotoxy(20,17);cout<<"STACK EMPTY ENTER ELEMENTS BEFORE VIEWING ";
					gotoxy(20,18);cout<<"PRESS ANY KEY TO CONTINUE";
					getch();
				}
				getch();
				break;
			case '4':
				exit(0);
				break;
			default:
				gotoxy(20,20);cout<<"INAVAILD CHOICE";
				gotoxy(20,21);cout<<"TRY AGAIN";
				break;
		}
	}while(input!='4');
	return 0;
}

int itempush(item* nod){

	if (top==NULL)
		top=nod;
	else {
		t=top;
		top=nod;
		top->next=t;
	}
	return 1;
}

item* itempop(){
	tempptr=top;
	top=top->next;
	return tempptr;
}
int itemdisplay(){
	if(top==NULL){
		return 1;
	}
	item* tempp=top;
	while(tempp!=NULL){
		cout<<endl<<"Item No.:\t"<<tempp->itemno;
		cout<<endl<<"Price :\t"<<tempp->price;
		tempp=tempp->next;
	}
	return 0;
}
item* newitem(int x, float f){
	ptr= new item;
	ptr->itemno=x;
	ptr->price=f;
	ptr->next=NULL;
	return ptr;
}
