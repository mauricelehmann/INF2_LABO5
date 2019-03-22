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

//Constructeur
template<typename T>
Fraction<T>::Fraction(const T& denominateur,const T& numerateur){
    //Test à faire avec MAX VALUE ETC...
    this->denominateur = denominateur;
    this->numerateur = numerateur;
}

template<typename T>
Fraction<T> Fraction<T>::simplifie() const{

}

//TODO:  Que ce passe-t-il quand on compare deux type différents ?
template<typename T>
bool Fraction<T>::identite(const Fraction<T>& f) const{
    if(f.denominateur == denominateur && f.numerateur == numerateur){
        return true;
    }
    return false;
}





#endif //FRACTIONIMPL_H
