#include QMK_KEYBOARD_H

#define _BASE 0
#define _FNS 1
#define _NUMPAD 2
#define _GAMING 3
#define _REAPER 4

enum custom_keycodes {
  MAIN = SAFE_RANGE,
  CTL_ALT_DEL,
  WIN_SCN_LFT,
  WIN_SCN_RT,
  POP_SCN_DN,
  POP_SCN_UP,
  LAYER_UP,
  LAYER_DOWN,
  UNDO,
  REDO,
  COD_PING,
  DISCORD_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    WIN_SCN_LFT, POP_SCN_DN, POP_SCN_UP, WIN_SCN_RT, \
    KC_TILDE,    KC_LBRC,    KC_RBRC,    KC_BSLS, \
    KC_MUTE,     KC_VOLD,    KC_VOLU,    KC_MPLY, \
    CTL_ALT_DEL, KC_LALT,    KC_TAB,     LAYER_UP \
  ),

  [_FNS] = LAYOUT_ortho_4x4(
    KC_F1,      KC_F2,       KC_F3,        KC_F4, \
    KC_F5,      KC_F6,       KC_F7,        KC_F8, \
    KC_F9,      KC_F10,      KC_F11,       KC_F12, \
    LAYER_DOWN, LCTL(KC_F8), LSFT(KC_F11), LAYER_UP \
  ),

  [_NUMPAD] = LAYOUT_ortho_4x4(
    KC_P7,      KC_P8, KC_P9,      KC_KP_PLUS, \
    KC_P4,      KC_P5, KC_P6,      KC_KP_MINUS, \
    KC_P1,      KC_P2, KC_P3,      KC_DOT, \
    LAYER_DOWN, KC_P0, KC_NUMLOCK, LAYER_UP \
  ),

  [_GAMING] = LAYOUT_ortho_4x4(
    DISCORD_MUTE, _______,     _______,      COD_PING, \
    _______,      _______,     _______,      _______, \
    _______,      _______,     _______,      _______, \
    LAYER_DOWN,   _______,     _______,      LAYER_UP \
  ),

  [_REAPER] = LAYOUT_ortho_4x4(
    LCTL(KC_R), KC_SPACE,    KC_HOME,      KC_R, \
    UNDO,       REDO,        _______,      _______, \
    _______,    _______,     _______,      _______, \
    LAYER_DOWN, _______,     _______,      KC_LGUI \
  )

};


uint16_t active_layer = 0;
uint16_t top_layer = 4;

uint16_t layer_up(void) {
  active_layer += 1;
  if (active_layer > top_layer) {
    active_layer = top_layer;
  }
  return active_layer;
}

uint16_t layer_down(void) {
  active_layer -= 1;
  if (active_layer < 0) {
    active_layer = 0;
  }
  return active_layer;
}

void set_active_layer(uint16_t layer) {
  for (int i = 0; i <= top_layer; i++) {
    i == layer ? layer_on(i) : layer_off(i);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTL_ALT_DEL:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
        register_code16(KC_LALT);
        tap_code16(KC_DELETE);
      } else {
        unregister_code16(KC_LALT);
        unregister_code16(KC_LCTL);
      }
      break;
    case WIN_SCN_LFT:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
        register_code16(KC_LGUI);
        tap_code16(KC_LEFT);
      } else {
        unregister_code16(KC_LGUI);
        unregister_code16(KC_LCTL);
      }
      break;
    case WIN_SCN_RT:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
        register_code16(KC_LGUI);
        tap_code16(KC_RIGHT);
      } else {
        unregister_code16(KC_LGUI);
        unregister_code16(KC_LCTL);
      }
      break;
    case POP_SCN_DN:
      if (record->event.pressed) {
        register_code16(KC_LGUI);
        tap_code16(KC_DOWN);
      } else {
        unregister_code16(KC_LGUI);
      }
      break;
    case POP_SCN_UP:
      if (record->event.pressed) {
        register_code16(KC_LGUI);
        tap_code16(KC_UP);
      } else {
        unregister_code16(KC_LGUI);
      }
      break;
    case LAYER_UP:
      if (record->event.pressed) {
        set_active_layer(layer_up());
      }
      break;
    case LAYER_DOWN:
      if (record->event.pressed) {
        set_active_layer(layer_down());
      }
      break;
    case UNDO:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
        tap_code16(KC_Z);
      } else {
        unregister_code16(KC_LCTL);
      }
      break;
    case REDO:
      if (record->event.pressed) {
        register_code16(KC_LCTL);
        register_code16(KC_LSFT);
        tap_code16(KC_Z);
      } else {
        unregister_code16(KC_LSFT);
        unregister_code16(KC_LCTL);
      }
      break;
    case COD_PING:
      if (record->event.pressed) {
        tap_code16(KC_LALT);
      }
      break;
    case DISCORD_MUTE:
      if (record->event.pressed) {
        tap_code16(KC_EQUAL);
      }
      break;

  }
  return true;
}