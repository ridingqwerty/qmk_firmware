#pragma once

#define TAPPING_TERM 175
#define MACRO_TIMER 5
#define TAPPING_FORCE_HOLD_PER_KEY

#if (BOOTMAGIC_ENABLE == LITE)
#    define BOOTMAGIC_LITE_ROW 0
#    define BOOTMAGIC_LITE_COL 0
#endif

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 5
#    define COMBO_TERM 85
#endif

#ifdef LEADER_ENABLE
#    define LEADER_TIMEOUT 300
#    define LEADER_PER_KEY_TIMING
#endif

// testing
#define TAPPING_TERM_PER_KEY
//#define IGNORE_MOD_TAP_INTERRUPT // rolling R3 "zxcv", etc...
