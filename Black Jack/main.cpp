#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstring>
struct Jucator
{
    unsigned int bani=0;
    unsigned int miza=0;
    std :: string NumeUtilizator="";
};
struct Jucatori
{
    unsigned int bani=0;
    unsigned int miza=0;
    int cartijucatori[10];
    int nrcartijucatori;
    std :: string NumeUtilizator="";
};


using namespace std;

void IntrareInJoc(int x, Jucator utilizatori[])
{
    fstream inDateDeIntrare;
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
    {
    case '1':
    {
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
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
        utilizatori[x].bani=1000;
        inDateDeIntrare<<NumeUtilizator<<endl;
        inScor<<NumeUtilizator<<endl<<utilizatori[x].bani<<endl;
        inDateDeIntrare.close();
        inScor.close();

        cout<<"Se inregistreaza un nou utilizator...";
        cout<<endl;
        cout<<endl;
        for(int i=0; i<10; i++)
        {
            cout<<"~";
            Sleep(600);
        }

        cin.sync();
        cin.ignore();
        system("cls");

        cout<<"Felicitari! Te-ai inregistrat cu succes !"<<endl;
        Sleep(700);
        system("cls");
        break;
    }

    case '2':
    {
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
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
        {
            while(getline(inDateDeIntrare,line) && !gasit)
                if(line.compare(InUtilizator)==0)gasit=true;
            inDateDeIntrare.close();
            if(gasit!=0)
            {
                cout<<"Bun venit,  " << NumeUtilizator <<" !"<< endl;
                Sleep(1000);
                system("cls");
            }
            else
            {
                cout<<"Nu s-a gasit acest utilizator."<<endl;
                IntrareInJoc(x,utilizatori);
            }
            gasit=false;

            inScor.open("Scor.dat", ios::in);
            if(inScor.is_open())
            {
                while(getline(inScor,line) && !gasit)
                    if(line.compare(NumeUtilizator)==0)
                    {
                        gasit=true;
                        inScor>>utilizatori[x].bani;
                    }
                inDateDeIntrare.close();
                inScor.close();

            }

        }
        break;
    }

    default:
    {
        cout<<" Ai introdus un raspuns gresit. Mai incearca."<<endl;
        IntrareInJoc(x,utilizatori);
        break;
    }


    }
}




int DaCarte(int CartiImpartite[])
{
    int Ok=0;
    do
    {
        int GasireCarte=(rand()%53);
        if(GasireCarte!=0)
        {
            Ok=GasireCarte;
            if(CartiImpartite[Ok])
            {
                if(Ok/4)return Ok/4;
                else return true;
                CartiImpartite[Ok]=0;
            }
        }
    }
    while(true);
}

int AdunareScor(int CartiJucator[], int NrCartiJucator)
{
    int Scor=0;
    for(int i=0;i<NrCartiJucator;i++)
    {
        if(CartiJucator[i]<11)Scor=Scor+CartiJucator[i];
        else Scor=Scor+10;
    }
    return Scor;
}

void AfisareCarte(int Carte)
{
    if(Carte==1)
    {
        cout<<endl;
        cout<<"    ______    "<<endl;
        cout<<"   |A     |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |_____A|   "<<endl;
    }


    else if(Carte==11)
    {
        cout<<endl;
        cout<<"    ______    "<<endl;
        cout<<"   |J     |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |_____J|   "<<endl;
    }
    else if(Carte==12)
    {
        cout<<endl;
        cout<<"    ______    "<<endl;
        cout<<"   |Q     |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |_____Q|   "<<endl;
    }
    else if(Carte==13)
    {
        cout<<endl;
        cout<<"    ______    "<<endl;
        cout<<"   |K     |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |_____K|   "<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"    ______    "<<endl;
        cout<<"   |"<<Carte<<"     |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |      |   "<<endl;
        cout<<"   |_____"<<Carte<<"|   "<<endl;

    }
}

void Hit(int CartiJucator[],int NrCartiJucator,int CartiImpartite[])
{
    CartiJucator[NrCartiJucator]=DaCarte(CartiImpartite);
    AfisareCarte(CartiJucator[NrCartiJucator]);
}

void AfisareCarti(int CartiJucator[], int NrCartiJucator)
{
    for(int i=0; i<NrCartiJucator; i++)

    {
        const int UrmCarte=CartiJucator[i];
        AfisareCarte(UrmCarte);
    }
    cout<<endl;
}

