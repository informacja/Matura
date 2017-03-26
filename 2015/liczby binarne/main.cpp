#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

int main( int argc, char* arg[] )
{
    string linia;
    fstream plik;
    vector<string> tab;
    unsigned divide_by_2 = 0, divide_by_8 = 0;

    //ios_base::sync_with_stdio(0);					// wymaganie przez Organizatorów (przyœpiesza strumienie)

    if ( argc < 2 )
    {
       cout << "Nie podano argumentow do programu (Drag & Drop)\nBrak danych." << endl;
       cout << "" << endl;
       cin.ignore();
       getchar();
       return -1;
    }
    cout << arg[1];

        plik.open( arg[1], ios::in);
        if( plik.good() )
        {
            while( !plik.eof() )
            {
                getline( plik, linia);
                tab.push_back( linia );
            }
            plik.close();
        }

        for(int i = 0; i < tab.size(); i++ )
        {
            if ( tab[i][ tab[i].length()-1 ] == '0' )
            {
                divide_by_2++;
                if ( tab[i][ tab[i].length()-2 ] == '0' )
                    if ( tab[i][ tab[i].length()-3 ] == '0' )
                        divide_by_8++;
            }
            //cout << tab[i] << endl; //wyœwietlenie linii
        }

        cout << "\nPlik ma " << tab.size() << " lini" << endl;
        cout << "Liczb podzielnych przez 2: " << divide_by_2 << endl;
        cout << "Liczb podzielnych przez 8: " << divide_by_8 << endl;

    //cin.ignore();
    //getchar();
    return 0;
}
