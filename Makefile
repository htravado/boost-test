# Compilador
CC = g++

# Includes
INCLUDE = -I ./include
CFLAGS = -c -Wall -g

# A los includes del programa hay que agregar la ruta de include de la libreria de boost
TEST_INCLUDE = $(INCLUDE) -I /usr/include/

# Tambien hay que agregar la libreria de boost en el linking
# La ubicacion de la libreria puede depender de la plataforma y de la instalacion
TEST_LDFLAGS = $(LDFLAGS) -lboost_unit_test_framework #-L/usr/local/lib/libboost_unit_test_framework.so

# Fuentes
SOURCE = ./source
OUTPUT = ./build

TARGET = $(OUTPUT)/mainProgram.out
OBJECTS = $(OUTPUT)/main.o $(OUTPUT)/funcion.o

# Ubicacion de los test
TEST_TARGET = $(OUTPUT)/test.out
TEST_SOURCE = ./test/test.cpp

all: $(TARGET)
test: $(TEST_TARGET)

$(TARGET): $(OBJECTS) Makefile
	@echo "Linkeando el programa $@"
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

$(OUTPUT)/%.o: $(SOURCE)/%.cpp
	@echo "Compilando el objeto $@"
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ 

clean:
	@echo "Limpiando la instalacion"
	rm -f $(OUTPUT)/*.o $(TARGET)

$(OUTPUT)/test.o : $(TEST_SOURCE)
	@echo "Compilando los tests"
	$(CC) $(CFLAGS) $(TEST_INCLUDE) -o $@ $^ 

$(TEST_TARGET): $(OUTPUT)/test.o $(OUTPUT)/funcion.o Makefile
	@echo "Linkeando los tests"
	$(CC) $(OUTPUT)/test.o $(OUTPUT)/funcion.o -o $@ $(TEST_LDFLAGS)

runtests: $(TEST_TARGET)
	./build/test.out
