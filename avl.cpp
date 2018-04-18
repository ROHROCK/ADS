/*
  A Dictionary stores keywords and its meanings. Provide facility for adding new keywords , deleting
  new keywords , updating values of any entry.Provide facility to display whole data sorted in acending/decending order
  .Also find how many maximum comparisons may require for finding any keyword.Use Height Balance tree and find
  the complexity for finding a keyword.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
  public:
  string data;
  string meaning;
  int ascii;
  node *left,*right;
  int height;
    node(string d){
      ascii = 0;
      data = d;
      left = right = NULL;
    }
};

class avl{
  node *root;
  node *insertIntoAvl(node *,int,string,string);
  node *deleteFromAvl(node *,int);
  node *rotateLeft(node*);
  node *rotateRight(node*);
  node * RR(node*);
  node *LL(node*);
  node *RL(node*);
  node *LR(node*);
  int BF(node*);
  int Nodeheight(node*);
public:
    avl()
    {
      root = NULL;
    }
    void deleteFromA()
    {
      string w;
      cout<<"Enter the word :"<<endl;
      cin>>w;
      int x = asciiCal(w);
      root = deleteFromAvl(root,x);
    }
    int asciiCal(string w)
    {
      int ascii=0;
      for(int i = 0 ; i < w.length() ; i++)
        ascii += (int)w[i];

      cout<<"Ascii: "<<ascii<<endl;
      return ascii;
    }
    void insert(){
      string w,m;
      cout<<"Enter the word: "<<endl;
      cin>>w;
      cout<<"Enter the meaning: "<<endl;
      cin>>m;
      int x = asciiCal(w);
      root = insertIntoAvl(root,x,w,m);
    }
    void inorder(node *T){
        if(T != NULL){
          inorder(T->left);
          cout<<"Word: "<<T->data<<endl<<"Meaning: "<<T->meaning<<endl;
          inorder(T->right);
        }
    }
    void disp()
    {
      inorder(root);
    }
    void postorder(node *);
    void levelwise();
    void makeNUll(){root = NULL;}
};

/*
  Recursive Function to insert the data into the AVL
  x = ascii of first char of word
*/
node *createNewNode(string word,string meaning,int x)
{
  node* T = new node(word); //store the word and generate ascii of word
  T->left = NULL;
  T->right = NULL;
  T->meaning = meaning;
  T->ascii = x;
}
node* avl::insertIntoAvl(node *T,int x,string word,string meaning){
  if(T == NULL){
    T = new node(word);//createNewNode(word,meaning,x); //create a new node
    T->left = NULL;
    T->right = NULL;
    T->meaning = meaning;
    T->ascii = x;
    return T;
  }else{
    if(x > T->ascii) //insert to right side
    {
      T->right = insertIntoAvl(T->right,x,word,meaning);
      if(BF(T) == -2 )
        if(x > T->right->ascii)
          T = RR(T);
        else
          T = RL(T); //right of left condition
    }else
    {
       if(x < T->ascii){ //insert to left side
          T->left = insertIntoAvl(T->left,x,word,meaning);
          if(BF(T)== 2)
            if(x < T->left->ascii)
              T = LL(T); //left of left;
            else
              T = LR(T); //left of right; condition
          }
    }
    T->height = Nodeheight(T);
    return(T);
  }
}

node* avl::deleteFromAvl(node* T, int x){
  node *p;
  if(T == NULL)
    return NULL;
  else{ //ascii not matched and needs to traverse
    if(x > T->ascii){ //delete from right sub tree
      T->right = deleteFromAvl(T->right,x);
      if(BF(T) == 2) //if the left sub tree is unbalanced
        if(BF(T->left) >= 0) // perform operation on root if left has more nodes on left subT than right subT
          T = LL(T);
          else
          T = LR(T);
      }
      else if(x < T->ascii) { //delete from left sub tree
          T->left = deleteFromAvl(T->left,x);
          if(BF(T) == -2)
            if(BF(T->right) <= 0)// root of right has BF of -vge means right subT has more than left subT
            T = RR(T);
          else
            T = RL(T);
    }else{ //ascii match found
        if(T->right != NULL){
          //delete the inorder sucessor
          p = T->right;
          while(p->left != NULL)
            p = p->left;

          T->ascii = p->ascii;
          T->right = deleteFromAvl(T->right,p->ascii);
          if(BF(T) == 2)
            if(BF(T->left) >= 0)
              T = LL(T);
            else
              T = LR(T);
        }else
          return (T->left);
    }
  }
  T->height = Nodeheight(T);
  return T;
}

node* avl::rotateLeft(node * x){
  node *y = x->right;
  y = x->right;
  x->right = y->left;
  y->left = x;
  x->height = Nodeheight(x);
  y->height = Nodeheight(y);
  return y;
}
node* avl::rotateRight(node * x){
  node *y = x->left;
  x->left = y->right;
  y->right = x;
  x->height = Nodeheight(x);
  y->height = Nodeheight(y);
  return (y);
}
node* avl::RR(node *T){
  T = rotateLeft(T);
  return T;
}
node* avl::LL(node *T){
  T = rotateRight(T);
  return T;
}

node* avl::LR(node *T){
  T->left = rotateLeft(T->left);
  T = rotateRight(T);
  return T;
}

node* avl::RL(node *T){
  T->right = rotateRight(T->right);
  T = rotateLeft(T);
  return T;
}

int avl::BF(node* T){
  int lh,rh;
  if(T->right == NULL)
    rh = 0;
  else
    rh = 1 + T->right->height;

  if(T->left == NULL)
    lh = 0;
  else
    lh = 1 + T->left->height;

  return (lh - rh); //left - right
}
int avl::Nodeheight(node* T){
  int lh,rh;
  if(T->right == NULL)
    rh = 0;
  else
    rh = 1 + T->right->height;

  if(T->left == NULL)
    lh = 0;
  else
    lh = 1 + T->left->height;

  if(lh > rh) //to find the max length of node aka height
    return lh;

  return rh;
}
int main(){
  avl obj;
  int ch;
  char status;
  do{
    cout<<"*********MENU********"<<endl;
    cout<<"1.Create Dictionary"<<endl;
    cout<<"2.Display Dictionary"<<endl;
    cout<<"3.Delete Dictionary"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"*********************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 4: exit(EXIT_SUCCESS);
      case 1: obj.insert();
      break;
      case 2: obj.disp();
      break;
      case 3: obj.deleteFromA();
      break;
      default: cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ?"<<endl;
    cin>>status;
  }while(status == 'y' || status == 'Y');
  return 0;
}
