//Problem statement:
/*Convert given binary tree into threaded binary tree. Analyze time and space complexity of the
algorithm.*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
public:
  int data ;
  bool rightThread ;
  node* right;
  node* left;
  node(){right = left = NULL; rightThread = false;}
  node* initNode(int d){
      node *temp = new node;
      temp->data = d ;
      temp->right = temp->left = NULL;
      temp->rightThread = false;
      return temp;
    }
};

class Tbt:public node{
  node *head;
  public:
    Tbt(){head = NULL;}

    //function to add the data to the tbt
    void addNode(int data )
    {
      node *temp = initNode(data); //call the parameterized constructor
      node *child = head;
      node* parent = new node;
      if(head == NULL){
          head = temp;
      }else{
        //when the tree has a root
        while(child != NULL)
        {
          parent = child;
          if(data > child->data )
             child = child->right;
          else
             child = child->left;
        }
        //place the temp node at its appropiate place
        if(data > parent->data){
          if(parent->rightThread){
            temp->right = parent->right;
            parent->right = temp;
            temp->rightThread = true;
          }else{
            //the parent does not have any rightThread right subtree
            parent->right = temp;
          }
        }
        else{
            //the node is smaller than the parent hence it will always point to its parent
            temp->right = parent;
            parent->left = temp;
            temp->rightThread = true;
        }
      }
    }
    void createTbt(){
      int d =0,val = 0;
      cout<<"Enter the number nodes to add: "<<endl;
      cin>>d;
      for(int i = 1 ;i<=d;i++)
      {
        cout<<"Enter the value: "<<endl;
        cin>>val;
        addNode(val);
      }
    }
    void inorder(node *data) //TBT code traversal
    {
        if(data == NULL)
          return;

        cout<<data->data;
        inorder(data->right);
    }
    node* leftmost(){
      if(head == NULL)
      {
        cout<<"The Tree is empty !"<<endl;
        return NULL;
      }
      node *temp = head;
      while(temp->left != NULL)
        temp= temp->left;

    return temp;
    }
};

int main(){
  Tbt obj;
  int ch,data=0;
  char status;
  do {
    system("clear");
    cout<<"*************MENU************"<<endl;
    cout<<"1.Create the BST"<<endl;
    cout<<"2.Print the Threaded Tree"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 3: exit(EXIT_SUCCESS);
      case 1: obj.createTbt(); break;
      case 2: obj.inorder(obj.leftmost()); break;
      default: cout<<"Entered value is invalid !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
}
