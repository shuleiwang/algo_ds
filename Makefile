
src_dir := src/linked_list

.PHONY: all $(src_dir)
all: $(src_dir)

$(src_dir):
	$(MAKE) --directory=$@

