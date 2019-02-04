#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
void create();
void show();
void transfer();
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
	cout<<"\n2. Transfer\n";
	cout<<"3. Display contents of both files\n";
	cout<<"4. Exit\n";
	cout<<"Enter choice\n";
	ch=getche();
	switch(ch)
	{
		case '1': create();
			break;
		case '2': transfer();
			break;
		case '3': show();
			break;
		case '4': exit(0);
	}
	menu();
}
void create(){
    fstream fout;
    fout.open("original.txt", ios::out);
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
void transfer(){
    fstream fin,fin2;
    fin.open("original.txt", ios::in);
    fin2.open("trans.txt", ios::out);
    int flag=1;
    while(!fin.eof()){
        char str[20];
        fin>>str;
        if(str[0]>='A'&&str[0]<='Z'){
                fin2<<str;
                fin2<<"\n";
                flag=0;
        }
    }
    fin.close();
    fin2.close();
    if(flag){
        cout<<"Nothing to transfer!!;-(";
    }
}

void show(){
    fstream fin;
    fin.open("original.txt", ios::in);
    fin.seekg(0);
    cout<<endl<<"Original File"<<endl;
    while(!fin.eof()){
	char ch;
	fin.get(ch);
	cout<<ch;
    }
    fin.close();
    fin.open("trans.txt", ios::in);
    fin.seekg(0);
    cout<<endl<<"Transferred File"<<endl;
    while(!fin.eof()){
	char ch;
	fin.get(ch);
	cout<<ch;
    }
    fin.close();

}
