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
Fraction<T>::Fraction(const T& numerateur,const T& denominateur){
    //Test à faire avec MAX VALUE ETC...
    this->numerateur = numerateur;
    this->denominateur = denominateur;
}

template<typename T>
Fraction<T> Fraction<T>::simplifie() {

    T reste;
    T numerateurPgdc = numerateur;
    T denominateurPgdc = denominateur;
    
    while(denominateurPgdc != 0) {
        reste = numerateurPgdc % denominateurPgdc;
        numerateurPgdc = denominateurPgdc;
        denominateurPgdc = reste;
    }

    Fraction<T> fractionSimplifiee((numerateur / numerateurPgdc), (denominateur / numerateurPgdc));
    return fractionSimplifiee;
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
Fraction<T>& Fraction<T>::operator += (Fraction<T>& rhs){

}

template<typename T>
Fraction<T>& Fraction<T>::operator *= (Fraction<T>& rhs){
    this->numerateur *= rhs.numerateur;
    this->denominateur *= rhs.denominateur;
    return *this;
}
template<typename T>
Fraction<T>::operator double() const {
    return Fraction<double>((double)this->numerateur,(double)this->denominateur);
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
    return os << f.numerateur << "/" << f.denominateur  << std::endl;
}

template<typename T>
bool operator == (std::ostream& os, const Fraction<T>& f){

}

template<typename T>
T Fraction<T>::getNumerateur() const {
    return numerateur;
}

template<typename T>
T Fraction<T>::getDenominateur() const {
    return denominateur;
}




#endif //FRACTIONIMPL_H
