
sources := $(wildcard *.c)

sort_test: $(sources)
	$(CC) $(CPPFLAGS) $< $(lib_dir)/libsort.a -o $@

.PHONY : all clean
all : sort_test
	$(MV) $< $(build_dir)

clean:
	$(RM) $(build_dir)/sort_test

