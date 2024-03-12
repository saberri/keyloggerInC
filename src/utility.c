#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

// Generiert einen Zeitstempel im Format "YYYY-MM-DD HH:MM:SS"
char* GetCurrentTimestamp() {
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    // Speicher für den Zeitstempel-String reservieren
    char* timestamp = (char*)malloc(20); // YYYY-MM-DD HH:MM:SS + Nullterminator = 20 Zeichen
    if (timestamp != NULL) {
        snprintf(timestamp, 20, "%04d-%02d-%02d %02d:%02d:%02d",
                 tm_struct->tm_year + 1900,
                 tm_struct->tm_mon + 1,
                 tm_struct->tm_mday,
                 tm_struct->tm_hour,
                 tm_struct->tm_min,
                 tm_struct->tm_sec);
    }
    return timestamp;
}
