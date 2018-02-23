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
public:
  char data ;
  int operand; //if it is operand(any digit) then it should be 1 if it is operator(+) then 0
  node *left;
  node *right;
  node(){
    operand = 1;
    left = right = NULL;
  }
};

//This class will take the prefix expresson from the convert class and create a expression tree using stack
class convert{
  public:
  string infix;
  string prefix;
   //convert infix to prefix and return it
   void InfixtoPrefix(string infix)
   {
     //first reverse the infix expression
     string revstring = reverseInfix(infix);
     cout<<"Reverse String is: "<<revstring;
     //second take the postfix of that rev infix expression
     string pre = infixToPostfix(revstring);
     cout<<"Prefix before reverse: "<<prefix;
     //then reverse it and the print it
     prefix = revString(pre);
     cout<<"Prefix is: "<<pre<<endl;
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
      if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
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
class expression : public convert{
  node *head;
  stack<node*> expressionstack;
public:
  node* createNode(char val)
  {
    cout<<val<<endl;
    node *temp;
    temp->data = val; //conversion
    if(isOperand(temp->data))
      temp->operand = 1;
    else if(isOperator(temp->data))
      temp->operand = 0;

    cout<<"Done ?"<<endl;
    return temp;
  }
  void postfixTraversal()
  {
    node *root = head;
    // Check for empty tree
    if (root == NULL)
        return;

    stack <node*>s;
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                s.push(root->right);//push(stack, root->right);

            s.push(root);//push(stack, root);

            // Set root as root's left child
            root = root->left;
        }

        // Pop an item from stack and set it as root
        root = s.top();
        s.pop();

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && s.top() == root->right)
        {
            s.pop();  // remove right child from stack
            s.push(root);  // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            cout<<root->data;
            root = NULL;
        }
    } while (!s.empty());
  }

  void createExpressionTree()
  {
      //push the node in the stack
      for(int i = 0 ; i <= prefix.length() - 1; i++)
      {
          node *temp;
          temp = createNode(prefix[i]);
          expressionstack.push(temp); //push the node in the stack
      }

         node *r , *l , *root;
        while(expressionstack.size() == 1)
        {
          if(!expressionstack.empty())
          {
            r = expressionstack.top();
            expressionstack.pop();
          }
          if(!expressionstack.empty()){
            l = expressionstack.top();
            expressionstack.pop();
          }
            root = expressionstack.top();
            //expressionstack.pop();
            root->left = l;
            root->right = r;
            expressionstack.push(root);
         }
       // node *t;
       // if(!expressionstack.empty())
       //  {
       //    t = expressionstack.top();
       //    expressionstack.pop();
       //  }
       // if(expressionstack.empty())
       //    cout<<"Something went wrong !"<<endl;

      cout<<"Created Expression Tree !"<<endl;
  }
};

int main()
{
  string infix;
  expression obj;
  int ch,data=0;
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
        cout<<"Enter the infix expression: "<<endl;
        cin>>infix;
        obj.InfixtoPrefix(infix);
      break;
      case 2:
        obj.createExpressionTree();
      //  obj.postfixTraversal();
      break;
      default: cout<<"Entered value is invalid !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
