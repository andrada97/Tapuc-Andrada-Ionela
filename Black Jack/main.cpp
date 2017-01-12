#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstring>
struct Jucator{unsigned int scor=0;
               unsigned int valoare=0;
               unsigned int profit=0;
               std :: string NumeUtilizator="";
              };


using namespace std;

void IntrareInJoc(int x, Jucator utilizatori[])
{fstream inDateDeIntrare;
fstream inScor;
string InUtilizator;
string NumeUtilizator;

cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
cout<<"*       Black Jack            *"<<endl;
cout<<"*    Bun venit in joc !       *"<<endl;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
cout<<"* Apasa ENTER pentru a incepe *" << endl;
	cin.get();
system("cls");
Sleep(300);

cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
cout<<"*    Black Jack Utilizator    *"<<endl;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
cout<<endl;
cout<<endl;
cout<<"1.Utilizator nou.\n2.Utilizator existent."<<endl;
cout<<endl;
cout<<"Raspunde prin 1 sau 2:";
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
         Sleep(600);
         }

      cin.sync();
      cin.ignore();
      system("cls");

      cout<<"Felicitari! Te-ai inregistrat cu succes !"<<endl;
      Sleep(700);
      system("cls");
      break;}

case '2':
    {cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
    cout<<"*         Black Jack          *"<<endl;
    cout<<"*     Utilizator existent     *"<<endl;
    cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;

    inDateDeIntrare.open("NumeUtilizator.dat",ios::in);
    cout<<"Introduce numele tau:";
    std::cin>>NumeUtilizator;
    utilizatori[x].NumeUtilizator=NumeUtilizator;

     std::transform(NumeUtilizator.begin(),NumeUtilizator.end(),NumeUtilizator.begin(), ::tolower);

    InUtilizator=NumeUtilizator;
    string line;
    bool gasit=false;

    if(inDateDeIntrare.is_open())
        {while(getline(inDateDeIntrare,line) && !gasit)
              if(line.compare(InUtilizator)==0)gasit=true;
        inDateDeIntrare.close();
        if(gasit!=0)
            {cout<<"Bun venit,  " << NumeUtilizator <<" !"<< endl;
            Sleep(1000);
            system("cls");
            }
        else
            {cout<<"Nu s-a gasit acest utilizator."<<endl;
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


void ModalitateJoc(bool CartiImpartite[],int CartiPlayer[], int CartiDealer[],int NrCartiDealer,int NrCartiPlayer, int x, Jucator utilizatori[] )
{char modalitate;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
 cout<<"*        Black Jack           *"<<endl;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
 cout<<endl;
 cout<<"*   Selectati modul de joc :   *"<<endl;

cout<<"1.Joc cu delear-ul.\n2.Joc intre 2 playeri."<<endl;
cout<<endl;
cout<<"Raspunde prin 1 sau 2 : "<<endl;
cin>>modalitate;

switch(modalitate)
   {case '1':
       {system("cls");
        Sleep(200);
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*         Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        cout<<"* Va incepe jocul cu dealer-ul *"<<endl;
        cout<<"*        Succes !              *"<<endl;
        cout<<endl;
        for(int i=0;i<10;i++)
           {cout<<"~";
           Sleep(400);
           }
        cin.sync();
        cin.ignore();
        system("cls");
     //   JocDealer();
        break;
       }
   case '2':
       {system("cls");
        Sleep(200);
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*         Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        cout<<"*  Va incepe jocul 2 x player  *"<<endl;
        cout<<"*        Succes !              *"<<endl;
        cout<<endl;
        for(int i=0;i<10;i++)
           {cout<<"~";
           Sleep(400);
           }
        cin.sync();
        cin.ignore();
        system("cls");
      //  Joc2playeri();
        break;
       }
   default:
       {break;}
   }



   }

int main()
{time_t qTime;
time(&qTime);
srand(qTime);

int count=0;
bool CartiImpartite[52];
int NrCartiDealer=0;
int CartiDealer[10];
int NrCartiPlayer=0;
int CartiPlayer[10];
int x=0;
const int JUCATORI = 3;
Jucator utilizatori[JUCATORI];

IntrareInJoc(x,utilizatori);

ModalitateJoc( CartiImpartite, CartiPlayer, CartiDealer, NrCartiDealer, NrCartiPlayer, x, utilizatori );
system("pause");
return 0;
}

