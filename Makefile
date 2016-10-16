CC=clang++
CFLAGS=--std=c++14 -m64 -g -O0 $(CDIAGNOSTIC_FLAGS)
CDIAGNOSTIC_FLAGS=-Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-private-field -Wno-unused-parameter

LD=clang++
LDFLAGS=-lsamplerate

PROGRAM=bin/program
SOURCES=$(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJECTS=$(patsubst src/%.cpp, bin/%.o, $(SOURCES))
DEPS=$(patsubst src/%.cpp, bin/%.d, $(SOURCES))

install: $(PROGRAM)

run: install
	@./$(PROGRAM)

clean:
	@if [ -e bin/ ]; then rm -r bin/; fi

$(PROGRAM): $(OBJECTS)
	$(LD) -o $(PROGRAM) $^ $(CFLAGS) $(LDFLAGS)

bin/%.o: src/%.cpp bin/%.d
	@echo $@ | sed 's/\/[^/]*$$//' | xargs mkdir -p
	$(CC) -c $(CFLAGS) $< -o $@
	@$(CC) -MM -MP $(CFLAGS) $< | sed '1 s/^/bin\//' > $(word 2, $^)

bin/%.d:
	

.SECONDARY: $(DEPS)

-include bin/*.d
