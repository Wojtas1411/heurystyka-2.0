//
// Created by Y700 on 04.11.2017.
//

#include"utilities.h"
#include<fstream>
#include<stdio.h>
using namespace std;

void read_data(std::string filename)///wczytywanie danych do zmiennych globalnych
{
    printf("Reading data started\n");
    ifstream in;
    double counter = 0.1;
    in.open(filename.c_str());
    in>>num_of_proc;      ///ilocs procesorow
    in>>num_of_elem;      ///ilocs procesow
    for(int i=0;i<num_of_elem;i++)
    {
        in>>tab_of_elem[i];    ///wartosci procesow
        if(double(i)/num_of_elem>counter){printf(".");counter+=0.1;} ///wyswietlanie postepu procesu wczytywania - przydatne dla wiekszych instancji
    }
    in.close();
    printf(".\nReading data finished\n");
}

data_pack default_data_container(data_pack tmp)
{
    tmp.processors_end = num_of_proc;
    tmp.proces_end = num_of_elem;
    for(int i=0;i<tmp.proces_end;i++)
    {
        tmp.proces_tab[i] = tab_of_elem[i];
    }
    return tmp;
}
void print_data_pack(data_pack tmp)
{
    printf("\n\n--------------------\n\n");
    printf("Proces start:     %d\n",tmp.proces_start);
    printf("Proces end:       %d\n",tmp.proces_end);
    printf("Processors start: %d\n",tmp.processors_start);
    printf("Processors end:   %d\n",tmp.processors_end);
    printf("\n--------------------\n\n");
    printf("Print proceses:\n");
    for(int i=tmp.proces_start;i<tmp.proces_end;i++)
    {
        printf("%d. %d\n",i,tmp.proces_tab[i]);
    }
    printf("\n--------------------\n\n");
    printf("Print processors:\n");
    for(int i=tmp.processors_start;i<tmp.processors_end;i++)
    {
        printf("%d. %d\n",i,tmp.processors_tab[i]);
    }
    printf("\n--------------------\n\n");
}
void copy_tab (int tab1[], int tab2[], int p, int n)
{
    if(p>n)printf("\nCopying tab error!\n\n");
    else
    {
        for (int i=p;i<n;i++)
        {
            tab2[i] = tab1[i];
        }
    }

}
