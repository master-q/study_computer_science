SUBDIRS := $(wildcard */*/)

all test clean:
	@for i in $(SUBDIRS); do \
		$(MAKE) -C $$i $@; \
	done

.PHONY: all test clean $(SUBDIRS)
