SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c




# **** Compilación de módulos ****
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o -I$(INC) -L$(LIB) -ldiccionario

$(LIB)/libdiccionario.a : $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	ar rvs $(LIB)/libdiccionario.a $(OBJ)/Termino.o $(OBJ)/Diccionario.o

$(OBJ)/Termino.o : $(SRC)/Termino.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INC)

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INC)


# **** Generación de documentación ******
documentacion:
	doxygen doc/doxys/Doxyfile
	

all: $(BIN)/pruebadiccionario	
# **** Ejecutar ****
exec:
	./$(BIN)/pruebadiccionario ./datos/diccionario.txt
# **** Limpieza ****
clean :
	

mrproper : clean
	-rm doc/html/*