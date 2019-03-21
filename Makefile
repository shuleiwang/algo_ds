
lib_dir := $(CURDIR)/lib/
inc_dir := $(CURDIR)/include
sub_dir := src/linked_list
CC := gcc
CPPFLAGS := -I $(CURDIR)/include/
AR := ar
ARFLAGS := -r
RANLIB := ranlib
LD := ld
MV := mv
RM := rm -rf
CP := cp -r

export lib_dir
export inc_dir
export CC
export CPPFLAGS
export AR
export ARFLAGS
export RANLIB
export LD
export MV
export RM
export CP

.PHONY: all clean
all:
	$(MAKE) --directory=$(sub_dir)

clean:
	$(MAKE) clean --directory=$(sub_dir)
	$(RM) $(lib_dir)*.*

