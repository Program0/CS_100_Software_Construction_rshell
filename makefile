#marlo zeroth 861309346 mzero001@ucr.edu
#emmilio segovia 

#For compilation

CC=g++
CC_FLAGS= -Wall -Werror -ansi -pedantic

#Folder structure
BIN_DIR:=bin
SRC_DIR:=src
H_DIR:=src/header

#Name of executable
#EXEC:=rshell

all:rshell

VPATH = $(SRC_DIR) 

H_FILES:=$(wildcard $(H_DIR)/*.h)
DEPS:$(H_FILES)


CPP_FILES:=$(wildcard $(SRC_DIR)/*.cpp)

OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o,$(CPP_FILES))

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(H_DIR)/%.h
	mkdir -p $(BIN_DIR)
	$(CC) -I$(H_DIR) -o $@ -c $< $(CC_FLAGS)

$(BIN_DIR)/main.o:$(SRC_DIR)/main.cpp
	$(CC) -I$(H_DIR) -o $@ -c $(SRC_DIR)/main.cpp $(CC_FLAGS)

rshell: $(OBJECTS)
	$(CC) -o $(BIN_DIR)/$@ $(OBJECTS) $(CC_FLAGS)

#.PHONY: test
#test:
#	echo $(H_FILES)

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)
