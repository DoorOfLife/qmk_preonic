#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
float violin[][2] = SONG(VIOLIN_SOUND);
#endif

enum myCombos {
    EEP_RESET,
    BOOT_MODE,
    BRIGHTER,
    DARKER,
    RANDOM,
    LOCK_KEY,
    RCRD_MCRO1,
    RCRD_MCR02,
    PL_MCRO1,
    PL_MCR02,
    STP_RCRD,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM eep_reset_combo[] = {KC_ESC, KC_EQL, KC_LCTL, KC_RCTL, COMBO_END};
const uint16_t PROGMEM bootmode_combo[] = {KC_EQL, KC_LCTL, KC_RCTL, COMBO_END};
const uint16_t PROGMEM brighter_combo[] = {KC_ENT, KC_BSPC, KC_A, COMBO_END};
const uint16_t PROGMEM darker_combo[] = {KC_ENT, KC_BSPC, KC_Z, COMBO_END};
const uint16_t PROGMEM random_combo[] = {KC_ENT, KC_BSPC, KC_R, COMBO_END};
const uint16_t PROGMEM rcrd_m1_combo[] = {KC_ENT, KC_BSPC, KC_1, COMBO_END};
const uint16_t PROGMEM rcrd_m2_combo[] = {KC_ENT, KC_BSPC, KC_2, COMBO_END};
const uint16_t PROGMEM stop_record_combo[] = {KC_ENT, KC_BSPC, KC_ESC, COMBO_END};
const uint16_t PROGMEM play_m1_combo[] = {KC_LCTL, KC_SPC, KC_1, COMBO_END};
const uint16_t PROGMEM play_m2_combo[] = {KC_LCTL, KC_SPC, KC_2, COMBO_END};
/*
* ,---------------------
* |//////|//////|//////|
* |------+------+------+
* |//////|   Q  |   W  |
* |------+------+------+
* |//////|//////|//////|
* |------+------+------+
* |SHIFT |   Z  |//////|
* +------+------+------+
 */
const uint16_t PROGMEM lock_key_combo[] = {KC_Q, KC_W, KC_Z, KC_LSFT, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    [EEP_RESET] = COMBO(eep_reset_combo, EEP_RST),
    [BOOT_MODE] = COMBO(bootmode_combo, RESET),
    [BRIGHTER] = COMBO(brighter_combo, KC_BRIU),
    [DARKER] = COMBO(darker_combo, KC_BRID),
    [RANDOM] = COMBO(random_combo, RAND),
    [LOCK_KEY] = COMBO(lock_key_combo, KC_LOCK),
    [RCRD_MCRO1] = COMBO(rcrd_m1_combo, DM_REC1),
    [RCRD_MCRO2] = COMBO(rcrd_m2_combo, DM_REC2),
    [STP_RCRD] = COMBO(stop_record_combo, DM_RSTP),
    [PL_MCRO1] = COMBO(play_m1_combo, DM_PLY1),
    [PL_MCRO2] = COMBO(play_m2_combo, DM_PLY2),
};


enum preonic_layers {
    _COLEMAK,
    _QWERTY,
    _FUNCTION,
    _GAME,
    _FUN,
    _NAVIGATION,
    _MOUSE,
    _MEDIA,
    _CONFIG,
    _BIGMAC
};
enum preonic_keycodes {
    COLEMAK= SAFE_RANGE,
    QWERTY,
    GAME,
    AUDIO,
    RAND,
    TWSSE,
    ENDENT,
    RMLINE,
    DUPELN,
    CUTLN,
    BIOS
};



#define SHENTER RSFT(KC_ENT)
#define CONF LT(_CONFIG, KC_F4)
#define RAPP RALT_T(KC_APP)
#define LADEL LALT_T(KC_DEL)
#define MEDIA LT(_MEDIA,KC_GRV)
#define FUN LT(_FUN,KC_HOME)
#define MOUSE LT(_MOUSE,KC_END)
#define NAVI LT(_NAVIGATION,KC_COMM)

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
     * |confF4|//////|//////|//////|//////|//////|//////|//////|//////|//////|  -_  | RALT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////| Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|//////|//////|//////|//////|//////|//////|//////|  ;:  |   \  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  |Media | Fun  |    Space    | Nav  |Mse < |  >.  |  ",  |R-Ctrl|
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTION] = LAYOUT_preonic_1x2uC(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,     KC_EQL,
        CONFIG,  _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MINS,  RAPP,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,  KC_BSPC,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_BSLS,   KC_SLSH,  SHENTER,
        KC_LCTL, KC_LGUI, LADEL,   MEDIA,   FUN,          KC_SPC,      NAVI,   MOUSE,    KC_DOT,    KC_QUOT,  KC_RCTL),

