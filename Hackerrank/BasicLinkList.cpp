#include<stdio.h>
#include<iostream>
using namespace std;
class Data{
public:

  int var;
  Data* next;
};

Data* head;

void Insert(int x)
{
    Data* newNode= new Data();
    newNode->var = x;
    newNode->next = NULL;

    if(head==NULL){
        head=newNode;
    }
    else{
        Data* temp;
        temp=head;
        newNode->next=temp;
        head= newNode;
    }
}

void Delete()
{
    head = head->next;
}

void printList()
{
    Data* temp = head;
    cout << "LinkList: ";
    while(temp != NULL)
        cout << temp->var << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int main(){

    head = NULL;

    Insert(7);
    Insert(6);
    Insert(2);
    printList();
    Insert(20);
    Insert(4);
    printList();
    Delete();
    printList();

    return 0;
}
