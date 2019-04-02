/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.cpp
 Auteur(s)   : Maurice Lehmann
 Date        : 20.03.2019

 But         : Tester les approximations de PI de leibniz et de Nilakantha
               Et tester les surcharge d'operateur sur les fractions (+, +=, *, *=, ==)
               ainsi que la simplification d'une  fraction et que 2 fractions soient pareil

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip> //boolalpha
#include <cstdlib>
#include "Fraction.h"
#include <limits>
using namespace std;


template <typename T>
void leibnizApproximation(const size_t& NB_ITERATIONS );
template<typename T>
void nilakanthaApproximation(const size_t& NB_ITERATIONS);
template<typename T>
void testsClasseFraction();

int main(){

    //Test de la classes Fraction
    testsClasseFraction<int>();

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

template<typename T>
void testsClasseFraction(){
    //Tests des méthodes de la classe générique Fraction<T>
    Fraction<T> f1(1,2);
    Fraction<T> f2(-3,4);
    Fraction<T> f3(2,4);
    Fraction<T> f4(250,500);

    //Affichage
    cout << "Tests d affichage : " << endl;
    cout << "f1 = " << f1 << "\nf2 = " << f2 << endl << endl;

    //Additions
    cout << "Tests d additions : " << endl;
    cout << "f1 + f2 = " << f1 + f2 << endl;
    f1 += f2;
    cout << "f1 += f2 ; f1 = " << f1 << endl << endl;

    //Multiplication
    cout << "Tests de multiplications : " << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;
    f1 *= f2;
    cout << "f1 *= f2 ; f1 = " << f1 << endl << endl;

    //Identité
    cout << "Test fonction identite : " << endl;
    cout << boolalpha << f3 << " identite avec " << f4 << " = " << f3.identite(f4) << endl << endl;

    //operteur ==
    cout << "Test de l operateur ==  : " << endl;
    cout << boolalpha << f3 << " == " << f4 << " : " << (f3 == f4) << endl << endl;

    //Simplife
    cout << "Test de la fonction simplifie : " << endl;
    cout << f4 << " se simplifie en " << f4.simplifie() << endl << endl << endl;
}
