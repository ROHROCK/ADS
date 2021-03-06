#include<iostream>
#include<stdlib.h>
#define SIZE 101
using namespace std;
//find the hash using ASCII value
class name{
public:
  string name;
  int loc;
};

class hashing
{
  string hashTable[SIZE];
  double size;
  string SKey;
  string key;
  string n;
  name *nameptr;
public:
  hashing(){
    nameptr = new name[SIZE];
    // for(int i = 0 ; i < SIZE ; i++)
    //   hashTable[i] = '\0';
  }
  void getKey(){
    cout<<"Enter the name: "<<endl;
    cin>>n;
    cout<<"Enter the Key to be inserted in the hash table: "<<endl;
    cin>>key;
  }
  int hash()
  {
    char firstCharASCII = n[0];
    //cout<<"Test: "<<n[0]<<endl;
    return (firstCharASCII % SIZE-1); //works for lower case alphabets (range less than 100)
  }
  void insertIntoHashTable(){
    getKey();
    int location = hash();
    //location = location%100;
    cout<<key<<endl;
    if(hashTable[location].empty())
    {
      nameptr[location].name = this->n;
      nameptr[location].loc = location;
      hashTable[location] = key;
      cout<<"Number Successfully Entered Into the Hash Table !"<<endl;
    }else{
      //collision occured
      while(location < SIZE -1)
        if(hashTable[++location].empty())
          break;

      if(location == SIZE - 1)
      {
        cout<<"Sorry the Hash table is FULL !"<<endl;
        return;
      }
      nameptr[location].name = this->n;
      nameptr[location].loc = location;
      hashTable[location] = key;
      cout<<"Number Successfully Entered Into the Hash Table !"<<endl;
    }
  }

  void displayHashTable()
  {
    cout<<"ID---------- VALUE-----"<<endl;
    for(int i = 0 ; i < SIZE ; i++)
      cout<<i<<"\t"<<hashTable[i]<<endl;
  }

  void searchKey()
  {
    string name;
    cout<<"Enter the name: "<<endl;
    cin>>name;
    for(int i = 0 ; i < SIZE ; i++){
      if(name == (nameptr[i].name))
      {
        cout<<"Found !"<<endl<<"Number: "<<hashTable[nameptr[i].loc];
        return;
      }
    }
    cout<<"NOT FOUND !"<<endl;
  }
};

int main()
{
  hashing obj;
  int ch;
  char status;
  do{
    system("clear");
    cout<<"***********MENU**************"<<endl;
    cout<<"1.Enter the phone number: "<<endl;
    cout<<"2.Display the hash table : "<<endl;
    cout<<"3.Search the phone number: "<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"*****************************"<<endl;
    cin>>ch;
    switch (ch) {
      case 4:
        exit(EXIT_SUCCESS);
      case 1:
        obj.insertIntoHashTable();
      break;
      case 2:
        obj.displayHashTable();
      break;
      case 3:
        obj.searchKey();
      break;

      default:
        cout<<"Entered Data is invalid !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  }while(status == 'Y' || status == 'y');
  return 0;
}
