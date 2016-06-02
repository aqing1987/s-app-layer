# $(patsubst pattern,replacement,text)
# Finds whitespace-separated words in text that match pattern and
# replaces them with replacement.
# Here pattern may contain a ‘%’ which acts as a wildcard,
# matching any number of any characters within a word.


# $(patsubst squashfs-%,squashfs,$(1))

rootfs_type=$(patsubst jffs2-%,jffs2,$(patsubst squashfs-%,squashfs,$(1)))


# can't find xx-* in xx, assign xx to tt1
tt1=$(patsubst xx-%,yy1,xx)
# find xx-* in xx-bbb, replace xx-* with yy2 and assign it to tt2
tt2=$(patsubst xx-%,yy2,xx-bbb)

define Image/Build/squashfs
	@echo "build $(1)"
	@echo $(tt1)
	@echo $(tt2)
endef

define Image/Build
	@echo $(call rootfs_type, $(1))
	$(call Image/Build/$(call rootfs_type,$(1)),$(1))
endef

all:
	$(call Image/Build,squashfs)
