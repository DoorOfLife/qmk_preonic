#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

//#define DYNAMIC_MACRO_NO_NESTING

// The time in ms before a dual purpose key is interpreted as a hold, rather than a tap
#define TAPPING_TERM 180
/*
 * This mode makes tap and hold keys (like Layer Tap) work better for fast typists,
 * or for high TAPPING_TERM settings. Compared to the “permissive hold” mode,
 * this mode selects the hold action in more cases.
 * If a dual-purpose key is held, and then a second is pressed, the dual-purpose key is immediately counted as a hold (and not a tap)
 */
#define HOLD_ON_OTHER_KEY_PRESS
/*
 * If the IGNORE_MOD_TAP_INTERRUPT option is enabled, Mod Tap keys are no longer treated as a special case,
 * and their behavior will match the behavior of other dual-role keys such as Layer Tap.
 * Then the behavior of Mod Tap keys can be further tuned using other options such as PERMISSIVE_HOLD or HOLD_ON_OTHER_KEY_PRESS.
 */
#define IGNORE_MOD_TAP_INTERRUPT
/*
 * Allowing to use a dual-purpose key as a modifier shortly after having used it as a tap.
 */
#define TAPPING_FORCE_HOLD
#define EXTRA_SHORT_COMBOS
//By defining COMBO_NO_TIMER, the timer is disabled completely and combos are activated on the first key release.
// This also disables the "must hold" functionalities as they just wouldn't work at all.
#define COMBO_NO_TIMER
