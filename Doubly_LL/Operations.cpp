#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *prev;
  Node(int d)
  {
    data = d;
    next = NULL;
    prev = NULL;
  }
};
// insert at top
void insertAtHead(Node* &head, int val)
{
  Node *ptr = new Node(val);
  ptr->next = head;
  if (head != NULL)
  {
    head->prev = ptr;
  }
  head = ptr;
}
// insert at tail
void insertAtLast(Node* &head, int val)
{
  Node *ptr = new Node(val);
  if (head == NULL)
  {
    insertAtHead(head, val);
    return;
  }
  Node *temp = head;
  while (temp->next!= NULL)
  {
    temp = temp->next;
  }
  temp->next = ptr;
  ptr->prev = temp;
}
//deletion at head
void  deletionAtHead(Node* &head){
  Node* temp=head;
  head=head->next;
  head->prev=NULL;
  delete temp;

}
//deletion
void deletion(Node* &head, int pos){
  if(pos==1){
    deletionAtHead(head);
    return;
  }
  int count=1;
  Node* temp=head;
  while(count!=pos && temp!=NULL){
    temp=temp->next;
    count++;
  }
  temp->prev->next=temp->next;
  if(temp->next!=NULL){
     temp->next->prev=temp->prev;
  }
  delete temp;
}


// display
void Display(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *head = NULL;
  insertAtHead(head, 1);
  insertAtHead(head, 5);
  Display(head); //5 -> 1 ->
  insertAtLast(head, 2);
   Display(head); //5 -> 1 -> 2 ->
  insertAtLast(head, 3);
  Display(head); //5 -> 1 -> 2 -> 3 ->
  deletion(head,3);
  Display(head); //5 -> 1 -> 3 ->
  deletion(head,1);
  Display(head); //1 -> 3 -> 
  return 0;
}