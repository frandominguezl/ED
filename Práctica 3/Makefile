SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

	
# ************ Compilación de módulos ************
$(BIN)/pruebacola_max: $(OBJ)/pruebacola_max.o $(OBJ)/Cola_max_pila.o
	$(CXX) -o $(BIN)/pruebacola_max $(OBJ)/pruebacola_max.o -I$(INC)

$(OBJ)/pruebacola_max.o: $(SRC)/pruebacola_max.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp -I$(INC)	

$(OBJ)/Cola_max_pila.o:
	$(CXX) $(CPPFLAGS) -o $(OBJ)Cola_max_pila.o $(INC)/Cola_max_pila.h

all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*