void MemorareScoruri(int x, Jucator utilizatori[])
{
    fstream inScor;
    string line;
    string NumeUtilizator;
    int scor;
    bool gasit=false;
    NumeUtilizator=utilizatori[x].NumeUtilizator;
    scor=utilizatori[x].bani;
    inScor.open("Scor.dat", ios::in | ios::out );
    while(getline(inScor, line) && !gasit)
    {
        if(line.compare(NumeUtilizator)==0)
        {
            gasit=true;
            inScor<<scor;
        }
    }
    inScor.close();
}

void AfisareFinala(int CartiDealer[],  int NrCartiDealer, int CartiPlayer[],  int NrCartiPlayer)
{
    cout<<"Scorul Dealer-ului : "<< AdunareScor(CartiDealer,NrCartiDealer);
    AfisareCarti(CartiDealer,NrCartiDealer);
    cout<<"Scorul tau: "<<AdunareScor(CartiPlayer,NrCartiPlayer);
    cout<<endl;
}

void JocDealer(int CartiImpartite[],int CartiDealer[], int CartiPlayer[], int NrCartiDealer,  int NrCartiPlayer, int x, Jucator utilizatori[]  )
{
    bool Continua=true;
    char JocNou=1;
    int Miza;
    while(Continua==true)
    {

        CartiDealer[0]=DaCarte(CartiImpartite);
        CartiPlayer[0]=DaCarte(CartiImpartite);
        CartiDealer[1]=DaCarte(CartiImpartite);
        NrCartiDealer=2;
        CartiPlayer[1]=DaCarte(CartiImpartite);
        NrCartiPlayer=2;
        int ScorPlayer=AdunareScor(CartiPlayer,NrCartiPlayer);
        int ScorDealer=AdunareScor(CartiDealer,NrCartiDealer);
        char AlegereJucator;
        bool ContinuareJucator;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*        Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        cout<<endl;
        cout<<"Banii lui "<<utilizatori[x].NumeUtilizator<<" sunt: "<<utilizatori[x].bani<<endl;
        cout<<endl;
        cout<<"Stabileste miza jocului:";
        cin>>Miza;
        system("cls");
        while(utilizatori[x].miza> utilizatori[x].bani)
        {
            cout<<"Nu ai suficienti bani. Stabileste o alta miza:";
            cin>>utilizatori[x].miza;
        }
        system("cls");

        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*        Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        utilizatori[x].bani=utilizatori[x].bani-Miza;
        cout<<" Banii tai: "<<utilizatori[x].bani<<endl;
        cout<<endl;

        do
        {
            cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;

            cout<<"** Randul dealer-ului **"<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"***Cartile dealerului sunt: "<<endl;
            cout<<endl;
            if(NrCartiDealer==2)
            {
                cout<<endl;
                cout<<"    ______    "<<endl;
                cout<<"   |?     |   "<<endl;
                cout<<"   |      |   "<<endl;
                cout<<"   |      |   "<<endl;
                cout<<"   |      |   "<<endl;
                cout<<"   |      |   "<<endl;
                cout<<"   |_____?|   "<<endl;
                cout<<endl;
                AfisareCarte(CartiDealer[1]);
                cout<<endl;
            }
            else AfisareCarti(CartiDealer,NrCartiDealer);
            cout<<"*** Este randul tau ***"<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"***Cartile tale sunt: "<<endl;
            cout<<endl;
            AfisareCarti(CartiPlayer,NrCartiPlayer);

            if( NrCartiPlayer==2 && ScorPlayer==21)
            {
                cout<<"~ BLACKJACK ~"<<endl;
                cout<<" Felicitari ! "<<endl;
                utilizatori[x].bani=utilizatori[x].bani+3/2*Miza;
                cout<<" Scorul tau este acum: "<<utilizatori[x].bani<<" ."<<endl;
            }
            if(utilizatori[x].bani>utilizatori[x].miza)
            {
                cout<<"\nHit(1)    Stay(2)    Double(3) "<<endl;
                cin>>AlegereJucator;
            }

            else
            {
                cout<<"\nHit(1)          Stay(2)"<<endl;
                cin>>AlegereJucator;
            }

            if(AlegereJucator=='1'){

            Hit(CartiPlayer,NrCartiPlayer,CartiImpartite);
            NrCartiPlayer++;
            ScorPlayer = AdunareScor(CartiPlayer,NrCartiPlayer);
            ContinuareJucator = true;
            }
            else if(AlegereJucator=='2'){ ContinuareJucator=false;}
            else if((AlegereJucator=='3') && (utilizatori[x].bani>utilizatori[x].miza))
            {
                Hit(CartiPlayer,NrCartiPlayer,CartiImpartite);
                ContinuareJucator=false;
                utilizatori[x].miza*=2;
            }
            else {cout<<" Raspuns eronat. Incearca din nou ! "<<endl;
            ScorPlayer= AdunareScor(CartiPlayer,NrCartiPlayer);
            }
        }
        while(ContinuareJucator && ScorPlayer<22);

        if(ScorPlayer>21)
        {
            cout<<endl;
            MemorareScoruri(x,utilizatori);
            cout<<"Ai pierdut ! "<<endl;
            cout<<"Dealer-ul a castigat ."<<endl;
            cout<<"Scorul tau acum este:"<<utilizatori[x].bani<<endl;
            AfisareFinala(CartiDealer,NrCartiDealer,CartiPlayer,NrCartiPlayer);
        }

        else
        {
            ScorDealer=AdunareScor(CartiDealer,NrCartiDealer);

            while(ScorDealer<17)
            {
                Hit(CartiDealer,NrCartiDealer,CartiImpartite);
                CartiDealer++;
                ScorDealer=AdunareScor(CartiDealer,NrCartiDealer);
            }

            bool DealerPrins=(ScorDealer > 21);
            if(DealerPrins)
            {
                system("cls");
                cout<<"Ai castigat ! " <<endl;
                Miza=Miza*2;
                utilizatori[x].bani=Miza + utilizatori[x].bani;
                MemorareScoruri(x,utilizatori);
                AfisareFinala(CartiDealer,NrCartiDealer,CartiPlayer,NrCartiPlayer);
            }

            else
            {
                if (ScorDealer<ScorPlayer)
                {
                    system("cls");
                    cout<< "~~~ AI CASTIGAT ~~~" <<endl;
                    Miza=Miza*2;
                    utilizatori[x].bani=Miza+utilizatori[x].bani;
                    cout<<"Ai castigat "<< Miza <<endl;
                     MemorareScoruri(x,utilizatori);
                    AfisareFinala(CartiDealer,NrCartiDealer,CartiPlayer,NrCartiPlayer);

                }

                else if (ScorDealer == ScorPlayer)
                {
                    system("cls");
                    cout<< "** EGALITATE **" <<endl;


                    utilizatori[x].bani = Miza+ utilizatori[x].bani ;
                    MemorareScoruri(x,utilizatori);

                    AfisareFinala(CartiDealer,NrCartiDealer,CartiPlayer,NrCartiPlayer);
                }

                else
                {
                    system("cls");
                    cout<<" Ai pierdut, iar dealer-ul a castigat. "<<endl;
                    MemorareScoruri(x,utilizatori);
                    AfisareFinala(CartiDealer,NrCartiDealer,CartiPlayer,NrCartiPlayer);

                }
            }
        }
        system("pause");
        system("cls");
        cout<<"Incepi o noua runda? "<<endl;
        cout<<"Raspunde cu Da(d) sau Nu(n) . "<<endl;
        cin>>JocNou;

        while(!(JocNou=='d' || JocNou=='n'))
        {
            cout<<" Raspunsul tau nu este valid."<<endl;
            cout<<"Incearca din nou."<<endl;
            cin>>JocNou;
        }
        if(JocNou=='d')
        {
            Continua=true;
            system("cls");
        }
        else Continua=false;
    }

}

