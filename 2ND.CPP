#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

class item
{
	int itemno;
	char itemname[20];
	int qty;
	float price;

public:
	void getdata()
	{
		cout<<"Enter Item no\n";
		cin>>itemno;
		cout<<"Enter Item name\n";
		gets(itemname);
		cout<<"Enter Quantity\n";
		cin>>qty;
		cout<<"Enter price\n";
		cin>>price;
	}
	void displaydata()
	{
		cout<<"\nItem no: "<<itemno;
		cout<<"\nItem name: "<<itemname;
		cout<<"\nQuantity :"<<qty;
		cout<<"\nPrice: "<<price;
	}
	float ret_price()
	{
		return price;
	}
};
int show();
int menu();
int search();
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
	cout<<"\n2. Search for items with price over 1000\n";
	cout<<"3.show file contents\n";
	cout<<"4. Exit\n";
	cout<<"Enter choice\n";
	ch=getche();
	switch(ch)
	{
		case '1': if(writee())
                    cout<<"Nothing to write";
			break;
		case '2': if(search())
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
    item temp;
    fout.open("item.dat", ios::binary|ios::app);
	for( int i=0; i<n; i++)
	{
		cout<<"\n Enter data for "<<i+1<<"th record\n";
		temp.getdata();
		fout.write((char*)&temp, sizeof(item));
	}
	fout.close();
    return 0;
}
int search(){
    ifstream fin("item.dat",ios::binary);
	item tmp;
	int flag=1;
	while(!fin.eof())
	{
		fin.read((char*)&tmp, sizeof(tmp));
		if(tmp.ret_price()>1000){
	    tmp.displaydata();
            flag=0;
		}
	}
	return flag;
}
int show(){
    ifstream fin("item.dat",ios::binary);
	item tmp;
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
