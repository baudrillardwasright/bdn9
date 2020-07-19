
#include QMK_KEYBOARD_H

enum custom_keycodes {
    SWW = SAFE_RANGE,
    OBJECT,
    QKC,
    PRIV,
    LETTERHEAD,
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
        case LETTERHEAD:
        if (record->event.pressed) { 
                SEND_STRING(SS_LCTL("j"));
            } else {                        
    }
    break; {
}
}
}
}
}
 } return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
// DEBUG LAYER 

    [0] = LAYOUT(
        TG(1), RESET, DEBUG,
        KC_MSEL, KC_MSTP, KC_MRWD,
        KC_MYCM, KC_MPLY, KC_MFFD
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
    PRIV, LETTERHEAD, KC_MFFD,
    OBJECT, SWW, QKC
),
};

layer_state_t layer_state_set_user(layer_state_t state) {

    // Color codes
    // https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h

    uint8_t layer = biton32(state);

    switch (layer) {

        case 0:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv(213, 255, 255);
            break;

        case 1:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv(85, 255, 255);
            break;

        case 2:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv(128, 255, 255);
            break;

    }

    return state;
}





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
