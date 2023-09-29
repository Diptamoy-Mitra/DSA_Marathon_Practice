#include <bits/stdc++.h>
using namespace std;
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
// dispaly
void display(Node *head)
{
  Node *temp = head;
  do
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}
// insert at top
void insertAtTop(Node *&head, int d)
{
  Node *n = new Node(d);
  if (head == NULL)
  {
    n->next = n;
    head = n;
    return;
  }
  Node *temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = n;
  n->next = head;
  head = n;
}
// insert at end
void insertAtEnd(Node *&head, int d)
{
  if (head == NULL)
  {
    insertAtTop(head, d);
    return;
  }
  Node *n = new Node(d);
  Node *temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = n;
  n->next = head;
}
//deletion at head
void deletionAtHead(Node* &head){
  Node* temp=head;
  while(temp->next!=head){
    temp=temp->next;
  }
  Node* t=head;
  temp->next=head->next;
  head=head->next;
  delete t;

  


}
//Deletion
void deletion(Node* &head, int pos){
  if(pos==1){
    deletionAtHead(head);
    return;
  }
  Node* temp=head;
  int i=1;
  while(i!=pos-1){
    temp=temp->next;
    i++;
  }
  Node *t=temp->next;
  temp->next=temp->next->next;
  delete t;
}


int main()
{
  Node *head = NULL;
  insertAtEnd(head, 1);
  insertAtEnd(head, 2);
  insertAtEnd(head, 3);
  display(head); //1 -> 2 -> 3 ->  
  insertAtTop(head,5);
  display(head); //5 -> 1 -> 2 -> 3 -> 
  deletion(head, 4);
  display(head); //5 -> 1 -> 2 ->
  deletion(head, 1);
  display(head); //1 -> 2 ->

  return 0;
}