# ----------------------------
# Makefile Options
# ----------------------------

NAME = Dungeon
ICON = iconc.png
DESCRIPTION = "Demonic Dungeon"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -O0
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
