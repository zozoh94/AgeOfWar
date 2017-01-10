CFLAGS = -W -Wall -std=c++14 -O4
LDFLAGS =
DEP = airedejeu.o archer.o catapulte.o fantassin.o humain.o ia.o joueur.o supersoldat.o typeunite.o unite.o
CC = g++
NAME = ageofwar

ifeq (${DEBUG}, 1)
	CFLAGS += -g -O0
endif

all: $(DEP)
	$(CC) $(addprefix bin/, $(DEP)) src/main.cpp -o bin/$(NAME) $(CFLAGS) $(LDFLAGS)

%.o: src/%.cpp
	$(CC) -c $< -o bin/$@ $(CFLAGS)

#clean
clean:
	rm -rf bin/*.bak; rm -rf bin/*.o

#mrproper
mrproper: clean
	rm -f bin/($NAME)
