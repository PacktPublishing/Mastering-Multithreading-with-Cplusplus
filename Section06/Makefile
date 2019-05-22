
GCC := g++

OUTPUT := dispatcher_demo
SOURCES := $(wildcard *.cpp)
CCFLAGS := -pthread -std=c++11 -g3

all: $(OUTPUT)
	
$(OUTPUT):
	$(GCC) $(SOURCES) -o $(OUTPUT) $(CCFLAGS) 
	
clean:
	rm $(OUTPUT)
	
.PHONY: all
