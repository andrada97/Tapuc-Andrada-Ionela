#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <vector>

struct Jucator{unsigned int scor=0;
               unsigned int valoare=0;
               unsigned int profit=0;
               std :: string NumeUtilizator="";
              };

void IntrareInJoc(int x, Jucator utilizatori[]);

using namespace std;

int main()
{time_t qTime;
time(&qTime);
srand(qTime);

int count=0;
bool CartiImpartite[52];
int HouseCardCount=0;
int HouseHand[10];
int PlayerCardCount=0;
int PlayerHand[10];
int x=0;
const int JUCATORI = 3;
Jucator utilizatori[JUCATORI];

IntrareInJoc(x,utilizatori);

system("pause");
return 0;
}

void IntrareInJoc(int x, Jucator utilizatori[])
{fstream inDateDeIntrare;
fstream inScor;
string InUtilizator;
string NumeUtilizator;
bool gasit=false;

cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
cout<<"*    Black Jack Utilizator    *"<<endl;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
cout<<endl;
cout<<endl;
cout<<"1.Utilizator nou.\n 2.Utilizator existent."<<endl;
cout<<"Raspundeti prin 1 sau 2:";
char raspuns;
cin>>raspuns;
system("cls");

switch(raspuns)
  {case '1':
      {cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
      cout<<"*         Black Jack          *"<<endl;
      cout<<"*       Utilizator nou        *"<<endl;
      cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
      cout<<endl;
      cout<<endl;
      inDateDeIntrare.open("NumeUtilizator.dat", ios::app);
      inScor.open("Scor.dat", ios::app);
      cout<<"Nume utilizator:";
      std::cin>>NumeUtilizator;

      std::transform(NumeUtilizator.begin(),NumeUtilizator.end(),NumeUtilizator.begin(), ::tolower);

      cout<<endl;
      utilizatori[x].NumeUtilizator=NumeUtilizator;
      utilizatori[x].scor=1000;
      inDateDeIntrare<<NumeUtilizator<<endl;
      inScor<<NumeUtilizator<<endl<<utilizatori[x].scor<<endl;
      inDateDeIntrare.close();
      inScor.close();

      cout<<"Se inregistreaza un nou utilizator...";
      cout<<endl;
      cout<<endl;
      for(int i=0;i<10;i++)
         {cout<<"~";
         Sleep(400);
         }

      cin.sync();
      cin.ignore();
      system("cls");

      cout<<"Felicitari! V-ati inregistrat cu succes !"<<endl;
      Sleep(500);
      system("cls");
      break;}

case '2':
    {cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
    cout<<"*         Black Jack          *"<<endl;
    cout<<"*     Utilizator existent     *"<<endl;
    cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;

    inDateDeIntrare.open("NumeUtilizator.dat",ios::in);
    cout<<"Introduceti numele :";
    std::cin>>NumeUtilizator;
    utilizatori[x].NumeUtilizator=NumeUtilizator;

     std::transform(NumeUtilizator.begin(),NumeUtilizator.end(),NumeUtilizator.begin(), ::tolower);

    InUtilizator=NumeUtilizator;
    string line;
    if(inDateDeIntrare.is_open())
        {while(getline(inDateDeIntrare,line) && !gasit)
              if(line.compare(InUtilizator)==0)gasit=true;
        inDateDeIntrare.close();
        if(gasit!=0)
            {cout<<"Bun venit " << NumeUtilizator << endl;
            Sleep(500);
            system("cls");
            }
        else
            {cout<<"Nu se poate gasi acest utilizator."<<endl;
             IntrareInJoc(x,utilizatori);
        }
    gasit=false;

    inScor.open("Scor.dat", ios::in);
    if(inScor.is_open())
       {while(getline(inScor,line) && !gasit)
           if(line.compare(NumeUtilizator)==0)
           {gasit=true;
           inScor>>utilizatori[x].scor;
           }
        inDateDeIntrare.close();
        inScor.close();

        }

}
  break;}

default:
    {cout<<" Ai introdus un raspuns gresit. Mai incearca."<<endl;
    IntrareInJoc(x,utilizatori);
    break;
        }


  }
  }


