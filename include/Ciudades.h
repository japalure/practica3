/**
  * @file Ciudades.h
  * @brief Fichero cabecera del TDA Ciudades
  *
  */

#ifndef __CIUDADES
#define __CIUDADES

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Ciudad.h"

using namespace std;

/**
  *  @brief T.D.A. Ciudades
  *
  * Esta clase almacenará un conjunto
  * de objetos Ciudad, de forma que
  * estos deberán permanecer ordenados
  * por pais y por ciudad
  *  
  * @author Jose Antonio Palomino Ureña
  * @author Antonio Priego Raya
  * @date Octubre 2018
  *
  */

class Ciudades {

 private:
/**
  * @page repConjunto Rep del TDA Ciudades
  *
  * @section invConjunto Invariante de la representación
  * El invariante es poblacion>=0
  * @pre El VD de enteros solo servirá almacenar
  * otro orden, por lo que no usaremos sus atributos
  * "n" ni "reservados"
  *
  * @section faConjunto Función de abstracción
  * (orden1.datos[0], orden1.datos[1], ... , orden1.datos[orden1.datos.size()-1])
  * (orden2.datos[0], orden2.datos[1], ... , orden2.datos[orden2.datos.size()-1])
  */

  vector<Ciudad>  orden1;      /**< conjunto de ciudades->orden por país y ciudad */
  vector<int>     orden2;      /**< conjunto de punteros a ciudades->orden por ciudad*/


 public:
  class iterator{
	private:
		vector<Ciudad>::iterator it;
	public:
		iterator():it.punt(0){}
		iterator & operator++(){
			
		}
		friend class Ciudades;
		friend class const_iterator;
  };
  
  class const_iterator{
	private:
		vector<Ciudad>::const_iterator it;
	public:
		friend class Ciudades;
		friend class iterator;		
	}:
  iterator begin();
  iterator end();
  const_iterator begin()const;
  const_iterator end()const; 
/**
  * @brief Constructor por defecto de clase.
  */
  Ciudades ();

/**
  * @brief Constructor de copia de la clase
  * @param (c.datos[0], c.datos[1], ... , c.datos[c.datos.size()-1]), c.n, c.reservados
  */
  Ciudades (const Ciudades& c);

/**
  * @brief Devuelve el tama�o del conjunto Ciudades
  */
  int size () const;

/**
	* @brief Inserta una ciudad en el conjunto de forma que permanezca ordenado 
	* @param (ciudad ciudad a insertar)
	*/
  void Insertar (Ciudad ciudad);

/**
  * @brief Ordena el vector de segundo orden (orden2)
  */
  void InsertarOrden2 ();

/**
	* @brief Borra una ciudad de indice determinado
	* @param (a_eliminar ciudad a borrar del conjunto)
	*/
  void BorrarCiudad (Ciudad a_eliminar);

/**
	* @brief Devuelve una ciudad según la posición que ocupe en orden ciudad
	* @param (indice posición de la ciudad a devolver)
	*/
	Ciudad GetCiudad_Ciudad (int indice) const;
	
	int getPoblacion(string nombre, string pais);
	
	Posicion getPosicion(string nombre, string pais);

/**
	* @brief Devuelve una ciudad según la posición que ocupe en orden país
	* @param (indice posición de la ciudad a devolver)
	*/
	Ciudad GetCiudad_Pais (int indice) const;


	/**
	* @brief Devuelve una ciudad según el nombre de la ciudad
	* @param (nombre_ciudad nombre de la ciudad que se quiere obtener)
	*/
	//Ciudad GetCiudad_Nombre_Pais (string nombre_ciudad, string nombre_pais) const;
	
	/**
	* @brief Devuelve un conjunto de ciudades según el nombre de la ciudad
	* @param (nombre_ciudad nombre de la ciudad que se quiere obtener)
	*/
	Ciudades GetAllCiudadesNombre (string nombre_ciudad) const;

/**
	* @brief Devuelve un conjunto de ciudades que comparten el país indicado
	* @param (nombre_pais país común de todas las ciudades del conjunto devuelto)
	*/
	Ciudades GetAllCiudadesPais (string nombre_pais) const;

/**
	* @brief Devuelve la ciudad con posición indice
	* @param (indice posición de la ciudad que se quiere obtener)
	*/
	const Ciudad& operator[] (int indice) const {return orden1[indice];};
	
	Ciudades &operator= (const Ciudades &Ciudades);

/**
	* @brief modifica el valor en una posici�n
	* @param (indice posición de la ciudad que se quiere obtener)
	* @param nueva ciudad que se requiere para modificar
	*/
	void modifica(int indice, Ciudad nueva);

/**
  * @brief Salida de un indice a ostream
  * @param is stream de entrada
  * @param nueva es una ciudad de m 
  * @post Se obtiene una ciudad
*/
	friend ostream& operator<< (ostream& os, const Ciudades& c);

/**
  * @brief Entrada de una posicion a istream
  * @param os stream de salida
  * @param p de Posicion a mostrar
  * @post Se obtiene una salida con la longitud y la latitud
*/
	friend istream& operator>> (istream& is, Ciudades& c);	
};

#endif
