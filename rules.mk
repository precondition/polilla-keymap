COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes
STENO_ENABLE = no
TAP_DANCE_ENABLE = yes

LTO_ENABLE = yes
AUTO_SHIFT_ENABLE = no
BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no
UNICODEMAP_ENABLE = no
COMMAND_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_LOCK_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no

CFLAGS += -save-temps=obj

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C += combos.c
endif
