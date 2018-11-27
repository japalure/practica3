#include "Ciudad.h"
using namespace std;

Ciudad:: Ciudad(){
	nombre = "null";
	Posicion p (0,0);
	posicion = p;
	pais  = "null";
	poblacion = 0 ;
}
//Constructor con todas los valores
Ciudad::Ciudad(string nombre, string pais, Posicion posicion, int poblacion)
{
	this->nombre    = nombre;
	this->pais      = pais;
	this->posicion  = posicion;
	this->poblacion = poblacion;
}

//Constructor de copia
Ciudad::Ciudad (const Ciudad& c)
{
	this->nombre    = c.nombre;
	this->pais      = c.pais;
	this->posicion  = c.posicion;
	this->poblacion = c.poblacion;
}

void Ciudad::set (string no, string pa, Posicion po, int pob){
	nombre    = no;
	pais      = pa;
	posicion  = po;
	poblacion = pob;
}
Ciudad& Ciudad::operator=(const Ciudad& c){
	
	this->set (c.GetCiudad(), c.GetPais(), c.GetPosicion(), c.GetPoblacion());
	return *this;
}

const bool Ciudad::operator == (const Ciudad &c) const{
	if ((nombre == c.GetCiudad()) && (pais == c.GetPais()))
		return true;
	else
		return false;
	
}
//Flujo de salida
ostream& operator << (ostream& os, const Ciudad& c){
	
	os << c.nombre << ',' << c.GetPais() << ',' << '\t'
	   << '[' << c.GetPosicion().GetLat() << ','
	   << c.GetPosicion().GetLon() << ']' << '\t'
	   << c.GetPoblacion();
	return os;
}

//Flujo de entrada
istream& operator >> (istream& is,  Ciudad& c){
	
	string nombre,  pais;
	float la, lo;
	int poblacion;
	Posicion posicion;
	char caracter;
	string linea;


	getline(is,nombre,';');
	getline(is,pais,';');
	is >> la >> caracter;
	is >> lo >> caracter;
	is >> poblacion;
	getline(is,linea);
	

	posicion.setlatitudlongitud(la, lo);
	
	c.set(nombre, pais, posicion, poblacion);
	
	
	return is;
}
