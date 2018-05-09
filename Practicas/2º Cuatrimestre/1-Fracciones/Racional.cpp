#include "Racional.h"
#include <cmath>

  //Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
Racional:: Racional(long numer,long denom){
	if(denom == 0) throw EDenominadorCero ();
	else{
		_numer = numer; _denom = denom;
		this->reduce();
	}
}
	Racional Racional:: suma(const Racional& c) const{
		long minM = this->mcm(_denom, c._denom);
		Racional r(_numer*(minM/_denom) + c._numer*(minM/c._denom),minM);
		r.reduce();
		return r;
	}
	Racional Racional:: operator -(const Racional& c) const{
		long minM = this->mcm(_denom, c._denom);
		Racional r(_numer*(minM/_denom) - c._numer*(minM/c._denom),minM);
		r.reduce();
		return r;
	}
	Racional Racional:: operator *(const Racional& c) const{
		Racional r(_numer*c._numer,_denom*c._denom);
		r.reduce();
		return r;
	}
	Racional Racional:: operator /(const Racional& c) const{
		if(c._numer == 0) throw EDivisionPorCero ();
		else{
			Racional r(_numer*c._denom,_denom*c._numer);
			r.reduce();
			return r;
		}
	}

	Racional& Racional::operator=(const Racional& c){
		_numer = c._numer;
		_denom = c._denom;
		this->reduce();
		return *this;
	}
	Racional& Racional::operator+=(const Racional& c){
		Racional suma = this->suma(c);
		_numer = suma._numer;
		_denom = suma._denom;
		this->reduce();
		return *this;
	}
	Racional& Racional::operator-=(const Racional& c){
		Racional resta = *this - c;
		_numer = resta._numer;
		_denom = resta._denom;
		this->reduce();
		return *this;
	}
	Racional& Racional::operator*=(const Racional& c){
		Racional mul = *this*c;
		_numer = mul._numer;
		_denom = mul._denom;
		this->reduce();
		return *this;
	}
	void Racional::divideYActualiza(const Racional& c){
		Racional div = *this/c;
		*this = div;
	}

	long Racional:: numer() const{
			return _numer;
		}
	long Racional::denom() const{
			return _denom;
		}

	bool Racional::operator==(const Racional& c){
			return _numer == c._numer &&_denom == c._denom;
		}
  
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

