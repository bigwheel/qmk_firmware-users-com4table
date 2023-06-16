#include "disable_ime.h"
#include "caravelle_backward_func.h"

#include QMK_KEYBOARD_H

void disable_ime(void) {
#if MAC_KEYMAP == 1
    tap_code(KC_LNG2);
#else
    tap_code(KC_INT5);
#endif
}
