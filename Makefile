# Build each library with its own Makefile. Archives stay in their directories.
SUBDIRS := libft gnl printfs
CLEAN_TARGETS := $(addsuffix -clean,$(SUBDIRS))
FCLEAN_TARGETS := $(addsuffix -fclean,$(SUBDIRS))

.DEFAULT_GOAL := all
.PHONY: all bonus clean fclean re norm test check
.PHONY: $(SUBDIRS) $(CLEAN_TARGETS) $(FCLEAN_TARGETS)

all: $(SUBDIRS)

$(SUBDIRS):
	+$(MAKE) -C $@ all

# All sources, including bonus sources, are already part of each library.
bonus: all

clean: $(CLEAN_TARGETS)

$(CLEAN_TARGETS): %-clean:
	+$(MAKE) -C $* clean

fclean: $(FCLEAN_TARGETS)

$(FCLEAN_TARGETS): %-fclean:
	+$(MAKE) -C $* fclean

# Keep deletion and compilation sequential, including with make -j.
re:
	+$(MAKE) fclean
	+$(MAKE) all

norm:
	norminette $(SUBDIRS)

check: all norm
