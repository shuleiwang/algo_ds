
lib_dir := $(CURDIR)/lib
inc_dir := $(CURDIR)/inc
src_dir := $(CURDIR)/src/sort_algo 

silent := @

CC := $(silent)gcc
CPPFLAGS := -I $(CURDIR)/inc
AR := $(silent)ar -r
RANLIB := $(silent)ranlib
LD := $(silent)ld
MV := $(silent)mv
RM := $(silent)rm -rf
CP := $(silent)cp -r

export lib_dir
export inc_dir
export CC
export CPPFLAGS
export AR
export RANLIB
export LD
export MV
export RM
export CP

.PHONY: all $(src_dir)
all: $(src_dir)

$(src_dir):
	$(silent)$(MAKE) --directory=$@ $(TARGET)

