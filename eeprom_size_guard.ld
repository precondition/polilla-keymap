/*
 * Fail the build if the firmware overlaps the emulated EEPROM.
 *
 * On the STM32F042x6, QMK's legacy emulated EEPROM uses the last
 * FEE_PAGE_COUNT (2) × FEE_PAGE_SIZE (1 KiB) of flash but the ChibiOS linker
 * script still gives the whole 32 KiB to the firmware, so nothing prevents
 * the firmware from growing into those pages. When it does, the keyboard
 * becomes unresponsive.
 *
 * .data is the last section stored in flash (its initial values).
 */
ASSERT(LOADADDR(.data) + SIZEOF(.data) <= __flash0_end__ - 2 * 1024,
       "Firmware overlaps the emulated EEPROM in the last 2 KiB of flash. Shrink it or use EEPROM_DRIVER = transient.")
