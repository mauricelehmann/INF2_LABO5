/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : fraction.h
 Auteur(s)   : Maurice Lehmann
 Date        : 20.03.2019

 But         : Déclaration de la classe générique Fraction

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream> //ostream

//Pré-déclaration de la classe, pour pré-déclarer correctement les surcharges opérateurs
template<typename T> class Fraction;

template<typename T>
std::ostream& operator << (std::ostream& os, const Fraction<T>& f);

template<typename T>
bool operator == (std::ostream& os, const Fraction<T>& f);

template<typename T>
Fraction<T> operator + (Fraction<T> lhs, Fraction<T>& rhs );

template<typename T>
Fraction<T> operator * (Fraction<T> lhs, Fraction<T>& rhs );


template<typename T>
class Fraction {
    //Fonctions friend
    friend std::ostream& operator << <T>(std::ostream& os, const Fraction<T>& f);
    //surcharge de l'operateur cast
    //Retourne true meme si on compare 2/4 et 1/2 !
    //surcharge de l'operateur ==
    friend bool operator == <T>(std::ostream& os, const Fraction<T>& f);
    //surcharge de l'opérateur +
    friend Fraction<T> operator + <T>(Fraction<T> lhs, Fraction<T>& rhs );
    //surcharge de l'opérateur *
    friend Fraction<T> operator * <T>(Fraction<T> lhs, Fraction<T>& rhs );

public:

   //surcharge de l'opérateur +=
   Fraction<T>& operator += (Fraction<T> rhs);
   //surcharge de l'opérateur *=
   Fraction<T>& operator *= (const Fraction<T>& rhs);
   //surcharge de l'operateur cast (typename)
   operator double() const;

    //Constructeur
    Fraction(const T& numerateur,const T& denominateur);

    //fonction simplifie, qui retourne uniquement
    Fraction<T> simplifie() const;

    //Test si deux fractions sont "strictement égale" genre : 1/2 et 1/2 oui , mais 1/2 et 2/4 non
    bool identite(const Fraction<T>& f) const;

private:
    T denominateur,numerateur;
};


#include "fractionImpl.h"
#endif //FRACTION_H
