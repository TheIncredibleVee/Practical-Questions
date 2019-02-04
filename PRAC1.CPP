#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

void acc_data();
void show();
void sort();
void write();
void menu();

class Employee
{
	int empno;
	char ename[20];
	float salary;

public:
	void getdata()
	{
		cout<<"Enter empno\n";
		cin>>empno;
		cout<<"Enter e name\n";
		gets(ename);
		cout<<"Enter salary\n";
		cin>>salary;
	}
	void dispdata()
	{
		cout<<"\nEmpno: "<<empno;
		cout<<"\nEmpname: "<<ename;
		cout<<"\nSalary: "<<salary;
	}
	float ret_salary()
	{
		return salary;
	}
};
Employee e[20];
int n;
void main()
{
	clrscr();
	menu();
	getch();
}

void menu()
{
	int ch;
	cout<<"\nMENU:\n";
	cout<<"1. Enter details of an employee\n";
	cout<<"2. Sort data in increasing order of salary using bubbke sort";
	cout<<"\n3. Write the sorted data into a bianary file\n";
	cout<<"4.show file contents\n";
	cout<<"5. Exit\n";
	cout<<"Enter choice\n";
	cin>>ch;
	switch(ch)
	{
		case 1: acc_data();
			break;
		case 2: sort();
			break;
		case 3: write();
			break;
		case 4: show();
			break;
		case 5: exit(0);
	}
}

void acc_data()
{
	cout<<"\n Enter number of records u wanna enter: ";
	cin>>n;

	for( int i=0; i<n; i++)
	{
		cout<<"\n Enter data for "<<i+1<<"th record\n";
		e[i].getdata();
	}
	menu();
}

void sort()
{
	Employee t;
	int k;
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<n-i; j++)
		{
			k=j+1;
			if(e[j].ret_salary()>e[k].ret_salary())
			{
				t=e[i];
				e[i]=e[j];
				e[j]=t;
			}
		}
	}
	menu();
}

void write()
{
	fstream fout;
	fout.open("employee.dat",ios::binary|ios::app);

	for(int i=0; i<n; i++)
	{
		fout.write((char*)&e[i], sizeof(Employee));
	}

	fout.close();

	cout<<"data written successfully\n";
	menu();
}

void show()
{
	ifstream fin("employee.dat",ios::binary);
	Employee e1;
	while(!fin.eof())
	{
		fin.read((char*)&e1, sizeof(e1));
		if(fin.eof())
		break;
		e1.dispdata();

	}
	fin.close();
	menu();
}
