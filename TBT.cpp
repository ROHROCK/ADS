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
  bool leftThread;
  node* right;
  node* left;
  node(){right = left = NULL; rightThread = false;}
  node* initNode(int d){
      node *temp = new node;
      temp->data = d ;
      temp->right = temp->left = NULL;
      temp->rightThread = false;
      temp->leftThread = false;
      return temp;
    }
};

class Tbt:public node{
  node *head;
  public:
    Tbt(){head = NULL;}

    void createTbt(){
      int n = -1;
      node *ptr =  head;
      char character;
      int flag = 1;
        while(flag)
        {
          node *temp = new node;

          if(head == NULL)
          {
              cout<<"Enter the data: "<<endl;
              cin>>n;
              temp->data = n;
              temp->left = NULL;
              temp->right = NULL;
              head = temp;
              cout<<"The root is : "<<head->data<<endl;
              flag = 0;
          }else{

            cout<<"Enter Left or Right of :"<<ptr->data<<endl;
            cin>>character;
            if(n == -1){
                cout<<"Enter the data: "<<endl;
                cin>>n;
              }
            /*This code is for custom creation of tree by user point of view*/
            if(character == 'l' || character == 'L')
            {
              //if node is not present of root set the node and derive its parent pointers
              if(ptr->left == NULL && ptr == head)
              {
                temp->data = n;
                temp->right = head;
                temp->rightThread = true;
                ptr->left = temp;
                cout<<"Data entered Left of parent: "<<ptr->data<<endl;
                flag = 0;
              }else if(ptr->left == NULL){
                 //Here node is present left side of subtree
                 temp->data = n;
                 temp->right = ptr;
                 if(ptr->left != NULL){
                    temp->leftThread = true;
                    temp->left = ptr->left; //derive the pointer of parent to node
                    ptr->leftThread = false;
                  }
                 ptr->left = temp;
                 cout<<"Data entered Left of parent: "<<ptr->data<<endl;
                 flag = 0;
             }else  //Node exits so ... traverse the left subtree
                ptr = ptr->left;

             //Left node coding
            }else if(character == 'r' || character == 'R'){
              /*There will be 3 cases:
                1) When data is to be entered root->right
                2) When data is to be entered right
                3) When right subtree is being traversed*/
                if(ptr->right == NULL && ptr == head){ //case 1
                  temp->data = n;
                  temp->left = head;
                  ptr->right = temp;
                  cout<<"Data entered Right of Parent: "<<ptr->data<<endl;
                  flag = 0;
                }else if(ptr->right == NULL)
                {
                  temp->data = n;
                  temp->left = ptr;
                  if(ptr->right != NULL)
                    {
                      temp->right = ptr->right;
                      temp->rightThread = true;
                      ptr->rightThread = false;
                    }
                  ptr->right = temp;
                  cout<<"Data entered Right of Parent: "<<ptr->data<<endl;
                  flag = 0;
                }else //Node exits so traverse it:
                  ptr = ptr->right;
            }else
                cout<<"Invalid position entered please try again !"<<endl;
          }
        }
    }
    void inorder(node *data) //TBT code traversal
    {
        if(data == NULL)
          return;

        cout<<data->data<<" ";
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
    cout<<"1.Create the Binary Tree"<<endl;
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
