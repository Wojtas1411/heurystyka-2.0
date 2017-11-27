#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include"w_lib.h"
#include"utilities.h"

using namespace std;

int num_of_proc=0;
int num_of_elem=0;
int tab_of_elem[1000]={0};


int main()
{
    read_data("m25.txt");

    int avarage_process = sumof(tab_of_elem,num_of_elem)/num_of_elem;;
    int optimal_value_on_processor = sumof(tab_of_elem,num_of_elem)/num_of_proc;
    int avarage_programs_on_processor = optimal_value_on_processor/avarage_process;

    cout<<"Dane instancji"<<endl;
    cout<<avarage_process<<endl;
    cout<<optimal_value_on_processor<<endl;
    cout<<avarage_programs_on_processor<<endl;
    cout<<endl;

    int n,m;
    m=num_of_proc;
    n=num_of_elem;

    ///zachlanny 1
    data_pack test;
    test = default_data_container(test);

    greedy1(test);

    ///zachlanny 2
    data_pack test2;
    test2 = default_data_container(test2);

    greedy2(test2);

    ///kombinowany 1
    data_pack test3;
    test3 = default_data_container(test3);

    heuristics1(test3);

    //print_data_pack(test3);

    ///dziwnyjakis
    data_pack test4;
    test4 = default_data_container(test4);

    prawie_dokladny(test4);

    //print_data_pack(test4);

    ///plecakowy

    data_pack test5;
    test5 = default_data_container(test5);

    plecakowy(test5);

}
