/*For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive)*/
#include<iostream>

using namespace std;

int main()
{
  int ch;
  char status;
  do {
    system("clear");
    cout<<"*************MENU************"<<endl;
    cout<<"1."<<endl;
    cout<<"2."<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"******************************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 3: exit(EXIT_SUCCESS);
      case 1:  break;
      case 2:
      break;
      default: cout<<"Entered value is invalid !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
