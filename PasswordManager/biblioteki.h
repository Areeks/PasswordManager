#ifndef _biblioteki_h_
#define _biblioteki_h_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include "base64.h"
using namespace std;

struct struktura
{
	string kategoria;
	struct hasla
	{
		int id;
		string nazwa;
		string haslo;
		string status;
	} hasla;
};

int wczytaj(int dolna_granica, int gorna_granica, const char* co);
list<struktura> wczytajPlik(string sciezka, list<struktura> bazaHasel);
bool checkPassword(string pass, int iloscProb);
void zatrzymaj();
void WyswietlHasla(list<struktura> bazaHasel);
void WyswietlKategorie(list<struktura> bazaHasel);
void WyswietlNaglowek();
void DodajHaslo(list<struktura> bazaHasel);
void zapiszPlik(string sciezka, list<struktura> bazaHasel);
list<struktura> dodajHaslo(list<struktura> bazaHasel, int licznik);
list<struktura> usunHaslo(list<struktura> bazaHasel);
int licznikID(list<struktura> bazaHasel);
list<struktura> usunHasloKategoria(list<struktura> bazaHasel);
void WyswietlHaslaKategoria(list<struktura> bazaHasel);
#endif
