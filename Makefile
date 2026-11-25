CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g -Iinclude
LDFLAGS = -shared -flto

BUILD_DIR = build
TARGET = $(BUILD_DIR)/spruce.so

SRC = $(shell find src -name "*.c")
OBJ = $(patsubst src/%.cc,$(BUILD_DIR)/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
