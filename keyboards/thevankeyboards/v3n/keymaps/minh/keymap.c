#include "v3n.h"

#define _QW 0
#define _L1 1
#define _L2 2
#define _L3 3

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_1, 	 KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    LT(_L3,KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, LT(_L2,KC_ENT),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LALT, KC_LGUI, KC_ENT,  KC_ENT,   LT(_L1,KC_SPC),           KC_SPC,  LT(_L1,KC_LEFT), LT(_L2,KC_DOWN), LT(_L3,KC_RIGHT)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_1, 	 KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT,
    _______, KC_LGUI, _______, _______,          _______, _______,          _______, _______, _______, _______
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
    KC_1, 	 KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_VOLD, _______,
    _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
    KC_F1, 	 KC_F2,    KC_F3,    KC_F4,    RGB_VAI,  RGB_VAD,
    _______, _______, KC_UP, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_DEL,
    _______,  KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_VOLU,
    KC_LSFT, RESET,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_UP,  KC_VOLD,
    _______, KC_LSFT, KC_B,    _______,          _______,  _______,             _______, KC_LEFT, KC_DOWN, KC_RIGHT
  )
};

void process_indicator_update(layer_state_t state, uint8_t usb_led) {
  for (int i = 0; i < 3; i++) {
    setrgb(0, 0, 0, (LED_TYPE *)&led[i]);
  }
  setrgb(200, 23, 23, (LED_TYPE *)&led[0]);
  setrgb(0, 255, 0, (LED_TYPE *)&led[1]);
  setrgb(0, 0, 255, (LED_TYPE *)&led[2]);

  rgblight_set();
};

void keyboard_post_init_user(void) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  process_indicator_update(state, host_keyboard_leds());
    return state;
};


