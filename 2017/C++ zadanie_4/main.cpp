/*
 * Dane z pliku cukier.txt musza zostaæ przygotowane
 * mo¿na u¿yæ ró¿nych narzêdzi np. Excela.
 * Ja u¿y³em edytora notepad++ poni¿ej polecenia.
 *
 * Chc¹c usunac myslnik '-' klikamy przed pierwszym w kolumnie
 * przewijamy plik do koñcza wciskamy Shift + Lewy Alt za myœlnikem.
 * Powinny zostaæ zaznaczona kolumna myœlników, pozosta³o nacisn¹æ spacje.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // std::for_each

using namespace std;

struct sData
{
    int dzien;
    int miesiac;
    int rok;
};

class cTransakcja
{
public:
    sData   data;
    string  nip;
    int     cukier_sprzedany; // w kilogramach
    void posprzataj()
    {
        data.dzien = data.miesiac = data.rok = cukier_sprzedany = 0;
        nip = "";
    }
};

class klient
{
public:
    string nip = "";
    int kupil = 0; // w kilogramach
    klient( string n, int k )
    {
        nip = n;
        kupil = k;
    }
    klient() {};
};

int nip_nr( string nip,  vector <cTransakcja> *transakcje )
{
    for( int i = 0; i < (*transakcje).size(); i++ )
    {
        if ( (*transakcje)[i].nip.compare( nip ) == 0 )
            return i;
    }
    return 0;
}

int main()
{
    // vektory to takie ulepszone tablice
    // mo¿emy dodawaæ elementy, sprawdzaæ rozmiar, same zalety
    vector <cTransakcja> transakcje;

    fstream plik ("cukier.txt", ios::in );

    cTransakcja ostanio_wczytany_rekord;

    while ( true )  // wieczna petla
    {
        cTransakcja buff;

        plik >> buff.data.rok;

        if ( buff.data.rok == 0 )    // prymitywnie sprawdzamy czy dane sie nie wczytuj¹ czyli koniec pliku
            break;

        plik >> buff.data.miesiac;
        plik >> buff.data.dzien;
        plik >> buff.nip;
        plik >> buff.cukier_sprzedany;

        ostanio_wczytany_rekord = buff;

        // potêga u¿ywania wektorow, sproboj zrobiæ coœ takiego na zwyklej tablicy ;)
        transakcje.push_back( buff );
        buff.posprzataj();
    }

    // zobaczmy co siê wczytalo
    /*
    for ( int i = 0; i < transakcje.size(); i++ )
    {
        cout    << transakcje[i].data.rok
        << " "  << transakcje[i].data.miesiac
        << " "  << transakcje[i].data.dzien
        << "\t" << transakcje[i].nip
        << "\t"  << transakcje[i].cukier_sprzedany
        << endl;
    }

    cout << "Wczytano transakcji: " << transakcje.size() << endl;
    */

    // zadanie 4.1
    {
        vector <klient> najlepsi;

        // przypisujemy pierwszych 3 jako najlepszych
        for ( int i = 0; i < 3; i++ )
        {
            najlepsi.push_back(
                               klient ( // rzutowanie na typ kilent, musi byæ taki sam jak tablicy
                                       transakcje[i].nip, transakcje[i].cukier_sprzedany
                                      )
                               );
        }

        for ( int i = 3; i < transakcje.size(); i++ )
        {
            for ( int k = 0; k < najlepsi.size(); k++ )
            {
//                if ( transakcje[i].cukier_sprzedany > najlepsi[k].kupil )
                {
                    if ( najlepsi[k].nip.compare( "847-48-41-699" ) == 0 )
                    {
                        static int a;
                        a++;
                        cout << a << endl;
                    }
                    int nip = 0;
                    if ( nip = nip_nr( najlepsi[k].nip, &transakcje ) )
                    {    // jest ju¿ ten nip w bazie najlepszych, wiêc dodajemy

                        najlepsi[k].kupil += transakcje[nip].cukier_sprzedany;
                        break;
                    }
                    else
                    // jeœli nie ma takiego nip w najlepszych
                    najlepsi.push_back ( klient( transakcje[i].nip,
                                                 transakcje[i].cukier_sprzedany));
                }
            }
//            cout << "Current " << i << " of "<< transakcje.size() << endl;
//            if (i % 100 == 0)   printf( "%.2f\%\n", float(i)/transakcje.size()*100);
        }


        // sortujemy ---------------------------------------------

       klient trio[3]; // trzech wspania³ych, najlepszych klientów

//        for ( int i = 0; i < najlepsi.size(); i++)
//        {
//            cout << najlepsi[i].kupil << endl;
//        }

        for ( int n = 0; n < 3; n++ )
        {
            int top_one_klient_index = 0;
            int zakupiono = 0;

            // zaczynamy od 1 bo linie wczesniej przypisalismy pierwszy element
            for( int i = 0; i < najlepsi.size(); i++ )
            {
                if ( zakupiono < najlepsi[i].kupil )
                {
                    zakupiono = najlepsi[i].kupil;
                    top_one_klient_index = i;
                }
            }

            trio[n] = najlepsi[top_one_klient_index];
            najlepsi.erase(najlepsi.begin() + top_one_klient_index);
            // niestety taka jest sk³adnia na usuniêcie elementu, musi byæ pocz¹tek tablicy + index
        }

        // wypiszmy najlepszych
        for ( int i = 0; i < 3; i++)
        {
            cout << "Klient nr " << i+1 << " w klasyfikacji ogolnej o nr NIP " << trio[i].nip << " kupil " << trio[i].kupil << " kg cukru\n";
        }

        fstream file( "wynik4.txt", ios::out  );
        file << "4.1" << endl <<
        trio[0].kupil << endl <<
        trio[1].kupil << endl <<
        trio[2].kupil << endl;

    } // end of zadanie 4.1




    return 0;
}
