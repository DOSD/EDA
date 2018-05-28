#include "GestionAdmisiones.h"

/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas,iter posicion, Gravedad grav):
	_nombre(nombre),  _sintomas(sintomas), _edad(edad), _pos(posicion), _grav(grav) {}	

unsigned int Paciente::edad() const {
   return _edad;	
}
const string& Paciente::nombre() const {
   return _nombre;	
}
const string& Paciente::sintomas() const {
   return _sintomas;
}

Gravedad Paciente:: grav(){
	return _grav;
}
iter Paciente::posicion(){
	return _pos;
}

/**
Implementa aquí los métodos de las clases adicionales
*/

 
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/ 


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENATR
	if(_pacientes.contiene(codigo)) throw EPacienteDuplicado();
	else{
		if(gravedad == LEVE){
			_leve.pon_ppio(codigo);
			_pacientes.inserta(codigo,Paciente(nombre,edad,sintomas,_leve.begin(),gravedad));
		}
		else if(gravedad == NORMAL){
			_normal.pon_ppio(codigo);
			_pacientes.inserta(codigo,Paciente(nombre,edad,sintomas,_normal.begin(),gravedad));
		}
		else{
			_grave.pon_ppio(codigo);
			_pacientes.inserta(codigo,Paciente(nombre,edad,sintomas,_grave.begin(),gravedad));
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENATR
	if(!_pacientes.contiene(codigo)) throw EPacienteNoExiste();
	else
	{
		Paciente p = _pacientes.valorPara(codigo);
		nombre = p.nombre();
		edad = p.edad();
		sintomas = p.sintomas();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENATR
	if(_pacientes.esVacio()) throw ENoHayPacientes();
	else{
		if(!_grave.esVacia()){
			codigo = _grave.ultimo();
			gravedad = GRAVE;
		}
		else if(!_normal.esVacia()){
			codigo = _normal.ultimo();
			gravedad = NORMAL;
		}
		else{
			codigo = _leve.ultimo();
			gravedad = LEVE;
		}

	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {  
  // A IMPLEMENATR
	return !_pacientes.esVacio();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
  // A IMPLEMENATR
	if(_pacientes.contiene(codigo)){
		Paciente paciente = _pacientes.valorPara(codigo);
		Gravedad gravedad = paciente.grav();
		if(gravedad == LEVE){
			_leve.eliminar(paciente.posicion());
		}
		else if(gravedad == NORMAL){
			_normal.eliminar(paciente.posicion());
		}
		else{
			_grave.eliminar(paciente.posicion());
		}
		_pacientes.borra(codigo);
	}
}
   
