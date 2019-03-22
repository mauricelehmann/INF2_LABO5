/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : OperatorFractionImpl.h
 Auteur(s)   : Maurice Lehmann
 Date        : 20.03.2019

 But         : Déclarations & définitions des surcharge des opérateurs de la classe générique Fraction

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef OPERATORFRACTIONIMPL_H
#define OPERATORFRACTIONIMPL_H

//Pré-déclaration de la classe, pour pré-déclarer correctement les surcharges opérateurs
template<typename T> class Fraction;
//Pré
template<typename T>
std::ostream& operator <<(std::ostream& os, const Fraction<T>& f);

template<typename T>
bool operator == (std::ostream& os, const Fraction<T>& f);

template<typename T>
Fraction<T> operator + (Fraction<T> lhs, Fraction<T>& rhs );


//template<typename T>
//Fraction<T>& operator += (const Fraction<T>& rhs);

template<typename T>
Fraction<T> operator * (Fraction<T> lhs, Fraction<T>& rhs );


#endif /* OPERATORFRACTIONIMPL_H */
