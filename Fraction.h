/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : fraction.h
 Auteur(s)   : Maurice Lehmann
 Date        : 20.03.2019

 But         : Déclaration de la classe génlrique Fraction

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef FRACTION_H
#define FRACTION_H

template<typename T>
class Fraction {

//Fonctions friend
   
//surcharge de l'operateur cast
   //TODO

//Retourne true meme si on compare 2/4 et 1/2 !
//surcharge de l'operateur ==
   //TODO
   
//surcharge de l'opérateur <<
   //TODO
 
//surcharge de l'opérateur +
   //TODO
   
//surcharge de l'opérateur +=
   //TODO
   
//surcharge de l'opérateur *
   //TODO
   
//surcharge de l'opérateur *=
   //TODO

public:
    //Constructeur
    Fraction(const T& denominateur,const T& numerateur){};

    //fonction simplifie, qui retourne uniquement
    Fraction<T> simplifie() const;

    //Test si deux fractions sont "strictement égale" genre : 1/2 et 1/2 oui , mais 1/2 et 2/4 non
    bool identite(const Fraction<T>& f) const;

private:
    T denominateur,numerateur;
};




#include "fractionImpl.h"
#endif //FRACTION_H
