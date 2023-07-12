CXX = g++
CXXFLAGS = -O3 -pedantic-errors -std=c++20
BINARIES := $(patsubst %.cpp,%,$(wildcard *.cpp))

.PHONY: all clean run
.SILENT: run

all: $(BINARIES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(BINARIES)
	$(foreach prog,$^,echo "=== $(prog) ==="; ./$(prog);)

clean:
	rm -f $(BINARIES)
