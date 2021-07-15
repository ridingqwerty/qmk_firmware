//#include <stdio.h>
#include <time.h>
#include "ridingqwerty.h"
#include "dict.h"

//testing
#include <string.h>

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

/*
// inherited from ridingqwerty.h
(outdated)
typedef union {
    struct {
        uint8_t aesthetic : 1,
                spongebob : 1,
                uppercase : 1,
                australia : 1,
                unusued   : 4;
    };
    uint8_t all;
} mode_config_t;
mode_config_t mode = {.all = 0U};
*/

// Used in process_record_user(), a layer tap for a custom keycode.
void custom_lt(char s[], keyrecord_t *record) {
  static uint16_t lt_timer;
  if (record->event.pressed) {
    lt_timer = timer_read(); 
  } else {
    if (timer_elapsed(lt_timer) < 200) {
      SEND_STRING(s);
    }
  }
}

void tap_code16_nomods(uint8_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

void tap_unicode_glyph(uint32_t glyph) {
    unicode_input_start();
    register_hex32(glyph);
    unicode_input_finish();
}

void tap_unicode_glyph_nomods(uint32_t glyph) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_unicode_glyph(glyph);
    set_mods(temp_mod);
}

typedef uint32_t (*translator_function_t)(bool is_shifted, uint32_t keycode);

#define DEFINE_UNICODE_RANGE_TRANSLATOR(translator_name, lower_alpha, upper_alpha, zero_glyph, number_one, space_glyph) \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) {                                         \
        switch (keycode) {                                                                                              \
            case KC_A ... KC_Z:                                                                                         \
                return (is_shifted ? upper_alpha : lower_alpha) + keycode - KC_A;                                       \
            case KC_0:                                                                                                  \
                return zero_glyph;                                                                                      \
            case KC_1 ... KC_9:                                                                                         \
                return (number_one + keycode - KC_1);                                                                   \
            case KC_SPACE:                                                                                              \
                return space_glyph;                                                                                     \
        }                                                                                                               \
        return keycode;                                                                                                 \
    }

#define DEFINE_UNICODE_LUT_TRANSLATOR(translator_name, ...)                     \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) { \
        static const uint32_t translation[] = {__VA_ARGS__};                    \
        uint32_t              ret           = keycode;                          \
        if ((keycode - KC_A) < (sizeof(translation) / sizeof(uint32_t))) {      \
            ret = translation[keycode - KC_A];                                  \
        }                                                                       \
        return ret;                                                             \
    }


bool process_record_glyph_replacement(uint16_t keycode, keyrecord_t *record, translator_function_t translator) {
    uint8_t temp_mod   = get_mods();
    uint8_t temp_osm   = get_oneshot_mods();
    bool    is_shifted = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    if (((temp_mod | temp_osm) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) == 0) {
        if (KC_A <= keycode && keycode <= KC_Z) {
            if (record->event.pressed) {
                tap_unicode_glyph_nomods(translator(is_shifted, keycode));
            }
            return false;
        } else if (KC_1 <= keycode && keycode <= KC_0) {
            if (is_shifted) {  // skip shifted numbers, so that we can still use symbols etc.
                return process_record_keymap(keycode, record);
            }
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        } else if (keycode == KC_SPACE) {
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        }
    }
    return process_record_keymap(keycode, record);
}

//DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_name, lower, upper, zero, one, space);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_wide, 0xFF41, 0xFF21, 0xFF10, 0xFF11, 0x2003);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_script, 0x1D4EA, 0x1D4D0, 0x1D7CE, 0x1D7C1, 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_boxes, 0x1F170, 0x1F170, '0', '1', 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_fraktur, 0x1D51E, 0x1D504, '0', '1', 0x2002);
//DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_regional, 0x1F1E6, 0x1F1E6, '0', '1', 0x2003);


DEFINE_UNICODE_LUT_TRANSLATOR(unicode_lut_translator_aussie,
                              0x0250,  // a
                              'q',     // b
                              0x0254,  // c
                              'p',     // d
                              0x01DD,  // e
                              0x025F,  // f
                              0x0183,  // g
                              0x0265,  // h
                              0x1D09,  // i
                              0x027E,  // j
                              0x029E,  // k
                              'l',     // l
                              0x026F,  // m
                              'u',     // n
                              'o',     // o
                              'd',     // p
                              'b',     // q
                              0x0279,  // r
                              's',     // s
                              0x0287,  // t
                              'n',     // u
                              0x028C,  // v
                              0x028D,  // w
                              0x2717,  // x
                              0x028E,  // y
                              'z',     // z
                              0x0269,  // 1
                              0x3139,  // 2
                              0x0190,  // 3
                              0x3123,  // 4
                              0x03DB,  // 5
                              '9',     // 6
                              0x3125,  // 7
                              '8',     // 8
                              '6',     // 9
                              '0'      // 0
);

