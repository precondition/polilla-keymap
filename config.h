#pragma once

// Home row mods settings //

// Default tapping term is 200
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY // See bottom of keymap.c

// This prevents accidental repeats of the tap-hold keys when typing quickly.
//#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 60

#define COMBO_TERM 30

// Use the native int size for STM for layer size to save up on firmware space
#define LAYER_STATE_32BIT


#define TAP_CODE_DELAY 30

// Save firmware space
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// Disable hardware lock switches support to free up space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// tap_code(KC_CAPS) blocks for TAP_HOLD_CAPS_DELAY (default 80ms) while the
// matrix isn't scanned, so a key tapped quickly after toggling CAPS_WORD_LOCK
// gets dropped (e.g. "DMS" → "MS"). The 80ms default is only needed by macOS,
// which ignores very short Caps Lock taps; Linux is fine with a short delay.
#define TAP_HOLD_CAPS_DELAY 10

// Save space on native repeat key feature.
#define NO_ALT_REPEAT_KEY

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RIGHT_CTRL
#define MODS_TO_NEUTRALIZE { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI), MOD_BIT(KC_LEFT_ALT)|MOD_BIT(KC_LEFT_SHIFT), MOD_BIT(KC_LEFT_ALT)|MOD_BIT(KC_RIGHT_SHIFT)  }

// Custom config settings that are not part of QMK core. //

// Define the delay to wait for before pressing the next key in a sequence of
// keys defined as a part of a macro/custom keycode.
#define KEY_SEQ_DELAY 10

// The second key must be pressed within ADAPTIVE_KEY_TERM milliseconds of the
// last input activity for the adaptive key functionality to take effect.
// Applies to adaptive swaps as well.
#define ADAPTIVE_KEY_TERM 809

// Shamelessly stolen mouse key settings from @pierrechevalier83 //

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Hz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100
