#include "Libreria.h"

Libreria::Libreria() {
	// A IMPLEMENTAR
	_total_libros = 0;
}
void Libreria::an_libro(const string& libro, unsigned int n) {
	// A IMPLEMENTAR
	if(!_libros.contiene(libro)){
		_libros.inserta(libro,n);
		_total_libros++;
	}
	else
		_libros.inserta(libro,_libros.valorPara(libro)+n);
}

void Libreria::comprar(const string& libro) {
	// A IMPLEMENTAR
	if(!_libros.contiene(libro))
		throw ELibroNoExiste();
	else if(_libros.valorPara(libro) == 0)
		throw ENoHayEjemplares();
	else
		_libros.inserta(libro,_libros.valorPara(libro)-1);
}
bool Libreria::esta_libro(const string& libro) const {
	// A IMPLEMENTAR
	if(_libros.contiene(libro))
		return true;
	else return false;
}

void Libreria::elim_libro(const string& libro) {
	// A IMPLEMENTAR
	if(_libros.contiene(libro)){
		_libros.borra(libro);
		_total_libros--;
	}
}
	
int Libreria::num_ejemplares(const string& libro) const {
	// A IMPLEMENTAR
	if(!_libros.contiene(libro))
		throw ELibroNoExiste();
	else return _libros.valorPara(libro);
}

int Libreria::num_libros() const {
	// A IMPLEMENTAR
	return _total_libros;
}
