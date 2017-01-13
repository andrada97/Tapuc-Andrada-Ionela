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
               unsigned int miza=0;
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




int DaCarte(int CartiImpartite[])
{int Ok=0;
do{int GasireCarte=(rand()%53);
   if(GasireCarte!=0)
       {Ok=GasireCarte;
        if(CartiImpartite[Ok])
            { if(Ok/4)return Ok/4;
              else return true;
            CartiImpartite[Ok]=0;
            }
   }
}while(true);
}

int AdunareScor(int Carte,int Scor)
{if(Carte<11)Scor=Scor+Carte;
else if(Carte==11 || Carte==12 || Carte==13) Scor=Scor+10;
}

void AfisareCarte(int Carte)
{if(Carte==1)
   {cout<<endl;
       cout<<"    ______    "<<endl;
    cout<<"   |A     |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |_____A|   "<<endl;
   }


     else if(Carte==11)
          { cout<<endl;
              cout<<"    ______    "<<endl;
            cout<<"   |J     |   "<<endl;
            cout<<"   |      |   "<<endl;
            cout<<"   |      |   "<<endl;
            cout<<"   |      |   "<<endl;
            cout<<"   |      |   "<<endl;
            cout<<"   |_____J|   "<<endl;
           }
          else if(Carte==12)
                { cout<<endl;
                    cout<<"    ______    "<<endl;
                  cout<<"   |Q     |   "<<endl;
                  cout<<"   |      |   "<<endl;
                  cout<<"   |      |   "<<endl;
                  cout<<"   |      |   "<<endl;
                  cout<<"   |      |   "<<endl;
                  cout<<"   |_____Q|   "<<endl;
                }
                else if(Carte==13) {cout<<endl;
                        cout<<"    ______    "<<endl;
                       cout<<"   |K     |   "<<endl;
                       cout<<"   |      |   "<<endl;
                       cout<<"   |      |   "<<endl;
                       cout<<"   |      |   "<<endl;
                       cout<<"   |      |   "<<endl;
                       cout<<"   |_____K|   "<<endl;
                      }
                      else
         {cout<<endl;
             cout<<"    ______    "<<endl;
          cout<<"   |"<<Carte<<"     |   "<<endl;
          cout<<"   |      |   "<<endl;
          cout<<"   |      |   "<<endl;
          cout<<"   |      |   "<<endl;
          cout<<"   |      |   "<<endl;
          cout<<"   |_____"<<Carte<<"|   "<<endl;

        }
}


