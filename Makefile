# ------------------------------------------------
# Generic Makefile
#
# Author: alexis.baret@gmx.fr
# #version 1
# Date  : 2018-09-03
# ------------------------------------------------


#-------------- Options ----------------------------
PROJECT   = test
CC       = gcc
DBG      = gdb
CFLAGS   = -W -Wall -std=gnu99 -D_GNU_SOURCE
LCC   = gcc
LFLAGS   = -ldl
SRC_DIR   = ./src/
OBJ_DIR   = ./obj/
BIN_DIR   = .
TEST_SCRIPT=./test.sh
DEBUG= -DDEBUG=0
DBG_MODE = 
#----------------- Compile + linker ------------------
SRC  := $(wildcard $(SRC_DIR)/*.c)
INCL := $(wildcard $(SRC_DIR)/*.h)
OBJ  := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
rm       = rm -f

all: build

build: $(BIN_DIR)/$(PROJECT)

debug: CFLAGS += -g -DDEBUG=0
debug: LFLAGS += -g -DDEBUG=0
debug: mrproper build
debug: DBG_MODE += 1
gdb : CFLAGS += -g
gdb: LFLAGS += -g -ldl
gdb: build
	$(DBG) $(BIN_DIR)/$(PROJECT)

.PHONY: run
run: build
    ifneq ($(DBG_MODE),1)
		$(BIN_DIR)/$(PROJECT)
    endif

$(BIN_DIR)/$(PROJECT): $(OBJ)
	@$(LCC) $(OBJ) $(LFLAGS) -o $@

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@$(rm) $(OBJ)

.PHONY: mrproper
mrproper: clean
	@$(rm) $(BIN_DIR)/$(PROJECT)

