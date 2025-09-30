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

    int getLenght(){
      return length;
    }

    void appendList(int value){
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

    void printList(){
      Node *temp = head;
      while(temp){
        cout << temp->value << " ";
        temp = temp->next;
      }
      cout << endl;
    }

    void deleteLast(){
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
        delete temp;
      }
      length--;
    }

    void prependList(int value){
      Node *newNode = new Node(value);
      if(length == 0){
        head = newNode;
        tail = newNode;
      }
      else{
        newNode->next = head;
        head = newNode;
      }
      length++;
    }

    void deleteFirst(){
      if(length == 0){
        return;
      }
      Node *temp = head;
      if(length == 1){
        head = nullptr;
        tail = nullptr;
      }
      else{
        head = head->next;
      }
      length--;
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

    bool insertNode(int index, int value){
      if(index < 0 || index > length){
        return false;
      }
      if(index == 0){
        prependList(value);
        return true;
      }
      if(index == length){
        appendList(value);
        return true;
      }
      Node *newNode = new Node(value);
      Node *temp = head;
      for(int i = 0; i < index - 1; i++){
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
      length++;
      return true;
    }

    void deleteNode(int index){
      if(index < 0 || index > length){
        return;
      }
      if(index == 0){
        return deleteFirst();
      }
      if(index == length){
        return deleteLast();
      }
      Node *prev = head;
      for(int i = 0; i < index - 1; i++){
        prev = prev->next;
      }
      Node *temp = prev->next;
      prev->next = temp->next;
      delete temp;
      length--;
    }

    void reverseList(){
      Node *temp = head;
      head = tail;
      tail = temp;
      Node *after = temp->next;
      Node *before = nullptr;

      for(int i = 0; i < length; i++){
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
      }
    }
};

int main(){
  // Declared List
  LinkedList list(100);

  // Append List
  list.appendList(200);
  list.appendList(300);
  list.appendList(400);
  list.appendList(500);

  //Print List
  list.printList();

  // Delete Last Node
  list.deleteLast();
  list.printList();

  // Prepend list
  list.prependList(140);
  list.printList();

  // Delete First Node
  list.deleteFirst();
  list.printList();

  // Get Value by index
  cout << "Value at index 2 : " << list.getValue(2) << endl;

  // Set Value by index
  list.setValue(1, 4000);
  list.printList();

  // Insert new node at index
  list.insertNode(2, 1000);
  list.printList();

  // Delete Node at index
  list.deleteNode(3);
  list.printList();

  // Reverse the linkedlist
  cout << "LL before reverse():" << endl;
  list.printList();

  list.reverseList();

  cout << "LL after reverse():\n";
  list.printList();  

  cout << list.getLenght() << endl;
  return 0;
}