DEFINE_UNICODE_LUT_TRANSLATOR(unicode_lut_translator_altcodes,
                              'a',     // a
                              'b',     // b
                              0x00A9,  // c
                              'd',     // d
                              'e',     // e
                              'f',     // f
                              'g',     // g
                              0x262d,  // h
                              'i',     // i
                              'j',     // j
                              'k',     // k
                              'l',     // l
                              'm',     // m
                              'n',     // n
                              'o',     // o
                              'p',     // p
                              'q',     // q
                              0x00AE,  // r
                              0x1f571, // s
                              0x2122,  // t
);

bool     randword_seed = false;
uint8_t  user_mod_state;
uint8_t  mod_state;
uint16_t rand_key;
uint16_t temp_keycode;
uint32_t user_key_timer;

bool process_record_altcodes(uint16_t keycode, keyrecord_t *record) {
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
            user_mod_state = (get_mods() | get_oneshot_mods()) & MOD_BIT(KC_RALT);
            if (user_mod_state) {
                unregister_mods(MOD_BIT(KC_RALT));
                process_record_glyph_replacement(keycode, record, unicode_lut_translator_altcodes);
                set_mods(user_mod_state);
                return false;
            }
#endif
        }
    }
    return false;
}

bool process_record_aussie(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            if (!process_record_glyph_replacement(keycode, record, unicode_lut_translator_aussie)) {
                tap_code16_nomods(KC_LEFT);
                return false;
            }
        }
    } else if (record->event.pressed && keycode == KC_SPACE) {
        tap_code16_nomods(KC_SPACE);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_ENTER) {
        tap_code16_nomods(KC_END);
        tap_code16_nomods(KC_ENTER);
        return false;
    } else if (record->event.pressed && keycode == KC_HOME) {
        tap_code16_nomods(KC_END);
        return false;
    } else if (record->event.pressed && keycode == KC_END) {
        tap_code16_nomods(KC_HOME);
        return false;
    } else if (record->event.pressed && keycode == KC_BSPC) {
        tap_code16_nomods(KC_DELT);
        return false;
    } else if (record->event.pressed && keycode == KC_DELT) {
        tap_code16_nomods(KC_BSPC);
        return false;
    } else if (record->event.pressed && keycode == KC_QUOT) {
        tap_unicode_glyph_nomods(is_shifted ? 0x201E : 0x201A);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_DOT) {
        tap_unicode_glyph_nomods(is_shifted ? '>' : 0x02D9);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_SLASH) {
        tap_unicode_glyph_nomods(is_shifted ? 0x00BF : '/');
        tap_code16_nomods(KC_LEFT);
        return false;
    }
    return process_record_keymap(keycode, record);
}

bool process_record_zalgo(uint16_t keycode, keyrecord_t *record) {
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            tap_code16_nomods(keycode);
            int number = (rand() % (8 + 1 - 2)) + 2;
            for (int index = 0; index < number; index++) {
                uint16_t hex = (rand() % (0x036F + 1 - 0x0300)) + 0x0300;
                tap_unicode_glyph(hex);
            }
            return false;
        }
    }
    return process_record_keymap(keycode, record);
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  uprintf("MODS: ");
  uprintf(get_mods() & MOD_MASK_CTRL ?"C":" " );
  uprintf(get_mods() & MOD_MASK_SHIFT?"S":" " );
  uprintf(get_mods() & MOD_MASK_ALT  ?"A":" " );
  uprintf(get_mods() & MOD_MASK_GUI  ?"G":" " );
  uprintf("\n");
