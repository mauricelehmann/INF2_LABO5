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

//Constructeur par copie
template<typename T>
Fraction<T>::Fraction(const Fraction<T>& rhs){
    numerateur = rhs.numerateur;
    denominateur = rhs.denominateur;
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

    return Fraction<T> ((numerateur / numerateurPgdc), (denominateur / numerateurPgdc));
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

    //simplifier *this
    *this = this->simplifie();
    //simplifier rhs
    rhs = rhs.simplifie();

    if(numerateur > (std::numeric_limits<T>::max() - abs(rhs.numerateur))){
        throw std::overflow_error("overflow dans l addition des numerateurs");
    }
    if(denominateur > (std::numeric_limits<T>::max() - abs(rhs.denominateur))){
        throw std::overflow_error("overflow dans l addition des denominateurs");
    }

    if(numerateur > (std::numeric_limits<T>::max() / abs(rhs.denominateur))){
        throw std::overflow_error("overflow dans la multiplication entre le numerateur gauche et le denominateur droit");
    }
    if(denominateur > (std::numeric_limits<T>::max() / abs(rhs.denominateur))){
        throw std::overflow_error("overflow dans la multiplication entre le denominateur gauche et le denominateur droit");
    }
    if(denominateur > (std::numeric_limits<T>::max() / abs(rhs.numerateur))){
        throw std::overflow_error("overflow dans la multiplication entre le denominateur gauche et le numerateur droit");
    }
    //Multiplication croisée des numerateurs et denominateurs
    T tmpDenominateur = denominateur;

    numerateur *= rhs.denominateur;
    rhs.numerateur *= denominateur;
    denominateur *= rhs.denominateur;
    rhs.denominateur *= tmpDenominateur;
    //Addition des numérateurs
    numerateur += rhs.numerateur;

    *this = this->simplifie();
    return *this;
}

template<typename T>
Fraction<T>& Fraction<T>::operator *= (const Fraction<T>& rhs){
    if(numerateur > (std::numeric_limits<T>::max() / abs(rhs.numerateur))){
        throw std::overflow_error("overflow dans la multiplication des numerateurs");
    }
    if(denominateur > (std::numeric_limits<T>::max() / abs(rhs.denominateur))){
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
    lhs += rhs;
    return lhs;
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
bool operator == (Fraction<T>& lhs,Fraction<T>& rhs){
    Fraction<T> lhsSimplifie = lhs.simplifie();
    Fraction<T> rhsSimplifie = rhs.simplifie();
    return (lhsSimplifie.numerateur == rhsSimplifie.numerateur) && (lhsSimplifie.denominateur == rhsSimplifie.denominateur);
}

#endif //FRACTIONIMPL_H
