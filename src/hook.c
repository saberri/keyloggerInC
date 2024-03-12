#include "hook.h"

// Globale Variable für die Hook-Handle
HHOOK hKeyboardHook = NULL;

// Hook-Procedure: Wird aufgerufen, wenn eine Tastatureingabe erfolgt
LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        // Prüfen, ob eine Taste gedrückt wurde
        if (wParam == WM_KEYDOWN) {
            // Hier könnte man den Tastenanschlag verarbeiten
            // Zum Beispiel könnte man den Tastenanschlag an die Logging-Funktion weiterleiten
        }
    }
    // Weitergabe an die nächste Hook-Procedure
    return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}

// Setzt den Keyboard-Hook
BOOL SetKeyboardHook() {
    hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookProc, NULL, 0);
    return hKeyboardHook != NULL;
}

// Entfernt den Keyboard-Hook und gibt die Ressourcen frei
void ReleaseKeyboardHook() {
    if (hKeyboardHook != NULL) {
        UnhookWindowsHookEx(hKeyboardHook);
        hKeyboardHook = NULL;
    }
}
