define Image/Build/squashfs
	@echo "build hh"
endef

define Image/Build
	$(call Image/Build/squashfs)
endef

define Image/mkfs/squashfs
	@echo "mkfs hh"
	$(call Image/Build,squashfs)
endef

all:
	$(call Image/mkfs/squashfs)
