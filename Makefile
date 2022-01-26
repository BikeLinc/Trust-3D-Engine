# Makefile For Trust3D
TARGET=Trust3D

## Operating System Detection
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
# do something Linux
endif
ifeq ($(UNAME), Darwin)
# do something OSX
endif

# Directory Macros
SRC_DIR=./src/
OUT_DIR=./build/
BIN_DIR=$(OUT_DIR)bin/
OBJ_DIR=$(OUT_DIR)objects/

# Files
SRCS=$(wildcard $(SRC_DIR)*.cpp)
OBJS=$(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

# Compiler
CXX=g++
CFLAGS=-Wall
LDFLAGS= -D $(UNAME)
ifeq ($(UNAME), Darwin)
	LDFLAGS+= -I/usr/local/include -lGLEW -lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif


all: setup compile

compile: $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(BIN_DIR)$@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(BIN_DIR)$(TARGET)
	@./$(BIN_DIR)$(TARGET)

setup:	
	@[ -d $(OUT_DIR) ] || mkdir $(OUT_DIR) && echo Directory Created: $(OUT_DIR)
	@[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR) && echo Directory Created: $(BIN_DIR) 
	@[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR) && echo Directory Created: $(OBJ_DIR)

.PHONY clean:
	[ -d $(OUT_DIR) ] && rm -rf $(OUT_DIR)
