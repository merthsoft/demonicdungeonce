# ----------------------------
# Makefile Options
# ----------------------------

NAME = Dungeon
ICON = iconc.png
DESCRIPTION = "Demonic Dungeon"
COMPRESSED = YES
COMPRESSED_MODE ?= zx7
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Ofast
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
