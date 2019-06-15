SRC = src
INC = include
OBJ = build
LIB = lib
BIN = bin

CXX = g++
CXXFLAGS = -std=c++17 -o $@ -I $(INC)

BINFILES = $(addprefix $(BIN)/, $(basename $(notdir $(wildcard $(SRC)/*.cpp))))
OBJFILES = $(patsubst $(LIB)/%.cpp, $(OBJ)/%.o, $(wildcard $(LIB)/*/*.cpp))

OBJDIRS = $(addprefix $(OBJ)/, $(notdir $(wildcard $(LIB)/*)))

.PRECIOUS: $(OBJ)/%.o

all: directories $(BINFILES)

directories: $(BIN) $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJDIRS)

$(BIN)/%: $(SRC)/%.cpp $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^

$(OBJ)/%.o: $(LIB)/%.cpp $(INC)/%.hpp
	$(CXX) $(CXXFLAGS) $< -c

re: clean all

run: all
	./bin/main

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