/*void Joc2Players(int CartiImpartite[],int x, Jucatori utilizatori[])
{bool Continuare=true;
while(Continuare==true)
{int Miza=0;
int Castig=0;
char StabilireMiza;
cout<<endl;
cout<<"Stabiliti miza de comun acord:"<<endl;
cout<<"  a)20$   b)50$   c)100$      "<<endl;
cout<<"Raspunsul este :"<<endl;
cin>>StabilireMiza;
if(StabilireMiza=='a')Miza=20;
  else if(StabilireMiza=='b')Miza=50;
       else if(StabilireMiza=='c')Miza=100;
            else while(StabilireMiza!='a' && StabilireMiza!='b' && StabilireMiza!='c')
                      {cout<<"endl";
                        cout<<"Raspuns invalid."<<endl;
                        cout<<"Incercati din nou: "<<endl;
                        cin>>StabilireMiza;
                      }
for(int i=0; i<2; i++)
    {utilizatori[i].miza=Miza;
    utilizatori[i].bani=utilizatori[i].bani-Miza;
    Castig=2*Miza;
    char AlegereJucator;
    bool ContinuareJucator=true;
    utilizatori[i].cartijucatori[0]=DaCarte(CartiImpartite);
    utilizatori[i].cartijucatori[1]=DaCarte(CartiImpartite);
    utilizatori[i].nrcartijucatori=2;
    int ScorJucator;
    ScorJucator=AdunareScor(utilizatori[i].cartijucatori,utilizatori[i].nrcartijucatori);
    cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*        Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        cout<<endl;

    cout<<"**** Este randul lui "<<utilizatori[i].NumeUtilizator;
    cout<<endl<<endl;
    cout<<"Bani ramasi ai lui "<<utilizatori[i].NumeUtilizator <<" :"<<utilizatori[i].bani<<endl;

    do{
      cout<<"Scorul lui "<<utilizatori[i].NumeUtilizator<<" :"<<AdunareScor(utilizatori[i].cartijucatori,utilizatori[i].nrcartijucatori)<<endl;
      AfisareCarti(CartiJucator,NrCartiJucator);

      if( NrCartiJucator==2 && ScorJucator==21)
            {
                cout<<"~ BLACKJACK ~"<<endl;
                cout<<" Felicitari ! "<<endl;
                utilizatori[x].bani=utilizatori[x].bani+3/2*Miza;
                cout<<" Scorul lui"<<utilizatori[i].NumeUtilizator<<" este acum: "<<utilizatori[x].bani<<" ."<<endl;
            }
            if(utilizatori[x].bani>utilizatori[x].miza)
            {
                cout<<"\nHit(1)    Stay(2)    Double(3) "<<endl;
                cin>>AlegereJucator;
            }

            else
            {
                cout<<"\nHit(1)          Stay(2)"<<endl;
                cin>>AlegereJucator;
            }

            if(AlegereJucator=='1'){

            Hit(CartiJucator,NrCartiJucator,CartiImpartite);
            NrCartiJucator++;
            ScorJucator = AdunareScor(CartiJucator,NrCartiJucator);
            ContinuareJucator = true;
            }
            else if(AlegereJucator=='2'){ ContinuareJucator=false;}
            else if((AlegereJucator=='3') && (utilizatori[x].bani>utilizatori[x].miza))
            {
                Hit(CartiJucator,NrCartiJucator,CartiImpartite);
                ContinuareJucator=false;
                utilizatori[x].miza*=2;
            }
            else {cout<<" Raspuns eronat. Incearca din nou ! "<<endl;}
              ScorJucator= AdunareScor(CartiJucator,NrCartiJucator);
        }
        while(ContinuareJucator && ScorJucator<22);


}


}


}

*/

