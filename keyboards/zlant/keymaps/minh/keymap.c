#include QMK_KEYBOARD_H

#define BASE 0
#define _LOWER   1
#define _RAISE   2
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   MT(KC_BSPC,KC_DEL), \
    KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
    RGB_HUI, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  /*  BASE LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │ Bspc │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │ ESC  |   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │ LSFT │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │ Enter│
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │LED H+│LCTL  │ LALT │ LGUI │MO1   │    Space    │  MO2 │ Left │ Down │  Up  │ Right│
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */
  [_RAISE]   = LAYOUT(
    MT(KC_GRV,RESET),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PGUP, KC_HOME, _______, _______, \
    RGB_VAI, RGB_VAD, RESET,   KC_PSCR, _______, _______, _______, _______, KC_PGDN, KC_END,  _______, KC_DEL   \
  ),
   [_LOWER]   = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PGUP, KC_HOME, _______, _______, \
    KC_VOLU, KC_VOLD, RESET,   KC_PSCR, _______, _______, _______, _______, KC_PGDN, KC_END,  _______, KC_DEL   \
  )
};  
  /*  RAISE LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │      │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │   -  │   =  │   [  │   ]  │   \  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │      │  F7  │  F8  │   F9 │  F10 │  F11 │  F12 │      │ PgUp │ Home │      │      │
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │LED V+│LED V-│ Reset│ PScr │      │             │      │ PgDn │ End  │      │ Del  │
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */


/*  LOWER LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │  ~   │   !  │   @  │   #  │   $  │   %  │   ^  │   &  │   *  │   (  │   )  │      │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │   _  │   +  │   {  │   }  │   \  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │      │  F7  │  F8  │   F9 │  F10 │  F11 │  F12 │      │ PgUp │ Home │      │      │
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │LED V+│LED V-│ Reset│ PScr │      │             │      │ PgDn │ End  │      │ Del  │
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */