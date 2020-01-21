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

#define LAYOUT_atreus( \
    K00,   K01,   K02,   K03,   K04,                 K40,   K41,   K42,   K43,   K44, \
    K10,   K11,   K12,   K13,   K14,                 K50,   K51,   K52,   K53,   K54, \
    K20,   K21,   K22,   K23,   K24,                 K60,   K61,   K62,   K63,   K64, \
    K30,   K31,   K32,   K33,   K34,   K35,   K70,   K71,   K72,   K73,   K74,   K75  \
) { \
  { K00, K01, K02, K03, K04, KC_NO }, \
  { K10, K11, K12, K13, K14, KC_NO }, \
  { K20, K21, K22, K23, K24, KC_NO }, \
  { K30, K31, K32, K33, K34, K35   }, \
  { K44, K43, K42, K41, K40, KC_NO }, \
  { K54, K53, K52, K51, K50, KC_NO }, \
  { K64, K63, K62, K61, K60, KC_NO }, \
  { K75, K74, K73, K72, K71, K70   }  \
}

//#define ALPHA XP(UCM_LDEL, UCM_UDEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_atreus_wrapper( /* Qwerty */
    ________________ATREUS_L1__________________,                   ________________ATREUS_R1__________________,
    ________________ATREUS_L2__________________,                   ________________ATREUS_R2__________________,
    ________________ATREUS_L3__________________,                   ________________ATREUS_R3__________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
  [_DVORAK] = LAYOUT_atreus_wrapper( /* Qwerty */
    ________________DVORAK_L1__________________,                   ________________DVORAK_R1__________________,
    ________________DVORAK_L2__________________,                   ________________DVORAK_R2__________________,
    ________________DVORAK_L3__________________,                   ________________DVORAK_R3__________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
  [_COLEMAK] = LAYOUT_atreus_wrapper( /* Qwerty */
    ________________COLEMAK_L1_________________,                   ________________COLEMAK_R1_________________,
    ________________COLEMAK_L2_________________,                   ________________COLEMAK_R2_________________,
    ________________COLEMAK_L3_________________,                   ________________COLEMAK_R3_________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
//#if defined(UNICODEMAP_ENABLE)
//#ifdef UNICODE_H
#ifdef UNICODEMAP_ENABLE
  [_GREEK] = LAYOUT_atreus_wrapper(
    ________________GREEK_L1___________________,                   ________________GREEK_R1___________________,
    ________________GREEK_L2___________________,                   ________________GREEK_R2___________________,
    ________________GREEK_L3___________________,                   ________________GREEK_R3___________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
  [_RUSSIAN] = LAYOUT_atreus_wrapper(
    ________________CYRLC_L1___________________,                   ________________CYRLC_R1___________________,
    ________________CYRLC_L2___________________,                   ________________CYRLC_R2___________________,
    ________________CYRLC_L3___________________,                   ________________CYRLC_R3___________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________CYRLC_R4___________________
  ),
  [_RUNES] = LAYOUT_atreus_wrapper(
    ________________FTHRK_L1___________________,                   ________________FTHRK_R1___________________,
    ________________FTHRK_L2___________________,                   ________________FTHRK_R2___________________,
    ________________FTHRK_L3___________________,                   ________________FTHRK_R3___________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
  [_HIRA1] = LAYOUT_atreus_wrapper(
    ________________JIS1_L1____________________,                   ________________JIS1_R1____________________,
    ________________JIS1_L2____________________,                   ________________JIS1_R2____________________,
    ________________JIS1_L3____________________,                   ________________JIS1_R3____________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
  [_HIRA2] = LAYOUT_atreus_wrapper(
    ________________JIS2_L1____________________,                   ________________JIS2_R1____________________,
    ________________JIS2_L2____________________,                   ________________JIS2_R2____________________,
    ________________JIS2_L3____________________,                   ________________JIS2_R3____________________,
    ________________BOTTOM_L4__________________, ____THUMBS_R4___, ________________BOTTOM_R4__________________
  ),
#endif
  [_EDITOR] = LAYOUT_atreus_wrapper( /* ED_A, ED_ESC */
    ________________EDITOR_L1__________________,                   ________________EDITOR_R1__________________,
    ________________EDITOR_L2__________________,                   ________________EDITOR_R2__________________,
    ________________EDITOR_L3__________________,                   ________________EDITOR_R3__________________,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
  ),
  [_NUMBER] = LAYOUT_atreus_wrapper( /* NM_SCLN, NM_BSPC */
    ________________NUMROW_L1__________________,                   ________________NUMROW_R1__________________,
    ________________NUMROW_R1__________________,                   ________________NUMPAD_R2__________________,
    ___________________________________________,                   ________________NUMPAD_R3__________________,
    ___________________________________________, ________________, ________________NUMPAD_R4__________________
  ),
  [_SYMBOL] = LAYOUT_atreus_wrapper( /* SM_SPC */
    ________________SYMROW_L1__________________,                   ________________SYMROW_R1__________________,
    ________________SYMROW_R1__________________,                   ________________SYMROW_R1__________________,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_BSLS, 
    KC_LBRC, _______, _______, _______, _______, ________________, _______, _______, _______, _______, KC_RBRC
  ),
  [_F_KEYS] = LAYOUT_atreus_wrapper( /* FK_DOT */
    ________________FKEYROW_L1_________________,                   ________________FKEYROW_R1_________________,
    ________________FKEYROW_R1_________________,                   ________________FKEYROW_L1_________________,
    KC_F11,  KC_F12,  _______, _______, _______,                   KC_F11,  KC_F12,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_DEBUG] = LAYOUT_atreus_wrapper( /* shhhh... */
    ________________DEBUG_L1___________________,                   ________________DEBUG_R1___________________,
    ________________DEBUG_L2___________________,                   ________________DEBUG_R2___________________,
    ________________DEBUG_L3___________________,                   ________________DEBUG_R3___________________,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
  ),
  [_SECRET] = LAYOUT_atreus( /* shhhh... */
    _______, _______, _______, RUSTY,   FUEL,                      _______, _______, _______, _______, _______,
    AR1ST,   SYSNOC,  _______, _______, _______,                   _______, _______, _______, OS_LAB,  _______,
    CDLOCAL, _______, C0RE,    VAXIS,   _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FINAL] = LAYOUT_atreus( /* . */
    _______, _______, _______, _______, TESTY,                     _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};
