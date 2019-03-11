
CC = clang
CPPFLAGS = -I include/linked_list

VPATH = include/linked_list

list.o: list.h
dlist.o: dlist.h

.PHONY: clean
clean:
	-rm -f *.o

