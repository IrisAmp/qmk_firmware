#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

#define TOG_LAYERCOLOR TOGGLE_LAYER_COLOR

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(\
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,\
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                                    KC_RBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,\
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           MO(6),                                          MO(6),          KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,\
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,\
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_ESCAPE,                                                                      KC_ESCAPE,      KC_UP,          KC_DOWN,        KC_RALT,        KC_RGUI,        KC_RCTRL,\
    KC_SPACE,       KC_BSPACE,      MO(5),                                                                                                                                                                          MO(5),          KC_DELETE,      KC_ENTER\
  ),
  [1] = LAYOUT_moonlander(\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRNS,                                        KC_TRNS,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_BSLASH,\
    KC_TRNS,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_TRNS,                                        KC_TRNS,        KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_SLASH,\
    KC_TRNS,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,                                                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS\
  ),
  [2] = LAYOUT_moonlander(\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_BSLASH,\
    KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_D,           KC_TRNS,                                        KC_TRNS,        KC_H,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,\
    KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS\
  ),
  [3] = LAYOUT_moonlander(\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_F,           KC_U,           KC_P,           KC_SCOLON,      KC_BSLASH,\
    KC_TRNS,        KC_A,           KC_S,           KC_H,           KC_T,           KC_G,           KC_TRNS,                                        KC_TRNS,        KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           KC_QUOTE,\
    KC_TRNS,        KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,                                                                           KC_K,           KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS\
  ),
  [4] = LAYOUT_moonlander(\
    KC_NUMLOCK,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_KP_SLASH,    KC_SLCK,                                        KC_SLCK,        KC_NUMLOCK,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_TRNS,\
    KC_TRNS,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_KP_ASTERISK, KC_NO,                                          KC_NO,          KC_NO,          KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_KP_SLASH,\
    KC_TRNS,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_KP_ASTERISK,\
    KC_TRNS,        KC_KP_0,         KC_KP_0,       KC_KP_DOT,      KC_KP_ENTER,    KC_NO,                                                                          KC_NO,          KC_KP_0,         KC_KP_0,       KC_KP_DOT,      KC_KP_ENTER,    KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS\
  ),
  [5] = LAYOUT_moonlander(\
    KC_NO,          TO(1),          TO(2),          TO(3),          TO(4),          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),          KC_NO,\
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,\
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,\
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,\
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,                                                                          RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,\
    KC_NO,          KC_NO,          KC_TRNS,                                                                                                                                                                        KC_TRNS,        KC_NO,          KC_NO\
  ),
  [6] = LAYOUT_moonlander(\
    KC_TRNS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F11,                                         KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRNS,\
    KC_TRNS,        KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_F17,         KC_F23,                                         KC_F24,         KC_F18,         KC_F19,         KC_F20,         KC_F21,         KC_F22,         KC_TRNS,\
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,\
    KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,\
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_INSERT,                                                                      KC_DELETE,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,\
    KC_HOME,        KC_END,         KC_NO,                                                                                                                                                                          KC_NO,          KC_PGUP,        KC_PGDOWN\
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

/*------------------------------------------------------------------------------
------------------------------------------------------------------------------*/
#define XX 99

uint8_t key_coords[2][7][7] = {
  { { 0,  5,  10, 15, 20, 25, 29 },
    { 1,  6,  11, 16, 21, 26, 30 },
    { 2,  7,  12, 17, 22, 27, 31 },
    { 3,  8,  13, 18, 23, 28, XX },
    { 4,  9,  14, 19, 24, XX, XX },
    { XX, XX, XX, XX, XX, 35, XX },
    { XX, XX, XX, XX, 32, 33, 34 } },
  { { 65, 61, 56, 51, 46, 41, 36 },
    { 66, 62, 57, 52, 47, 42, 37 },
    { 67, 63, 58, 53, 48, 43, 38 },
    { XX, 64, 59, 54, 49, 44, 39 },
    { XX, XX, 60, 55, 50, 45, 40 },
    { XX, 71, XX, XX, XX, XX, XX },
    { 70, 69, 68, XX, XX, XX, XX } }
};

#define _________ 0, 0, 0
#define COLOR_BLK 0x00, 0x00, 0x00
#define COLOR_WHT 0xFF, 0xFF, 0xFF
#define COLOR_RED 0xFF, 0x20, 0x20
#define COLOR_GRN 0x20, 0xFF, 0x20
#define COLOR_BLU 0x20, 0x20, 0xFF
#define COLOR_CYN 0x10, 0xFF, 0xFF
#define COLOR_MAG 0xFF, 0x10, 0xFF
#define COLOR_YLW 0xFF, 0xFF, 0x10
#define COLOR_001 COLOR_BLU
#define COLOR_002 COLOR_RED
#define COLOR_003 COLOR_GRN
#define COLOR_004 COLOR_CYN
#define COLOR_005 COLOR_YLW
#define COLOR_006 COLOR_MAG

uint8_t color_maps[][2][7][7][3] = {
/*------------------------------------------------------------------------------
  LAYER 0: QWERTY
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_BLU }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ }, { _________ }, { _________ } } } },

/*------------------------------------------------------------------------------
  LAYER 1: DVORAK
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_001 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 } },
    { { COLOR_BLU }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 } },
    { { _________ }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_WHT } },
    { { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ }, { _________ }, { _________ } } } },

/*------------------------------------------------------------------------------
  LAYER 2: COLEMAK
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_002 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 } },
    { { COLOR_BLU }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 } },
    { { _________ }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_WHT } },
    { { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ }, { _________ }, { _________ } } } },

/*------------------------------------------------------------------------------
  LAYER 3: WORKMAN
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_003 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 } },
    { { COLOR_BLU }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 } },
    { { _________ }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_WHT } },
    { { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ }, { _________ }, { _________ } } } },

/*------------------------------------------------------------------------------
  LAYER 4: Numpad
------------------------------------------------------------------------------*/
{ { { { COLOR_006 }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_WHT }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_BLK } },
    { { COLOR_WHT }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_BLK }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_BLK }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_006 } } },
  { { { COLOR_006 }, { COLOR_006 }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_WHT } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_BLU }, { COLOR_BLK }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 } },
    { { _________ }, { COLOR_BLK }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT } },
    { { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ }, { _________ }, { _________ } } } },

