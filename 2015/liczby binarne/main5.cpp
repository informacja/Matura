#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#define SAVE

using namespace std;

struct ludnosc
{
    unsigned kobiet;
    unsigned mezczyzn;
};

class cWoj
{
public:
    int nr;
    char region;
    ludnosc r2013;
    ludnosc r2014;


};

vector<cWoj> tab;

void zdanie5_1()
{



#ifdef SAVE
    fstream file( "wynik5.txt", ios::out );
    file << "5.1\n"  << endl;
#endif // SAVE
}

void zdanie4_2()
{


#ifdef SAVE
    fstream file( "wynik5.txt", ios::out | ios::app );
    file << "5.2\n" << endl;
#endif // SAVE
}

// ------------------------------------------------------------------------

void zdanie4_3()
{


#ifdef SAVE
    fstream file( "wynik5.txt", ios::out | ios::app );
    file << "5.3\n" << endl;
#endif // SAVE

}

int main( int argc, char* arg[] )
{
    string linia;
    fstream plik;

//    ios_base::sync_with_stdio(0);					// wymaganie przez Organizatorów (przyœpiesza strumienie)

    fstream dane( "kraina_excel.txt", ios::in );

    if ( dane.is_open() )
    {
        cWoj buff;

        while ( buff.nr != "" )
        {
            string atrapa;
            getline( dane, atrapa );



            dane >> buff.nr;
            dane >> buff.region;
            dane >> buff.r2013.kobiet;
            dane >> buff.r2013.mezczyzn;
            dane >> buff.r2014.kobiet;
            dane >> buff.r2014.mezczyzn;

            tab.push_back( buff );
            cout << tab.size() << endl;
        }
        dane.close()
    }


    cout << "numer: " << tab[0].nr;
//

    zdanie5_1();
//    zdanie5_2();
//    zdanie5_3();

    //cin.ignore();
    //getchar();
    return 0;
}
