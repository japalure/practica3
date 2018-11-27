/**
  * @file Posicion.h
  * @brief Fichero cabecera del TDA Posicion
  *
  */

#ifndef POSICION_H
#define POSICION_H

#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Posicion
  *
  * Representa una localización geográfica definida por longitud y latitud. La
  * longitud se define como el ángulo entre el meridiano que pasa por Greenwich y el
  * meridiano que pasa por el punto. La latitud es el ángulo entre el paralelo ecuatorial y
  * la ĺínea que pasa por este punto. La latitud expresa la localización de un lugar en
  * dirección Norte o Sur. Y la longitud expresa la localización Este-Oeste de un punto. El
  * rango normal de la latitud, en grados, es [-90,90]. La longitud se expresa normalmente
  * en el rango [-180,180] grados.
  * 
  * @author Jose Antonio Palomino Ureña
  * @author Antonio Priego Raya
  * @date Octubre 2018
  *
  */
  
class Posicion {
	private:
		float longitud, //ángulo entre el meridiano que pasa por Greenwich y el meridiano que pasa por el punto.
			   latitud; //ángulo entre el paralelo ecuatorial y la ĺínea que pasa por este punto.
	public:
		/**
		  * @brief Constructor por defecto de la clase. Crea la posición (0,0)
		*/
		Posicion();
		
		/**
		  * @brief Constructor con parámetros de la clase. Crea la posición (lo,la)
		  * @param lo: la longitud
		  * @param la: la latitud
		*/
		Posicion(float la, float lo);
		
		/**
		  * @brief Devuelve un float con la longitud
		*/
		float GetLon() const;
		
		/**
		  * @brief Devuelve un float con la latitud
		*/
		float GetLat() const;
		
		/**
		  * @brief asigna unos valores pasados a longitud y latiitud
		  * @param lo: la longitud
		  * @param la: la latitud
		*/
		void setlatitudlongitud( float la, float lo);
		
		/**
		  * @brief Sobrecarga del operador ==
		  * @param p posición a comparar con el objeto implícito
		  * @return Devuelve true si este objeto es igual a p
		  */  
		bool operator ==(const Posicion &p);
		
		/**
		* @brief Crea una copia de p
		* @param p posicion a copiar
		*/
	   Posicion& operator=(const Posicion& p);
		
	
		
};
#endif
