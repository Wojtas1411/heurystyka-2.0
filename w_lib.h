//
// Created by Y700 on 04.11.2017.
//

#ifndef HEURYSTYKA_2_0_W_LIB_H
#define HEURYSTYKA_2_0_W_LIB_H
#include"utilities.h"

int sumof(int tab[], int n); ///suma wszystkich elementów tablicy
int find_lowest_index(int tab[], int start, int fin); ///znajdowanie najmniejszych elementow - pierwszyw wolny procesor
int find_highest_index(int tab[], int start, int fin); ///znajdowanie najwiekszych elementow - calkowity czas wykonania
void make_local_tab(int tab[], int n); ///kopiowanie elelmentów z tablicy globalnej wartości procesów do lokalnej
void greedy1(data_pack &tmp); ///algorytm zachlanny - procesy przydzielane do aktualnie pierwszego wolnego procesora
void greedy2(data_pack &tmp); ///jak powyzszy, tylko sortowane od najwiekszego
void greedy2_old(int tab0[], int start0, int end0, int tabp[], int startp, int endp);

void heuristics1(data_pack &tmp);///heurystyka opracowana przeze mnie :D
#endif //HEURYSTYKA_2_0_W_LIB_H
