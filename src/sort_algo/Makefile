
sources := $(wildcard *.c)
objects := $(subst .c,.o,$(sources))

$(objects) : $(sources)

libsort.a : $(objects)
	$(AR) $@ $^

.PHONY : all clean
all : libsort.a
	$(MV) $^ $(lib_dir)

clean :
	$(RM) $(objects)

