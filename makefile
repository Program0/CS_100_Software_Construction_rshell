#marlo zeroth 861309346 mzero001@ucr.edu
#emmilio segovia 

#For compilation

CC=g++
CC_FLAGS= -g -Wall -Werror -ansi -pedantic

#make[1]: main.o all <- all

#Folder structure
BIN_DIR:=bin
SRC_DIR:=src
H_DIR:=src/header

all:rshell

H_FILES:=$(wildcard $(H_DIR)/*.h)
DEPS:$(wildcard $(BIN_DIR)/*.d)


CPP_FILES:=$(wildcard $(SRC_DIR)/*.cpp)

OBJECTS := $(CPP_FILES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(H_DIR)/%.h
	mkdir -p $(BIN_DIR)
	$(CC) -I$(H_DIR) -o $@ -c $< $(CC_FLAGS)

$(BIN_DIR)/main.o:$(SRC_DIR)/main.cpp $(H_FILES)
	$(CC) -I$(H_DIR) -o $@ -c $(SRC_DIR)/main.cpp $(CC_FLAGS)

rshell: $(OBJECTS)
	$(CC) -o $(BIN_DIR)/$@ $(OBJECTS) $(CC_FLAGS)

include $(DEPS)

$(MAKEFILE_LIST): ;
%:: %,v
%:: RCS/%,v
%:: RCS/%
%:: s.%
%:: SCCS/s.%

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)
	
