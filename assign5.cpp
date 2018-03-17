/*There are flight paths between cities. If there is a flight between city A and city B then there is
an edge between the cities. The cost of the edge can be the time that flight takes to reach city
B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can
be represented by airport name or name of the city. Use adjacency list representation of the
graph or use adjacency matrix representation of the graph. Justify the storage representation
used.*/

#include<iostream>
#include<stdlib.h>
#define MAX 50
using namespace std;

class Data{
  int n;
  string cities[MAX];
  int cityAdjancent[MAX][MAX];
  int cityTime[MAX][MAX];
public:
  //printing code
  void getCitiesPath()
  {
    //Get the name from the cities !
    cout<<"Enter the number of cities: "<<endl;
    cin>>n;
    for(int i = 0 ; i < n ; i ++)
    {
      cout<<"Enter the city name: "<<endl;
      cin>>cities[i];
    }
    //Get if available Path is available !
    char choice ;
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < n ; j++)
      {
        if(i != j && cityAdjancent[i][j] == 0){
          cout<<"Is path available from "<<cities[i]<<" --> "<<cities[j]<<"[Y/N]"<<endl;
          cin>>choice;
          if(choice == 'Y' || choice == 'y'){
            cityAdjancent[i][j] = 1;
            cityAdjancent[j][i] = 1;
          }
          else{
            cityAdjancent[i][j] = -1;
            cityAdjancent[j][i] = -1;
          }
        }
      }
    }
  }
  void printCities()
  {
    cout<<"Available Paths: "<<endl;
    for(int i = 0 ; i < n ; i++)
      cout<<cities[i]<<"  ";

    cout<<endl;

    for(int i = 0 ; i < n ; i++)
    {
        cout<<cities[i]<<"\t";
        for(int j = 0 ; j < n ; j++)
        {
            cout<<cityAdjancent[i][j]<<"   ";
        }
        cout<<endl;
      }
    }

};
int main()
{
  Data obj;
  int ch;
  char status;
  do{
    system("clear");
    cout<<"***********MENU**************"<<endl;
    cout<<"1.Enter the data for cities: "<<endl;
    cout<<"2.Display the Time taken from cities: "<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"*****************************"<<endl;
    cin>>ch;
    switch (ch) {
      case 3:
        exit(EXIT_SUCCESS);
      case 1:
        obj.getCitiesPath();
      break;

      case 2:
        obj.printCities();
      break;

      default:
        cout<<"Entered Data is invalid !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  }while(status == 'Y' || status == 'y');
  return 0;
}
