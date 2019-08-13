/* Copyright 2019 George Koenig
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "ridingqwerty.h"
 
// can move to keymap.h
// modtaps
/*
#define LS_Z MT(MOD_LSFT, KC_Z)
#define LC_ESC MT(MOD_LCTL, KC_ESC)
#define LG_TAB MT(MOD_LGUI, KC_TAB)
#define LA_LBRC MT(MOD_LALT, KC_LBRC)
#define LS_RBRC MT(MOD_LSFT, KC_RBRC)
#define RS_MINS MT(MOD_RSFT, KC_MINS)
#define RA_EQL MT(MOD_RALT, KC_EQL)
//RG_LMOT defined in process_records.h
#define RC_ENT MT(MOD_RCTL, KC_ENT)
#define RS_SLSH MT(MOD_RSFT, KC_SLSH)
// layertaps
#define ED_A LT(_EDITOR, KC_A)
#define ED_ESC LT(_EDITOR, KC_ESC)
#define NM_SCLN LT(_NUMBER, KC_SCLN)
#define NM_BSPC LT(_NUMBER, KC_BSPC)
#define SM_SPC LT(_SYMBOL, KC_SPC)
#define SC_TAB LT(_SECRET, KC_TAB)
#define FK_DOT LT(_F_KEYS, KC_DOT)
*/

/*                                                         Atreus      
        ┏━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┓                 ┏━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┯━━━━━━━━┓
        ┃   Q    │   W    │   E    │   R    │   T    ┃                 ┃   Y    │   U    │   I    │   O    │   P    ┃
        ┠────────┼────────┼────────┼────────┼────────┨                 ┠────────┼────────┼────────┼────────┼────────┨
       /┃  ¶ A   │   S    │   D    │   F    │   G    ┃                 ┃   H    │   J    │   K    │   L    │  🔢 ;  ┃
        ┠────────┼────────┼────────┼────────┼────────┞━━━━━━━━┳━━━━━━━━┞────────┼────────┼────────┼────────┼────────┨
       /┃  ⇧ Z   │   X    │   C    │   V    │   B    │        ┃        │   N    │   M    │   ,    │  𝔽 .   │  ⇧ /   ┃
        ┠────────┼────────┼────────┼────────┼────────┤  ¶ ⎋   ┃  ❦ ⇥   ├────────┼────────┼────────┼────────┼────────┨
        ┃  ⎈ ⎋   │  ⌘ ⇥   │  ⎇ [   │  ⇧ ]   │ 🔢 ⌫   │        ┃        │  ★ ␣   │  ⇧ -   │  ⎇ =   │  ⌘ '   │  ⎈ ↵   ┃
        ┗━━━━━━━━┷━━━━━━━━┷━━━━━━━━┷━━━━━━━━┷━━━━━━━━┷━━━━━━━━┻━━━━━━━━┷━━━━━━━━┷━━━━━━━━┷━━━━━━━━┷━━━━━━━━┷━━━━━━━━┛
                    MODS                   //              LAYERS              //                  MODS           //
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    ED_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    NM_SCLN,
    LS_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, FK_DOT,  RS_SLSH,
    LC_ESC,  LG_TAB,  LA_LBRC, LS_RBRC, NM_BSPC, ED_ESC,  SC_TAB,  SM_SPC,  RS_MINS, RA_EQL,  RG_QUOT, RC_ENT
  ),
  [_EDITOR] = LAYOUT( /* ED_A, ED_ESC */
    KC_GRV,  _______, KC_END,  _______, KC_TAB,                    _______, _______, KC_INS,  _______, KC_PGUP,
    KC_HOME, _______, KC_DELT, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT, 
    _______, _______, _______, _______, _______,                   KC_PGDN, _______, _______, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______
  ),
  [_NUMBER] = LAYOUT( /* NM_SCLN, NM_BSPC */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, KC_4,    KC_5,    KC_6,    _______,
    _______, _______, _______, _______, _______,                   _______, KC_1,    KC_2,    KC_3,    KC_BSLS,
    _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_0,    KC_0,    KC_DOT,  _______, _______
  ),
  [_SYMBOL] = LAYOUT( /* SM_SPC */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                   _______, _______, _______, _______, KC_COLN, 
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_BSLS, 
    _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______
  ),
  [_F_KEYS] = LAYOUT( /* FK_DOT */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    _______, _______, _______, _______, KC_F11,
    KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_SECRET] = LAYOUT( /* shhhh... */
    RESET,   _______, _______, RUSTY,   FUEL,                      KC_F13,  _______, _______, _______, _______,
    AR1ST,   SYSNOC,  _______, _______, _______,                   _______, _______, _______, OS_LAB,  _______,
    CDLOCAL, _______, C0RE,    VAXIS,   _______,                   _______, MUNKY,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FINAL] = LAYOUT( /* . */
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

// custom tap/hold keys
uint16_t key_timer;
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case RG_QUOT:   
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(_NUMBER);
                register_mods(MOD_BIT(KC_RGUI));
            } else {
                unregister_mods(MOD_BIT(KC_RGUI));
                layer_off(_NUMBER);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    register_code(KC_QUOT);
                    unregister_code(KC_QUOT);
                }
            }
            return false; break;
    }
    return true;
};
