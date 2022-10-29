#include "biblioteki.h"

int wczytaj(int dolna_granica, int gorna_granica, const char* co)
{
	int wartosc;
	cout << "Podaj " << co << " z zakresu " << dolna_granica << ", " << gorna_granica << endl;
	cin >> wartosc;
	while ((wartosc < dolna_granica) || (wartosc > gorna_granica))
	{
		cout << "Podana liczba jest spoza zakresu. Wczytaj ja ponownie:" << endl;
		cin >> wartosc;
	}
	return wartosc;

}

list<struktura> wczytajPlik(string sciezka, list<struktura> bazaHasel)
{
    string line = " ";
    ifstream readFile(sciezka);
    string nazwa;
    string haslo;
    string kategoria;
    string rodzaj;
    int i = 1;
    while (getline(readFile, line)) {

        stringstream iss(line);
        iss >> nazwa >> haslo >> kategoria >> rodzaj;
        struktura zaczytana = {base64_decode(kategoria) };
        zaczytana.hasla = {i, base64_decode(nazwa), base64_decode(haslo), base64_decode(rodzaj) };
        bazaHasel.push_back(zaczytana);
        i++;
    }
    readFile.close();
    return bazaHasel;
}

list<struktura> dodajHaslo(list<struktura> bazaHasel, int licznik)
{
    string nazwa;
    string haslo;
    string kategoria;
    string rodzaj;
    int i = licznik+1;
    cout << "Podaj nazwe: ";
    cin >> nazwa;
    cout << "Podaj haslo: ";
    cin >> haslo;
    cout << "Podaj kategorie: ";
    cin >> kategoria;
    cout << "Podaj rodzaj: ";
    cin >> rodzaj;

        struktura zaczytana = { kategoria };
        zaczytana.hasla = { i, nazwa, haslo, rodzaj };
        bazaHasel.push_back(zaczytana);

    return bazaHasel;
}

list<struktura> usunHaslo(list<struktura> bazaHasel)
{
    int i;
    cout << "Podaj ID hasla do skasowania: ";
    cin >> i;
    
    list<struktura>::iterator itri = bazaHasel.begin();
    while (itri != bazaHasel.end())
    {
        if (itri->hasla.id == i)
        {
            bazaHasel.erase(itri++);
        }

        else
        {
            ++itri;
        }
    }
    cout << "Haslo skasowane pomyslnie!";
    zatrzymaj();
    return bazaHasel;
}

list<struktura> usunHasloKategoria(list<struktura> bazaHasel)
{
    string kategoria;
    cout << "Podaj Kategorie hasla do skasowania: ";
    cin >> kategoria;

    list<struktura>::iterator itri = bazaHasel.begin();
    while (itri != bazaHasel.end())
    {
        if (itri->kategoria == kategoria)
        {
            bazaHasel.erase(itri++);
        }

        else
        {
            ++itri;
        }
    }
    cout << "Hasla skasowane pomyslnie!";
    zatrzymaj();
    return bazaHasel;
}


void zapiszPlik(string sciezka, list<struktura> bazaHasel)
{
    ofstream saveFile(sciezka, ofstream::out);
    for (auto v : bazaHasel)
    {
        saveFile << base64_encode(v.hasla.nazwa) << " " << base64_encode(v.hasla.haslo) << " " << base64_encode(v.kategoria) << " " << base64_encode(v.hasla.status) << "\n";
    }
    saveFile.close();
}


bool checkPassword(string pass, int iloscProb) {
    string password;
    int i = iloscProb;
    while (i > 0 && pass != password)
    {
        cout << "Pozostaly " << i << " proby!" << endl;
        cout << "Wprowadz haslo do programu:";
        cin >> password;
        i--;
    } 
    if (i == 0)
    {
        cout << "Przekroczono limit prob hasla! - Nastapi zakoczenie programu!";
        zatrzymaj();
        return false;
    }
    else {
        cout << "Pomyslnie zalogowano!";
        zatrzymaj();
        return true;
    }
}

void zatrzymaj()
{
    cin.get();
    cin.get();
}

void WyswietlHasla(list<struktura> bazaHasel)
{
    system("cls");
    WyswietlNaglowek();
    for (auto v : bazaHasel)
    {
        cout << setw(5) << v.hasla.id << setw(10) << v.hasla.nazwa << setw(10) << v.hasla.haslo << setw(10) << v.kategoria << setw(10) << v.hasla.status << "\n";
    }
}

void WyswietlHaslaKategoria(list<struktura> bazaHasel)
{
    string kategoria;
    system("cls");
    cout << "Podaj kategorie do wyswietlenia: ";
    cin >> kategoria;
    WyswietlNaglowek();
    for (auto v : bazaHasel)
    {
        if(v.kategoria == kategoria)
        cout << setw(5) << v.hasla.id << setw(10) << v.hasla.nazwa << setw(10) << v.hasla.haslo << setw(10) << v.kategoria << setw(10) << v.hasla.status << "\n";
    }
}

int licznikID(list<struktura> bazaHasel)
{
    int licznik = 0;
    for (auto v : bazaHasel)
    {
        licznik++;
    }

    return licznik;
}

void WyswietlKategorie(list<struktura> bazaHasel)
{
    string kategoria;
    cout << "Wprowadz kategorie: ";
    cin >> kategoria;
    for (auto v : bazaHasel)
    {
        if (v.kategoria == kategoria)
        {
            WyswietlNaglowek();
            cout << setw(5) << v.hasla.id << setw(10) << v.hasla.nazwa << setw(10) << v.hasla.haslo << setw(10) << v.kategoria << setw(10) << v.hasla.status << "\n";
        }
    }
    zatrzymaj();
    system("cls");
}

void WyswietlNaglowek()
{
   cout << setw(5) << "ID" << setw(10) << "Nazwa" << setw(10) << "Haslo" << setw(10) << "Kategoria" << setw(10) << "Status" << "\n";
}

void DodajHaslo(list<struktura> bazaHasel)
{
    string kategoria;
    cout << "Podaj kategorie hasla: ";
    cin >> kategoria;
 
}