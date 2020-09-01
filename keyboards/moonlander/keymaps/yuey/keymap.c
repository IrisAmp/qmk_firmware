#include QMK_KEYBOARD_H
#include "version.h"
#include "moonlander.h"

extern bool mcp23018_leds[3];
extern bool is_launching;

#define TOG_LAYERCOLOR TOGGLE_LAYER_COLOR

#define ___CLR___ 0, 0, 0
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

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*------------------------------------------------------------------------------
  LAYER 0: QWERTY
------------------------------------------------------------------------------*/
  [0] = LAYOUT_moonlander(\
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                   KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,\
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MO(6),                     MO(6),   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
    KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,          KC_ESC,                    KC_ESC,           KC_UP,   KC_DOWN, KC_RALT, KC_RGUI, KC_RCTL,\
                                                 KC_SPC,  KC_BSPC, MO(5),   MO(5),   KC_DEL,  KC_ENT\
  ),
/*------------------------------------------------------------------------------
  LAYER 1: DVORAK
------------------------------------------------------------------------------*/
  [1] = LAYOUT_moonlander(\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,                   _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,\
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,                   _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,\
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,\
    _______, _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, _______,\
                                                 _______, _______, _______, _______, _______, _______\
  ),
/*------------------------------------------------------------------------------
  LAYER 2: COLEMAK
------------------------------------------------------------------------------*/
  [2] = LAYOUT_moonlander(\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______,                   _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,\
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______,                   _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,\
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,\
    _______, _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, _______,\
                                                 _______, _______, _______, _______, _______, _______\
  ),
/*------------------------------------------------------------------------------
  LAYER 3: WORKMAN
------------------------------------------------------------------------------*/
  [3] = LAYOUT_moonlander(\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    _______,                   _______, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSLS,\
    _______, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    _______,                   _______, KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,\
    _______, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                                        KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, _______,\
    _______, _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, _______,\
                                                 _______, _______, _______, _______, _______, _______\
  ),
/*------------------------------------------------------------------------------
  LAYER 4: Numpad
------------------------------------------------------------------------------*/
  [4] = LAYOUT_moonlander(\
    KC_NLCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_PSLS, KC_SLCK,                   KC_SLCK, KC_NLCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,\
    _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PAST, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PSLS,\
    _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, XXXXXXX, _______,                   _______, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_PAST,\
    _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, XXXXXXX,                                     XXXXXXX, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, _______,\
    _______, _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, _______,\
                                                 _______, _______, _______, _______, _______, _______\
  ),
/*------------------------------------------------------------------------------
  LAYER 5: Config
------------------------------------------------------------------------------*/
  [5] = LAYOUT_moonlander(\
    TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR,  XXXXXXX,\
    XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1,                   DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          DM_RSTP,                   DM_RSTP,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                                 XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX\
  ),
/*------------------------------------------------------------------------------
  LAYER 6: FN
------------------------------------------------------------------------------*/
  [6] = LAYOUT_moonlander(\
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,\
    _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F23,                    KC_F24,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  _______,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_MUTE, XXXXXXX, KC_MPLY, XXXXXXX, _______,\
    _______, _______, _______, KC_MPRV, KC_MNXT,          KC_INS,                    KC_DEL,           KC_VOLU, KC_VOLD, _______, _______, _______,\
                                                 KC_HOME, KC_END,  DM_PLY1, DM_PLY2, KC_PGUP, KC_PGDN\
  ),
};

uint8_t color_maps[][2][7][7][3] = {
/*------------------------------------------------------------------------------
  LAYER 0: QWERTY
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_RED }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_005 } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_BLU }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_RED }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_005 }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
/*------------------------------------------------------------------------------
  LAYER 1: DVORAK
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_001 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { ___CLR___ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_RED }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_005 } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 } },
    { { COLOR_BLU }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 } },
    { { ___CLR___ }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_001 }, { COLOR_WHT } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_RED }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_005 }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
/*------------------------------------------------------------------------------
  LAYER 2: COLEMAK
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_002 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { ___CLR___ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_RED }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_005 } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 } },
    { { COLOR_BLU }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 } },
    { { ___CLR___ }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_002 }, { COLOR_WHT } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_RED }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_005 }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
/*------------------------------------------------------------------------------
  LAYER 3: WORKMAN
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_003 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { ___CLR___ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_RED }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_005 } } },
  { { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { COLOR_WHT }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 } },
    { { COLOR_BLU }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 } },
    { { ___CLR___ }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_003 }, { COLOR_WHT } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_RED }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_005 }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
/*------------------------------------------------------------------------------
  LAYER 4: Numpad
------------------------------------------------------------------------------*/
{ { { { COLOR_006 }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_WHT }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_BLK } },
    { { COLOR_WHT }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_BLK }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_BLK }, { ___CLR___ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_RED }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_005 } } },
  { { { COLOR_006 }, { COLOR_006 }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_WHT } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_BLU }, { COLOR_BLK }, { COLOR_004 }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 } },
    { { ___CLR___ }, { COLOR_BLK }, { COLOR_004 }, { COLOR_004 }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_RED }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_005 }, { COLOR_WHT }, { COLOR_WHT }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
