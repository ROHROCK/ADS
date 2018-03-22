#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
  public:
  string word;
  string meaning;
  node *next;
  node(){
    next = NULL;
  }
};
class hashClass{
  node *hashTable;
  int s;
public:
    hashClass(int size){
      s = size;
      hashTable = new node[size];
    }
    node* createNode(string word , string meaning) {
      node *temp = new node();
      temp->word = word;
      temp->meaning = meaning;
      return temp;
    }
    int hashFunction(string name)
    {
        int ASCIIAddition= 0;
        for(int i = 0 ; i < name.length() ;  i++)
        {
          ASCIIAddition += name[i];
        }
        return ASCIIAddition%s;
    }
    void insertIntoHashTable()
    {
        string word,meaning;
        cout<<"Enter the word: "<<endl;
        cin>>word;
        cout<<"Enter the meaning: "<<endl;
        cin>>meaning;
        int location = hashFunction(word);
        if(hashTable[location].word.empty())
        {
          //Here the location is empty .. just place it in the hash table
          hashTable[location].word = word;
          hashTable[location].meaning = meaning;
          hashTable[location].next = NULL;
        }else{
          //Collision ocurred !
          node *temp = createNode(word,meaning); //create a node
          node *ptr = &hashTable[location];
          while(ptr->next != NULL){
            ptr = ptr->next;
          }
          ptr->next = temp;
        }
    }


    void deleteWord(){
      string wordToBeDeleted;
      cout<<"Enter the word to be deleted !"<<endl;
      cin>>wordToBeDeleted;
      int location = hashFunction(wordToBeDeleted);
      //The word to be deleted is at the array
      if(wordToBeDeleted == hashTable[location].word){
        //if word is in Hash table default;
        if(!hashTable[location].next){
          //only one word exits...
          cout<<"SINGLE ENTRY"<<endl;
          hashTable[location].word = "";
          hashTable[location].meaning = "";
        }else{
          //chain exits in that particular location and there might be a word in the chain
          cout<<"Multi ENTRY !"<<endl;
          node *ptr = hashTable[location].next;
          hashTable[location].word = ptr->word;
          hashTable[location].meaning = ptr->meaning;
          hashTable[location].next = ptr->next;
          delete(ptr);
        }
      }else{
        //The word exist inside the chain
        /*Possible conditions ... 1.the word to be deleted does not exist in the chain
        2.When the delted word is found then ... check which deletion logic to be used
          i)delete from middle ii)Delete from end */
          node *ptr = &hashTable[location];
          while(ptr != NULL)
          {
            if(ptr->word == wordToBeDeleted)
              break;

            ptr = ptr->next;
          }
          //Delete last node
          //if(!ptr->next)
      }
    }

    void display(){
      string keyWord;
      cout<<"Enter the word to display: "<<endl;
      cin>>keyWord;
      int location = hashFunction(keyWord);
      if(hashTable[location].word.empty())
      {
        //does not exist !
        cout<<"The word does not exist !"<<endl;
      }else if(!hashTable[location].word.empty()){
        cout<<"The word exist !"<<endl;
        if(hashTable[location].word == keyWord)
        {
          cout<<"The meaning is: "<<hashTable[location].meaning<<endl;
          return;
        }else{
          //search in middle
          node *ptr = &hashTable[location];
          while(ptr != NULL){
            if(ptr->word == keyWord)
              break;

            ptr = ptr->next;
        }
        if(ptr->word.empty()){
            cout<<"No such word exist !"<<endl;
            return;
        }else{
          cout<<"The meaning is: "<<ptr->meaning<<endl;
        }
      }
    }
  }
};

int main()
{
  hashClass object(100);
  int ch;
  char status;
  do{
    cout<<"1.Insert word into the dictionary"<<endl;
    cout<<"2.Delete word from the dictionary"<<endl;
    cout<<"3.Display the hash table"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"********************************"<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>ch;
    switch (ch) {
      case 4:
        exit(EXIT_SUCCESS);
      case 1:
        object.insertIntoHashTable();
      break;
      case 2:
        object.deleteWord();
      break;
      case 3:
      object.display();
        break;
      default:
        cout<<"Invalid choice entered !"<<endl;
    }
    cout<<"Do you want to continue ?[Y/N]"<<endl;
    cin>>status;
  }while(status == 'Y' || status == 'y');
  return 0;
}
