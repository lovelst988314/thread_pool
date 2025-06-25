cc = g++

target = main
sources = main.cpp
objects = $(sources:.cpp=.o)

CFLAGS = -Wall -Wextra -std=c++11

all: $(target)

$(target): $(objects)
	$(cc) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(objects) $(target)