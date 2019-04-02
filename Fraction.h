/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : fraction.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 20.03.2019

 But         : Déclaration de la classe générique Fraction

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream> //ostream
#include <limits>
#include <cmath> //abs

//Pré-déclaration de la classe, pour pré-déclarer correctement les surcharges opérateurs
template<typename T> class Fraction;
//Pré-déclaration de l'opérateur de flux
template<typename T>
std::ostream& operator << (std::ostream& os, const Fraction<T>& f);
//Pré-déclaration de de l'opérateur ==
template<typename T>
bool operator == (Fraction<T>& lhs,Fraction<T>& rhs);
//Pré-déclaration de de l'opérateur +
template<typename T>
Fraction<T> operator + (Fraction<T> lhs, Fraction<T>& rhs );
//Pré-déclaration de de l'opérateur  *
template<typename T>
Fraction<T> operator * (Fraction<T> lhs, Fraction<T>& rhs );

/**
 * Classe générique fraction
 * @param numerateur   Numérateur de la fraction de type générique
 * @param denominateur Dénominateur de la fraction de type générique
 */
template<typename T>
class Fraction {
    //Fonctions friend
    /**
     * Opérateur de flux de la classe Fraction
     * @param numerateur   Numérateur de la fraction à afficher
     * @param denominateur Dénominateur de la fraction à afficher
     */
    friend std::ostream& operator << <T>(std::ostream& os, const Fraction<T>& f);
    /**
     * Opérateur ==
     * @param lhs , objet Fraction , opérande de gauche
     * @param rhs , objet Fraction , opérande de droite
     * @return true si les versions simplifiée des deux opérandes sont égales
     */
    friend bool operator == <T>(Fraction<T>& lhs,Fraction<T>& rhs);
    /**
     * Opérateur +
     * @param lhs , objet Fraction , opérande de gauche
     * @param rhs , objet Fraction , opérande de droite
     * @return nouvel objet Fraction<T>
     */
    friend Fraction<T> operator + <T>(Fraction<T> lhs, Fraction<T>& rhs );
    /**
     * Opérateur +
     * @param lhs , objet Fraction , opérande de gauche
     * @param rhs , objet Fraction , opérande de droite
     * @return nouvel objet Fraction<T>
     */
    friend Fraction<T> operator * <T>(Fraction<T> lhs, Fraction<T>& rhs );
public:
    /**
     * Constructeur
     * @param numerateur numerateur
     * @param denominateur denominateur
     */
    Fraction(const T& numerateur,const T& denominateur);
    /**
     * Constructeur par copie
     * @param rhs Object Fraction à copier
     */
    Fraction(const Fraction<T>& rhs);
   /**
    * Opérateur +=
    * @return Modifie l'objet "lhs"
    */
   Fraction<T>& operator += (Fraction<T> rhs);
   /**
    * Opérateur *=
    * @return Modifie l'objet "lhs"
    */
   Fraction<T>& operator *= (const Fraction<T>& rhs);
   /**
    * Operateur cast
    * @return double, division du numérateur par le dénominateur
    */
   operator double() const;
    /**
     * Simplifie la fraction, qui retourne un nouvel objet Fraction
     * @return Fraction<T>, nouvel objet Fraction simplifié
     */
    Fraction<T> simplifie() ;
    /**
     * Test si deux fractions sont "strictement égale"
     * e.g : 1/2 et 1/2 = true , mais 1/2 et 2/4 = false
     * @param  f Fraction à comparer
     * @return   bool, true si strictement égal, sinon false
     */
    bool identite(const Fraction<T>& f) const;

private:
    T denominateur,numerateur;
};
#include "FractionImpl.h"
#endif //FRACTION_H
