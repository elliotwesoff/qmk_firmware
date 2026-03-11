/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,                KC_HOME,    KC_MUTE,
        KC_F7,                  KC_F8,      LSFT(KC_F8),
        LCTL(LGUI(KC_LEFT)),    MO(1),      LCTL(LGUI(KC_RIGHT))
    ),
    [1] = LAYOUT(
        QK_BOOT,    _______,    _______,
        LALT(KC_TAB),           KC_HOME,    KC_END,
        _______,    _______,    _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    // knob 1
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(QK_MOUSE_WHEEL_DOWN);
        } else {
            tap_code(QK_MOUSE_WHEEL_UP);
        }
    }
    // knob 2
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    // knob 3
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
