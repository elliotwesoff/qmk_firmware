#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAMING 1
#define _RAISE 2

enum custom_keycodes {
  MAIN = SAFE_RANGE,
  CTL_ALT_DEL,
  WIN_SCN_LFT,
  WIN_SCN_RT,
  POP_SCN_DN,
  POP_SCN_UP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    GRAVE_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RGB_TOG,          KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(2),   KC_LCTL, KC_LGUI,                   KC_SPC,  KC_BSPC,  MO(2)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_SPC,  _______, _______,                   _______, _______, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_PSCR, _______, _______, _______, _______, LCTL(LSFT(KC_ESC)),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                             _______, _______, KC_INS,  KC_LBRC, KC_RBRC, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
WIN_SCN_LFT, POP_SCN_DN, POP_SCN_UP, WIN_SCN_RT, KC_VOLD, KC_VOLU,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, KC_MUTE, KC_MPLY, KC_MNXT, KC_TRNS,          KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RALT, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_INS,  KC_DEL,  KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// these *must* be updated when layers are added/removed.
int layer = 0;
int layerCount = 3;

void set_all_leds(int hue, int sat, int val) {
  for (int i = 0; i < RGBLED_NUM; i++) {
    sethsv(hue, sat, val, (LED_TYPE *)&led[i]);
  }
  rgblight_set();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
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
  }
  return true;
}

void encoder_update_user(int index, bool clockwise) {
  clockwise ? layer++ : layer--;

  if (layer > layerCount - 1) {
    layer = 0;
  } else if (layer < 0) {
    layer = layerCount - 1;
  }

  layer_on(layer);

  for (int i = 0; i < layerCount; i++) {
    if (i != layer) {
      layer_off(i);
    }
  }

  if (layer == _QWERTY) {
    set_all_leds(16, 247, 95);
  } else if (layer == _GAMING) {
    set_all_leds(104, 255, 65);
  } else if (layer == _RAISE) {
    set_all_leds(0, 255, 95);
  } else {
    set_all_leds(0, 0, 100); // white if something unexpected happens
  }
}
