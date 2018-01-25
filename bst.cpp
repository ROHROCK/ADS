#include<iostream>

using namespace std;

class node{
   int data;
   node *left;
   node *right;
 public:
   node()
   {
     data = 0;
     left = right = NULL;
   }
};

class bst {
  int highestDepth;
  node * Head;
public:
  bst(){Head = NULL;}

  //Main logic to add the bst
  void addNode(int data)
  {
      temp = initializeNode(data);
      node *child = HEAD,*parent;
      if (HEAD == NULL) {
        head = temp;
      }else
      {
          while(child != NULL)
          {
              parent = child;
              if (data > child->data)
                child = child->right;
              else
                child = child->left;
          }
          if (data > parent->data)
            parent->right = temp;
          else
            parent->left = temp;
      }
  }

  node* initializeNode(int data)
  {
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  //This code is to accept the data and add to a BST
  void createBST(){
   int no,data;
   cout<<"Enter the Number of data to be added :"<<endl;
   cin>>no;
   for (int i = 0; i < no; i++) {
     cout<<"Enter the data: "<<endl;
     cin>>data;
     addNode(data);
   }
  }
};

int main(){
  int ch ;
  char status;
  do {
    /* code */
    cout<<"*************MENU************"<<endl;
    cout<<"1.Create the BST"<<endl;
    cout<<"2.Add node to the BST"<<endl;
    cout<<"3.Find node in the longest path: "<<endl;
    cout<<"4.Minimum data in the tree"<<endl;
    cout<<"5.Swap the pointers in the tree"<<endl;
    cout<<"6.Search a value in the tree"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 7: exit(EXIT_SUCESS);
      case 1: createBST(); break;
      case 2: addNode(); break;
      case 3: longestPath(); break;
      case 4: searchMin(); break;
      case 5: swapPointers(); break;
      case 6: searchValue(); break;
      default: cout<<"Entered value is invalid !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
