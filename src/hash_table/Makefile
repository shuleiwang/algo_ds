
lib := libhashtable.a
sources := chash_table.c oa_hash_table.c
objects := $(subst .c,.o,$(sources))

$(lib): $(objects)
	$(AR) $@ $^
	$(RANLIB) $@
	$(MV) $(lib) $(lib_dir)

$(objects): $(inc_dir)/linked_list $(inc_dir)/hash_table/

.PHONY: clean
clean:
	-$(RM) $(objects) $(lib)

