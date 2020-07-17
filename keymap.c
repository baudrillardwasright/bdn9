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

enum custom_keycodes {
    SWW = SAFE_RANGE,
    OBJECT,
    QKC,
    PRIV,
    };

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SWW:
        if (record->event.pressed) { 
                SEND_STRING("Subject to and without waiving the above objections, Plaintiff responds as follows:");
            } else {
        case OBJECT:
        if (record->event.pressed) {
                SEND_STRING("Plaintiff objects to this Request on the basis that");
            } else {
        case QKC:
        if (record->event.pressed) { 
                SEND_STRING("qmk compile"SS_TAP(X_ENT));
            } else {
        case PRIV:
        if (record->event.pressed) { 
                SEND_STRING("Plaintiff objects to this request to the extent that it seeks information which is covered by the attorney-client privilege or the work product privilege.");
            } else {                        
    }
    break; {
}
}
}
}
 } return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
// LED controls 

    [0] = LAYOUT(
        TG(1), RGB_MOD, KC_MPLY,
        RGB_SPI, RGB_SAI  , RGB_HUI,
        RGB_SPD, RGB_SAD, RGB_HUD
    ),

//FTL layer

    [1] = LAYOUT(
        TG(2), KC_V, KC_SPACE,
        KC_1, KC_2, KC_3,
        KC_X, KC_Z, KC_J
    ),

// hotkey/debug layer

    [2] = LAYOUT(
    TO(0), RESET, DEBUG,
    PRIV, KC_MUTE, KC_MFFD,
    OBJECT, SWW, QKC
),
};



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
