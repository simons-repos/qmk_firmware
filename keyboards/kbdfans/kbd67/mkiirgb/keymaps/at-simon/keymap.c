/* Copyright 2022 at-simon
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
 
// Useful stuff at: /users/drashna/callbacks.md

#include QMK_KEYBOARD_H
#include "customizations.h"

// Custom Keycodes
enum custom_user_keycodes {
    RGB_M_0 = SAFE_RANGE,
    RGB_M_1,
    RGB_M_2,
};

// LAYERS
enum custom_user_layers {
    _BASE,
    _SETTINGS,
    _KEYPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ,--------------------------------------------------------------------------------------------------.
     * | Ec~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgUp |
     * |-------------------------------------------------------------------------------------------+------|
     * | MO 2     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgDn |
     * |-------------------------------------------------------------------------------------------+------|
     * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * | LCtrl | LGUI | LAlt |               Space                 | RAlt | MO 1 |   | Left  | Dwn | Rght |
     * `-------------------------------------------------------------------------┘   └--------------------´
     */
    [_BASE] = LAYOUT_65_ansi_blocker(
        QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLASH,KC_PGUP,
        MO(2),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO(1),              KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),


    /* Settings layer
     * ,--------------------------------------------------------------------------------------------------.
     * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     Del     | PScr |
     * |-------------------------------------------------------------------------------------------+------|
     * |        |     |     |     |     |     |     |     |     |     |     | TG2 |     |          | Ins  |
     * |-------------------------------------------------------------------------------------------+------|
     * | Caps     |     |     |     |     |     |     |     |     |     |     |     |              | Play |
     * |-------------------------------------------------------------------------------------------+------|
     * |     VV     |     |     |     |     | RST | EEP |     | RM0 | RM1 | RM2 |     VV     | V + | Mute |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * |   VV  |  VV  |  VV  |                                     |  VV  |  VV  |   | Prev  | V - | Next |
     * `-------------------------------------------------------------------------┘   └--------------------´
     */
    [_SETTINGS] = LAYOUT_65_ansi_blocker(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_PSCR,
        RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(2),    XXXXXXX,  XXXXXXX,  KC_INS,
        KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_MPLY,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,  EE_CLR,   XXXXXXX,  RGB_M_0,  RGB_M_1,  RGB_M_2,  _______,            KC_VOLU,  KC_MUTE,
        _______,  _______,  _______,                                XXXXXXX,                      _______,  _______,            KC_MPRV,  KC_VOLD,  KC_MNXT
    ),
  
  
    /* Keypad layer
     * ,--------------------------------------------------------------------------------------------------.
     * | TG2 |     |     |     |     |     |     |  7  |  8  |  9  |     |  -  |  +  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * |        |     |     |     |     |     |     |  4  |  5  |  6  |     |  *  |  /  |          |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |    VV    |     |     |     | NmL |     |     |  1  |  2  |  3  |     |     |    Enter     |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |            |     |     |     |     |     |     |  0  |  ,  |  .  |  /  |            | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * |       |      |      |                                     |      |      |   | Left  | Dwn | Rght |
     * `-------------------------------------------------------------------------┘   └--------------------´
     */
    //  TODO update keypad layer -> numpad and add xcv and control keys to image
    [_KEYPAD] = LAYOUT_65_ansi_blocker(
        TG(2),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  KC_PMNS,  KC_PPLS,  KC_BSPC,  KC_HOME,
        KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  KC_PAST,  KC_PSLS,  XXXXXXX,  KC_PGUP,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM,   XXXXXXX,  XXXXXXX,  KC_P1,    KC_P2,    KC_P3,    XXXXXXX,  XXXXXXX,            KC_ENT,   KC_PGDN,
        KC_LSFT,  XXXXXXX,  KC_X,     KC_C,     KC_V,     XXXXXXX,  XXXXXXX,  KC_P0,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  XXXXXXX,  KC_LALT,                                XXXXXXX,                      XXXXXXX,  XXXXXXX,            KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),
};



