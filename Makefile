# Makefile for Space project

# Compiler and flags
CXX := g++
CFLAGS := -Wall
DEBUG_FLAGS := -g
RELEASE_FLAGS := -O2

# Libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-system
EXEC := Solitaire

# Directories (use double quotes for directory names with spaces)
OBJ_DIR := Object_files
BIN_DIR := Binaries
HEADERS_DIR := Header_files
SOURCE_DIR := Source_files
DEBUG_DIR := $(BIN_DIR)/Debug
RELEASE_DIR := $(BIN_DIR)/Release

# Source files (list your source files here, relative to SOURCE_DIR)
SRC_FILES := main.cpp Button.cpp Label.cpp Gui.cpp Card.cpp Deck.cpp Node.cpp Stack.cpp

# Generate object file names from source file names
OBJ_FILES := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Targets
all: Debug Release

Debug: CXXFLAGS += $(DEBUG_FLAGS)
Debug: $(DEBUG_DIR)/$(EXEC)

Release: CXXFLAGS += $(RELEASE_FLAGS)
Release: $(RELEASE_DIR)/$(EXEC)

$(DEBUG_DIR)/$(EXEC): $(OBJ_FILES)
	@mkdir -p $(DEBUG_DIR)
	$(CXX) -o $@ $(OBJ_FILES) -L$(BIN_DIR) $(LIBS)
	@echo "Output file is $@ with size $$(du -hb $@ | cut -f1 | awk '{print $$1/1024}') KB"

$(RELEASE_DIR)/$(EXEC): $(OBJ_FILES)
	@mkdir -p $(RELEASE_DIR)
	$(CXX) -o $@ $(OBJ_FILES) -L$(BIN_DIR) $(LIBS)
	@echo "Output file is $@ with size $$(du -hb $@ | cut -f1 | awk '{print $$1/1024}') KB"

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

.PHONY: all Debug Release
