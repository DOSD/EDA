#include "Foro.h"


/*** METODOS DE Mensaje ***/

Mensaje::Mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo,msg pos):
	_id(id), _remitente(remitente), _asunto(asunto), _cuerpo(cuerpo), _posicion(pos) {}	

const MID Mensaje::id() const {
	return _id;
}

const string& Mensaje::remitente() const {
   return _remitente;	
}

const string& Mensaje::asunto() const {
   return _asunto;	
}

const string& Mensaje::cuerpo() const {
   return _cuerpo;	
}

msg Mensaje::posicion(){
	return _posicion;
}


/*** METODOS DE Foro ***/

Foro::Foro() {
	// A IMPLEMENTAR
	_nMensajes = 0;
}
   
void Foro::envia_mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo) {
  // A IMPLEMENTAR
	if(_foro.contiene(id)) throw EMIDDuplicado();
	else{
		_lista.pon_ppio(id);
		_foro.inserta(id,Mensaje(id,remitente,asunto,cuerpo,_lista.begin()));
		_nMensajes++;
	}
}

const Mensaje& Foro::consulta_mensaje(MID id) const {
  // A IMPLEMENTAR
	if(_foro.contiene(id)){
		return _foro.valorPara(id);
	}
	else throw ENoHayMensaje();
}

void Foro::elimina_mensaje(MID id) {
  // A IMPLEMENTAR
	if(_foro.contiene(id)){
		Mensaje m = _foro.valorPara(id);
		_lista.eliminar(m.posicion());
		_foro.borra(id);
		_nMensajes--;
	}
}
   
Lista<MID> Foro::recupera_mensajes(unsigned int n) const {
  // A IMPLEMENTAR
	Lista<MID> res;
	int mensajes = n;
	if(n > _nMensajes)
		mensajes = _nMensajes;
	Lista<MID>::ConstIterator ini = _lista.cbegin();
	for(int i = 1; i <= mensajes;++i){
		res.pon_final(ini.elem());
		ini.next();
	}
	return res;
}

unsigned int Foro::numero_mensajes() const {
  // A IMPLEMENTAR
	return _nMensajes;
}