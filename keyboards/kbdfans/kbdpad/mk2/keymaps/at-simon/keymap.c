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

#include QMK_KEYBOARD_H
#include "customizations.h"

enum custom_user_layers {
    _CALC,
    _CONTROL,
    _MEDIA,
    _RESET
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _CALC
     * ,-----------------------.
     * | ESC |     | DF2 | DF3 |
     * `-----------------------´
     * ,-----------------------.
     * | N L |  /  |  *  |  -  |
     * |-----------------------|
     * |  7  |  8  |  9  |     |
     * |-----------------|  +  |
     * |  4  |  5  |  6  |     |
     * |-----------------------|
     * |  1  |  2  |  3  |     |
     * |-----------------| ENT |
     * |     0     |  .  |     |
     * `-----------------------´  KC_ESC
     */
    [_CALC] = LAYOUT_numpad_6x4(
        KC_ESC,  XXXXXXX, DF(1),  DF(2),
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /* _CONTROL
     * ,-----------------------.
     * | ESC | DF1 |     | DF3 |
     * `-----------------------´
     * ,-----------------------.
     * | N L |  /  |  *  |  -  |
     * |-----------------------|
     * |  7  |  8  |  9  |     |
     * |-----------------|  +  |
     * |  4  |  5  |  6  |     |
     * |-----------------------|
     * |  1  |  2  |  3  |     |
     * |-----------------| ENT |
     * |     0     |  .  |     |
     * `-----------------------´
     */
    [_CONTROL] = LAYOUT_numpad_6x4(
        KC_ESC,  DF(0),   XXXXXXX, DF(2),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_P1,            XXXXXXX, XXXXXXX
    ),

    /* _MEDIA
     * ,-----------------------.
     * | ESC | DF0 | DF1 |     |
     * `-----------------------´
     * ,-----------------------.
     * |     | V 0 | V - | V + |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|     |
     * |     |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|     |
     * |           |     |     |
     * `-----------------------´
     */
    [_MEDIA] = LAYOUT_numpad_6x4(
        KC_ESC,  DF(0),   DF(1),   MO(3),
        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_P2,            XXXXXXX, XXXXXXX
    ),

    /* Empty keymap
     * ,-----------------------.
     * |     |     |     |     |
     * `-----------------------´
     * ,-----------------------.
     * |     |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|     |
     * |     |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|     |
     * |           |     |     |
     * `-----------------------´
     */
    [_RESET] = LAYOUT_numpad_6x4(
        XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT,          EE_CLR,  XXXXXXX
    )
};



/* Empty keymap
 * ,-----------------------.
 * |     |     |     |     |
 * `-----------------------´
 * ,-----------------------.
 * |     |     |     |     |
 * |-----------------------|
 * |     |     |     |     |
 * |-----------------|     |
 * |     |     |     |     |
 * |-----------------------|
 * |     |     |     |     |
 * |-----------------|     |
 * |           |     |     |
 * `-----------------------´
 */
