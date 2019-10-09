/* Copyright 2019 George Koenig
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
//#include "minorca.h"
#include QMK_KEYBOARD_H
#include "ridingqwerty.h"
//#include "tapdance.c"
//#include "unicode.h"

// FIXME
/*                                                         MinOrca
        ┏━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┓
        ┃   ⎋    │   Q    │   W    │   E    │   R    │   T    │   Y    │   U    │   I    │   O    │   P    │  ❦ ⌫   ┃
        ┠────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────┨
        ┃   ¶ ⇥    │   A    │   S    │   D    │   F    │   G    │   H    │   J    │   K    │   L    │     🔢 ↵      ┃
        ┠──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬───────────┨
        ┃    " ⇧       │   Z    │   X    │   C    │   V    │   B    │   N    │   M    │   ,    │  𝔽 .   │    ⇧ /    ┃
        ┠──────────┬───┴──────┬─┴────────┼────────┴────────┴──┬─────┴────────┴─────┬──┴───────┬┴───────┬┴───────────┨
        ┃   { ⎈    │   [ ⌘    │  (  ⌥    │       🔢 ␣         │       ★ ␣          │   ) ⌥    │  ] ⌘   │    } ⎈     ┃
        ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━┷━━━━━━━━━━━━┛
*/

#define LAYOUT( \
    KA00, KA01, KA02, KA03, KA04, KA05, KA06, KA07, KA08, KA09, KA10, KA11, \
    KB00,  KB01, KB02, KB03, KB04, KB05, KB06, KB07, KB08, KB09,    KB11,   \
    KC00,    KC02, KC03, KC04, KC05, KC06, KC07, KC08, KC09, KC10,   KC11,  \
    KD00,  KD02,  KD03,          KD04, KD07,           KD09,  KD10,  KD11   \
) { \
  {  KA00,  KA01,   KA02,  KA03,  KA04,  KA05,   KA06,   KA07,  KA08,   KA09,  KA10,   KA11  }, \
  {  KB00,  KB01,   KB02,  KB03,  KB04,  KB05,   KB06,   KB07,  KB08,   KB09,  KC_NO,  KB11  }, \
  {  KC00,  KC_NO,  KC02,  KC03,  KC04,  KC05,   KC06,   KC07,  KC08,   KC09,  KC10,   KC11  }, \
  {  KD00,  KC_NO,  KD02,  KD03,  KD04,  KC_NO,  KC_NO,  KD07,  KC_NO,  KD09,  KD10,   KD11  } \
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = {
        {KC_GESC,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     SC(BSPC) }, 
        {ED(TAB),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     XXXXXXX,  NM(SCLN) }, 
        {LS(QUOT), XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  FK(DOT),  RS(SLSH) }, 
        {LC(ESC),  XXXXXXX,  LG(LBRC), LA(RBRC), NM(BSPC), XXXXXXX,  XXXXXXX,  SM(SPC),  XXXXXXX,  RA(MINS), RG(EQL),  RC(ENT)  }
/*
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
*/

        
    },
#ifdef UNICODE_H
    [_RUNE] = { 
        {KC_ESC,  X(INGWZ), X(WUNJO),  X(EHWAZ), X(RAIDO), X(TIWAZ), X(IWAZ),  X(UR),    X(ISAZ),  X(ETHEL), X(PERTH), SC(BSPC) },
        {ED(TAB), X(ANSUZ), X(SOWIL),  X(DAGAZ), X(FE),    X(GEBO),  X(HAGLZ), X(JERAN), X(KAUNA), X(LAUKZ), XXXXXXX,  NM(SCLN) },
        {MT_QUOT, XXXXXXX,  X(ALGIZ),  X(THURS), X(KAUNA), X(WUNJO), X(BEORC), X(NAUDZ), X(MANNZ), KC_COMM,  FK(DOT),  RS(SLSH) },
        {LC(ESC), XXXXXXX,  LG(LBRC),  LA(RBRC), NM(BSPC), XXXXXXX,  XXXXXXX,  SM(SPC),  XXXXXXX,  RA(MINS), RG(EQL),  RC(ENT)  }
    },
#endif
    [_EDITOR] = {
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        {KC_GRV,  _______, _______, KC_END,  _______, KC_F5,   _______, _______, KC_INS,  _______, KC_PGUP, KC_DELT },
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        {_______, KC_HOME, _______, KC_DELT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_SCLN },
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
        {_______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PGDN, _______, KC_SCLN, KC_QUOT, KC_BSLS },
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
        {_______, XXXXXXX, _______, _______, KC_EQL,  XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX, KC_COLN, KC_DQUO, KC_PIPE }
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
    },
    [_NUMBER] = {
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        {KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        {_______, KC_4,    KC_5,    KC_6,    KC_PAST, _______, KC_PPLS, KC_4,    KC_5,    KC_6,    XXXXXXX, _______ },
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
        {_______, KC_7,    KC_8,    KC_9,    KC_SLSH, _______, _______, KC_MINS, KC_1,    KC_2,    KC_3,    _______ },
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
        {_______, XXXXXXX, KC_0,    _______, _______, XXXXXXX, XXXXXXX, KC_0,    XXXXXXX, KC_DOT,  _______, _______ }
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
    },
    [_SYMBOL] = {
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELT },
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, XXXXXXX, _______ },
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
        {_______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_SCLN, KC_QUOT, KC_BSLS },
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
        {_______, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_COLN, KC_DQUO, KC_PIPE }
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
    },
#ifdef MOUSEKEY_ENABLE
    [_MOUSE] = {
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        {_______, KC_BTN2, KC_MS_U, KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______ },
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, XXXXXXX, _______ },
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
        {_______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
        {_______, XXXXXXX, _______, _______, KC_ACL0, XXXXXXX, XXXXXXX, KC_ACL2, XXXXXXX, _______, _______, _______ }
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
    },
#endif
    [_SECRET] = {
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        {RESET,   _______, _______, _______, RUSTY,   FUEL,    _______, _______, _______, _______, VERSION, _______ },
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        {_______, AR1ST,   SYSNOC,  DEBUG,   FLAG,    _______, _______, _______, _______, OS_LAB,  XXXXXXX, MAKE    },
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
        {_______, XXXXXXX, _______, _______, C0RE,    VAXIS,   _______, _______, MUNKY,   _______, _______, _______ },
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
        {_______, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______ }
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
    },
    [_F_KEYS] = {
      //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        {KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______ },
      //├────────┴────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤
        {_______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
      //├─────────────────┼────────┼────────┼────────┴────────┼────────┴────────┼────────┴────────┼────────┼────────┤
        {_______, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, _______ }
      //└─────────────────┴────────┴────────┴─────────────────┴─────────────────┴─────────────────┴────────┴────────┘
    },
};

uint16_t key_timer;
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    // multi-function macros
    switch(keycode) {
/*
        case MT_LBRC:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("{");
                }
            }
            return false; break;
        case MT_RBRC:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RCTL);
            } else {
                unregister_code(KC_RCTL);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("}");
                }
            }
            return false; break;
        case MT_LBRK:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("[");
                }
            }
            return false; break;
        case MT_RBRK:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RGUI);
            } else {
                unregister_code(KC_RGUI);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("]");
                }
            }
            return false; break;
        case MT_LPRN:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("(");
                }
            }
            return false; break;
        case MT_RPRN:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RALT);
            } else {
                unregister_code(KC_RALT);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING(")");
                }
            }
            return false; break;
*/
        }
    return true;
};

void matrix_init_keymap(void) {
    set_unicode_input_mode(UC_LNX);
}
