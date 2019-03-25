/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : fractionImpl.h
 Auteur(s)   : Maurice Lehmann
 Date        : 20.03.2019

 But         : Définition de la classe générique Fraction

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef FRACTIONIMPL_H
#define FRACTIONIMPL_H

#include <limits>

//Constructeur
template<typename T>
Fraction<T>::Fraction(const T& numerateur,const T& denominateur){
    if(denominateur == 0){
        throw std::overflow_error("Le denominateur ne peut pas etre 0");
    }
    this->numerateur = numerateur;
    this->denominateur = denominateur;
    if(denominateur < 0){
        this->numerateur *= -1;
        this->denominateur *= -1;
    }
}

template<typename T>
Fraction<T> Fraction<T>::simplifie() const{

}

/*
    Définitions des méthodes
*/

//TODO:  Que ce passe-t-il quand on compare deux type différents ?
template<typename T>
bool Fraction<T>::identite(const Fraction<T>& f) const{
    if(f.denominateur == denominateur && f.numerateur == numerateur){
        return true;
    }
    return false;
}


/*
    Définitions des opérateurs
*/
template<typename T>
Fraction<T>& Fraction<T>::operator += (Fraction<T> rhs){
    if(numerateur > (std::numeric_limits<T>::max() - rhs.numerateur)){
        throw std::overflow_error("overflow dans l addition des numerateurs");
    }
    if(denominateur > (std::numeric_limits<T>::max() - rhs.denominateur)){
        throw std::overflow_error("overflow dans l addition des denominateurs");
    }
    //simplifier *this
    //simplifier rhs

    numerateur *= rhs.denominateur;
    denominateur *= rhs.numerateur;

}

template<typename T>
Fraction<T>& Fraction<T>::operator *= (const Fraction<T>& rhs){
    if(numerateur > (std::numeric_limits<T>::max() / rhs.numerateur)){
        throw std::overflow_error("overflow dans la multiplication des numerateurs");
    }
    if(denominateur > (std::numeric_limits<T>::max() / rhs.denominateur)){
        throw std::overflow_error("overflow dans la multiplication des denominateurs");
    }
    numerateur *= rhs.numerateur;
    denominateur *= rhs.denominateur;
    return *this;
}

template<typename T>
Fraction<T>::operator double() const {
    return numerateur / (double)denominateur;
}

template<typename T>
Fraction<T> operator + (Fraction<T> lhs, Fraction<T>& rhs ){

}

template<typename T>
Fraction<T> operator * (Fraction<T> lhs, Fraction<T>& rhs ){
    lhs *= rhs;
    return lhs;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Fraction<T>& f){
    return os << f.numerateur << "/" << f.denominateur ;
}

template<typename T>
bool operator == (std::ostream& os, const Fraction<T>& f){

}

#endif //FRACTIONIMPL_H
