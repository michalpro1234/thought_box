
//w trakcie tworzenia korzysta³em z code blocks i internetowego debuggera :https://www.onlinegdb.com

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char z [40];
    string napis;
    int j=1;


    cout<<"Witaj, by przetworzyc plik, upewnij sie,"<<endl
    <<"ze jest w fomacie .htm / .html"<<endl
    <<"i , ze paragrafy w pliku nie posiadaja"<<endl
    <<" atrybutow ani spacji w znaczniku"<<endl
    <<"na przyklad nie wygladaja tak : <p > "<<endl;
    cout<<"tu wpisz PELNA nazwe pliku : ";
    cin>>z;


    fstream ifs;
    ifs.open( z , ios::in );

    ofstream ofs;
    ofs.open ( "wynik.txt", ios::out );


    if (ifs.good() == false)
    {
        cout<<"plik nie istnieje"<<endl;
        return 0;
    }



    while(getline( ifs, napis ))
    {
        size_t pozycja = napis.find( "<title" );
        size_t pozycja_2 = napis.find( "<h1" );
        size_t pozycja_3 = napis.find( "<h2" );
        size_t pozycja_4 = napis.find( "<p" );
        size_t koniec_4 = napis.find( "</p>" );

        if(pozycja != string::npos)
        {
            size_t pozycja = napis.find( ">" );


            int dlugosc=napis.length();


            for(int i=pozycja+1 ; i<dlugosc-8 ; i++)
            {
                ofs<< napis[i];
            }
            ofs<<endl<<endl<<endl;
        }

        if(pozycja_2 != string::npos)
        {
            size_t pozycja_2 = napis.find( ">" );


            int dlugosc=napis.length();


            for(int i=pozycja_2+1 ; i<dlugosc-5 ; i++)
            {
                ofs<< napis[i];
            }
            ofs<<endl<<"-------------------------------"<<endl<<endl<<endl;
        }

        if(pozycja_3 != string::npos)
        {
            size_t ksiazki=napis.find("Bibliografia");

            if(ksiazki == string::npos)
            {
                size_t pozycja_3=napis.find( ">" );


                int dlugosc=napis.length();


                for(int i=pozycja_3+1 ; i<dlugosc-5 ; i++)
                {
                    ofs<< napis[i];
                }
                ofs<<endl<<"-------------------------------"<<endl<<endl<<endl;
            } //koniec if(ksiazki)

        }//koniec if(pozycja_3)

        if(pozycja_4 != string::npos)
        {
            do
            {
                j=1;
                size_t pozycja_4 = napis.find( "<p>" );
                size_t koniec_4 = napis.find( "</p>" );


                if(pozycja_4 != string::npos && koniec_4 == string::npos)
                {
                    int dlugosc=napis.length();


                    for(int i=pozycja_4+3 ; i<dlugosc-4 ; i++)
                    {
                        ofs<< napis[i];
                    }
                    getline(ifs, napis);
                    j=0;
                }
                else if (pozycja_4 == string::npos && koniec_4 == string::npos)
                    {
                        int dlugosc=napis.length();


                        for(int i=0 ; i<dlugosc ; i++)
                        {
                            ofs<< napis[i];
                        }
                        getline(ifs, napis);
                        j=0;

                    }
                    else if (pozycja_4 == string::npos && koniec_4 != string::npos)
                        {
                            int dlugosc=napis.length();


                            for(int i=0 ; i<dlugosc-4 ; i++)
                            {
                                ofs<< napis[i];
                            }
                            ofs<<endl<<endl<<endl;
                        }
                        else if(pozycja_4 != string::npos && koniec_4 != string::npos)
                            {
                                int dlugosc=napis.length();


                            for(int i=pozycja_4+3 ; i<dlugosc-4 ; i++)
                                {
                                    ofs<< napis[i];
                                }
                            ofs<<endl<<endl<<endl;
                            }

            }while(j==0);

        } //koniec if

    }//koniec glownego while
   cout<<"_______________________________________________________________"<<endl;
   cout<<"ZROBIONE!"<<endl
   <<"PRZETWORZONY PLIK ZNAJDZIESZ W TYM SAMYM FOLDERZE, W KTORYM"<<endl
   <<"ZNAJDUJE SIE PROGRAM, POD NAZWA ' wynik.txt '"<<endl;
   cout<<"---------------------------------------------------------------"<<endl;
    ofs.close ();
    ifs.close();


	return 0;
}
