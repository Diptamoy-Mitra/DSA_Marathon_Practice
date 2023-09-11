#include <bits/stdc++.h>
using namespace std;
// 3->8->2->5->Null
class Node
{
public:
  int data;
  Node *next;
  Node(int d)
  {
    data = d;
    next = NULL;
  }
};

//insert at first
void insertAtFirst(Node *&head, int d)
{
  Node *ptr = new Node(d);

  ptr->next = head;
  head = ptr;
}
//insert at last
void insertAtLast(Node* head, int d){
  Node* ptr=new Node(d);
  Node* temp=head;
  ptr->next=NULL;
  while(temp->next!= NULL){
    temp=temp->next;
  }
  temp->next=ptr;

}
//insert at any index
void insertAtIndex(Node* head,int d, int t){
    Node* ptr=new Node(d);
    Node* p=head;
    int i=0;
    while(i!=t-1){
      p=p->next;
      i++;
    }
    ptr->next=p->next;
    p->next=ptr;


}//delete 1st node
void deleteAtFirst(Node* &h){
  Node* ptr=h;
  h=h->next;
  delete ptr;

}
//delete a node in between a node
void deleteAtIndex(Node* h, int index){
    Node* p=h;
    Node* q=h->next;
    for(int i=0;i<index-1;i++){
      p=p->next;
      q=q->next;
    }
    p->next=q->next;
    delete q;
}
//delete last node
void deleteAtEnd(Node* h)
{
  Node* p=h;
  Node* q=h->next;
  while(q->next!=NULL)
  { 
    p=p->next;
    q=q->next;
  }
  p->next=NULL;
  delete q;
}
//delete element with given value
void deleteByValue(Node* h, int d)
{
  Node* p=h;
  Node* q=h->next;
  while(q->data!=d && q->next!=NULL){
    p=p->next;
    q=q->next;
  }
  p->next=q->next;
  delete q;
}


//print
void print(Node *h)
{
  while (h != NULL)
  {
    cout << h->data << "->";
    h = h->next;
  }
}

int main()
{
  Node *head = NULL;
  insertAtFirst(head, 1);
  insertAtFirst(head, 2);
  insertAtFirst(head, 3);
  insertAtLast(head, 4);
  print(head);//3->2->1->4->
  insertAtIndex(head, 123, 2);
  cout<<endl;
  print(head); //3->2->123->1->4->
  deleteAtFirst(head);
  cout<<endl;
   print(head); //2->123->1->4->
   deleteAtIndex(head,2);
   cout<<endl;
   print(head); //2->123->4->
   deleteAtEnd(head);
   cout<<endl;
   print(head); //2->123->
  deleteByValue(head,123);
  cout<<endl;
   print(head); //2->
}