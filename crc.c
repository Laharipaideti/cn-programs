#include <stdio.h>

int main() {
    int data[100], div[20], temp[120];
    int datalen = 0, divlen = 0, i, j;
    char ch;

    printf("Enter data bits: ");
    while ((ch = getchar()) != '\n') if (ch == '0' || ch == '1') data[datalen++] = ch - '0';

    printf("Enter divisor bits: ");
    while ((ch = getchar()) != '\n') if (ch == '0' || ch == '1') div[divlen++] = ch - '0';

    for (i = 0; i < datalen; i++) temp[i] = data[i];
    for (i = 0; i < divlen - 1; i++) temp[datalen + i] = 0;

    for (i = 0; i <= datalen - 1; i++)
        if (temp[i] == 1)
            for (j = 0; j < divlen; j++) temp[i + j] ^= div[j];

    printf("\nRemainder (CRC bits): ");
    for (i = datalen; i < datalen + divlen - 1; i++) printf("%d", temp[i]);

    printf("\nTransmitted Frame: ");
    for (i = 0; i < datalen; i++) printf("%d", data[i]);
    for (i = datalen; i < datalen + divlen - 1; i++) printf("%d", temp[i]);

    return 0;
}