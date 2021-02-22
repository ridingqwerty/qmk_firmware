#include QMK_KEYBOARD_H

#define KC_LC KC_LCTL
#define KC_LG KC_LGUI
#define KC_LA KC_LALT
#define KC_LS KC_LSFT
#define FN MO(1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
          KC_A,         KC_B,               KC_C, KC_D,    KC_E,       KC_F,          KC_G,
    KC_H,       KC_I,   KC_J,               KC_K,    KC_L, KC_M,       KC_N,    KC_P,       KC_BSPC,
    KC_Q, KC_R, KC_S,                       KC_T, KC_U,    KC_V, KC_W, KC_X,    KC_Y, KC_Z, KC_ENT,
    KC_LC,      KC_LG,  KC_LA, KC_LS, FN,   KC_SPC,        KC_LEFT,    KC_RGHT, KC_DOWN,    KC_UP
  ),
  [1] = LAYOUT(
          KC_1,         KC_2,               KC_EQL, KC_MINS,  KC_VOLD,    KC_VOLU,               KC_INS,
    KC_3,       KC_4,   KC_5,               KC_LBRC, KC_RBRC, KC_MUTE,    KC_O,         KC_ESC,           KC_DEL,
    KC_6, KC_7, KC_8,                       KC_9,  KC_0,      KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_SCLN, KC_QUOT,
    KC_LC,      KC_LG,  KC_LA, KC_LS, FN,   KC_SPC,           KC_HOME,    KC_END,       KC_PGDN,          KC_PGUP
  )
};
