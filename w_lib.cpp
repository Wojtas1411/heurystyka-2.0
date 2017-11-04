//
// Created by Y700 on 04.11.2017.
//
#include "w_lib.h"
#include "utilities.h"
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int sumof(int tab[], int n) ///suma wszystkich elementów tablicy
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        x+=tab[i];
    }
    return x;
}

int find_lowest_index(int tab[], int start, int fin) ///znajdowanie najmniejszych elementow - pierwszyw wolny procesor
{
    int x=9999999,y=0;
    for(int i=start;i<fin;i++)
    {
        if(tab[i]<x)
        {
            x=tab[i];
            y=i;
        }
    }
    return y;
}

int find_highest_index(int tab[], int start, int fin) ///znajdowanie najwiekszych elementow - calkowity czas wykonania
{
    int x=0,y=0;
    for(int i=start;i<fin;i++)
    {
        if(tab[i]>x)
        {
            x=tab[i];
            y=i;
        }
    }
    return y;
}

void make_local_tab(int tab[], int n) ///kopiowanie elelmentów z tablicy globalnej wartości procesów do lokalnej
{
    for(int i=0;i<n;i++)
    {
        tab[i]=tab_of_elem[i];
    }
}

void greedy1(data_pack &tmp)
{
    printf("Algorytm Zachlanny 1\n");

    for(int i=tmp.proces_start;i<tmp.proces_end;i++)
    {
        tmp.processors_tab[find_lowest_index(tmp.processors_tab,tmp.processors_start,tmp.processors_end)]+=tmp.proces_tab[i];
    }
    printf("Czas trwania procesow %d\n\n",tmp.processors_tab[find_highest_index(tmp.processors_tab,tmp.processors_start,tmp.processors_end)]);
}

void greedy2(data_pack &tmp)
{
    printf("Algorytm Zachlanny 2\n");
    sort(tmp.proces_tab+tmp.proces_start,tmp.proces_tab+tmp.proces_end,greater<int>());
    for(int i=tmp.proces_start;i<tmp.proces_end;i++)
    {
        tmp.processors_tab[find_lowest_index(tmp.processors_tab,tmp.processors_start,tmp.processors_end)]+=tmp.proces_tab[i];
    }
    printf("Czas trwania procesow %d\n\n",tmp.processors_tab[find_highest_index(tmp.processors_tab,tmp.processors_start,tmp.processors_end)]);
}

void greedy2_old(int tab0[], int start0, int end0, int tabp[], int startp, int endp)
{
    printf("Algorytm Zachlanny 2\n");
    sort(tab0+start0,tab0+end0,greater<int>());
    for(int i=start0;i<end0;i++)
    {
        tabp[find_lowest_index(tabp,startp,endp)]+=tab0[i];
    }
    printf("Czas trwania procesow %d\n\n",tabp[find_highest_index(tabp,startp,endp)]);
}

void heuristics1(data_pack &tmp)
{
    printf("Algorytm kombinowany1\n\n");

    /***dziala na podstawie algorytmu zachlannego 2
    algorytm sprawdza ilosc procesorow
    na ktorych srednio musi byc wiecej procesow
    wg wartosci srednich
    nastepnie dzieli procesy i procesory wedlug tych danych
    i osobno przydiela procesy
    jest prostsze niz brzmi z opisu
    zlozonosc mniejsza od zlozonosci sortowania***/

    sort(tmp.proces_tab+tmp.proces_start,tmp.proces_tab+tmp.proces_end);

    int av_proc = sumof(tmp.proces_tab,tmp.proces_end)/(tmp.proces_end-tmp.proces_start);
    int op_proc = sumof(tmp.proces_tab,tmp.proces_end)/(tmp.processors_end-tmp.processors_start);
    int op_on_proc = op_proc/av_proc;
    //podzial procesow
    int p1_size = ((tmp.proces_end-tmp.proces_start)-op_on_proc*(tmp.processors_end-tmp.processors_start))*(op_on_proc+1);
    int p2_size = (tmp.proces_end-tmp.proces_start)-p1_size;
    //cout<<p1_size<<" "<<p2_size<<endl;
    //podzial procesorow
    int p2_size_p = p2_size/op_on_proc;
    int p1_size_p = (tmp.processors_end-tmp.processors_start)-p2_size_p;
    //cout<<p1_size_p<<" "<<p2_size_p<<endl;

    //parzystosc op on proc
    int op_on_proc2;
    if((op_on_proc+1)%2==0)
    {
        op_on_proc2 = op_on_proc+1;
    }
    else
    {
        op_on_proc2 = op_on_proc;
    }

    int tmp1 = p1_size;
    int tmp2 = tmp.proces_start;

    for(int i=tmp.processors_start;i<p1_size_p;i++)
    {
        for(int j=0;j<op_on_proc2;j++)
        {
            if(j%2==0)
            {
                tmp.processors_tab[i]+=tmp.proces_tab[tmp2];
                tmp2++;
            }
            else if(j%2==1)
            {
                tmp.processors_tab[i]+=tmp.proces_tab[tmp1-1];
                tmp1--;
            }
        }
    }
    if(op_on_proc2 == op_on_proc)
    {
        printf("nieistotne poczatek\n\n");
        ///TODO
        greedy2_old(tmp.proces_tab,tmp2,tmp1,tmp.processors_tab,tmp.processors_start,p1_size_p);
        printf("nieistotne koniec\n\n");
    }

    //parzystosc op on proc v2
    if(op_on_proc%2==0)
    {
        op_on_proc2 = op_on_proc;
    }
    else
    {
        op_on_proc2 = op_on_proc-1;
    }

    tmp1=p1_size;
    tmp2=tmp.proces_end;

    for(int i=tmp.processors_start+p1_size_p;i<tmp.processors_end;i++)
    {
        for(int j=0;j<op_on_proc2;j++)
        {
            if(j%2==0)
            {
                tmp.processors_tab[i]+=tmp.proces_tab[tmp1];
                tmp1++;
            }
            else if(j%2==1)
            {
                tmp.processors_tab[i]+=tmp.proces_tab[tmp2-1];
                tmp2--;
            }
        }
    }
    if(op_on_proc2 != op_on_proc)
    {
        printf("nieistotne poczatek\n\n");
        ///TODO
        greedy2_old(tmp.proces_tab,tmp1,tmp2,tmp.processors_tab,p1_size_p,tmp.processors_end);
        printf("nieistotne koniec\n\n");
    }

    printf("Koniec algorytmu kombinowanego\n");
    printf("Czas trwania procesow %d\n\n",tmp.processors_tab[find_highest_index(tmp.processors_tab,tmp.processors_start,tmp.processors_end)]);

}

