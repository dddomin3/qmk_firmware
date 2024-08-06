/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _MAC, _WINDOWS, _LOWER, _RAISE, _PLOVER, _ADJUST, _MACNAV, _WINNAV, _NUM };

enum planck_keycodes { MAC = SAFE_RANGE, WINDOWS, EXT_PLV, PLOVER };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MACNAV TT(_MACNAV)
#define WINNAV TT(_WINNAV)
#define NUM TT(_NUM)
// Mac Keys
#define MUPWRD A(KC_UP)
#define MDWNWRD A(KC_DOWN)
#define MLFTWRD A(KC_LEFT)
#define MRGTWRD A(KC_RGHT)
#define MACHOME C(KC_A)
#define MACEND C(KC_E)

// Windows Keys
#define WUPWRD C(KC_UP)
#define WDWNWRD C(KC_DOWN)
#define WLFTWRD C(KC_LEFT)
#define WRGTWRD C(KC_RGHT)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* MAC
 * ,-----------------------------------------------------------------------------------.
 * | GESC |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Nav  | Ctrl | Alt  | GUI  |Lower | Space| Enter|Raise | Bksp | Alt  | Ctrl | Num  |
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_planck_grid(
    QK_GESC, KC_Q   , KC_W   , KC_E   , KC_R ,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F ,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V ,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MACNAV , KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT,  RAISE,    KC_BSPC, KC_RALT, KC_RCTL, NUM
),

/* WINDOWS
 * ,-----------------------------------------------------------------------------------.
 * | GESC |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Nav  | Ctrl | Alt  | GUI  |Lower | Space| Enter|Raise | Bksp | Alt  | Ctrl | Num  |
 * `-----------------------------------------------------------------------------------'
 */
[_WINDOWS] = LAYOUT_planck_grid(
    QK_GESC, KC_Q   , KC_W   , KC_E   , KC_R ,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F ,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V ,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    WINNAV , KC_LGUI, KC_LALT, KC_LCTL, LOWER, KC_SPC, KC_ENT,  RAISE,    KC_BSPC, KC_RALT, KC_RCTL, NUM
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   [  |   ]  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Vol- | Vol+ |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Del  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV , KC_1   , KC_2   ,   KC_3 , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
    _______, KC_F1  , KC_F2  ,   KC_F3, KC_F4  , KC_F5  , KC_F6  , _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7  , KC_F8  ,   KC_F9, KC_F10 , KC_F11 , KC_F12 , _______, KC_VOLD, KC_VOLU, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Vol- | Vol+ |  |   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Del  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , _______, _______, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_VOLD, KC_VOLU, KC_PIPE, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff| Mac  |Window|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF ,  MAC   , WINDOWS, _______, _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF ,  MI_ON , MI_OFF , _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* MACNAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home |      | End  |      |      |      | Home |      |  End |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_MACNAV] = LAYOUT_planck_grid(
    _______, _______, KC_UP  , _______, _______, _______, _______, _______, MUPWRD , _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, MDWNWRD, MLFTWRD, MRGTWRD, _______, _______,
    _______, MACHOME, _______, MACEND , _______, _______, _______, MACHOME, _______, MACEND , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* WINNAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home |      | End  |      |      |      | Home |      |  End |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


[_WINNAV] = LAYOUT_planck_grid(
    _______, _______, KC_UP  , _______, _______, _______, _______, _______, WUPWRD , _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, WDWNWRD, WLFTWRD, WRGTWRD, _______, _______,
    _______, KC_HOME, _______, KC_END , _______, _______, _______, KC_HOME, _______, KC_END , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      |      |   7  |   8  |   9  |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home |      | End  |      |      |      |   1  |   2  |   3  |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |   .  |  *   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    _______, KC_ACL0, KC_MS_U, KC_ACL1, KC_ACL2, _______, _______, KC_7   , KC_8, KC_9  , KC_MINS, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, KC_4   , KC_5, KC_6  , KC_PLUS, _______,
    _______, KC_WH_U, _______, KC_WH_D, _______, _______, _______, KC_1   , KC_2, KC_3  , KC_BSLS, _______,
    _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, KC_0, KC_DOT, KC_ASTR, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
)
};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
float windows_song[][2] = SONG(MAJOR_SOUND);
float mac_song[][2] = SONG(MINOR_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WINDOWS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WINDOWS);
            }
#ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(windows_song);
#endif
            return false;
            break;
        case MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
#ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(mac_song);
#endif
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_off(_MACNAV);
                layer_off(_WINNAV);
                layer_off(_NUM);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}