SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -O2 -std=c++17 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
TARGET := $(patsubst main%.cc,pgm%,$(wildcard main*.cc))

all:	$(TARGET)

pgm%:	main%.o widget.o
	$(CXX) -o $@ $^ $(LDFLAGS)
widget.o: widget.cc widget.h # Caution in the recipe!
	$(CXX) -c -o $@ $< -g
.phony:	clean, ec
clean:
	rm -f *.o
	rm -f $(TARGET)
ec: main*.cc # for test
	echo $(patsubst main%.cc,pgm%,$^)
	echo $(TARGET)
# $(patsubst %.cc,%.o,main*.cc)