#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  LOL
};
// Tap Dance declarations
enum {
   TD_ESC_CAPS,
   TD_QOUT_SMCLN
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_QOUT_SMCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // TD(TD_ESC_CAPS)


/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | Enter| Alt|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_QOUT_SMCLN),
  LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  LSFT_T(KC_SLSH),
                    LGUI_T(KC_TAB), LT(ADJUST, KC_TAB), LT(RAISE, KC_SPC),         LT(LOWER,KC_BSPC), KC_ENT, KC_LALT
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Esc  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Shift|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT_split_3x5_3(
  KC_ESC, KC_TILD, KC_EXLM, KC_AT, KC_HASH,       KC_LCBR, KC_DLR, KC_PERC, KC_RCBR, KC_UNDS,
  KC_TAB,MEH(KC_S), MEH(KC_D), MEH(KC_F),   MEH(KC_G),      KC_LPRN, KC_MINS, KC_PLUS,  KC_RPRN, KC_AMPR,
  KC_LSFT, MEH(KC_X),  LGUI(KC_C), LGUI(KC_V), MEH(KC_B),      KC_LBRC, KC_EQL, KC_LBRC, KC_RBRC, KC_CIRC,
                    QK_BOOT, _______, _______,      KC_BSPC, KC_LGUI, KC_LCTL
),
/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   7  |   8  |   9  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   4  |   5  |   6  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |   0  |   1  |   2  |   3  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------|      |    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
  KC_GRV, KC_AT,   KC_1, KC_2,  KC_3,        KC_7, KC_8, KC_9,KC_0,KC_MINS,
  KC_ESC,  _______, KC_4, KC_5, KC_6,        KC_L, KC_5, KC_6,KC_LBRC,KC_RBRC,
  KC_LSFT, KC_TILD, KC_7, KC_8, KC_9,       KC_1, KC_2, KC_3,  KC_EQL,KC_BSLS,
                    KC_0, KC_LGUI, _______,      _______,  _______, KC_DEL
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT_split_3x5_3(
  MEH(KC_Q),   MEH(KC_W),   MEH(KC_E),   MEH(KC_R),   MEH(KC_T),        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_PGUP,
  MEH(KC_A),  MEH(KC_S),  MEH(KC_D), MEH(KC_F), MEH(KC_G),      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGDN,
  MEH(KC_Z),   MEH(KC_X), MEH(KC_C), MEH(KC_V), MEH(KC_B),      _______, _______, _______, _______,  _______,
                    _______, _______, _______,      _______,  _______, _______
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case LOL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("lol");
            register_code(KC_ENT);
            unregister_code(KC_ENT);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
  return true;
}
