#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<string> tab;

void zdanie4_1()
{
    int more_zeros = 0;

    for(int i = 0; i < tab.size(); i++ )
    {
        int ilosc_zer = 0, ilosc_jedynek = 0;

        for(int k = 0; k < tab[i].length(); k++ )
        {
            if ( tab[i][k] == '0' ) ilosc_zer++;
            else                    ilosc_jedynek++;
        }
        if ( ilosc_zer > ilosc_jedynek )
            more_zeros++;
    }

    cout << "Liczb majacych wiecej zer niz jedynek: " << more_zeros << endl;
}

void zdanie4_2()
{
    unsigned divide_by_2 = 0, divide_by_8 = 0;

    for( int i = 0; i < tab.size(); i++ )
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

}

void zdanie4_3()
{
    int Min = tab[0].length(), Max = tab[0].length();

    for( int i = 1; i < tab.size(); i++ )
    {
        if ( tab[i].length() < Min )
        {
            Min = tab[i].length();
        }
        else if ( tab[i].length() > Max )
        {
            Max = tab[i].length();
        }
    }

    cout << "Min: " << Min << endl << "Max: " << Max << endl;

    vector <int> vMin, vMax;

    for( int i = 0; i < tab.size(); i++ )
    {
        if ( tab[i].length() == Min )
            vMin.push_back( i );
        else if ( tab[i].length() == Max )
            vMax.push_back( i );
    }

    for ( int i : vMin )
    {
        cout << tab[ i ] << endl;
    }

    cout << endl;

    for ( int i : vMin )
    {
        cout << i << endl;
    }
    cout << endl;

    unsigned pos = 1;

    while( pos < Min )
    {
        bool is_one = true;    /// czy jest jedynka bitowa

        for( int i = 0; i < vMin.size(); i++ )
        {
            //if ( vMin.size == 1 ) break;
            if ( tab[ vMin[i] ][pos] == '0' )
            {
                is_one = false;

                break;
            }
        }

        for( int i = 0; i < vMin.size(); i++ )      /// usuwa
        {
             if ( vMin.size() == 1 ) break;

            if ( tab[ vMin[i] ][pos] == '1' && is_one == false )
            {
                vMin.erase( vMin.begin() + i );
                i--;
            }
        }
        pos++;
    }

    cout << endl;
    for ( int i = 0; i < vMin.size(); i++ )
    {
        cout << vMin[i] << endl;
    }


    cout << "Rozmiar vMin: " << vMin.size() << endl;
    cout << "Rozmiar vMax: " << vMax.size() << endl;
    //for ( int i : vMax )
      //  cout << "Linia max: " << i << endl;
}

int main( int argc, char* arg[] )
{
    string linia;
    fstream plik;

    //ios_base::sync_with_stdio(0);					// wymaganie przez Organizatorów (przyœpiesza strumienie)

    if ( argc < 2 )
    {
       cout << "Nie podano argumentow do programu (Drag & Drop)\nBrak danych." << endl;
       cout << "" << endl;
       cin.ignore();
       getchar();
       return -1;
    }zdanie4_1();
    cout << arg[1] << endl;

        plik.open( arg[1], ios::in );
        if( plik.good() )
        {
            while( !plik.eof() )
            {
                getline( plik, linia);
                tab.push_back( linia );
            }
            plik.close();
        }
        else
        {
            cout << "Blad otwarcia pliku" << endl;
        }

    //zdanie4_1();
    //zdanie4_2();
    zdanie4_3();

    //cin.ignore();
    //getchar();
    return 0;
}
