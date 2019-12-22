
inc_dir   := $(CURDIR)/include
lib_dir   := $(CURDIR)/lib
build_dir := $(CURDIR)/build
sub_dir   := $(CURDIR)/src/sort_algo $(CURDIR)/test

silent := @

CC := $(silent)gcc
CPPFLAGS := -I $(inc_dir)
AR := $(silent)ar -rs
LD := $(silent)ld
MV := $(silent)mv
RM := $(silent)rm -rf
CP := $(silent)cp -r

export inc_dir
export lib_dir
export build_dir
export CC
export CPPFLAGS
export AR
export LD
export MV
export RM
export CP

.PHONY : all $(sub_dir)
all : $(sub_dir)

$(sub_dir):
	$(silent)$(MAKE) --directory=$@ $(TARGET)

