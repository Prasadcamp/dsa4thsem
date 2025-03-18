#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct student
{
	int rollno;
	string name;
	string  add;
	string div;
};

void addstu()
{
	student s;
	cout<<"\n Enter the rollno: ";
	cin>>s.rollno;
	cout<<"\n Enter the name:";
	cin>>s.name;
	cout<<"\n Enetr the address : ";
	cin>>s.add;
	cout<<"\n Enter the division :";
	cin>>s.div;
	ofstream fout("abcd.txt",ios::app);
	fout<<s.rollno<<" "<<s.name<<" "<<s.add<<" "<<s.div<<endl;
	fout.close();
}

void deletestu()
{
	cout<<"\n Enter the rollno to search: ";
	cin>>
}