void ModalitateJoc(int CartiImpartite[],int CartiPlayer[], int CartiDealer[],int NrCartiDealer,int NrCartiPlayer, int x, Jucator utilizatori[] )
{
    char modalitate;
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
    {
    case '1':
    {
        system("cls");
        Sleep(200);
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*         Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        cout<<"* Va incepe jocul cu dealer-ul *"<<endl;
        cout<<"*        Succes !              *"<<endl;
        cout<<endl;
        for(int i=0; i<10; i++)
        {
            cout<<"~";
            Sleep(400);
        }
        cin.sync();
        cin.ignore();
        system("cls");
        JocDealer(CartiImpartite, CartiDealer,  CartiPlayer, NrCartiDealer, NrCartiPlayer, x, utilizatori);
        break;
    }
    case '2':
    {
        system("cls");
        Sleep(200);
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<"*         Black Jack           *"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout<<endl;
        cout<<"*  Va incepe jocul 2 x player  *"<<endl;
        cout<<"*        Succes !              *"<<endl;
        cout<<endl;
        for(int i=0; i<10; i++)
        {
            cout<<"~";
            Sleep(400);
        }
        cin.sync();
        cin.ignore();
        system("cls");
/*          Joc2Players(CartiImpartite,CartiPlayer,NrCartiPlayer,x,utilizatori);*/
        break;
    }
    default:
    {
        break;
    }
    }
}

int main()
{
    time_t qTime;
    time(&qTime);
    srand(qTime);
    int CartiImpartite[52];
    int k=1;
    for(int i=0; i<53; i=i+4)
    {
        if(k==14)break;

        else
        {
            CartiImpartite[i]=k;
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

