#include <iostream>
#include <fstream>
using namespace std;


 
 
 struct List
{
    double coeff;
    double expon;
    List * pNext;
};
List *first = NULL;
List *second = NULL;
List *third = NULL;

 
void add_first_list(int data,int step)
{
    if (first == NULL)
    {
        first = new (List);
        first->coeff = data;
        first->expon=step;
        first->pNext = NULL;
    }
    else
    {
        List *adr;
        adr = first;
        while (adr->pNext != NULL)
        {
            adr = adr->pNext;
        }
        adr->pNext = new(List);
        adr = adr->pNext;
        adr->coeff = data;
        adr->expon=step;
        adr->pNext = NULL;
    }
}
void add_second_list(double data,int step)
{
    if (second == NULL)
    {
        second = new (List);
        second->coeff = data;
        second->expon=step;
        second->pNext = NULL;
    }
    else
    {
        List *adr;
        adr = second;
        while (adr->pNext != NULL)
        {
            adr = adr->pNext;
        }
        adr->pNext = new(List);
        adr = adr->pNext;
        adr->coeff = data;
        adr->expon=step;
        adr->pNext = NULL;
    }
}


void show_list()
{
    List *temp = second;
 
    while (temp->pNext != NULL)
    {
        cout<<temp->coeff<<"x^("<<temp->expon<<")"<<"+";
        temp = temp->pNext;
    }
    cout<<temp->coeff<<"x^("<<temp->expon<<")"<<endl;
}



 
void division(double num){
    List *temp = first;
    double  tmp;
    while (temp != NULL)
    {
        tmp=temp->coeff/num;
        add_second_list(tmp, temp->expon);
        temp = temp->pNext;
    }
}

int write(){
    ofstream Fin;
         Fin.open ( "boo.dat", ios::binary );
         Fin.write( (char*)&first, sizeof(List) );
         Fin.close();
    return 0;
}
int read(){
    ifstream Fn( "boo.dat", ios::binary);
         Fn.read( (char*)&third, sizeof(List) );
         Fn.close();
    return 0;
}

int main()
{
    add_first_list(3,5);
    add_first_list(2,4);
    add_first_list(6,3);
    add_first_list(9,2);
    add_first_list(6,1);

    write();
    read();
    double num=0;
    cout<<"Enter number A : ";
    cin>>num;
    division(num);
    show_list();
   return 0;
}
