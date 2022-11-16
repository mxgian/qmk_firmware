/*
Copyright 2021 Matthew Dias <matthewdias@me.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#define _L0 0
#define _L1 1
#define _L2 2
#define _L3 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( \
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_BSPC, \
        LT(3,KC_TAB),  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, LT(2,KC_ENT),           \
        KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP),          \
        KC_LCTL, KC_LALT, KC_LGUI,  LT(1, KC_SPC), LT(2, KC_SPC),   LT(_L1,KC_LEFT), LT(_L2,KC_DOWN), LT(_L3,KC_RIGHT)           \
    ),

    [1] = LAYOUT( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,  \
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO,  \
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT, \
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS           \
    ),

    [2] = LAYOUT( \
        _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,   \
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,  \
         _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,                       KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS   \
    ),
    [3] = LAYOUT( \
        KC_TRNS, KC_1,    KC_UP,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,          \
        KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_VOLD,          \
        KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,                       KC_TRNS,            KC_LEFT, KC_DOWN, KC_RIGHT   \
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
