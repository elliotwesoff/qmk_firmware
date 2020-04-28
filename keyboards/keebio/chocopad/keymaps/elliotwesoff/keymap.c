#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_P7,  KC_P8, KC_P9, KC_KP_PLUS, \
    KC_P4, KC_P5, KC_P6, KC_KP_MINUS, \
    KC_P1, KC_P2, KC_P3, KC_KP_ASTERISK, \
    KC_DOT, KC_P0, KC_KP_SLASH, TO(_FN1)
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    KC_F1, KC_F2, KC_F3, KC_F4, \
    KC_F5, KC_F6, KC_F7, KC_F8, \
    KC_F9, KC_F10, KC_11, KC_12, \
    TO(_BASE), LCTRL(KC_F8), LSFT(KC_F11), TO(_FN2)
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    KC_G, KC_G, KC_G, KC_G \
    KC_G, KC_G, KC_G, KC_G \
    KC_G, KC_G, KC_G, KC_G \
    TO(_FN1), KC_G, KC_G, KC_G
  )

};