/*------------------------------------------------------------------------------
  LAYER 5: Config
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_001 }, { COLOR_002 }, { COLOR_003 }, { COLOR_004 }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_YLW }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_RED } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { ___CLR___ } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_RED }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_005 } } },
  { { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_RED }, { COLOR_BLK } },
    { { COLOR_RED }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { ___CLR___ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK } },
    { { ___CLR___ }, { COLOR_RED }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_005 }, { COLOR_BLK }, { COLOR_BLK }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
/*------------------------------------------------------------------------------
  LAYER 6: FN
------------------------------------------------------------------------------*/
{ { { { COLOR_WHT }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_WHT }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 } },
    { { COLOR_WHT }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLU } },
    { { COLOR_WHT }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { ___CLR___ } },
    { { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_006 }, { COLOR_006 }, { ___CLR___ }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_006 }, { ___CLR___ } },
    { { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { COLOR_006 }, { COLOR_006 }, { COLOR_BLK } } },
  { { { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT } },
    { { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT } },
    { { COLOR_BLU }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_BLK }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_BLK }, { COLOR_006 }, { COLOR_BLK }, { COLOR_006 }, { COLOR_BLK }, { COLOR_WHT } },
    { { ___CLR___ }, { ___CLR___ }, { COLOR_006 }, { COLOR_006 }, { COLOR_WHT }, { COLOR_WHT }, { COLOR_WHT } },
    { { ___CLR___ }, { COLOR_006 }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } },
    { { COLOR_BLK }, { COLOR_006 }, { COLOR_006 }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ }, { ___CLR___ } } } },
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

uint8_t rgb_coords[2][7][7] = {
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

bool reserved_keys[2][7][7] = {
  { { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 } },
  { { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0 } }
};

void set_rgb_matrix_coords(uint8_t side, uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  rgb_matrix_set_color(rgb_coords[side][y][x], red, green, blue);
}

void set_alpha_rgb(uint8_t red, uint8_t green, uint8_t blue) {
  for (uint8_t y = 1; y < 4; y++) {
    for (uint8_t x = 1; x < 6; x++) {
      rgb_matrix_set_color(rgb_coords[0][y][x], red, green, blue);
    }
  }
  for (uint8_t y = 1; y < 4; y++) {
    for (uint8_t x = 1; x < 6; x++) {
      rgb_matrix_set_color(rgb_coords[1][y][x], red, green, blue);
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
        if (!reserved_keys[z][y][x]) {
          set_rgb_matrix_coords(z, x, y, color_maps[mapIdx][z][y][x][0], color_maps[mapIdx][z][y][x][1], color_maps[mapIdx][z][y][x][2]);
        }
      }
    }
  }
}

void reserve_rgb_coord(uint8_t side, uint8_t x, uint8_t y, bool value) {
  reserved_keys[side][y][x] = value;
}

static volatile bool recording = false;
static volatile bool playing = false;
static volatile bool blinking = false;
static volatile bool macroRecordProcessed = false;
static bool macro1Recorded = false;
static bool macro2Recorded = false;

