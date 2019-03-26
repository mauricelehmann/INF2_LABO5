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
#include "Fraction.h"
using namespace std;


int main(){
    Fraction<int> f1(30, 75);

    cout << f1;
    cout << f1.simplifie();
    try{
        Fraction<int> f1(2,4);
        Fraction<int> f2(1,3);

        cout << f2 + f1;

    }catch( exception& e){
        cout << e.what();
    }

    return EXIT_SUCCESS;
}
