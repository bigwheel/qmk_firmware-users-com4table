#pragma once

#include QMK_KEYBOARD_H
#ifdef BMP_MODE
#    include "bmp_custom_keycode.h"
#endif

enum com4table_custom_keycodes {
#ifdef BMP_MODE
    KC_DISPEL = BMP_SAFE_RANGE,  // 記号を押したときのIME無効化の挙動を打ち消す
#else
    KC_DISPEL = SAFE_RANGE,  // 記号を押したときのIME無効化の挙動を打ち消す
#endif
    COM4TABLE_SAFE_RANGE,
};

bool process_record_user_auto_disable_ime(uint16_t keycode, keyrecord_t *record);
