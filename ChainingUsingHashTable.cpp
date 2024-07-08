/*Implement all the functions of a dictionary (ADT) using hashing and handle collisions using
chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Node
{
public:
int data;
string name;
string mobile;
Node *next;
};

class Hash{
    public:
        Node *hash_table[10];
        Node *createNode(int x,string a,string b);
        Node *temp;

        int hash_function(int val);
        void display();
        int Search(int data);
        void Insert(int data,string name,string mobile);
        void Delete(int data);
        
        Hash(){
            for(int i=0;i<10;i++){
                hash_table[i]=NULL;
            }
        }

};

int Hash::hash_function(int data){
    return data%10;
}

Node *Hash::createNode(int x,string a,string b){
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    temp->name=a;
    temp->mobile=b;
    return temp;
}

void Hash::display(){
    cout<<"\n";
    for(int i=0;i<10;i++){
        temp=new Node;
        temp=hash_table[i];
        cout<<i<<" : ";
        while(temp!=NULL){
            cout<<"  ->  "<<temp->data<<" - "<<temp->name<<" - "<<temp->mobile;
            temp=temp->next;
        }
        cout<<endl;
    }
}
void Hash::Insert(int data,string name,string mobile){
    int hash_value=hash_function(data);
    Node *temp=new Node;
    Node *head=new Node;
    head=createNode(data,name,mobile);
    temp=hash_table[hash_value];
    if(temp==NULL){
        hash_table[hash_value]=head;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
    }
}

int Hash::Search(int data){
	bool flag = 0;
	int hash_value = hash_function(data);
	Node *newNode = hash_table[hash_value];

	cout<<"\nElement found at : ";
	while (newNode != NULL)
	{
	if (newNode->data==data)
	{
		cout<<hash_value<<" : "<<newNode->data<<endl;
		flag = 1;
	}
	newNode = newNode->next;
	}
	if (!flag)
	return -1;
}

void Hash::Delete(int data){
    int hash_value = hash_function(data);
    Node *newNode = hash_table[hash_value];
    if(newNode==NULL){
        cout<<"NOT FOUND\n";
        return;
    }
    if (newNode->data==data){
        hash_table[hash_value]=newNode->next;
        
        return;
    }
    while ((newNode->next)->data != data){
		newNode = newNode->next;
	}
		newNode->next=(newNode->next)->next;
}

int main(){
    Hash H;
    string name,mobile;
    int data,Skey,Dkey,ch;
    char res;
    do{
        cout<<"-------------------------MENU-------------------------\n";
        cout<<"1.Press 1 to INSERT new newNode\n2.Press 2 to DISPLAY the phonebook\n3.Press 3 to SEARCH an element\n4.Press 4 to DELETE an element\n\n";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter data to INSERT\t"; //data is roll no or any key
                cin>>data;
                cout<<"Name: \t";
                cin>>name;
                cout<<"Mobile: \t";
                cin>>mobile;
                H.Insert(data,name,mobile);
                break;
            case 2:
                cout<<"-------------------------PHONEBOOK-------------------------\n";
                H.display();
                break;
            case 3:
                cout<<"Enter the data to be searched\t";
                cin>>Skey;
                if(H.Search(Skey)==-1){
                    cout<<"NOT FOUND\n";
                    continue;
                }
                break;
            case 4:
                cout<<"Enter the data to be deleted\t";
                cin>>data;
                H.Delete(data);
                cout<<"DELETED\n";
                break;
            case 5:
                exit(0);
        }
        cout<<"Do you want to continue(y/n)\n";
        cin>>res;
    }while(res=='Y'||res=='y');
}
