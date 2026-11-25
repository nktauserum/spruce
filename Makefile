CXX = g++
CPPFLAGS = -Wall -Wextra -pedantic -O3 -march=native -mtune=native -DNDEBUG -Iinclude
CXXFLAGS = -fPIC -flto
LDFLAGS = -shared -flto

BUILD_DIR = build
TARGET = $(BUILD_DIR)/spruce.so

SRC = $(shell find src -name "*.cc")
OBJ = $(patsubst src/%.cc,$(BUILD_DIR)/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
