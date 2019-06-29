SRC = src
INC = include
OBJ = build
LIB = lib
BIN = bin

CXX = g++
LINKFLAGS = -lGL -lGLU -lGLEW -lglfw3
CXXFLAGS = -std=c++17 -o $@ -I $(INC) -framework OpenGL -lglfw

BINFILES = $(addprefix $(BIN)/, $(basename $(notdir $(wildcard $(SRC)/*.cpp))))
OBJFILES = $(patsubst $(LIB)/%.cpp, $(OBJ)/%.o, $(wildcard $(LIB)/*/*.cpp) $(wildcard $(LIB)/*.cpp))

OBJDIRS = $(addprefix $(OBJ)/, $(notdir $(wildcard $(LIB)/*)))


.PHONY: directories
.PRECIOUS: $(OBJ)/%.o

all: directories $(BINFILES)

directories: $(BIN) $(OBJ)

$(BIN):
	@mkdir -p $(BIN)

$(OBJ):
	@mkdir -p $(OBJDIRS) $(OBJ)

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
