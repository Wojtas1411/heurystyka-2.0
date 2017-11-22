//
// Created by Y700 on 04.11.2017.
//

#ifndef HEURYSTYKA_2_0_UTILITIES_H
#define HEURYSTYKA_2_0_UTILITIES_H
#include<string>
//using namespace std;

///paczka utilities - zawiera elemnty u¿ytkowe

///zmienne globalne do ktorych wczytywane s¹ dane instancje
extern int num_of_proc;   ///liczba procesorow
extern int num_of_elem;   ///liczba procesow - elementow
extern int tab_of_elem[1000];    ///wartosci poszczegolnych procesow - elementow

struct data_pack   ///struktura w ktorej przechowywane sa wejsciowe parametry funkcji
{
    int proces_tab[10000]={0}; /// tablica wartosci procesow
    int processors_tab[1000]={0};  ///tablica wartosci procesorow
    int proces_start=0; /// proces od ktorego zaczynamy
    int proces_end=0; ///proces na ktorym konczymy
    int processors_start=0; ///procesor od ktorego zaczynamy
    int processors_end=0; ///procesor na ktorym konczymy
    ///taka ilosc danych jest niezbedna do ewentulanej parametryzacji funkcji
};

void read_data(std::string filename); ///funkcja odczytuje dane z pliku (argument) i zapisuje je do zmiennych globalnych
data_pack default_data_container(data_pack tmp); ///laduje do struktury podstawowe informacje
void print_data_pack(data_pack tmp); ///wyswietla cala strukture
void copy_tab (int tab1[], int tab2[],int p, int n); ///kopiuje komorki z tab1 do tab2 od p do n
#endif //HEURYSTYKA_2_0_UTILITIES_H
