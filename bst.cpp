/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i.Insert new node
ii.Find number of nodes in longest path
iii.Minimum data value found in the tree
iv.Change a tree so that the roles of the left and right pointers are swapped at
every node
v.Search a value
*/
#include<iostream>
#include<queue>
#include<list>
#include<stdlib.h>

using namespace std;

class node{
public:
   int data;
   node *left;
   node *right;
   node()
   {
     data = 0;
     left = right = NULL;
   }
};

class bst {
  int highestDepth;
  node *Head,*revHead;
public:
  node* getHead(){ ret\urn Head;}
  node* getRevHead(){return revHead;}
  bst(){revHead = Head = NULL;}

  //Main logic to add the bst ..when flag value is 0 then add the main else if 1 then add to the copy tree
  void addNode(int data,int f)
  {
      node *temp = initializeNode(data);
      node *child;
      node *parent = new node;
      if(f == 0){
        child = Head; //this is the main tree
      }
      else if(f == 1){
        child = revHead; //this is the copy of the tree
      }
      if (f == 0 && Head == NULL)
          Head = temp;
      else if(f == 1 && revHead == NULL)
          revHead = temp;
      else
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

   //Code for print in order
   void print(struct node* node)
 {
      if (node == NULL){
           return;
      }

      /* first recur on left child */
      print(node->left);
      /* then print the data of node */
      cout<<node->data<<" ";
      /* now recur on right child */
      print(node->right);
 }

  node* initializeNode(int data)
  {
    node *temp = new node;
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
     addNode(data,0); //add to main tree
     addNode(data,1);//add to copy tree
   }
  }

  void swap()
  {
    //To find the longestPath
    if(Head == NULL)
      return ;

    std::queue<node *> q;

    q.push(revHead);
    int height = 0;

    while (1) {
      int nodeCount = q.size();
      if(nodeCount == 0)
        return;
      else
        height++;

        node *temp;
        node *ptr;
      //Remove nodes at this level and add the node of next level
      while(nodeCount > 0)
      {
        temp = q.front();
        q.pop();

        temp = swapPointers(temp);
        //push its children
        if(temp->left != NULL)
          q.push(temp->left);
        if(temp->right != NULL)
          q.push(temp->right);
        nodeCount--;
       }
      }
  }
  int longestPath(){
    //To find the longestPath
    if(Head == NULL)
      return 0;

    std::queue<node *> q;

    q.push(Head);
    int height = 0;

    while (1) {
      int nodeCount = q.size();
      if(nodeCount == 0)
        return height;
      else
        height++;

        node *temp;
      //Remove nodes at this level and add the node of next level
      while(nodeCount > 0)
      {
        temp = q.front();
        q.pop();
        //push its children
        if(temp->left != NULL)
          q.push(temp->left);
        if(temp->right != NULL)
          q.push(temp->right);
        nodeCount--;
       }
      }
}
  void searchValue(){
    int key;
    cout<<"Enter the key you want to search: "<<endl;
    cin>>key;
    //code to serach the value in the tree and print the parent
    if(Head->data == key){
      cout<<"The data is root value hence no parent.."<<endl;
      return;
    }

    node* child = Head, *parent;
    int flag = 0;
    while(child != NULL)
    {
        parent = child;
        if (key > child->data)
          child = child->right;
        else
          child = child->left;

        if(child != NULL && child->data == key){
           flag = 1;
           cout<<"The key is found ! "<<key<<" The parent is: "<<parent->data<<endl;
           break;
        }
    }
    if(flag == 0)
      cout<<"The key is not present in the tree !"<<endl;
  }
  void searchMin(){
    //code to search the min node in the tree
    node *temp = new node;
    temp = Head;
    while(temp->left != NULL)
    {
      temp = temp->left;
    }
    cout<<"The minimum value of the tree is: "<<temp->data<<endl;
  }
  node* swapPointers(node *temp){
      node* newnode = new node;
      newnode->left = temp->left;
      temp->left = temp->right;
      temp->right = newnode->left;
      return temp;
  }

};

int main(){
  bst obj;
  int ch,data=0;
  char status;
  do {
    system("clear");
    cout<<"*************MENU************"<<endl;
    cout<<"1.Create the BST"<<endl; //DONE
    cout<<"2.Add node to the BST"<<endl; //DONE
    cout<<"3.Find number of nodes in longest path: "<<endl; //NOT YET
    cout<<"4.Minimum data in the tree"<<endl; //DONE
    cout<<"5.Swap the pointers in the tree"<<endl; //DONE
    cout<<"6.Search a value in the tree"<<endl; //DONE
    cout<<"7.Print the tree"<<endl;//DONE
    cout<<"8.Print the Reverse tree"<<endl;//DONE
    cout<<"9.Exit"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 9: exit(EXIT_SUCCESS);
      case 1: obj.createBST(); break;
      case 2: cout<<"Enter the data: "<<endl; cin>>data; obj.addNode(data,0); break;
      case 3: cout<<"The number of nodes in longest path: "<<obj.longestPath()<<endl; break;
      case 4: obj.searchMin(); break;
      case 5: obj.swap(); break;
      case 6: obj.searchValue(); break;
      case 7: obj.print(obj.getHead()); break;
      case 8: obj.print(obj.getRevHead()); break;

      default: cout<<"Entered value is invalid !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
