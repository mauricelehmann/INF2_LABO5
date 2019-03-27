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
<<<<<<< HEAD
#include "fraction.h"
#include <limits>
using namespace std;


void LeibnizApproximation(const size_t& nbIterations ){
=======
#include "Fraction.h"
using namespace std;


int main(){
    Fraction<int> f1(30, 75);

    cout << f1;
    cout << f1.simplifie();
>>>>>>> 80e9fd9139e980b822dc3a7f0554bd1ba0975c0e
    try{
        int numerateur = 4;
        int denumerateur = 1;
        short signe = 1;
        Fraction<long long> f1(numerateur,denumerateur);

        while(i < 50){
            signe *= -1;
            f1 += Fraction<long long>((signe * numerateur),denumerateur+(2*i++)) ;
        }
        //cout << f1 << endl;
    }catch( exception& e){
        cout << e.what();
    }
}

int main(){

    try{
        size_t i = 1;
        int numerateur = 4;
        int denumerateur = 1;
        short signe = 1;
        Fraction<long long> f1(numerateur,denumerateur);

        while(i < 50){
            signe *= -1;
            f1 += Fraction<long long>((signe * numerateur),denumerateur+(2*i++)) ;
        }
        //cout << f1 << endl;
    }catch( exception& e){
        cout << e.what();
    }

    return EXIT_SUCCESS;
}
