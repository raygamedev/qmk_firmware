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
  RAY,
  OFFICE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  LSFT_T(KC_SLSH),
                    KC_LCTL, LGUI_T(KC_ESC), LT(RAISE, KC_SPC),         LT(LOWER, KC_BSPC), LT(ADJUST,KC_ENT), KC_LALT),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Esc  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                               `------'    `------'
 */
[_RAISE] = LAYOUT_split_3x5_3(
  LGUI(KC_GRV), MEH(KC_W), MEH(KC_E),MEH(KC_R), MEH(KC_T),   LCA(KC_Y),    LCA(KC_U),   LCA(KC_I),    LCA(KC_O),    KC_PGUP,
  KC_TAB,       MEH(KC_S), MEH(KC_D), MEH(KC_F), MEH(KC_G),        KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_PGDN,
  KC_LSFT,      MEH(KC_X), MEH(KC_C), MEH(KC_V), MEH(KC_B),       LCA(KC_H), LCA(KC_J), LCA(KC_K), LCA(KC_L),  KC_QUOT,
                        QK_BOOT, KC_BSPC, _______,           KC_HOME, KC_END, _______
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------|      |    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
  KC_GRV, KC_1, KC_2, KC_3,  KC_0,      KC_LBRC, KC_EXLM, KC_AT, KC_RBRC, KC_ASTR,
  KC_TAB,  KC_4, KC_5, KC_6, _______,      KC_LPRN, KC_MINS, KC_EQL, KC_RPRN, KC_QUOT,
  KC_LSFT, KC_7, KC_8, KC_9, _______,      KC_HASH, KC_DLR, KC_AMPR, KC_PIPE,  KC_PERC,
              KC_0, _______, _______,      KC_BSPC,  _______, KC_BSLS
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
  RAY,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  OFFICE,  KC_F12,  KC_DEL, _______, _______,      KC_HOME, _______, _______, KC_END, CALTDEL,
  QK_BOOT,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______,
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
    case OFFICE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("");
            register_code(KC_ENT);
            unregister_code(KC_ENT);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case RAY:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("");
            register_code(KC_ENT);
            unregister_code(KC_ENT);
        } else {
            // when keycode QMKBEST is released
        }
        break;
  }
  return true;
}