/* Empty keymap
 * ,--------------------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |             |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |          |     |     |     |     |     |     |     |     |     |     |     |              |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
 * |-------------------------------------------------------------------------┬---┬-------------+------|
 * |       |      |      |                                     |      |      |   |       |     |      |
 * `-------------------------------------------------------------------------┘   └--------------------´
 
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │           │     │
 * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
 * │        │     │     │     │     │     │     │     │     │     │     │     │     │        │     │
 * │────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴────────┼─────┤
 * │          │     │     │     │     │     │     │     │     │     │     │     │            │     │
 * ├──────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┬─────┼─────┤
 * │            │     │     │     │     │     │     │     │     │     │     │          │     │     │
 * ├───────┬────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴────┬┴─────┼─────┴┬───┬───────────┼─────┤
 * │       │      │      │                                     │      │      │   │     │     │     │
 * └───────┴──────┴──────┴─────────────────────────────────────┴──────┴──────┘   └─────┴─────┴─────┘
 *
 * ┌ ─ ┬ ─ ┐
 * │   │   │
 * ├ ─ ┼ ─ ┤
 * │   │   │
 * └ ─ ┴ ─ ┘
 */

__attribute__ ((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
  keyboard_post_init_keymap();
  
  #ifdef RGB_MATRIX_ENABLE
      rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
  #endif
}

#ifdef RGB_MATRIX_ENABLE
    static uint8_t lighting_mode = 0;
    
    uint8_t get_lighting_mode(void) {
      return lighting_mode;
    }

    void colorize_keycaps(void) {
      for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_YELLOW); i++) {
            rgb_matrix_set_color(LED_LIST_MILKSHAKE_YELLOW[i], RGB_MILKSHAKE_YELLOW);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_RED); i++) {
            rgb_matrix_set_color(LED_LIST_MILKSHAKE_RED[i], RGB_MILKSHAKE_RED);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_GREEN); i++) {
            rgb_matrix_set_color(LED_LIST_MILKSHAKE_GREEN[i], RGB_MILKSHAKE_GREEN);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_BLUE); i++) {
            rgb_matrix_set_color(LED_LIST_MILKSHAKE_BLUE[i], RGB_MILKSHAKE_BLUE);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_PURPLE); i++) {
            rgb_matrix_set_color(LED_LIST_MILKSHAKE_PURPLE[i], RGB_MILKSHAKE_PURPLE);
        }
    }

    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        switch(get_highest_layer(layer_state)){ 
        case _BASE:
            switch(get_lighting_mode()) {
                case 0:
                    rgb_matrix_set_color_all(RGB_WHITE);
                    colorize_keycaps();
                    break;
                case 1:
                    rgb_matrix_set_color_all(RGB_OFF);
                    colorize_keycaps();
                    break;
                case 2:
                    rgb_matrix_set_color_all(RGB_OFF);
                    break;
                default:
                    break;
            }
            break;
        case _SETTINGS: 
            rgb_matrix_set_color_all(RGB_OFF);
            
            rgb_matrix_set_color(LED_LBRC, RGB_MILKSHAKE_RED);
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LIGHTNIG_MODE); i++) {
                rgb_matrix_set_color(LED_LIST_LIGHTNIG_MODE[i], RGB_MILKSHAKE_YELLOW);
            }
            rgb_matrix_set_color(LED_LIST_LIGHTNIG_MODE[get_lighting_mode()], RGB_MILKSHAKE_RED);
            
            break;
        case _KEYPAD:
            rgb_matrix_set_color_all(RGB_OFF);
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_KEYPAD); i++) {
                if (IS_HOST_LED_ON(USB_LED_NUM_LOCK) == true) {
                    rgb_matrix_set_color(LED_LIST_KEYPAD[i], RGB_MILKSHAKE_BLUE);
                } else {
                    rgb_matrix_set_color(LED_LIST_KEYPAD[i], RGB_MILKSHAKE_RED);
                }
            }
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_KEYPAD_EXTRA); i++) {
                rgb_matrix_set_color(LED_LIST_KEYPAD_EXTRA[i], RGB_MILKSHAKE_PURPLE);
            }
            rgb_matrix_set_color(LED_ESC, RGB_MILKSHAKE_RED);
            rgb_matrix_set_color(LED_CAPS, RGB_MILKSHAKE_RED);
            break;
        default:
            break;
        }
    }    
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
    switch (keycode) {
        case RGB_M_0:
            if (record->event.pressed) {
                lighting_mode = 0;
            }
            return false;
            break;
        case RGB_M_1:
            if (record->event.pressed) {
                lighting_mode = 1;
            }
            return false;
            break;
        case RGB_M_2:
            if (record->event.pressed) {
                lighting_mode = 2;
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}
