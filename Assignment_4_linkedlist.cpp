#include<iostream>
using namespace std;
class Node{
  public:
  string Song_name;
  Node* next;
  Node(string data){
    Song_name=data;
    next = NULL;
  }
};

class Playlist{
    public:
    Node* head;
   
    Playlist(){
        head=NULL;
    }
    void insert_end(string name){
      Node* nn = new Node(name);
      if(head==NULL){
       head=nn;
      }
      else{
        Node *T =head;
        while(T->next !=NULL){
          T=T->next;
        }
        T->next=nn;
      }
    }
    void insert_beg(string name){
      Node* nn = new Node(name);
      if(head == NULL){head =nn;}
      else{
        nn->next=head;
        head = nn;
      }
    }
    void insert_after(string sn,string nsn){
      Node *nn = new Node(nsn);
      Node *T =head;
      while(T->next !=NULL){
        if(T->Song_name==sn){
          break;
        }
        else{
          T = T->next;
        }
      }
      nn->next = T->next;
      T->next = nn;
      
    }
    void display(){
      Node *temp = head;
      if(head == NULL){
        cout<<"LL is Empty\n";
        return;
      }
      cout<<"-------------------\n";
      while(temp!=NULL){
        cout<<temp->Song_name<<"\n";
        temp = temp->next;
      }
     cout<<"-------------------\n";
    }
};

int main(){
  Playlist P;
  P.insert_end("perfect");
  P.insert_end("qafirana");
  P.insert_end("despacito");
  P.insert_beg("gurenge");
  P.display();
  P.insert_after("perfect","jhol");
  P.display();
  return 0;
}