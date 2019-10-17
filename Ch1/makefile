CC = gcc 
SRC= charInputOutput.o tempConv.o detab.o

DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS =-g
else
	CFLAGS=
endif

all: $(SRC)

charInputOutput.o:
tempConv.o:
detab.o: 
	
%.o: %.c 
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean all
clean:
	rm *.o