#endif

  temp_keycode = keycode;
  if ((mode.all != 0U) && ((keycode != DB(TAB) || keycode != ED(ESC)) && ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)))) {
      temp_keycode &= 0xFF;
  }

  if (mode.spongebob) {
    switch(temp_keycode) {
      case KC_A ... KC_Z:
        if (record->event.pressed) {
          (mode.uppercase ^= 1) == 0 ? tap_code16(S(temp_keycode)) : tap_code(temp_keycode);
        }
        return false;
    }
  }

  if (mode.aesthetic) {
    switch(temp_keycode) {
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
      case KC_A:
        if (record->event.pressed) {
          send_unicode_hex_string("039B");
          tap_code(KC_SPC);
        }
        return false;
      case KC_E:
        if (record->event.pressed) {
          send_unicode_hex_string("039E");
          tap_code(KC_SPC);
        }
        return false;
#else
      case KC_A:
      case KC_E:
        if (record->event.pressed) {
          tap_code16(S(temp_keycode));
          tap_code(KC_SPC);
        }
      return false;
#endif
      case KC_B ... KC_D:
      case KC_F ... KC_Z:
        if (record->event.pressed) {
          tap_code16(S(temp_keycode));
          tap_code(KC_SPC);
        }
        return false;
      case KC_1 ... KC_0:
        if (record->event.pressed) {
          tap_code(temp_keycode);
          tap_code(KC_SPC);
        }
        return false;

      case KC_BSPC:
        if (record->event.pressed) {
          tap_code(KC_BSPC);
          tap_code(KC_BSPC);
        }
        return false;
      case KC_SPC:
        if (record->event.pressed) {
          tap_code(KC_SPC);
          tap_code(KC_SPC);
          tap_code(KC_SPC);
        }
        return false;
    }
  }

  if (mode.l33tsp34k) {
    switch(temp_keycode) {
      case KC_A:
        if (record->event.pressed) {
          tap_code(KC_4);
        }
        return false;

      case KC_E:
        if (record->event.pressed) {
          tap_code(KC_3);
        }
        return false;

      case KC_I:
        if (record->event.pressed) {
          tap_code(KC_1);
        }
        return false;

      case KC_O:
        if (record->event.pressed) {
          tap_code(KC_0);
        }
        return false;

      //default:
        //return true;
    }
  }

  if (mode.fancytext) {
    if (((KC_A <= temp_keycode) && (temp_keycode <= KC_0)) || temp_keycode == KC_SPACE) {
      return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_script);
    }
  }

  if (mode.gothictxt) {
    if (((KC_A <= temp_keycode) && (temp_keycode <= KC_0)) || temp_keycode == KC_SPACE) {
      return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_fraktur);
    }
  }

  switch(keycode) {

    case VERSION:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR(QMK_KEYBOARD ":" QMK_KEYMAP "\nVersion:" QMK_VERSION ", built: " QMK_BUILDDATE "\n"), MACRO_TIMER);
      }
      break;

    case QWERTY ... COLEMAK:
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
    case GREEK ... HIRAGAN:
