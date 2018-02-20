/*For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive).*/
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<cstring>
#include<stdio.h>
#define MAX 25
using namespace std;


/*class node which is a structure for the expression tree */
class node{
  string data ;
  int operand; //if it is operand(any digit) then it should be 1 if it is operator(+) then 0
  node *left;
  node *right;
  node(){
    data = "";
    operand = 1;
    left = right = NULL;
  }
};

//This class will take the prefix expresson from the convert class and create a expression tree using stack
class expression{
  node *head;
  stack<node> s;
public:
  node* createNode(char val)
  {
    node *temp;
    temp->data = val;
    if(isOperand(val))
      temp->operand = 1;
    else if(isOperator)
      temp->operand = 0;

    return temp;
  }
  void createExpressionTree(string prefix)
  {
      node * temp ;
      //push the node in the stack
      for(int i = 0 ; i <= prefix.length() - 1; i++)
      {
          temp = createNode(prefix[i]);
          s.push(temp); //push the node in the stack
      }

      node *r , *l , *root;
      while(s.size() != 1)
      {
        r = s.top();
        s.pop();
        l = s.top();
        s.pop();
        root = s.top();
        s.pop();
        root->left = l;
        root->right = r;
        s.push(root);
      }
      head = s.top();
      s.pop();
      if(!s.empty())
        cout<<"Something went wrong !"<<endl;
  }

  //print the expresson tree using postfix non-recursion
  void printExpressionTree()
  {

  }
};
class convert{
  string infix;
public:
   //convert infix to prefix and return it
   void InfixtoPrefix(string infix)
   {
     //first reverse the infix expression
     string revstring = reverseInfix(infix);
     //second take the postfix of that rev infix expression
     string prefix = infixToPostfix(revstring);
     //then reverse it and the print it
     cout<<"Prefix is: "<<revString(prefix)<<endl;
   }

   //function to reverse the string ;
   string revString(string str)
   {
      string rev = str; //to set the size fo rev to str
      int j = 0;
      int i = str.length();
      while(i > 0 )
        rev[j++] = str[i--];

      return rev;
   }
   //reverse the string
   string reverseInfix(string infix)
   {
     //reverse(infix.begin(),infix.end());
     string revinfix = infix;
     int j = infix.length()-1;
     int i = 0;
     while(j >= 0)
     {
       revinfix[i++] = infix[j--];
     }
     revinfix[infix.length()+1] = '\0';
     for(int i = 0 ; i < infix.length() ; i++)
     {
       if(revinfix[i] == '(')
         revinfix[i] = ')';
       else if(revinfix[i] == ')')
         revinfix[i] = '(';
     }
     return revinfix;
   }
   string infixToPostfix(string infix){
     stack <char>s;
     string res = " ";
     for(int i = 0 ; i < infix.length(); i++)
     {
        if(isOperand(infix[i]))
            res = res + infix[i];
        else if(isOperator(infix[i]))
        {
            while(!s.empty() && !isOpeningPara(infix[i]) && hasHigherPrecedance(s.top(),infix[i]))
            {
              res = res + s.top();
              s.pop();
            }
            s.push(infix[i]);
        }else if(isOpeningPara(infix[i]))
          s.push(infix[i]);
        else if(isClosingPara(infix[i]))
        {
          while(!s.empty() && !isOpeningPara(s.top()))
          {
            res = res + s.top();
            s.pop();
          }
          s.pop(); // to remove the opening para
        }
     }
     while(!s.empty())
     {
       res = res + s.top();
       s.pop();
     }
     return res;
   }

   int w(char ch)
   {
     int weight;
     switch (ch) {
       case '+':
       case '-':
          weight = 1;
       case '*':
       case '/':
          weight = 2;

       case '^':
          weight = 3;
     }

     return weight;
   }
   bool hasHigherPrecedance(char top , char current)
   {
     int weightTop = w(top);
     int weightCurrent = w(top);

     if(weightTop == weightCurrent)
     {
          if(isRightAssociative(top))
              return true;
          else
            return false;
     }
    return (weightTop > weightCurrent)?true:false;
   }

   int isRightAssociative(char ch)
   {
        if(ch == '+' || ch == '-' || ch == '+' || ch == '/')
            return true;
        else
            return false;
   }

   bool isOperand(char ch)
   {
      if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch > '0' && ch < '1')
        return true;

      return false;
   }

   bool isOperator(char ch)
   {
     switch (ch) {
       case '*':
       case '/':
       case '+':
       case '-':
        return true;
     }
     return false;
   }

   bool isOpeningPara(char ch)
   {
     if(ch == '(')
      return true;

     return false;
   }

   bool isClosingPara(char ch )
   {
     if( ch == ')')
      return true;

    return false;
   }

};
int main()
{
  string infix;
  convert obj;
  int ch,data=0;
  char status;
  do {
    system("clear");
    cout<<"*************MENU************"<<endl;
    cout<<"1.Enter infix expression to convert expression tree"<<endl; //DONE
    cout<<"2.Traverse using postorder traversal"<<endl; //DONE
    cout<<"4.TO convert infix to postfix expression: "<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 3: exit(EXIT_SUCCESS);
      case 1:
      break;
      case 4:
        cout<<"Enter the infix expression: "<<endl;
        cin>>infix;
        obj.InfixtoPrefix(infix);
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