/* Overrides keys that causes issues in games
 * Toggle
 * ,-----------------------------------------------------------------------------------.
 * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |//////|//////|//////|//////|//////|/////////////|//////|//////|//////|//////|//////|
 * `-----------------------------------------------------------------------------------'
 */
    [_GAME] = LAYOUT_preonic_1x2uC(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* F keys + additional function
     * ,-----------------------------------------------------------------------------------.
     * |//////|  F1  |  F2  |  F3  |  F4  |  F5  |//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F7  |//////|  F8  |  F9  | F10  |//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////| F11  | F12  |//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|/////////////|//////|//////|//////|//////|//////|
     * `-----------------------------------------------------------------------------------'
     */
	[_FUN] = LAYOUT_preonic_1x2uC(
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, _______, _______,
            KC_F6,   KC_F7,   _______, KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * | Bksp |  [   |  ENT |  ]   |  INS |//////|//////|//////| NMLCK|   /  |   *  |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  | HOME |  UP  | END  |  (   | PGUP |//////|//////|  7   |  8   |  9   |  +   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |//////| LEFT | DOWN | RIGHT|  )   | PGDN |//////|//////|  4   |  5   |  6   |  ,   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|PRTSCR| NMLCK| CAPS |//////|//////|//////|//////|  1   |  2   |  3   |  =   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|/////////////|//////|  0   |  0   |  .   |ENTER |
     * `-----------------------------------------------------------------------------------'
     */
	[_NAVIGATION] = LAYOUT_preonic_1x2uC(
			KC_BSPC, KC_LBRC, KC_ENT, KC_RBRC,  KC_INS,  _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
			KC_DEL,  KC_HOME, KC_UP,  KC_END,   KC_LPRN, KC_PGUP, _______, _______, KC_P7, KC_P8, KC_P9, KC_PPLS,
			_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_PGDN, _______, _______, KC_P4, KC_P5, KC_P6, KC_PCMM,
			_______, KC_PSCR, KC_NLCK, KC_CAPS, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PEQL,
			_______, _______, _______, _______, _______, _______, _______, KC_P0, KC_P0, KC_PDOT, KC_PENT),

    /* Mouse
     * MA = Mouse acceleration
     * ,-----------------------------------------------------------------------------------.
     * |//////| MA1  | MA2  | MA3  |//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|  M1  |  MU  |  M2  | WHU  |//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|  ML  |  MD  |  MR  | WHD  |//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|///////|////////////|//////|//////|//////|//////|//////|
     * `-----------------------------------------------------------------------------------'
     */
	[_MOUSE] = LAYOUT_preonic_1x2uC(
			_______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, _______, _______, _______, _______,
			_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Config
     * ,-----------------------------------------------------------------------------------.
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|QWERTY|COLEMK|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|COMBO |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////| GAME |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|AUDIO |//////| MUSIC MODE  |MUSICM|//////|//////|//////|//////|
     * `-----------------------------------------------------------------------------------'
     */
    [_CONFIG] = LAYOUT_preonic_1x2uC(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CMB_TOG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GAME,
        _______, _______, _______, AU_TOG,  _______, MU_TOG,  MU_MOD, _______, _______, _______, _______),

    /* Media
     * ,-----------------------------------------------------------------------------------.
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|VOL-D | PLAY |VOL-U |//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////| PREV | STOP | NEXT |//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|REWIND| MUTE |FFRWRD|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|///////|////////////|//////|//////|//////|//////|//////|
     * `-----------------------------------------------------------------------------------'
     */
	[_MEDIA] = LAYOUT_preonic_1x2uC(
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, KC_VOLD, KC_MPLY, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, KC_MPRV, KC_MSTP, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, KC_MRWD, KC_MUTE, KC_MFFD, _______, _______, _______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

/* BigMac Boss Layer For Supreme Functionality
     * ,-----------------------------------------------------------------------------------.
     * | BIOS |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|//////|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|DUPELN|//////|//////|//////|//////|//////|RMLINE|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|CUTLN |//////|//////|//////|//////|//////|//////|//////|//////|ENDENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |//////|//////|//////|//////|//////|/////////////|//////|//////|//////|//////|//////|
     * `-----------------------------------------------------------------------------------'
 */
[_BIGMAC] = LAYOUT_preonic_1x2uC(
    BIOS,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, DUPELN,  _______, _______, _______, _______, _______, RMLINE,
    _______, _______, CUTLN,   _______, _______, _______, _______, _______, _______, _______, _______, ENDENT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GAME:
            if (record->event.pressed) {
                layer_invert(_GAME);
            }
            return false; // Skip all further processing of this key
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case BIOS:
            tap_code(KC_DEL);
            tap_code(KC_F2);
            tap_code(KC_F1);
            tap_code(KC_F10);
            tap_code(KC_F11);
            tap_code(KC_ESC);
            return false;
        case RAND:
            if (record->event.pressed){
                tap_random_base64();
            }
            return false;
        case ENDENT:
            tap_code(KC_END);
            tap_code(KC_ENT);
            return false;
        case RMLINE:
            tap_code(KC_END);
            tap_code16(S(KC_HOME));
            tap_code(KC_DEL);
            return false;
        case DUPELN:
            tap_code(KC_HOME);
            tap_code16(S(KC_END));
            tap_code16(C(KC_C));
            tap_code(KC_RGHT);
            tap_code(KC_ENT);
            tap_code16(C(KC_V));
            return false;
        case CUTLN:
            tap_code(KC_HOME);
            tap_code16(S(KC_END));
            tap_code16(C(KC_X));
            tap_code(KC_BSPC);
            return false;
        case TWSSE:
            if (record->event.pressed){
                SEND_STRING("That's what she said.");
            } else {
                tap_code(KC_ENT);
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

void ensure_function_layer_enabled(void) {
    if (IS_LAYER_OFF(_FUNCTION)){
        layer_on(_FUNCTION);
    }
}

void keyboard_post_init_user(void) {
    ensure_function_layer_enabled();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _CONFIG:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0x00,  0x00, 0xFF);
            #endif
            break;
        case _MEDIA:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0xFF,  0x00, 0x00);
            #endif
            break;
        case _MOUSE:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0x00,  0xFF, 0x00);
            #endif
            break;
        case _NAVIGATION:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0x7A,  0x00, 0xFF);
            #endif
            break;
        case _FUN:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0xFF,  0x00, 0x7A);
            #endif
            break;
        case _GAME:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0x00,  0xFF, 0x7A);
            #endif
            break;
        case _FUNCTION:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0xFF, 0x00, 0xFF);
            #endif
            break;
        case _BIGMAC:
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb(0xFF, 0xFF, 0xFF);
            #endif
            #ifdef AUDIO_ENABLE
            PLAY_SONG(violin);
            #endif
            break;
        default: //  for any other layers, or the default layer
            #ifdef RGBLIGHT_ENABLE
            rgblight_setrgb (0x00,  0xFF, 0xFF);
            #endif
            ensure_function_layer_enabled();
            break;
    }
    update_tri_layer(_NAVIGATION, _FUN, _BIGMAC);
    return state;
}
bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case CONFIG:
            return false;
        default:
            return true;
    }
}