void process_rgb_matrix_state(void) {
  #ifdef RGB_MATRIX_ENABLE

  if (rgb_matrix_get_mode() != RGB_MATRIX_EFFECT_MAX) {
    rgb_matrix_mode(RGB_MATRIX_EFFECT_MAX);
  }

  uint8_t layer = get_highest_layer(layer_state);
  set_rgb_by_map(layer);

  led_t lock_state = host_keyboard_led_state();

  switch (layer) {
    case 4:
      if (lock_state.num_lock) {
        set_rgb_matrix_coords(0, 0, 0, COLOR_005);
        set_rgb_matrix_coords(1, 1, 0, COLOR_005);
      }
      if (lock_state.scroll_lock) {
        set_rgb_matrix_coords(0, 6, 0, COLOR_005);
        set_rgb_matrix_coords(1, 0, 0, COLOR_005);
      }

    case 0:
    case 1:
    case 2:
    case 3:
      if (lock_state.caps_lock) {
        set_rgb_matrix_coords(0, 0, 2, COLOR_005);
      }
      break;

    case 5:
      if (macro1Recorded) {
        set_rgb_matrix_coords(0, 6, 2, COLOR_GRN);
      }
      if (macro2Recorded) {
        set_rgb_matrix_coords(1, 0, 2, COLOR_GRN);
      }
      break;

    case 6:
      if (macro1Recorded) {
        set_rgb_matrix_coords(0, 6, 6, COLOR_GRN);
      }
      if (macro2Recorded) {
        set_rgb_matrix_coords(1, 0, 6, COLOR_GRN);
      }
      break;

    default:
      break;
  }

  if (recording) {
    set_rgb_matrix_coords(0, 6, 2, COLOR_RED);
    set_rgb_matrix_coords(1, 0, 2, COLOR_RED);
  }

  #endif
}

void keyboard_post_init_user(void) {
  process_rgb_matrix_state();
}

void rgb_matrix_indicators_user(void) {
  process_rgb_matrix_state();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  process_rgb_matrix_state();
  return state;
}

void keymap_led_thread_task(void) {
  if (blinking || playing) {
    ML_LED_1(true);
    ML_LED_2(true);
    ML_LED_3(true);
    ML_LED_4(true);
    ML_LED_5(true);
    ML_LED_6(true);
    chThdSleepMilliseconds(25);
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);
    chThdSleepMilliseconds(25);
    ML_LED_1(true);
    ML_LED_2(true);
    ML_LED_3(true);
    ML_LED_4(true);
    ML_LED_5(true);
    ML_LED_6(true);
    chThdSleepMilliseconds(25);
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);
    blinking = false;
  }
}

void keymap_rgb_thread_task(void) {
  if (recording) {
    set_rgb_matrix_coords(0, 6, 6, COLOR_RED);
    set_rgb_matrix_coords(1, 0, 6, COLOR_RED);
    chThdSleepMilliseconds(100);
    set_rgb_matrix_coords(0, 6, 6, COLOR_WHT);
    set_rgb_matrix_coords(1, 0, 6, COLOR_WHT);
    chThdSleepMilliseconds(100);
    set_rgb_matrix_coords(0, 6, 6, COLOR_RED);
    set_rgb_matrix_coords(1, 0, 6, COLOR_RED);
    chThdSleepMilliseconds(100);
    set_rgb_matrix_coords(0, 6, 6, COLOR_WHT);
    set_rgb_matrix_coords(1, 0, 6, COLOR_WHT);
    chThdSleepMilliseconds(500);
  }
}

static THD_WORKING_AREA(waKeymapLEDThread, 128);
static THD_FUNCTION(KeymapLEDThread, arg) {

    (void)arg;

    while (true) {
      keymap_led_thread_task();
      chThdSleepMilliseconds(1);
    }
}

static THD_WORKING_AREA(waKeymapRGBThread, 128);
static THD_FUNCTION(KeymapRGBThread, arg) {

    (void)arg;

    while (true) {
      keymap_rgb_thread_task();
      chThdSleepMilliseconds(1);
    }
}

void keyboard_pre_init_user(void) {
  chThdCreateStatic(waKeymapRGBThread, sizeof(waKeymapRGBThread), NORMALPRIO-16, KeymapRGBThread, NULL);
  chThdCreateStatic(waKeymapLEDThread, sizeof(waKeymapLEDThread), NORMALPRIO-16, KeymapLEDThread, NULL);
}

#ifdef DYNAMIC_MACRO_ENABLE
void dynamic_macro_record_start_user(void) {
  recording = true;
  macroRecordProcessed = false;
  reserve_rgb_coord(0, 6, 6, true);
  reserve_rgb_coord(1, 0, 6, true);
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
  blinking = true;
  macroRecordProcessed = true;
}

void dynamic_macro_play_start_user(int8_t direction) {
  playing = true;
}

void dynamic_macro_play_end_user(int8_t direction) {
  playing = false;
}

void dynamic_macro_record_end_user(int8_t direction) {
  recording = false;
  reserve_rgb_coord(0, 6, 6, false);
  reserve_rgb_coord(1, 0, 6, false);
  if (direction == 1) {
    macro1Recorded = macroRecordProcessed;
  } else if (direction == -1) {
    macro2Recorded = macroRecordProcessed;
  }
}
#endif
