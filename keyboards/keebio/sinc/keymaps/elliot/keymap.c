#include QMK_KEYBOARD_H

enum custom_keycodes {
  M1, M2, M3, M4, M5, M6, M7, M8, M9, M10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    XXXXXXX,                          KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  LSFT(KC_INS),  KC_MUTE,
    LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
    LGUI(KC_7), LGUI(KC_Z),           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    LGUI(KC_5), LGUI(KC_6),           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_BRIU,
    LGUI(KC_3), LGUI(KC_4),           KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_BRID,
    LGUI(KC_1), LGUI(KC_2),           KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  MO(1),            XXXXXXX, KC_SPC,  KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_with_macro(
    _______,    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          KC_PSCR,   _______,
    M9, M10,    RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_DELETE, _______,
    M7, M8,     RGB_MOD, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
    M5, M6,     KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,          _______, _______,
    M3, M4,     _______,          _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_END,  _______, _______, KC_VOLU, _______,
    M1, M2,     _______, _______, _______, _______, _______, _______,          _______, _______, _______,  _______, _______, _______, KC_VOLD, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M4:
      if (record->event.pressed) {
        send_string(ONEPASS);
      }
      break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}
