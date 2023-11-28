PROG = main.exe 
SRC = main.cpp
CFLAGS = -g -std=c++20
LIBS = 
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean