//projekt tworzony w code blocks, MICHAŁ MAŁKOWSKI, 175895
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int tab_pol [7] [7];

void tytul();
void menu_startowe();
void zasady();
void start ();
void gra ();
int losowanie_gracza();
void ruch_gracza ();
void wypisz_tab();
void ruch_komputera();
void sprawdzenie_kolumny(int n, int v);
int wygrana();
int pion();
int poziom();
int skos();
void menu_k();
void czyszczenie();

int main()
{
    menu_startowe();
    cin.sync();
cin.get();
return 0;
}

void menu_startowe (void)
{
    int n=1;

    while (n!=0)
    {
        tytul();
        cout<<"Wybierz opcje"<<endl;
        cout<<"1. Start gry"<<endl;
        cout<<"2. Zasady gry"<<endl;
        cout<<"0. koniec programu"<<endl;
        cin>>n;
        switch (n)
        {
            case 1 : start(); n=0; break;
            case 2 : zasady(); break;
            case 0 : cout<<"0"; break;
            default : cout<<"                                   NIE MA TAKIEJ OPCJI!"<<endl<<endl; break;
        }
    }
}
void tytul (void)
{
    cout<<"-------------------------------"<<endl;
    cout<<"  PSEUDO KOLKO I KRZYZYK  "<<endl;
    cout<<"-------------------------------"<<endl;
}
void zasady (void)
{
    cout<<"W grze bierze udzial dwoch graczy."<<endl<<
    "Gracze na zmiane umieszczaja swoje krazki na planszy"<<endl<<
    "(uzytkownik 'C', komputer 'B')"<<endl<<
    "tak, ze krazki spadaja na dol tabeli."<<endl<<
    "By wygrac uloz swoje cztery krazki"<<endl<<
    "w lini: skosnej, poziomej lub pionowej."<<endl<<
    "PO PRAWEJ STRONIE BEDA WYSWIETLANE KOMUNIKATY."<<endl<<
    "ZWROC UWAGE, CZY SA WIDOCZNE W KONSOLI!"<<endl;
    cout<<endl;
}
void start (void)
{
    int m;
    cout<<"Wybierz opcje"<<endl;
    cout<<"1. zacznij"<<endl;
    cout<<"0. wroc"<<endl;
    cin>>m;

    if (m==0) menu_startowe();
    else if (m<0 || m>1) cout<<"                                   NIE MA TAKIEJ OPCJI!"<<endl;
        else gra();
}
void gra (void)
{
    int i=0;
    czyszczenie();
    losowanie_gracza();
    if (losowanie_gracza()==1)
    {
        cout<<"                                   ZACZYNA UZYTKOWNIK"<<endl;

        for(i=1; i<10; i++)
        {
            wypisz_tab();
            ruch_gracza();
            wypisz_tab();
            ruch_komputera();


    }
    }
    else
    {
        cout<<"                                   ZACZYNA KOMPUTER"<<endl;

        for(i=1; i<10; i++)
        {
            wypisz_tab();
            ruch_gracza();
            wypisz_tab();
            ruch_komputera();


    }
    }
        menu_k();
    }
    int losowanie_gracza ()
{
    int x;
    srand(time( NULL ) );
    x =( rand())%2+0;
    return x;
}
void sprawdzenie_kolumny(int n,int v)
{
    int i=6;
    do
    {
        if (tab_pol[i][n]==0)
        {
            tab_pol[i][n]=v;
            i=-1;
        }
        else
        {
            i--;
            if(i==-1)
            {
                if(v=1)
                    {
                        cout<<"                                   KOLUMNA JEST PELNA! WYBIERZ INNA : "<<endl;
                        cin>>n;
                        sprawdzenie_kolumny(n,v);

                    }
                else
                    if(v=2) ruch_komputera();
            }
        }
    }
    while(i>-1);

    }
void ruch_komputera()
{
    const int v=2;
    int z;
    srand(time( NULL ) );
    z =( rand())%6+0;
    cout<<"                                   KOMPUTER WYBIERA "<< z <<" KOLUMNE";
    switch (z)
    {
        case 0: sprawdzenie_kolumny(z,v); break;
        case 1: sprawdzenie_kolumny(z,v); break;
        case 2: sprawdzenie_kolumny(z,v); break;
        case 3: sprawdzenie_kolumny(z,v); break;
        case 4: sprawdzenie_kolumny(z,v); break;
        case 5: sprawdzenie_kolumny(z,v); break;
    }
    cout<<"                                   ZMIANA AKTYWNEGO GRACZA.";
}
void ruch_gracza (void)
{
    const int v=1;
    int m=0;
    int x;
    cout<<"                                   WYBIERZ KOLUMNE :"<<endl;

    do
    {
        cin>>x;
        cout<<"                                   UZYTKOWNIK WYBIERA "<<x<<" KOLUMNE";
        m=0;
        switch (x)
        {
            case 0: sprawdzenie_kolumny(x,v); break;
            case 1: sprawdzenie_kolumny(x,v); break;
            case 2: sprawdzenie_kolumny(x,v); break;
            case 3: sprawdzenie_kolumny(x,v); break;
            case 4: sprawdzenie_kolumny(x,v); break;
            case 5: sprawdzenie_kolumny(x,v); break;
            default: cout<<"                                   NIE MA TAKIEJ KOLUMNY, WYBIERZ PONOWNIE"<<endl; m=1; break;
        }
    }while(m==1);
    cout<<"                                   ZMIANA AKTYWNEGO GRACZA.";
}
void wypisz_tab()
{
    tytul();
    for(int i=0 ; i<7 ; i++)
    {
        for(int j=0 ; j<7 ; j++)
        {
            if(tab_pol[i][j]==0) cout<<"| ";
            else if(tab_pol[i][j]==1) cout<<"|C";
           else cout<<"|B";
        }
        cout<<endl;
    }
    cout<<" 0 1 2 3 4 5";
    cout<<endl<<endl;
    wygrana();
}
void menu_k()
{
    int m;
    cout<<"Wybierz opcje"<<endl;
    cout<<"1. powrot do menu"<<endl;
    cout<<"0. zagraj ponownie"<<endl;
    cin>>m;

    if (m==1) menu_startowe();
    else if (m<0 || m>1) cout<<"                                   NIE MA TAKIEJ OPCJI!"<<endl;
         else if (m==0)
         {
             czyszczenie();
             gra();
         }
}
void czyszczenie (void)
{
    for(int i=0 ; i<7 ; i++)
        for(int j=0 ; j<7 ; j++)
            tab_pol[i][j]=0;
}
int wygrana(void)
{
/* funkcja, ktora wychodzila z petli for w fukcji 'gr'"a tym samym obwieszczajac zwycieztwo*/
}
