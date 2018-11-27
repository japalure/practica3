SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) --std=c++11
all:CompilandoModulos                \
	$(OBJ)/Posicion.o            \
	$(OBJ)/Ciudad.o              \
	$(OBJ)/Ciudades.o            \
	$(OBJ)/kciudades_cercanas.o  \
	$(BIN)/kciudades_cercanas    \
	Documentando		     \
	documentacion		     \
	FIN


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de ejecutables ************

$(BIN)/kciudades_cercanas : $(OBJ)/Posicion.o $(OBJ)/Ciudad.o $(OBJ)/Ciudades.o $(OBJ)/kciudades_cercanas.o
	g++ -o $@ $(OBJ)/Posicion.o $(OBJ)/Ciudad.o $(OBJ)/Ciudades.o $(OBJ)/kciudades_cercanas.o


# ************ Compilación de módulos ************

$(OBJ)/Posicion.o : $(SRC)/Posicion.cpp $(INC)/Posicion.h
	g++ -c -o $@ $< $(CPPFLAGS)

$(OBJ)/Ciudad.o : $(SRC)/Ciudad.cpp $(INC)/Ciudad.h
	g++ -c -o $@ $< $(CPPFLAGS)

$(OBJ)/Ciudades.o : $(SRC)/Ciudades.cpp $(INC)/Ciudades.h
	g++ -c -o $@ $< $(CPPFLAGS)

$(OBJ)/kciudades_cercanas.o :$(SRC)/kciudades_cercanas.cpp 
	g++ -c -o $@ $< $(CPPFLAGS)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

CompilandoModulos : 
	@echo "Compilando Modulos...\n"

CompilandoTestCiuadades :
	@echo "Compilando kciudades...\n"
Documentando :
	@echo "\nDocumentando el proyecto...\n"

FIN :
	@echo "FIN"
