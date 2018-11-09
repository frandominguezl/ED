SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# **** Compilación de módulos ****
$(BIN)/pruebacola_max: $(OBJ)/pruebacola_max.o $(LIB)/libcola.a
	$(CXX) -o $(BIN)/pruebacola_max $(OBJ)/pruebacola_max.o -I$(INC) -L$(LIB) -lcola

$(LIB)/libcola.a : $(OBJ)/Cola_max_pila.o
	ar rvs $(LIB)/libcola.a $(OBJ)/Cola_max_pila.o

$(OBJ)/Cola_max_pila.o : $(SRC)/Cola_max_pila.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Cola_max_pila.o $(SRC)/Cola_max_pila.cpp -I$(INC)

$(OBJ)/pruebacola_max.o : $(SRC)/pruebacola_max.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp -I$(INC)

# **** Generación de documentación ******
documentacion:
	doxygen doc/doxys/Doxyfile

all: $(BIN)/pruebacola_max

# **** Ejecutar ****
exec:
	./$(BIN)/pruebacola_max

# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm doc/html/*