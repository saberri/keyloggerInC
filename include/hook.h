#ifndef HOOK_H
#define HOOK_H

#include <windows.h>

// Funktionsprototyp für den Tastatur-Hook-Handler
LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);

// Funktion zum Einrichten des Hooks
BOOL SetKeyboardHook();

// Funktion zum Entfernen des Hooks
void ReleaseKeyboardHook();

#endif // HOOK_H
