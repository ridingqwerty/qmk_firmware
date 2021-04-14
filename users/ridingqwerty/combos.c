#include "combos.h"

const uint16_t PROGMEM x_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {CCCV, TD_BRC, COMBO_END};
const uint16_t PROGMEM build_combo[] = {KC_Q, KC_P, COMBO_END};
//const uint16_t PROGMEM p_combo[] =  {LS(Z), KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_X] = COMBO(x_combo, KC_X),
  [COMBO_CAPS] = COMBO(caps_combo, KC_CAPS),
  //[COMBO_TAB] =  COMBO(tab_combo, KC_TAB),
  [COMBO_TAB] =  COMBO_ACTION(tab_combo),
  [COMBO_BUILD] =  COMBO_ACTION(build_combo),
  //[COMBO_P] =  COMBO(p_combo, KC_P)
};

 __attribute__ ((weak))
void process_combo_keymap(uint8_t combo_index, bool pressed) {
}

/*
void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_TAB:
    if (pressed) {
      tap_code(KC_TAB);
    }
    break;
    case COMBO_BUILD:
    if (pressed) {
      send_string_with_delay_P(PSTR("sleep 1 && bin/qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP "\n"), MACRO_TIMER);
      reset_keyboard();
    }
    break;
  }
}
*/


/*
 * TJ's bullshit below (all in combo.c)
 */

/*
// Combos
enum combo_events {
  //COMBO_RESET,
  CAPS_COMBO,
  CRET,
  COMBOPP,
  COMBO_NEXT,
  COMBO_PREV,
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_ESC2
};

//const uint16_t PROGMEM combo_reset[] = {KC_Q, KC_F, COMBO_END};
#ifdef KEYBOARD_crkbd_rev1
const uint16_t PROGMEM caps_combo[] = {KC_M, KC_V, COMBO_END};
#endif
#ifndef KEYBOARD_crkbd_rev1
const uint16_t PROGMEM caps_combo[] = {KC_K, KC_V, COMBO_END};
#endif
const uint16_t PROGMEM cret[] = {KC_QUOT, KC_O, COMBO_END};
const uint16_t PROGMEM combo_pp[] = {KC_7, KC_9, COMBO_END};
const uint16_t PROGMEM combo_next[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_prev[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_esc2[] = {KC_F, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  //[COMBO_RESET] = COMBO_ACTION(combo_reset),
  [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
  [CRET] = COMBO(cret, KC_ENT),
  [COMBOPP] = COMBO(combo_pp,KC_MPLY),
  [COMBO_NEXT] = COMBO(combo_next,KC_MNXT),
  [COMBO_PREV] = COMBO(combo_prev,KC_MPRV),
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_ESC2] = COMBO(combo_esc2,KC_ESC),
};

 __attribute__ ((weak))
void process_combo_keymap(uint8_t combo_index, bool pressed) {
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_RESET:
    if (pressed) {
      reset_keyboard();
    }
    break;
  }
}
*/
