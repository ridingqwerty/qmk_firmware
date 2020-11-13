#include "ridingqwerty.h"

__attribute__((weak))
void matrix_init_keymap(void) {}

void matrix_init_user(void) {
    matrix_init_keymap();

#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
    set_unicode_input_mode(UC_LNX);
#endif

    //set_single_persistent_default_layer(_QWERTY);
    default_layer_set(1U << _QWERTY);
}

__attribute__((weak))
void matrix_scan_keymap(void) {
}

bool     randchar_mode = false;
uint32_t rng_char_timer = 0;

LEADER_EXTERNS();
void matrix_scan_user(void) {

  if (randchar_mode) {
    if (rng_char_timer > 0) {
      rng_char_timer--;
    } else {
      tap_random_base64();
      rng_char_timer = timer_read32() % 1000;
      if ((rng_char_timer % 10) == 0) tap_code(KC_SPC);
      if ((rng_char_timer % 45) == 0) tap_code(KC_ENT);
    }
  }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    /*
    SEQ_ONE_KEY(KC_T) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LCTRL(SS_LSFT("t")));
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
    SEQ_TWO_KEYS(KC_N, KC_T) {
      // When I press KC_LEAD and then N followed by T, this sends CTRL + T
      SEND_STRING(SS_LCTRL("t"));
    }
    */
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("leader test\n");
    }
    SEQ_FOUR_KEYS(KC_L, KC_E, KC_E, KC_T) {
      if (!(mode.spongebob ^= 1)) { mode.all = 0U; };
    }
    SEQ_FIVE_KEYS(KC_S, KC_P, KC_O, KC_N, KC_G) {
      if (!(mode.spongebob ^= 1)) { mode.all = 0U; };
    }
    SEQ_FIVE_KEYS(KC_S, KC_T, KC_R, KC_A, KC_Y) {
      if (!(mode.australia ^= 1)) { mode.all = 0U; };
    }
    SEQ_FIVE_KEYS(KC_V, KC_A, KC_P, KC_O, KC_R) {
      if (!(mode.aesthetic ^= 1)) { mode.all = 0U; };
    }
    SEQ_FIVE_KEYS(KC_C, KC_L, KC_E, KC_A, KC_R) {
      // clear modes (STRICT_KEY_PROCESSING? need one for ED(A)? 
      mode.all = 0U;
      // add another line to set back to QWERTY?
    }
  }
}

__attribute__((weak))
void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
#if defined(CONSOLE_ENABLE)
    debug_enable = true;
    debug_matrix = true;
    //debug_keyboard=true;
    //debug_mouse=true;
    uprintf("Post Init: Debug Enabled\n");
#endif
}

__attribute__((weak))
layer_state_t   layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _EDITOR, _DEBUG, _SECRET);
#ifdef CONSOLE_ENABLE
    uprintf("LAYER: %u\n", state);
#endif
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RC(ENT):
    case ED(ESC):
      return 225;
    default:
      return TAPPING_TERM;
  }
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NM(SCLN):
      return true;
    default:
      return false;
  }
}

mode_config_t mode = {.all = 0U};
