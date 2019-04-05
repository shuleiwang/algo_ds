
lib := liblinkedlist.a
sources := list.c dlist.c sclist.c dclist.c
objects := $(subst .c,.o,$(sources))

$(lib): $(objects)
	$(AR) $@ $^
	$(RANLIB) $@
	$(MV) $(lib) $(lib_dir)

$(objects): $(inc_dir)/linked_list

.PHONY: clean
clean:
	-$(RM) $(objects) $(lib)

