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
#include <limits>
using namespace std;


template <typename T>
void LeibnizApproximation(const size_t& NB_ITERATIONS );


int main(){

    cout << "Fraction en int: " << endl;
    LeibnizApproximation<int>(50);
    cout<< endl << endl;

    cout << "Fraction en long long: " << endl;
    LeibnizApproximation<long long>(50);
    cout << endl;
    return EXIT_SUCCESS;
}

template<typename T>
void test(const sizet& NB_ITERATIONS) {
    try{
    size_t i = 1;
    int numerateur = 4;
    int denumerateur = 1;
    short signe = 1;
    Fraction<T> f1(numerateur,denumerateur);

    while(i < NB_ITERATIONS){
        signe *= -1;
        f1 += Fraction<T>((signe * numerateur),denumerateur+(2*i++)) ;
        cout << "iteration numero " << i << " : " << (double)f1 << endl;
    }

    }catch( exception& e){
        cout << e.what();
    }

}

template<typename T>
void LeibnizApproximation(const size_t& NB_ITERATIONS ){
    try{
        size_t i = 1;
        int numerateur = 4;
        int denumerateur = 1;
        short signe = 1;
        Fraction<T> f1(numerateur,denumerateur);

        while(i < NB_ITERATIONS){
            signe *= -1;
            f1 += Fraction<T>((signe * numerateur),denumerateur+(2*i++)) ;
            cout << "iteration numero " << i << " : " << (double)f1 << endl;
        }

    }catch( exception& e){
        cout << e.what();
    }
}