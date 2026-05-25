CXX ?= g++
CXXFLAGS ?= -std=c++23 -Wall -Wextra -Isrc

TARGET = pkgbridge

SRC = $(wildcard \
src/*.cpp \
src/*/*.cpp \
src/*/*/*.cpp \
)

OBJ = $(SRC:.cpp=.o)

# =========================
# Default build
# =========================
all: CXXFLAGS += -O2
all: $(TARGET)

# =========================
# Debug build
# =========================
debug: CXXFLAGS += -g -O0
debug: $(TARGET)

# =========================
# Link step (cached objects)
# =========================
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# =========================
# Compile step (THIS is the cache)
# =========================
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
# Install
# =========================
install: $(TARGET)
	sudo install -m 755 $(TARGET) /usr/local/bin/$(TARGET)

# =========================
# Clean
# =========================
clean:
	rm -f $(TARGET) $(OBJ)

# =========================
# Run
# =========================
run: $(TARGET)
	./$(TARGET)
