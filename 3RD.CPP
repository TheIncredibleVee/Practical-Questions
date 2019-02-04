#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
void create();
void count();
void show();
void menu();
int main(){
    clrscr();
    menu();
    getch();
    return 0;
}
void menu(){
    char ch;
	cout<<"\nMENU:\n";
	cout<<"1. Create File \n";
	cout<<"\n2. Count no. of \"are\"\n";
	cout<<"3. Display contents of file\n";
	cout<<"4. Exit\n";
	cout<<"Enter choice\n";
	ch=getche();
	switch(ch)
	{
		case '1': create();
			break;
		case '2': count();
			break;
		case '3': show();
			break;
		case '4': exit(0);
	}
	menu();
}
void create(){
    fstream fout;
    fout.open("file.txt", ios::out);
    cout<<"\nPress * to exit\n";
    char ch=0;
    while(ch!='*'){
	ch= getche();
	if(ch=='*')
		break;
	fout<<ch;
    }
    fout.close();
}
void count(){
    int countt=0;
    fstream fin;
    fin.open("file.txt", ios::in);
    while(!fin.eof()){
	char * str;
	fin>>str;
	if(!strcmpi(str,"are"))
	    countt++;
    }

    fin.close();
    cout<<"No of are in the file are\t"<<countt<<endl;
}

void show(){
    fstream fin;
    fin.open("file.txt", ios::in);
    fin.seekg(0);
    cout<<endl;
    while(!fin.eof()){
	char ch;
	fin.get(ch);
	cout<<ch;
    }
    fin.close();
}
