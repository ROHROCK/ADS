#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class node
{
public:
  string data;
  node *next , *DL;
  int flag; //when flag is 0 then the next pointer is pointing to the next node and when flag is 1 then it is pointing to the next section
  node()
  {
    next = DL = NULL;
    flag = 0;
  }
};

class l{
  node *Head = new node;
  node *CurrentChapter = new node;
  node *CurrentSection = new node;
  node *CurrentSubsection = new node;
public:
  void createBook()
  {
    string title;
    int no_of_chapter = 0,no_of_section=0,noOfSubsection=0;

    cout<<"Enter the title of the Book: "<<endl;
    cin>>title;
    Head = createnode(title);

    //Enter the number of chapter
    cout<<"Enter the number of chapters in the book"<<endl;
    cin>>no_of_chapter;
    Head->DL = CurrentChapter;
    for(int i = 0 ; i < no_of_chapter ; i++)
    {
      CurrentChapter = addList("Chapter-"+std::to_string(i+1),Head);
      //cout<<"Added chapter no: "<<CurrentChapter->data;
      //Pass the int and node where node is the head of list and int is no of chapter
       cout<<"Enter the number of section in Chapter "<<i+1<<endl;
       cin>>no_of_section;
       //Add the respective sub_section
       //CurrentChapter->DL = CurrentSection;
       for(int j = 0 ; j < no_of_section ; j++)
       {
          string sec = "Section"+std::to_string(i+1)+"."+std::to_string(j+1);
          CurrentSection =  addList(sec,CurrentChapter);
          cout<<"Enter the number of Sub-section in section"<<j<<endl;
          cin>>noOfSubsection;
            for (int z = 0;z < noOfSubsection ; z++) {
                string subsec = "Sub_Section"+std::to_string(i+1)+"."+std::to_string(j+1)+"."+std::to_string(z+1);
                CurrentSubsection =  addList(subsec,CurrentSection);
          }
       }
    }

  }

  void displayBook()
  {
    /*
      Code for displaying the book
    */
    cout<<"**************BOOK***************"<<endl;
    cout<<Head->data<<endl;
    // print(Head->DL->DL);
    node *chapter = Head->DL; // first chapter node will stored here
    //print the chapter and the sections
    while(chapter != NULL) // then traverse the chapter nodes
    {
      cout<<chapter->data<<endl;
      CurrentSection = chapter->DL;
       print(chapter->DL); //pass the section
      //print the subsection
      for(node *temp = CurrentSection ; temp!= NULL ; temp=temp->next)
      {
         print(temp->DL);
        cout<<endl;
      }
      cout<<endl;
      chapter = chapter->next;
    }

  }
  //Function to init a basic node
  node* createnode(string value)
  {
      node *temp = new node;
      temp->data = value;
      temp->next = NULL;
      temp->DL = NULL;
      return temp;
  }

  node* addList (string chap_no , node *Head)
  {
    node *p = new node;
    node *temp = createnode(chap_no);
    cout<<"Created temp node "<<endl;
    if (Head->DL == NULL) {
      Head->DL = temp;
      return temp;
    }else
    {
      cout<<"traverse called "<<endl;
      p =traverse(Head->DL); //send me the last node address only
      p->next = temp;
      return temp;
    }
    cout<<"Node Added !"<<endl;
  }

  //This Function is used to traverse the list and return the last node when the
  //the f is 1 and when f is 0 then only print the nodes in the level
  node* traverse(node *pointer)
  {
      cout<<"Finding position !"<<endl;
      if(pointer->next == NULL){
        cout<<"Pos Found !"<<endl;
        return pointer;
      }         //if there is only one node present
      else{
        while(pointer->next != NULL)
        {
          pointer = pointer->next;  //more than one node present
        }
        cout<<"Pos Found !"<<endl;
        return pointer;
      }
  }

  void print(node *p)
  {
    while(p != NULL)
    {
      cout<<p->data<<" -> ";
      p = p->next;
    }
  }

  //Delete a part of a book
  void remove(){
    int ch;
    cout<<"1.To Delete The Whole Book: "<<endl;
    cout<<"2.To Delete A Chapter"<<endl;
    cout<<"3.To Delete A Section"<<endl;
    cout<<"4.To Delete A Sub-Section"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 1:
            Head = NULL;
      break;
      case 2:
            cout<<"Enter the Chapter you want to delete"<<endl;
            cin>>chap;
            /*Here three outcomes might take place ..
            1.There may be a last chapter middle chapter or starting
            chapter.
            2.So we need to find the position of current Node and call the
            appropiate code to delete the node
            3.When the node is the first it can be found be checking if
            the superior node-DL is == node to be deleted
            4.When the node is at the middle then we can check if the node
            is not pointing at null and != superior->DL
            5.When the node->next == NULL*/
      break;
    }
  }

  void deleteFromBegin(string chapter){}
  void deleteFromMiddle(string node){}
  void deleteFromEnd(string node){}
};

int main()
{
  l obj;
  int ch;
  char status;
  do{
    cout<<"*********MENU********"<<endl;
    cout<<"1.Create Book"<<endl;
    cout<<"2.Display Book"<<endl;
    cout<<"3.Delete A Book"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"*********************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 4: exit(EXIT_SUCCESS);
      case 1: obj.createBook(); break;
      case 2: obj.displayBook(); break;
      case 3: obj.remove(); break;
      default: cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ?"<<endl;
    cin>>status;
  }while(status == 'y' || status == 'Y');
  return 0;
}
