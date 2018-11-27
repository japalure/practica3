/**
 * Antonio Priego Raya 
 * José Antonio Palomino Ureña
 * C3
 **/
#include "Ciudades.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#define PI 3.14159265
#define RADIO_TIERRA 6378 //radio ecuatorial

/**
 * @brief Convierte grados a radianes 
 * @param d: valor en grados
 * @return el valor en radianes
 */
float ToRadianes(float d){
    return PI/180*d;
}
/**
 * @brief Dadas dos posiciones obtiene la distancia en Kms
 * @param posOrigen: Posicion de un punto geografico
 * @param posDestino: Posicion de un punto geografico
 * @return la distancia en kms entre dos posiciones
 */
float DistanciaKm(Posicion posOrigen, Posicion posDestino)
{
  float difLatitud = ToRadianes(posDestino.GetLat()-posOrigen.GetLat());
  float difLongitud =ToRadianes(posDestino.GetLon()-posOrigen.GetLon());
  float a = pow(sin(difLatitud/2),2)+
          cos(ToRadianes(posOrigen.GetLat()))*
          cos(ToRadianes(posDestino.GetLat()))*
          pow(sin(difLongitud/2),2);
   float c = 2 *atan2(sqrt(a), sqrt(1 -a));

   return RADIO_TIERRA*c;
}

/**
 * @brief Obtiene la poblacion total de un conjunto de ciudades
 * @param v: Conjunto de ciudades
 * @return la suma de las poblaciones en dichas ciudades
*/
unsigned int ObtenerPoblacion(Ciudades & v){
  unsigned int n=v.size();
  unsigned int t_pob=0;
  for (unsigned int i=0;i<n;i++)
    t_pob+=v[i].GetPoblacion();
  return t_pob;
}  
/**
 * @brief mensaje en pantalla indicando los parametros del programa
 */
void Mensaje(){
  cout<<"Los parametros son:"<<endl;
  cout<<"1.- Fichero con la informacion de las ciudades "<<endl;
  return;  
}  


int main(int argc, char *argv[]){

  if (argc!=5){
    Mensaje();
    return 0;
  }
  
  ifstream f(argv[1]);
  if (!f){
     cerr<<" No puedo abrir el fichero "<<argv[1]<<endl;
     return 0;
  }

  // _______________________________________________________________
  
  string ciudad_introducida, mipais;
  int poblacion = 313269;
 Posicion posicion;
  int ciudades_mostrar;

  Ciudades misciudades;
  Ciudad mi_ciudad;
  ciudad_introducida =string (argv[2]);
  mipais = argv[3];
  ciudades_mostrar = atoi(argv [4]);
  
  //Vector en el que se guardan las ciudades de más cercana a más lejana 
  VD<Ciudad> cercanas;

  f>>misciudades;
  cout<< "Numero de ciudades "<<misciudades.size();
  cin.get();

  poblacion = misciudades.getPoblacion( ciudad_introducida,  mipais);
  posicion = misciudades.getPosicion( ciudad_introducida,  mipais);

  mi_ciudad.set(ciudad_introducida, mipais, posicion, poblacion);
	cout << "\nEsta es mi ciudad: " << mi_ciudad <<  "\n";
  
  
  int i = 0, TAM_misciudades = misciudades.size();
  
  while ( i < TAM_misciudades){
		int TAM_cercanas = cercanas.size();
		
		float distancia_i = DistanciaKm(mi_ciudad.GetPosicion(), misciudades[i].GetPosicion());
		
		
			//Si la ciudad de misciudades está más cerca que la última ciudad del vector de cercanas entra
			if ( distancia_i < DistanciaKm(mi_ciudad.GetPosicion(), cercanas[TAM_cercanas].GetPosicion()))
			{
				//Compara la ciudad con cada ciudad de cercanas para saber en qué posición hay que insertarla
				bool insertado = false;
				for (int j = 0; j <= TAM_cercanas && insertado == false; j++)
				{
					
					if ( DistanciaKm(mi_ciudad.GetPosicion(), cercanas[j].GetPosicion()) > distancia_i)
					{
						cercanas.Insertar(misciudades[i], j);
						insertado = true;
						
					}
				}
			}
			//Si la ciudad de misciudades está más lejos que la última de cercanas pero se han introducido menos del número de las ciudades requeridas para mostrar se introuduce la última
			else if ( TAM_cercanas < ciudades_mostrar){
					cercanas.Insertar(misciudades [i], TAM_cercanas);
			}
			
		i++;
   }
  
  
  //Mostramos las ciudades almacenadas en cercanas;
  cout << "\nCiudades mas cercanas a " << ciudad_introducida << ", " << mipais << ":\n";
  
  for (int k = 0; k < ciudades_mostrar; k++){
	Ciudad aux = cercanas[k];
	cout << k;
	cout << ". " << aux  << endl;
	  
  }
  
  return 0;
}