#endif
      if (record->event.pressed) {
        //set_single_persistent_default_layer(keycode - QWERTY);
        default_layer_set(1U << (keycode - QWERTY));
      }
      break;

    case MAKE:
      if (record->event.pressed) {
        user_mod_state = get_mods() & MOD_MASK_CTRL;
        if (user_mod_state) {
          clear_mods();
          send_string_with_delay_P(PSTR("sleep 1 && "), MACRO_TIMER);
        }
        send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), MACRO_TIMER);
        if (user_mod_state) {
          send_string_with_delay_P(PSTR(":flash\n"), MACRO_TIMER);
          reset_keyboard();
        } else {
          send_string_with_delay_P(PSTR("\n"), MACRO_TIMER);
        }
      }
      break;

    case RNGWORD:
      if (randword_seed == false) {
        randword_seed = true;
        srand(timer_read32());
      }
      rand_key = rand() % NUMBER_OF_WORDS;
      if (record->event.pressed) {
        send_string(dict[rand_key]);
        tap_code(KC_SPC);
      }
      break;

    case TOG_RNG:
      if (randword_seed == false) {
        randword_seed = true;
        srand(timer_read32());
      }
      //rand_key = rand() % NUMBER_OF_WORDS;
      if (record->event.pressed) {
        randchar_mode ^= 1;
        rng_char_timer = timer_read32() % TAPPING_TERM;
        //send_string(dict[rand_key]);
        //tap_code(KC_SPC);
      }
      break; return false;

    case RG_QUOT:
      if (record->event.pressed) {
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
        //user_mod_state = get_mods() & MOD_MASK_ALT;
        user_mod_state = get_mods() & MOD_BIT(KC_RALT);
        if (user_mod_state) {
          unregister_mods(MOD_BIT(KC_RALT));
          send_unicode_hex_string("00B0");
          set_mods(user_mod_state);
          return false;
        }
#endif
        user_key_timer = timer_read32();
        layer_on(_NUMBER);
        register_mods(MOD_BIT(KC_RGUI));
      } else {
        unregister_mods(MOD_BIT(KC_RGUI));
        layer_off(_NUMBER);
        if (timer_elapsed32(user_key_timer) < TAPPING_TERM) {
          tap_code(KC_QUOT);
        }
      }
      return false; break;

    case KC_C:
    case KC_H:
    case KC_R:
    case KC_S:
    case KC_T:
      if (record->event.pressed) {
        process_record_altcodes(keycode, record);
      }
      break;

    case TESTING:
      ;
      char s[2];
      strcpy(s,"\"");
      //SEND_STRING(s);
      custom_lt(s,record);
      /*
      if (record->event.pressed) {
        char* str = malloc(100);
        sprintf(str, "%c%d + %d = %d%c%c", 34, 1, 2, 3, 34, 10);
        send_string(str);
        free(str);
      }
      */
      /*
      ;
      long unsigned int test_number = 12345;
      if (record->event.pressed) {
        int length = snprintf( NULL, 0, "%lu", test_number );
        char* str = malloc( length + 1 );
        snprintf( str, length + 1, "%lu", test_number );
        send_string(str);
        free(str);
        // make CFLAGS+="-lc -specs=nosys.specs" board:keymap
      }
      */
      break;

    case CCCV:  // One key copy/paste
      if (record->event.pressed) {
        user_key_timer = timer_read32();
      } else {
        if (timer_elapsed32(user_key_timer) > TAPPING_TERM) {  // Hold, copy
          register_code(KC_LCTL);
          tap_code(KC_C);
          unregister_code(KC_LCTL);
        } else {  // Tap, paste
          register_code(KC_LCTL);
          tap_code(KC_V);
          unregister_code(KC_LCTL);
        }
      }
      break;

    /*
    case KC_SCLN:
      if (record->event.pressed) {
        mod_state = get_mods();                                 // save mod state for testing and later restoration
        if (mod_state & MOD_MASK_SHIFT) {                       // if shift is held
          unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)); // unregister both mods
          tap_code(KC_SCLN);                                    // send ";" unmolested
          set_mods(mod_state);                                  // re-register mod state
          return false;                                         // done processing
        }
        else {                                                  // else, if shift isn't held
          tap_code16(KC_COLN);                                  // send shift+";"
          return false;
        }
      }
      break;
    */

    case SEED:
      if (record->event.pressed) {
        srand(timer_read32());
      }
      break;

    case VPRWAVE ... FANCY:
      if (record->event.pressed) {
        mode.all = 0U;
        mode.all |= (1 << (keycode - VPRWAVE));
      }
      break;

    /*
    case SARCASM:
      if (record->event.pressed) {
        if (!(mode.spongebob ^= 1)) { mode.all = 0U; };
      }
      break;
    */

    case NO_MODE:
      if (record->event.pressed) {
        mode.all = 0U;
        default_layer_set(1U << _QWERTY);
      }
      break;

    case CM_Q:
      if (record->event.pressed) {
        register_code(KC_Q);
      } else {
        unregister_code(KC_Q);
      }
      return false;

    case CM_W:
      if (record->event.pressed) {
        register_code(KC_W);
      } else {
        unregister_code(KC_W);
      }
      return false;

    default:
      if (record->event.pressed && record->event.key.col == 4 && record->event.key.row == 1) {
        if (get_mods() & MOD_BIT(KC_RALT)) {
          unregister_mods(MOD_BIT(KC_RALT));
          //send_unicode_hex_string("262D");
          tap_code(KC_BSPC);
          set_mods(MOD_BIT(KC_RALT));
          return false;
        }
      }
      break;

  }

  if (mode.australia) {
      return process_record_aussie(temp_keycode, record);
  } else if (mode.zalgotext) {
      return process_record_zalgo(temp_keycode, record);
  }

  return process_record_keymap(keycode, record) &&
    process_record_secrets(keycode, record);
}
