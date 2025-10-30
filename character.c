#include <stdio.h>
#define FLAG 'F'
#define ESC 'E'

void main() {
    char data[100], stuffed[200], ch;
    int i, j = 0;

    printf("Enter data: ");
    scanf("%s", data);

    stuffed[j++] = FLAG; // Start flag
    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == FLAG || data[i] == ESC)
            stuffed[j++] = ESC; // Add escape before FLAG/ESC
        stuffed[j++] = data[i];
    }
    stuffed[j++] = FLAG; // End flag
    stuffed[j] = '\0';

    printf("\nStuffed Data: %s", stuffed);

    // Unstuffing
    char unstuff[100];
    j = 0;
    for (i = 1; stuffed[i] != '\0' && stuffed[i] != FLAG; i++) {
        if (stuffed[i] == ESC) i++; // Skip escape
        unstuff[j++] = stuffed[i];
    }
    unstuff[j] = '\0';

    printf("\nUnstuffed Data: %s\n", unstuff);
}