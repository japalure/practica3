#include "Posicion.h"

//Constructor por defecto
Posicion::Posicion(){
	longitud = 0;
	latitud = 0;
}
//Constructor con parámetros
Posicion::Posicion(float la, float lo){
	longitud = lo;
	latitud = la;
}
//Devolver longitud
float Posicion::GetLon() const {
	return longitud;
}
//Devolver latitud
float Posicion::GetLat() const {
	return latitud;
}
//Asignar los valores de latitud y longitud
void Posicion::setlatitudlongitud( float la, float lo){
	longitud = lo;
	latitud = la;
}
//Operador ==
bool Posicion::operator==(const Posicion &p){
	if (longitud == p.GetLon() && latitud ==  p.GetLat())
		return true;
	else
		return false;
}

Posicion&  Posicion::operator=(const Posicion& p){
	this->setlatitudlongitud(p.GetLat(), p.GetLon());
	
	return *this;
}
