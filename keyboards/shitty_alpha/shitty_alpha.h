#pragma once

#include "quantum.h"

#define LAYOUT( \
         K01,       K03,            K06, K07,     K08,      K0A,       K0C,       \
    K10,      K12,  K13,            K16,    K17,  K18,      K1A,  K1B,      K1D,  \
    K20, K21, K22,                  K26, K27,     K28, K29, K2A,  K2B, K2C, K2D,  \
    K30,      K32,  K33, K34, K35,  K36,          K38,      K3A,  K3B,      K3D   \
) { \
    { KC_NO, K01,   KC_NO, K03,   KC_NO, KC_NO, K06, K07,   K08, KC_NO, K0A, KC_NO, K0C,   KC_NO }, \
    { K10,   KC_NO, K12,   K13,   KC_NO, KC_NO, K16, K17,   K18, KC_NO, K1A, K1B,   KC_NO, K1D   }, \
    { K20,   K21,   K22,   KC_NO, KC_NO, KC_NO, K26, K27,   K28, K29,   K2A, K2B,   K2C,   K2D   }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36, KC_NO, K38, KC_NO, K3A, K3B,   KC_NO, K3D   }, \
}
