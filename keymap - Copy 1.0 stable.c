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

//DMAU is CTS my file

enum custom_keycodes {
    DMAU = SAFE_RANGE
    TIMEKEEP = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DMAU:
            if (record->event.pressed) { 
                SEND_STRING("88-B1098");
            } else {
        case TIMEKEEP
            if (record->event.pressed {
                SEND_STRING(SS_DOWN(x_LCTL)"G"(SS_UP(x_LCTL)))
            })            

    }
    break;
} return true;
};


enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

//issue w/ underglow is probably soldering; need to inspect joints/test w/ multimeter. 




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(TG(1), BL_TOGG, RGB_M_B, RGB_M_R, RGB_M_SN, BL_INC, BL_DEC, BL_BRTG, RGB_SAD),
        [1] = LAYOUT(TG(2), DMAU, KC_9, KC_4, KC_5, KC_6, DMAU, KC_2, KC_3),
        [2] = LAYOUT(TO(0), RESET, DEBUG, KC_6, KC_6, KC_6, KC_1, KC_2, KC_3)
};


//case _BASE is layer0, case _NUM is layer 1, etc

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

