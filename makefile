TARGET=welcome
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
LD=g++
LDFLAGS=$(PTHREAD) $(GTKLIB) -rdynamic
OBJS=main.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
main.o: main.cc
	$(CC) -c $(CCFLAGS) main.cc $(GTKLIB) -o main.o