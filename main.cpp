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
void leibnizApproximation(const size_t& NB_ITERATIONS );
template<typename T>
void nilakanthaApproximation(const size_t& NB_ITERATIONS);


int main(){

    //Tests des méthodes de la classe générique Fraction<T>
    Fraction<int> f1(1,2);
    Fraction<int> f2(-3,4);

    //Affichage
    cout << "f1 = " << f1 << "\nf2 = " << f2 << endl;

    //Additions
    cout << "f1 + f2 = " << f1 + f2 << endl;
    f1 += f2;
    cout << "f1 += f2 ; f1 = " << f1 << endl;

    //Multiplication
    cout << "f1 * f2 = " << f1 * f2 << endl;
    f1 *= f2;
    cout << "f1 *= f2 ; f1 = " << f1 << endl;


    //Approximations de PI
    const size_t NB_ITERATIONS = 50;
    cout << "Approximation de Leibniz (int)" << endl;
    leibnizApproximation<int>(NB_ITERATIONS);
    cout<< endl << endl;

    cout << "Approximation de Leibniz (long long)" << endl;
    leibnizApproximation<long long>(NB_ITERATIONS);
    cout << endl << endl;

    cout << "Approximation de Nilakantha (int)" << endl;
    nilakanthaApproximation<int>(NB_ITERATIONS);
    cout<< endl << endl;

    cout << "Approximation de Nilakantha (long long)" << endl;
    nilakanthaApproximation<long long>(NB_ITERATIONS);
    cout << endl;
    return EXIT_SUCCESS;
}

template<typename T>
void leibnizApproximation(const size_t& NB_ITERATIONS ){
    try{
        T numerateur = 4;
        T denumerateur = 1;
        short signe = 1;
        Fraction<T> f1(numerateur,denumerateur);
        size_t i = 1;
        while(i < NB_ITERATIONS){
            cout << "iteration numero " << i << " : " << (double)f1 << endl;
            signe *= -1;
            f1 += Fraction<T>((signe * numerateur),denumerateur+(2*i++)) ;
        }
    }catch( exception& e){
        cout << e.what();
    }
}

template<typename T>
void nilakanthaApproximation(const size_t& NB_ITERATIONS){
    try{
        size_t i = 1;
        T numerateur = 4;
        T denumerateur = 2;
        short signe = -1;
        Fraction<T> f1(3,1);
        while(i < NB_ITERATIONS){
            signe *= -1;
            f1 += Fraction<T>((signe * numerateur),(denumerateur++ * denumerateur++ * denumerateur)) ;
            cout << "iteration numero " << i++ << " : " << (double)f1 << endl;
        }
    }catch( exception& e){
        cout << e.what();
    }
}
