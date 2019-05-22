
GCC := g++

OUTPUT := code2
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++11

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) $(SOURCES) -o $(OUTPUT) -pthread $(CCFLAGS)

clean:
	rm $(OUTPUT)

.PHONY: all
