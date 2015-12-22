AR= ar
CXX= g++
CXXFLAGS= -Wall -I$(INC) -O -pedantic
LIBS= ./lib
SOURCE= ./src
INC= ./includes
OBJ= ./obj

all: ./bin/buscaminas

./bin/buscaminas: $(OBJ)/buscaminas.o $(LIBS)/libjuego.a
	$(CXX) -o $(@) $(OBJ)/buscaminas.o -L$(LIBS) -ljuego

$(LIBS)/libjuego.a: $(OBJ)/campominas.o $(INC)/tablero.h
	$(AR) rvs $(LIBS)/libjuego.a $(OBJ)/campominas.o

$(OBJ)/campominas.o: $(INC)/campominas.h $(SOURCE)/campominas.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $(SOURCE)/campominas.cpp

$(OBJ)/buscaminas.o: $(SOURCE)/buscaminas.cpp 
	$(CXX) -c $(CXXFLAGS) -o $@ $(SOURCE)/buscaminas.cpp

clear: 
	rm $(OBJ)/*.o

destroy:
	rm ./bin/*
	rm $(OBJ)/*.o
	rm $(LIBS)/*.o
