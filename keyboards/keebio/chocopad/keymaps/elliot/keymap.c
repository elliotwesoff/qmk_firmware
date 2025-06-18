#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "secrets.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  M1, M2, M3, M4, M5, M6, M7, M8, M9, M10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    LCTL(LSFT(KC_LEFT)),    LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),   LCTL(LSFT(KC_LEFT)),
    KC_MPLY,                KC_MPRV,            KC_MNXT,        KC_CALC,
    LGUI(KC_1),             LGUI(KC_2),         LGUI(KC_3),     LGUI(KC_4),
    LGUI(KC_5),             LGUI(KC_6),         LGUI(KC_7),     MO(_FN1)
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    M1,         M2,         M3,         M4,
    M5,         M6,         M7,         M8,
    _______,    M9,         M10,        _______,
    QK_BOOT,    _______,    _______,    _______
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M1:
      if (record->event.pressed) {
        send_string_with_delay(PPTUSER, 10);
        tap_code_delay(KC_TAB, 20);
        send_string_with_delay(PPTPASS, 10);
        tap_code_delay(KC_ENTER, 20);
      }
      break;
    case M4:
      if (record->event.pressed) {
        send_string(ONEPASS);
      }
      break;
    default:
      break;
  }
  return true;
}
