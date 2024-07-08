/*
Department maintains a student information. The file contains roll number, name, division
and address. Allow user to add, delete information of student. Display information of
particular employee. If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details. Use sequential file to main the data.
*/

#include<iostream>
#include<fstream>
using namespace std;


class File
{
Public:
int R;
char Name[20],D,Address[20],ch;
ifstream fin,fin1;
ofstream fout, fout1;

void Add()
{
fout.open("stud.txt",ios::app);
do
{

cout<<"\n Enter Roll No:";
cin>>R;
fout<<R<<"\t";
cout<<"\n Enter Name:";
cin>>Name;
fout<<Name<<"\t";
cout<<"\n Enter Division:";
cin>>D;
fout<<D<<"\t";
cout<<"\n Enter Address:";
cin>>Address;
fout<<Address<<"\n";

cout<<"\n Do you want to continue:";
cin>>ch;
}while(ch=='Y'||ch=='y');

fout.close;
}

void Delete()
{

}

void Search()
{

}

void Update()
{

}

};





int main()
{
File f;

f.add();
f.Search();
f.Delete();
f.Update();




return 0;
}