/*------------------------------------------------------------------------------
  LAYER 5: Config
------------------------------------------------------------------------------*/
{ { { { COLOR_BLK }, { COLOR_001 }, { COLOR_002 }, { COLOR_003 }, { COLOR_004 }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { _________ } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_WHT } } },
  { { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_WHT }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { _________ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { _________ }, { _________ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_WHT }, { COLOR_BLK }, { COLOR_BLK }, { _________ }, { _________ }, { _________ }, { _________ } } } },

/*------------------------------------------------------------------------------
  LAYER 6: FN
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_WHT }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_WHT }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { _________ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { _________ }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_RED }, { _________ } },
    { { _________ }, { _________ }, { _________ }, { _________ }, { COLOR_006 }, { COLOR_006 }, { COLOR_BLK } } },
  { { { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT } },
    { { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT } },
    { { COLOR_BLU }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_WHT } },
    { { _________ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_WHT } },
    { { _________ }, { _________ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { _________ }, { COLOR_RED }, { _________ }, { _________ }, { _________ }, { _________ }, { _________ } },
    { { COLOR_BLK }, { COLOR_006 }, { COLOR_006 }, { _________ }, { _________ }, { _________ }, { _________ } } } },
};

void set_rgb_matrix_coords(uint8_t side, uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  rgb_matrix_set_color(key_coords[side][y][x], red, green, blue);
}

void set_alpha_rgb(uint8_t red, uint8_t green, uint8_t blue) {
  for (uint8_t y = 1; y < 4; y++) {
    for (uint8_t x = 1; x < 6; x++) {
      rgb_matrix_set_color(key_coords[0][y][x], red, green, blue);
    }
  }
  for (uint8_t y = 1; y < 4; y++) {
    for (uint8_t x = 1; x < 6; x++) {
      rgb_matrix_set_color(key_coords[1][y][x], red, green, blue);
    }
  }
}

void set_all_rgb(uint8_t red, uint8_t green, uint8_t blue) {
  for (uint8_t i = 0; i < 72; i++) {
    rgb_matrix_set_color(i, red, green, blue);
  }
}

void set_rgb_by_map(uint8_t mapIdx) {
  for (uint8_t z = 0; z < 2; z++) {
    for (uint8_t x = 0; x < 7; x++) {
      for (uint8_t y = 0; y < 7; y++) {
        set_rgb_matrix_coords(z, x, y, color_maps[mapIdx][z][y][x][0], color_maps[mapIdx][z][y][x][1], color_maps[mapIdx][z][y][x][2]);
      }
    }
  }
}

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  if (rgb_matrix_get_mode() != RGB_MATRIX_EFFECT_MAX) {
    rgb_matrix_mode(RGB_MATRIX_EFFECT_MAX);
  }
  uint8_t layer = get_highest_layer(layer_state);
  set_rgb_by_map(layer);
  led_t lock_state = host_keyboard_led_state();
  switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
      if (lock_state.caps_lock) {
        set_rgb_matrix_coords(0, 0, 2, COLOR_005);
      }
      break;

    case 4:
      if (lock_state.num_lock) {
        set_rgb_matrix_coords(0, 0, 0, COLOR_005);
        set_rgb_matrix_coords(1, 1, 0, COLOR_005);
      }
      if (lock_state.scroll_lock) {
        set_rgb_matrix_coords(0, 6, 0, COLOR_005);
        set_rgb_matrix_coords(1, 0, 0, COLOR_005);
      }
      break;

    default:
      break;
  }
  #endif
}
