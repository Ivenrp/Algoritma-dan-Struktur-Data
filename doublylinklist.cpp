#include <iostream>
using namespace std;

typedef struct node *address;
struct node{
    address prev;
    int data;
    address next;
};

//node z;
address first,last,temp;

address alokasi(int datax){ //fungsi mengembalikan data ke node baru
    address x=new node;
    x->prev=NULL;
    x->next=NULL;
    x->data=datax;
    return x;
}

void insertfirst(address baru){
    if(first!=NULL){
        baru->next=first;
        first->prev=baru;
        first=baru;
    }else{
        first=baru;
        last=baru;
    }
}

void cetak(){
    address jalan=first;
    while(jalan!=NULL){
        cout<<jalan->data<<"\n";
        jalan=jalan->next;
    }
}

void insertlast(address baru){
    if(first!=NULL){
      last->next=baru;
      baru->prev=last;
      last=baru;
    }else{
        last=baru;
        first=baru;
    }
}

void insertafter(address lama, address baru){
    if(first!=NULL){
        baru->next=lama->next;
        baru->prev=lama;
        lama->next=baru;
        baru->next->prev=baru;
    }
}

void deletefirst(){
    first=first->next;
    delete first->prev;
    first->prev=NULL;
}

void deletelast(){
    last=last->prev;
    delete last->next;
    last->next=NULL;
}

void deleteafter(address suatualamat) {
    address temp = suatualamat->next;
    temp->next->prev = suatualamat;
    suatualamat->next = temp->next;
    delete temp;
}
 
int main() {
    //temp=(address)malloc(sizeof(node)); // atau temp=new node;
    //temp->data=1000;
    //z.data=100;
    //cout<<temp->data; // data dari (node baru)
    //cout<<z.data; //data dari z (node lama)
    //address hasil=alokasi(30);
    //hasil=alokasi(90);
    //hasil=alokasi(70);
    //cout<<hasil->data;
    insertfirst(alokasi(200));
    insertfirst(alokasi(100));
    insertfirst(alokasi(300));
    //cetak();
    insertlast(alokasi(80));
    //cetak();
    insertafter(first->next,alokasi(288));
    deletefirst();
    deletelast();
    deleteafter(first);
    cetak();
    
    return 0;
}
