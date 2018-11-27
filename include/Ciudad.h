/**
  * @file Ciudad.h
  * @brief Fichero cabecera del TDA Ciudad
  *
  */

#ifndef __CIUDAD
#define __CIUDAD

#include <iostream>
#include <Posicion.h>
#include <string>
#include <cstring>


using namespace std;

/**
  *  @brief T.D.A. Ciudad
  *
  * Esta clase simplemente almacenará
  * los atributos que forman a una Ciudad
  * tales como su nombre, país al que 
  * pertenece, posición y población
  *  
  * @author Jose Antonio Palomino Ureña
  * @author Antonio Priego Raya
  * @date Octubre 2018
  *
  */

class Ciudad {

 private:
/**
  * @page repConjunto Rep del TDA Ciudad
  *
  * @section invConjunto Invariante de la representación
  * El invariante es poblacion>=0
  *
  * @section faConjunto Función de abstracción
  * (rep.nombre,rep.pais,rep.posicion,rep.poblacion)
  */

  string nombre;      /**< nombre */
  string pais;        /**< país al que pertenece */
  Posicion posicion;  /**< posición geográfica   */
  int poblacion;      /**< numero de habitantes  */


 public:
 
 Ciudad();

/**
  * @brief Constructor de clase. Recibe todos los valores, ya que una instancia sin estos sería inútil
  */
  Ciudad (string nombre, string pais, Posicion posicion, int poblacion);


/**
  * @brief Constructor de copia de la clase
  * @param c.nombre de la ciudad a construir
  * @param c.pais nombre del pais de la ciudad a construir
  * @param c.posicion posicion de la ciudad a construir
  * @param c.poblacion numero de habitantes de la ciudad a construir
  */
  Ciudad (const Ciudad& c);

/**
  * @brief nombre
  * @return Devuelve el nombre de la ciudad
  */
  string GetCiudad() const {return nombre;};

/**
  * @brief pais
  * @return Devuelve el nombre del pais al que pertenece la ciudad
  */
  string GetPais() const {return pais;};

/**
  * @brief posicion
  * @return Devuelve la posicion de la ciudad
  */
  Posicion GetPosicion() const {return posicion;};

/**
  * @brief poblacion
  * @return Devuelve el numero de habitantes de la ciudad
  */
  int GetPoblacion() const {return poblacion;};
  
  void set (string no, string pa, Posicion po, int pob);

  /**
  * @brief Devuelve si dos ciuades son iguales
  * @param Ciudad a comparar
  */
  const bool operator == (const Ciudad &c) const; 
  /**
	* @brief Crea una copia de c
	* @param c ciudad a copiar
	*/
  Ciudad& operator=(const Ciudad& c);
	
  friend ostream& operator << (ostream& os, const Ciudad& c);
  friend istream& operator >> (istream& is,  Ciudad& c);

};

#endif
