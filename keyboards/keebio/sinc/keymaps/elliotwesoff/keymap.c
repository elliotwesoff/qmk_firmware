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
  M10
};

enum combo_events {
  PI_COMBO,
  ONEPASS_COMBO,
  APOCALYPSE_COMBO
};

const uint16_t PROGMEM onepass_combo[] = {M1, M8, M10, COMBO_END};
const uint16_t PROGMEM apocalypse_combo[] = {M5, M6, M10, COMBO_END};
const uint16_t PROGMEM pi_combo[] = {M1, M3, M4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [PI_COMBO] = COMBO_ACTION(pi_combo),
  [APOCALYPSE_COMBO] = COMBO_ACTION(apocalypse_combo),
  [ONEPASS_COMBO] = COMBO_ACTION(onepass_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    // ******************************************************
    // for the love of god, do not commit from here...
    case ONEPASS_COMBO:
      if (pressed) {
      }
      break;
    case APOCALYPSE_COMBO:
      if (pressed) {
      }
      break;
    case PI_COMBO:
      if (pressed) {
      }
      break;
    // all the way down to here.
    // i mean it.
    // please don't.
    // thanks.
    // ******************************************************
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_iso_with_macro(
    KC_MUTE,      KC_ESC,     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
    M1,       M2, KC_GRV,     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, KC_HOME,
    M3,       M4, KC_TAB,     KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,
    M5,       M6, KC_CAPS,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,  KC_INS,
    M7,       M8, KC_LSFT,    MO(1),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    M9,       M10,KC_LCTL,    KC_LALT,  KC_LGUI, KC_LALT, _______, KC_LGUI,          _______, KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
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
    // on the physical keyboard, the "code" key
    // doesn't actually register when you program
    // a value to it on the keymap. instead, it
    // fires the first appearing custom keycode
    // in the custom_keycodes enum definition. WAT
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
