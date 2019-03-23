/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.cpp
 Auteur(s)   : Maurice Lehmann
 Date        : 20.03.2019

 But         : TODO

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include "fraction.h"
using namespace std;


int main(){

    Fraction<int> f1(1,2);
    Fraction<int> f2(2,4);

    cout << (double)f1;

    return EXIT_SUCCESS;
}
