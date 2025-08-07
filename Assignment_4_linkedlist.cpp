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
    void deleteNode( int position) {

    if (head == NULL) {
      cout<<"LL is empty";
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }


    Node* current = head;
    Node* prev = NULL;
    int count = 1;

    while (current != NULL&& count < position) {
        prev = current;
        current = current->next;
        count++;
    }
    prev->next = current->next;
    delete current;
  }
  void nav(int pos){
     if (head == NULL) {
      cout<<"LL is empty\n";
        return;
    }
    Node* T = head;
    Node* P=NULL;
    int count=1;
    while (T != NULL&& count < pos) {
        P=T;
        T=T->next;
        count++;
    }
    cout<<"Current Song: "<<T->Song_name<<endl;
    cout<<"Previous Song: "<<P->Song_name<<endl;
    Node *N;
    N=T->next;
    cout<<"Next Song: "<<N->Song_name<<endl;
 
  }

};

int main(){
  Playlist P;
  P.insert_end("perfect");
  P.insert_end("qafirana");
  P.insert_end("despacito");
  P.insert_beg("gurenge");
  P.insert_after("perfect","jhol");
  P.display();
  int dec=0;
  while(dec!=5){
    cout<<"Enter Choice \n 1.Display \n 2. Insert at end \n 3. Insert at Beginning \n 4.Insert after song name \n 5. Delete Song \n 6. Know Previous and Next Song\n 7. Exit \n";
    int choice;
    cin>>choice;
    string s,e;
    int pos;
    switch (choice)
    {
    case 1:
      P.display();
      break;
    case 2:
      cout<<"Enter Song Name\n";
      cin>>s;
      P.insert_end(s);
      break;
    case 3:
      cout<<"Enter Song Name \n";
      cin>>s;
      P.insert_beg(s);
      break;
    case 4:
      cout<<"Enter Song Name To insert\n";
      cin>>s;
      cout<<"Enter Song name To insert after \n ";
      cin>>e;
      P.insert_after(e,s);
      break;
    case 5: 
      cout<<"Enter Position Of the song to delete\n";
      cin>>pos;
      P.deleteNode(pos); 
      break;
    case 6:
      cout<<"Enter Position Of the song to delete\n";
      cin>>pos;
      P.nav(pos); 
      break;
       
    case 7:
      dec=5;
      break;
    }
  }
  return 0;
}
