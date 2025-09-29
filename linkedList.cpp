#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node *next;
    Node(int value){
      this->value = value;
      next = nullptr;
    }
};

class LinkedList{
  private:
    Node *head;
    Node *tail;
    int length;
  public:
    LinkedList(int value){
      Node *newNode = new Node(value);
      head = newNode;
      tail = newNode;
      length = 1;
    }

    void AppendList(int value){
      Node *newNode = new Node(value);
      if(length == 0){
        head = newNode;
        tail = newNode;
      }
      else{
        tail->next = newNode;
        tail = newNode;
      }
      length++;
    }

    void PrintList(){
      Node *temp = head;
      while(temp){
        cout << temp->value << " ";
        temp = temp->next;
      }
      cout << endl;
    }

    void DeleteLast(){
      if(length == 0){
        return ;
      }
      if(length == 1){
        head = nullptr;
        tail = nullptr;
      }
      else{
        Node *pre = head;
        Node *temp = head;
        while(temp->next){
          pre = temp;
          temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
      }
    }

    void PrependList(int value){
      Node *newNode = new Node(value);
      if(length == 0){
        head = newNode;
        tail = newNode;
        length++;
      }
      else{
        newNode->next = head;
        head = newNode;
        length++;
      }
    }
};

int main(){
  // Declared List
  LinkedList list(100);

  // Append List
  list.AppendList(200);
  list.AppendList(300);
  list.AppendList(400);
  list.AppendList(500);

  //Print List
  list.PrintList();

  // Delete Last Node
  list.DeleteLast();
  list.PrintList();

  // Prepend list
  list.PrependList(140);
  list.PrintList();


  return 0;
}