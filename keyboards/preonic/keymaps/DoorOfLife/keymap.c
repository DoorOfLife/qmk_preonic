#include QMK_KEYBOARD_H
enum preonic_layers {
    _COLEMAK,
    _QWERTY,
    _FUNCTION,
    _GAME,
    _FKEYS,
    _NAVIGATION,
    _MOUSE,
    _MEDIA,
    _UTILITY
    _SETTINGS,
};
enum preonic_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    GAME,
    BACKLIT
};

#define SHENTER RSFT(KC_ENT)
#define UTILITY LT(_UTILITY,KC_F7)
#define RAPP RALT_T(KC_APP)
#define LADEL LALT_T(KC_DEL)
#define MEDIA LT(_MEDIA,KC_GRV)
#define FKEYS LT(_FKEYS,KC_HOME)
#define MOUSE LT(_MOUSE,KC_END)
#define NAVIGATION LT(_NAVIGATION,KC_COMM)
#define SETTINGS LT(_SETTINGS,KC_RCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |XXXXXX|XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|   XXXXXX    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * `-----------------------------------------------------------------------------------'
     */
	[_COLEMAK] = LAYOUT_preonic_1x2uC(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    XXXXXXX, XXXXXXX,
            XXXXXXX, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX,
            XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_SCLN, KC_BSLS, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    /* Qwertysh
     * ,-----------------------------------------------------------------------------------.
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |XXXXXX|XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   P  |XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|   XXXXXX    |XXXXXX|XXXXXX|XXXXXX|XXXXXX| TRNS |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_preonic_1x2uC(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    XXXXXXX, XXXXXXX,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    /* function keys and numbers
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | L7/F7|______|______|______|______|______|______|______|______|______|  -_  | RALT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |______|______|______|______|______|______|______|______|______|______| Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|______|______|______|______|______|______|______|  ;:  |   \  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  |L5/GRV|L1/hme|    Space    |L4/end| L2/< |  >.  |  ",  |L3/CTL|
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTION] = LAYOUT_preonic_1x2uC(
        KC_ESC,    KC_1,      KC_2,     KC_3,       KC_4,     KC_5,       KC_6,     KC_7,     KC_8,        KC_9,      KC_0,     KC_EQL,
        UTILITY,   _______,   _______,  _______,    _______,  _______,    _______,  _______,  _______,     _______,   KC_MINS,  RAPP,
        KC_TAB,    _______,   _______,  _______,    _______,  _______,    _______,  _______,  _______,     _______,   _______,  KC_BSPC,
        KC_LSFT,   _______,   _______,  _______,    _______,  _______,    _______,  _______,  KC_SCLN,     KC_BSLS,   KC_SLSH,  SHENTER,
        KC_LCTL,   KC_LGUI,   LADEL,    MEDIA,      FKEYS,           KC_SPC,        MOUSE,    NAVIGATION,  KC_DOT,    KC_QUOT,  SETTINGS),

/* Overrides keys that causes issues in games
 * Toggle
 * ,-----------------------------------------------------------------------------------.
 * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     | TRNS | TRNS | TRNS | TRNS | TRNS |
 * `-----------------------------------------------------------------------------------'
 */
    [_GAME] = LAYOUT_preonic_1x2uC(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* F keys + additional function
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | L6/F6| PGDN | TRNS | PGUP | HOME | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | INS  | TRNS | TRNS | TRNS |  END | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `-----------------------------------------------------------------------------------'
     */
	[_FKEYS] = LAYOUT_preonic_1x2uC(
			KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
			LT(6,KC_F6), KC_PGDN, KC_TRNS, KC_PGUP, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * | Bksp |  [   |  ENT |  ]   |  INS | TRNS | TRNS | TRNS | NMLCK|   /  |   *  |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  | HOME | TRNS | END  |  (   | PGUP | TRNS | TRNS |  7   |  8   |  9   |  +   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS |  )   | PGDN | TRNS | TRNS |  4   |  5   |  6   |  ,   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS |PRTSCR| NMLCK| CAPS | TRNS | TRNS | TRNS | TRNS |  1   |  2   |  3   |  =   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     |L4/end|  0   |  0   |  .   |ENTER |
     * `-----------------------------------------------------------------------------------'
     */
	[_NAVIGATION] = LAYOUT_preonic_1x2uC(
			KC_BSPC, KC_LBRC, KC_ENT, KC_RBRC, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
			KC_DEL, KC_HOME, KC_UP, KC_END, KC_LPRN, KC_PGUP, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS,
			KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_PGDN, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PCMM,
			KC_TRNS, KC_PSCR, KC_NLCK, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PEQL,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_PENT),

	[_SETTINGS] = LAYOUT_preonic_1x2uC(
			NK_ON, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
			RGB_TOG, KC_NO, RGB_SAI, KC_NO, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEP_RST,
			KC_NO, RGB_RMOD, RGB_SAD, RGB_MOD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS),

    /* Mouse
     * MA = Mouse acceleration
     * ,-----------------------------------------------------------------------------------.
     * | Esc  | MA1  | MA2  | MA3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | L7/F7|  M1  |  MU  |  M2  | WHU  |   G  |   J  |   L  |   U  |   Y  |  -_  | RALT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |  ML  |  MD  |  MR  | WHD  |   D  |   H  |   N  |   E  |   I  |   O  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |  ;:  |   \  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  |L5/GRV|L1/home|   Space    |L4/end| L2/< |  >.  |  ",  |L3/CTL|
     * `-----------------------------------------------------------------------------------'
     */
	[_MOUSE] = LAYOUT_preonic_1x2uC(
			KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_MEDIA] = LAYOUT_preonic_1x2uC(
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_VOLD, KC_MPLY, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_MRWD, KC_MSTP, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_MPRV, KC_MUTE, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {

            } else {
                // Do something else when release
            }
            return false; // Skip all further processing of this key
        case KC_ENTER:
            // Play a tone when enter is pressed
            if (record->event.pressed) {
                PLAY_SONG(tone_qwerty);
            }
            return true; // Let QMK send the enter press/release events
        default:
            return true; // Process all other keycodes normally
    }
}

void keyboard_post_init_user(void) {
    layer_on(_FUNCTION)
}
