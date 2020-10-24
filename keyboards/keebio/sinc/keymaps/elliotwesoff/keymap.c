#include QMK_KEYBOARD_H

// note to future self:
// the blank space on the bottom left half
// of the board - second from the bottom right
// will *not* fire no matter what keycode you
// put in there. instead, it will trigger
// whichever custom keycode you have defined
// first in this enum. danny help!
enum custom_keycodes {
  WAT,
  ONEPASS,
  APOCALYPSE,
  PI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_iso_with_macro(
    KC_MUTE,                KC_ESC,     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
    ONEPASS,    APOCALYPSE, KC_GRV,     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, KC_HOME,
    PI,         KC_F4,      KC_TAB,     KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,
    KC_F5,      KC_F6,      KC_CAPS,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,  KC_INS,
    KC_F7,      KC_F8,      KC_LSFT,    MO(1),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_F9,      KC_F10,     KC_LCTL,    KC_LALT,  KC_LGUI, KC_LALT, _______, KC_LGUI,          _______, KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_iso_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_HUI, RGB_HUD, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
    RGB_SAI, RGB_SAD, RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    RGB_VAI, RGB_VAD, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WAT:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
      } else {
        unregister_code16(KC_LCTL);
      }
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
