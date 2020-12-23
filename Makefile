BIN = comp
DATE = $(shell date +%Y%m%d)
BIN_NAME = $(BIN)_$(DATE)

CC = gcc
BUILD_DIR = ./.build
SRC_PATH = src
INCLUDE_PATH = inc

SRC_FILE = $(wildcard $(SRC_PATH)/*.c)
INCLUDE_FILE = $(wildcard $(INCLUDE_PATH)/*.h)
OBJ_FILE = $(patsubst $(SRC_PATH)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILE))
CFLAGS = -Wall $(patsubst %,-I%,$(INCLUDE_PATH))
LDFLAGS = -lrt

all: $(BIN_NAME)

$(BIN_NAME): $(OBJ_FILE)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJ_FILE): $(BUILD_DIR)/%.o: $(SRC_PATH)/%.c $(INCLUDE_FILE)
	$(shell mkdir -p $(BUILD_DIR))
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(BIN)*

.PHONY: clean all