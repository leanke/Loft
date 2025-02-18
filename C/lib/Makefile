all: clean build

PROJECT_DIR ?= .
DIR := $(PROJECT_DIR)
LIBRARIES ?= $(PROJECT_DIR)
SRC_DIR := $(DIR)/src
INCLUDE_DIR := $(DIR)/include
BUILD_DIR := $(DIR)/build
BIN_DIR := bin
COMPILER ?= linux_clang
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -O2
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


build: $(PROJECT_DIR).a

$(PROJECT_DIR).a: $(OBJS)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(PROJECT_DIR).a

test:
	$(PROJECT_DIR)

.PHONY: all build clean
