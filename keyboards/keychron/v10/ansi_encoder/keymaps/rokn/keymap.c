/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include "keycodes.h"
#include "modifiers.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    BASE,
    NAV_LAYER,
    NUMPAD_LAYER,
    LAYER_3,
    LAYER_4,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

enum custom_keycodes {
    SEND_QMK_FLASH = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEND_QMK_FLASH:
            if (record->event.pressed) {
                SEND_STRING("qmk flash\n");
                reset_keyboard();
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,                KC_F1,    KC_F2,    KC_F3,        KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,       KC_F10,      KC_F11,      KC_F12,   LCTL(LGUI(KC_Q)),             LGUI(KC_TAB),
        KC_Y,     KC_GRV,                KC_1,     KC_2,     KC_3,         KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,        KC_0,        KC_MINS,     KC_EQL,   KC_BSPC,             DT_UP,
        _______,  KC_TAB,                KC_Q,     KC_W,     KC_E,         KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,        KC_P,        KC_LBRC,     KC_RBRC,  KC_BSLS,             DT_DOWN,
        _______,  LGUI(LCTL(KC_SPACE)),  KC_A,     KC_S,     KC_D,         KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,        KC_SCLN,     KC_QUOT,               KC_ENT,              DT_PRNT,
        _______,  KC_LSFT,  KC_Z,        KC_X,     KC_C,         KC_V,     KC_B,                KC_B,     KC_N,     KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,  SC_SENT,   KC_UP,
        _______,  KC_LCTL,  KC_LOPT,            MO(NUMPAD_LAYER),  LT(NAV_LAYER, KC_SPC),   KC_LCMD,                       LT(LAYER_3, KC_SPC),                KC_RCMD,                            KC_LEFT,   KC_DOWN,  KC_RGHT),

    [NAV_LAYER] = LAYOUT_ansi_89(
        KC_MEDIA_PLAY_PAUSE,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            LGUI(KC_GRAVE),
        _______,  KC_1,     _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  LCTL(KC_W),  _______,  _______,  _______,   LGUI(KC_C),  _______,  _______,  _______,  LGUI(KC_V),  _______,  _______,  _______,            _______,
        _______,  CW_TOGG,  LGUI(KC_A),  KC_LOPT,  KC_LCMD,  KC_LSFT,  LGUI(KC_X),   KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT,   _______,  _______,            _______,            _______,
        _______,  _______,            LGUI(KC_Z),  _______,  LGUI(KC_C),  LGUI(KC_V),  LGUI(LSFT(KC_Z)),  _______,  KC_BSPC,  _______,  _______,  _______,  _______,  _______,  _______,
        SEND_QMK_FLASH,  _______,  _______,            _______,  _______,  _______,                       LGUI(KC_SPC),            _______,                      _______,  _______,  _______),

    [NUMPAD_LAYER] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  KC_2,     _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  _______,   _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,  _______,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,   _______, KC_KP_1,  KC_KP_2,  KC_KP_3,   _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       KC_KP_0,            _______,                      _______,  _______,  _______),

    [LAYER_3] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  KC_3,     _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   LGUI(LSFT(LCTL(KC_LEFT))),  LGUI(KC_H),  LGUI(LSFT(KC_ENT)),  LGUI(LSFT(LCTL(KC_RGHT))),  _______,  _______,             _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,  _______,  _______,            _______,  LSFT(LGUI(KC_SPC)),  _______,                       _______,            _______,                       _______,  _______,  _______),

    [LAYER_4] = LAYOUT_ansi_89(
        _______,        _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,        KC_4,     _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,        _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,        _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,        _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,
        QK_BOOTLOADER,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NAV_LAYER] = { ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK) },
    [NUMPAD_LAYER] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [LAYER_3] = { ENCODER_CCW_CW(QK_RGB_MATRIX_MODE_PREVIOUS, QK_RGB_MATRIX_MODE_NEXT) },
    [LAYER_4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE
