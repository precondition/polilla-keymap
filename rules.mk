CONSOLE_ENABLE = no
COMMAND_ENABLE = no
UNICODEMAP_ENABLE = no
KEY_LOCK_ENABLE = no
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = no
LTO_ENABLE = yes
BOOTMAGIC_ENABLE = no
STENO_ENABLE = yes
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance.c
endif
