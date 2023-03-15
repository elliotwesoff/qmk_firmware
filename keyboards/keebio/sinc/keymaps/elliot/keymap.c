#include QMK_KEYBOARD_H
// note to future self:
// the blank space on the bottom left half of the board - second from the bottom right
// will *not* fire no matter what keycode you put in there. instead, it will trigger
// whichever custom keycode you have defined first in this enum. danny help!
enum custom_keycodes {
  WAT,
  M1,
  M2,
  M3,
  M4,
  M5,
  M6,
  M7,
  M8,
  M9,
  M10,
  LCTL_LSFT_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_iso_with_macro(
    XXXXXXX,                     KC_ESC, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                 LSFT(KC_INS), KC_MUTE,
    LCTL_LSFT_TAB, LCTL(KC_TAB), KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC,      KC_HOME,
    LGUI(KC_7), LGUI(KC_Z),      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                        KC_END,
    LGUI(KC_5), LGUI(KC_6),      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,          KC_ENT,       KC_BRIU,
    LGUI(KC_3), LGUI(KC_4),      KC_LSFT,    MO(1),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,        KC_BRID,
    LGUI(KC_1), LGUI(KC_2),      KC_LCTL,    KC_LALT, KC_LGUI, KC_LALT, _______, KC_LCTL,          _______, KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT,          KC_DOWN,      KC_RGHT
  ),
  [1] = LAYOUT_80_iso_with_macro(
    _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PSCR,            _______,
    M9, _______,                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DELETE, _______,
    M7, M8,                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                     _______,
    M5, M6,                       KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,
    M3, M4,                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,
    LGUI(KC_LBRC), LGUI(KC_RBRC), _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,            _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // on the physical keyboard, the "code" key
    // doesn't actually register when you program
    // a value to it on the keymap. instead, it
    // fires the first appearing custom keycode
    // in the custom_keycodes enum definition. WAT
    case WAT:
      if (record->event.pressed) {
        register_code16(KC_LGUI);
      } else {
        unregister_code16(KC_LGUI);
      }
      break;
    case M3:
      if (record->event.pressed) {
        send_string(ONEPASS);
      }
      break;
    case LCTL_LSFT_TAB:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
        register_code16(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code16(KC_LCTL);
        unregister_code16(KC_LSFT);
      }
      break;

  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
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
    return false;
}
