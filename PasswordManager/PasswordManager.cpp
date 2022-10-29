#include "biblioteki.h";

const string password = "xyz";
int main()
{
    int choose;
    int licznik;
    if (checkPassword(password, 3))
    {
        list<struktura> bazaHasel;
        bazaHasel = wczytajPlik("D:\\hasla.txt", bazaHasel); // Sciezka do odczytu pliku (zmienic pod siebie)
        do {
            licznik = licznikID(bazaHasel);
            system("cls");
            cout << "Menadzer Hasel\n\n";
            cout << "1. Wyswietl Hasla\n";
            cout << "2. Dodaj haslo\n";
            cout << "3. Usun haslo\n";
            cout << "4. Wyswietl hasla z danej kategorii\n";
            cout << "5. Usun kategorie wraz z haslami\n";
            cout << "0. Zakoncz program!\n\n";
            switch (choose = wczytaj(0, 5, " opcje: "))
            {
            case 1:
                WyswietlHasla(bazaHasel);
                zatrzymaj();
                break;
            case 2:
                bazaHasel = dodajHaslo(bazaHasel, licznik);
                break;
            case 3:
                bazaHasel = usunHaslo(bazaHasel);
                break;
            case 4:
                WyswietlHaslaKategoria(bazaHasel);
                zatrzymaj();
                break;
            case 5:
                bazaHasel = usunHasloKategoria(bazaHasel);
                break;
            }
            system("cls");
            zapiszPlik("D:\\hasla.txt", bazaHasel); // SCIEZKA DO ZAPISU PLIKU (ZMIENIC POD SIEBIE)
        } while (choose != 0);
        
        cout << "Koniec programu!";
        zatrzymaj();
        

        
    }
}


