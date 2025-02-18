all: clean build test

PROJECT_DIR ?= .
DIR := projects/$(PROJECT_DIR)
LIBRARIES ?= projects/$(PROJECT_DIR)
SRC_DIR := $(DIR)/src
INCLUDE_DIR := $(DIR)/include
BUILD_DIR := $(DIR)/build
BIN_DIR := bin
COMPILER ?= linux_clang
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -Werror
LDFLAGS :=

ifeq ($(COMPILER), linux_gcc)
	CC := gcc
endif
ifeq ($(COMPILER), linux_clang)
	CC := clang
endif
ifeq ($(COMPILER), windows)
	CC := x86_64-w64-mingw32-g++
endif


DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))


build: $(BIN_DIR)/$(PROJECT_DIR)

$(BIN_DIR)/$(PROJECT_DIR): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBRARIES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)/$(PROJECT_DIR)

test:
	$(BIN_DIR)/$(PROJECT_DIR)

.PHONY: all build clean