void JocDealer(int CartiImpartite[],int CartiDealer[], int CartiPlayer[],int NrCartiDealer, int NrCartiPlayer, int x, Jucator utilizatori[]  )
{CartiDealer[0]=DaCarte(CartiImpartite);
 CartiPlayer[0]=DaCarte(CartiImpartite);
 CartiDealer[1]=DaCarte(CartiImpartite);
 CartiPlayer[1]=DaCarte(CartiImpartite);
 NrCartiDealer=2;
 NrCartiPlayer=2;
 int ScorPlayer=0;
 int ScorDealer=0;
 cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
 cout<<"*        Black Jack           *"<<endl;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
cout<<endl;
cout<<endl;
cout<<"Banii lui "<<utilizatori[x].NumeUtilizator<<" sunt: "<<utilizatori[x].scor<<endl;
cout<<endl;
cout<<"Stabileste miza jocului:";
int Miza;
cin>>utilizatori[x].miza;
while(utilizatori[x].miza> utilizatori[x].scor)
     {cout<<"Nu ai suficienti bani. Stabileste o alta miza:";
      cin>>utilizatori[x].miza;
      }
Miza=utilizatori[x].miza;
bool Continuare=true;
system("cls");
do{

cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
 cout<<"*        Black Jack           *"<<endl;
cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
cout<<endl;
 cout<<"***Cartile dealer-ului sunt: "<<endl;
 cout<<endl;
 cout<<"Cartea numarul 1 este:   ";
 cout<<endl;
    cout<<"    ______    "<<endl;
    cout<<"   |?     |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |      |   "<<endl;
    cout<<"   |_____?|   "<<endl;
cout<<endl;
for(int i=1;i<NrCartiDealer;i++)
 {cout<<"Cartea numarul "<<i+1<<" este:  ";
       AfisareCarte(CartiDealer[i]);
cout<<endl;
 }
for(int i=0;i<NrCartiDealer;i++)
        ScorDealer=ScorDealer+ AdunareScor(CartiDealer[i],ScorDealer);

 cout<<"***Cartile tale sunt: "<<endl;
 cout<<endl;
 for(int i=0;i<NrCartiPlayer;i++)
 {cout<<"Cartea numarul "<<i+1<<" este:  ";
AfisareCarte(CartiPlayer[i]);
cout<<endl;
 }
  for(int i=0;i<NrCartiPlayer;i++)
        ScorPlayer=ScorPlayer+ AdunareScor(CartiPlayer[i],ScorPlayer);

cout<<"*    Scorul tau este:   " <<ScorPlayer<<endl;


utilizatori[x].scor=utilizatori[x].scor-Miza;

if( NrCartiPlayer==2 && ScorPlayer==21)
    {cout<<"~ BLACKJACK ~"<<endl;
     cout<<" Felicitari ! "<<endl;
    utilizatori[x].scor=utilizatori[x].scor+3/2*Miza;
    cout<<" Scorul tau este acum: "<<utilizatori[x].scor<<" ."<<endl;
    }
int Alegere;
if(utilizatori[x].scor>utilizatori[x].miza)
   {cout<<"\nHit(1)    Stay(2)    Double(3) "<<endl;
    cin>>Alegere;
   }

   else
      {cout<<"\nHit(1)          Stay(2)"<<endl;
    cin>>Alegere;
      }

if(Alegere=='1')
    {CartiPlayer[NrCartiPlayer]=DaCarte(CartiImpartite);
    ++NrCartiPlayer;}
    else if(Alegere=='2') Continuare=false;
         else if((Alegere=='3') && (utilizatori[x].scor>utilizatori[x].miza))
                  {CartiPlayer[NrCartiPlayer++]=DaCarte(CartiImpartite);
                  Continuare=false;
                   utilizatori[x].scor=utilizatori[x].scor-utilizatori[x].miza;
                   utilizatori[x].miza*=2;
                  }
              else cout<<" Raspuns eronat. Incearca din nou ! "<<endl;
ScorPlayer= ScorPlayer+ AdunareScor(CartiPlayer[NrCartiPlayer-1],ScorPlayer);
system("cls");
}while(Continuare==true && ScorPlayer < 22);

if(ScorPlayer>21)
    {cout<<"Ai pierdut ! "<<endl;
    cout<<"Scorul tau acum este:"<<utilizatori[x].scor<<endl;
    }

else
    if(ScorDealer<17)
       while(ScorDealer<17)
            {CartiDealer[NrCartiDealer]=DaCarte(CartiImpartite);
             ++NrCartiDealer;
             ScorDealer=ScorDealer+ AdunareScor(CartiDealer[NrCartiDealer],ScorDealer);
            }
}

void ModalitateJoc(int CartiImpartite[],int CartiPlayer[], int CartiDealer[],int NrCartiDealer,int NrCartiPlayer, int x, Jucator utilizatori[] )
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
        JocDealer(CartiImpartite, CartiDealer,  CartiPlayer, NrCartiDealer, NrCartiPlayer, x, utilizatori);
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
int CartiImpartite[52];
int k=1;
for(int i=0; i<53; i=i+4)
      {if(k==14)break;

       else
          {CartiImpartite[i]=k;
           CartiImpartite[i+1]=k;
           CartiImpartite[i+2]=k;
           CartiImpartite[i+3]=k;
          }
      k++;
      }

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

