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
        length--;
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
        length--;
        delete temp;
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

    void DeleteFirst(){
      if(length == 0){
        return;
      }
      Node *temp = head;
      if(length == 1){
        head = nullptr;
        tail = nullptr;
        length--;
      }
      else{
        head = head->next;
      }
      delete temp;
    }

    int getValue(int index){
      if(index < 0 || index > length){
        return NULL;
      }
      else{
        Node *temp = head;
        for(int i = 0; i < index; i++){
          temp = temp->next;
        }
        return temp->value;
      }
    }
    void setValue(int index, int value){
      if(index < 0 || index > length){
        return;
      }
      else{
        Node *temp = head;
        for(int i = 0; i < index; i++){
          temp = temp->next;
        }
        temp->value = value;
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

  // Delete First Node
  list.DeleteFirst();
  list.PrintList();

  cout << "Value at index 2 : " << list.getValue(2) << endl;

  list.setValue(1, 4000);
  list.PrintList();

  return 0;
}