#include<iostream>
using namespace std;




struct node
{
    string name;
    struct node* next;
};

class Stack
{
 private:
  struct node*top;

public:
 Stack()
 {
    top=NULL;
 }
 
 void push(string name)
 {
    struct node* temp= new node();
    temp->name=name;
    temp->next=top;
    top=temp;
 }

 string pop()
 {
    if(top==NULL)
    {
        return "stack underflow";

    }
    else
    {
        struct node*temp;
        temp= top;
        top=top->next;
        string data= temp->name;
        delete temp;
        return data;
    }
 }

 void showAllData()
 {
    struct node*temp= top;
 
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
       
    else
    {
        
    while(temp!=NULL)
    {
        cout<<temp->name<<endl;
        temp= temp->next;
    }
    delete temp;
 }
 }
};

int menu()
{
    cout<<"\n"<<endl;
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Show All Stack items"<<endl;
    cout<<"Enter Your option"<<endl;
    int opt;
    cin>>opt;
    return opt;
}
int main()
{
    Stack s;
    while(true)
    {
        int option = menu();
        if(option==1)
        {
            cout<<"Enter student name to store in stack "<<endl;
            string name;
            cin>>name;
            s.push(name);
        }
        else if(option==2)
        {
            string name= s.pop();
            cout<<name<<endl;

        }
        else if (option==3)
        {
            s.showAllData();
        }
    }
}
