#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

class student
{
	int rollno;
	char name[20];
	int clas;
	char section;
	float marks;

public:
	void getdata()
	{
		cout<<"Enter Roll no\n";
		cin>>rollno;
		cout<<"Enter Name\n";
		gets(name);
		cout<<"Enter Class\n";
		cin>>clas;
		cout<<"Enter Section\n";
		section=getche();
		cout<<"\nEnter Marks\n";
		cin>>marks;
	}
	void displaydata()
	{
		cout<<"\nRoll no: "<<rollno;
		cout<<"\nName: "<<name;
		cout<<"\nClass :"<<clas;
		cout<<"\nSection :"<<section;
		cout<<"\nMarks : "<<marks;
	}
	int ret_rollno()
	{
		return rollno;
	}
	void modify_marks(){
	    cout<<"enter New marks";
	    cin>>marks;
	}
};
int show();
int menu();
int modify();
int writee();
int main(){
    clrscr();
    menu();
    getch();
    return 0;
}
int menu(){
    char ch;
	cout<<"\nMENU:\n";
	cout<<"1. Enter details of an Item in the file\n";
	cout<<"\n2. Modify record of a particular roll no.\n";
	cout<<"3.show file contents\n";
	cout<<"4. Exit\n";
	cout<<"Enter choice\n";
	ch=getche();
	switch(ch)
	{
		case '1': if(writee())
		    cout<<"Nothing to write";
			break;
		case '2': if(modify())
		    cout<<"No records found";
			break;
		case '3': show();
			break;
		case '4': exit(0);
	}
	menu();
    return 0;
}

int writee(){
    cout<<"\n Enter number of records u wanna enter: ";
    int n;
	cin>>n;
	if(n<1)
	return 1;
    ofstream fout;
    student temp;
    fout.open("student.dat", ios::binary);
	for( int i=0; i<n; i++)
	{
		cout<<"\n Enter data for "<<i+1<<"th record\n";
		temp.getdata();
	fout.write((char*)&temp, sizeof(student));
	}
	fout.close();
    return 0;
}
int modify(){
	fstream f("student.dat",ios::binary|ios::in|ios::out);
	student tmp;
	int req;
	cout<<"enter the Roll no to modify"<<endl;
	cin>>req;
	while(!f.eof())
	{
		f.read((char*)&tmp, sizeof(tmp));
		if(tmp.ret_rollno()==req){
		cout<<endl;
		tmp.modify_marks();
		int x=f.tellg();
		f.seekp(x-1*sizeof(student));
		f.write((char*)&tmp, sizeof(student));
	f.close();
		return 0;
	}
	}
	return 1;
}
int show(){
    ifstream fin("student.dat",ios::binary);
	student tmp;
	while(!fin.eof())
	{
		fin.read((char*)&tmp, sizeof(tmp));
		if(fin.eof())
		break;
		tmp.displaydata();

	}
	fin.close();
	return 0;
}
