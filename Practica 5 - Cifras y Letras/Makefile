# autor: Francisco Domínguez Lorente
# autor: David Gómez Hernández

SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# Ejecución

exec_letras_L: comp_letras
	./$(BIN)/letras datos/spanish.txt datos/letras.txt 8 L

exec_letras_P: comp_letras
	./$(BIN)/letras datos/spanish.txt datos/letras.txt 8 P

exec_cantidad_letras: comp_cantidad_letras
	./$(BIN)/cantidad_letras datos/spanish.txt datos/letras.txt datos/salida.txt

# MÓDULOS

comp_all: comp_conjunto_letras comp_letras comp_cantidad_letras


## Letras
comp_letras: $(BIN)/letras

$(BIN)/letras: $(OBJ)/letras.o $(LIB)/liberialibreria.a
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o  -L$(LIB) -ljuego

$(OBJ)/letras.o : $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letras.o $(SRC)/letras.cpp 

## Cantidad_letras

comp_cantidad_letras: $(BIN)/cantidad_letras

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(LIB)/liberialibreria.a
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o  -L$(LIB) -ljuego

$(OBJ)/cantidad_letras.o : $(SRC)/cantidad_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp 

## LIBRERIAS

$(LIB)/liberialibreria.a : $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o $(OBJ)/lista_palabras.o
	ar rvs $(LIB)/liberialibreria.a $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o $(OBJ)/lista_palabras.o

$(OBJ)/letra.o : $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letra.o $(SRC)/letra.cpp 

$(OBJ)/conjunto_letras.o : $(SRC)/conjunto_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp 

$(OBJ)/bolsa_letras.o : $(SRC)/bolsa_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp

$(OBJ)/lista_palabras.o : $(SRC)/lista_palabras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/lista_palabras.o $(SRC)/lista_palabras.cpp

# **** Generación de documentación ******
documentacion:
	doxygen doc/doxys/Doxyfile

# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ datos/*_P.txt

mrproper : clean
	-rm doc/html/*