/*For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive).*/
#include<iostream>
#include<stdlib.h>
#include<stack.h>
#define MAX 25
using namespace std;

class node{
  string data ;
  int operand; //if it is operand(any digit) then it should be 1 if it is operator(+) then 0
  node *left;
  node *right;
  node(){
    data = "";
    operand = 1;
    left = right = null;
  }
};
class convert{
  node *head;
  stack<node> s;
  string infix;
public:
   void getInfix()
   {
     cout<<"Enter the infix expression: "<<endl;
     cin>>infix;
   }
   //convert infix to prefix and return it
   string prefix(string infix)
   {
      /*v*/
   }
};
int main()
{  int ch,data=0;
  char status;
  do {
    system("clear");
    cout<<"*************MENU************"<<endl;
    cout<<"1.Enter infix expression to convert expression tree"<<endl; //DONE
    cout<<"2.Traverse using postorder traversal"<<endl; //DONE
    cout<<"3.Exit"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 3: exit(EXIT_SUCCESS);
      case 1:
      break;
      case 2:
      break;
      default: cout<<"Entered value is invalid !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
