//Constructor por defecto
Ciudades::Ciudades ()
{
  
}

//Constructor de copia
Ciudades::Ciudades (const Ciudades& c)
{
	orden1 = c.orden1;
	orden2 = c.orden2;
}

//Devuelve el tama�o del conjunto Ciudades
 int Ciudades::size () const
{
  return orden1.size();
}

//Insertar un elemento en el conjunto ciudades
void Ciudades::Insertar (Ciudad ciudad)
{
	bool esInsertado1=false;
	int = 0;
	while (!esInsertado1) {                                                                 
	  
		if (orden1[i].GetPais() > ciudad.GetPais()){
		  orden1.insert(datos.begin()+i, ciudad);
		  esInsertado1=true;
		}

		else if (orden1[i].GetPais() == ciudad.GetPais()  &&  orden1[i].GetCiudad() > ciudad.GetCiudad()) {
		  orden1.insert(datos.begin()+i, ciudad);
		  esInsertado1=true;
		}

		else if (orden1.size()-i <= 1) {      //Si una vez recorrido el vector no tiene lugar
		  orden1.insert(datos.begin()+i, ciudad);
		  esInsertado1=true;
    }

    i++;
  }
}

void Ciudades::InsertarOrden2 () {
  int i=0;
  bool esInsertado2=false;


  while ( i<orden1.size() ) {
  
    while (!esInsertado2) {
      int j=0;

      if (orden1[j].GetCiudad() > orden1[i].GetCiudad() ) {
        orden2.insert(i, j);
        esInsertado2=true;
      }

      if (orden2.size()-i <= 1) {      //Si una vez recorrido el vector no tiene lugar
        orden2.insert(i, j);
        esInsertado2=true;
      }

      j++;
    }

    i++;
    esInsertado2=false;
  }
}

//Borrar un elemento del conjunto ciudades
void Ciudades::BorrarCiudad (Ciudad a_eliminar)
{
  for (int i=0; i < orden1.size(); i++) {                                                                 //
    if ( a_eliminar == orden1[ orden2[i] ] ) {                                                            //
      orden2.Borrar(i);                                                                                   // ORDEN 1) y 2)
      orden1.Borrar(orden2[i]);
    }                                                                                                     //
  }                                                                                                       //
}

//Obtener una ciudad por su orden ciudad
Ciudad Ciudades::GetCiudad_Ciudad (int indice) const
{
	
  return orden1[indice];
}

//Obtener una ciudad por su orden país y ciudad
Ciudad Ciudades::GetCiudad_Pais (int indice) const
{
  return orden1[indice];
}

int Ciudades::getPoblacion(string nombre, string pais){
		Ciudades subconjunto = GetAllCiudadesPais(pais);
		int contador = 0;
		int sub_TAM = subconjunto.size();
		bool encontrado = false;
		string no;
		
		while (contador < sub_TAM && encontrado == false)
		{
			no = subconjunto[contador].GetCiudad();
		
			if (no == nombre){
				
				encontrado = true;
			}
				
			contador++;
			
		}	
		contador--;
		
		return subconjunto[contador].GetPoblacion();
		
}

Posicion Ciudades::getPosicion(string nombre, string pais){
		Ciudades subconjunto = GetAllCiudadesPais(pais);
		int contador = 0;
		int sub_TAM = subconjunto.size();
		bool encontrado = false;
		string no;
		
		while (contador < sub_TAM && encontrado == false)
		{
			no = subconjunto[contador].GetCiudad();
		
			if (no == nombre){
				
				encontrado = true;
			}
				
			contador++;
			
		}	
		contador--;
		
		return subconjunto[contador].GetPosicion();
		
}



//Obtener un subconjunto con todas las ciudades que compartan nombre de ciudad
Ciudades Ciudades::GetAllCiudadesNombre (string nombre_ciudad) const
{
  Ciudades subconjunto;

  for (int i=0; i < orden1.size(); i++) {
    if (orden1[i].GetCiudad() == nombre_ciudad)
      subconjunto.Insertar(orden1[i]);
  }

  return subconjunto;
}

//Obtener un subconjunto con todas las ciudades que compartan nombre de país
Ciudades Ciudades::GetAllCiudadesPais (string nombre_pais) const
{
  Ciudades  subconjunto;

  for (int i=0; i < orden1.size(); i++) {
    if (orden1[i].GetPais() == nombre_pais)
      subconjunto.Insertar(orden1[i]);
  }

  return subconjunto;
}
Ciudades& Ciudades::operator= (const Ciudades &c){
	orden1 = c.orden1;
	orden2 = c.orden2;
	return *this;
}

//Flujo de salida
ostream& operator<< (ostream& os, const Ciudades& c)
{
  int TAM = c.size();
  for (int i = 0;  i < TAM; i++)
    os << c[i] << "\n";
  os << "\n";
  return os;
}
//Flujo de entrada
istream& operator>> (istream& is, Ciudades& c) {
  const std::string FORMATO = "#city;country;lat;lng;pop";
  const int N_ciudades = 7254;
  
  std::string formato;
  Ciudad aux;
  
  is >> formato;
  is.ignore();
  if(formato.compare(FORMATO) == 0) {
	   is >> aux;
    while( aux != NULL || isspace(aux)) {
      c.Insertar(aux);
      is >> aux;
      
    }
  }
  else 
    cerr <<"error de formato\n";
                
  return is;
}
