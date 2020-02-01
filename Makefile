CXX = g++ 
CC = $(CXX)
CPPFLAGS = -std=c++11 -Wall -Wextra -march=native -lpthread -O2
SOURCES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=build/demo

.PHONY: all
	all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: check
check:
	cppcheck --enable=all src/
