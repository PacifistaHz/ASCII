#include <stdio.h>

void printHeader() {
    printf("+-----+-----+-----+-----+--------+\n");
    printf("| DEC | HEX | OCT | BIN | CHAR   |\n");
    printf("+-----+-----+-----+-----+--------+\n");
}

void printRow(int dec, char ch) {
    // İkilik (Binary) gösterimini elde etmek için bir fonksiyon yazıyoruz
    char binary[9];
    for(int i = 7; i >= 0; i--) {
        binary[7-i] = (dec & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0'; // Dize sonu karakteri ekliyoruz

    printf("| %3d | %3X | %3o | %s |   %c    |\n", dec, dec, dec, binary, ch);
}

int main() {
    printf("Genişletilmiş ASCII Tablusu:\n");
    printHeader();
    for (int i = 0; i < 256; i++) {
        if (i < 32 || (i >= 127 && i < 160)) {
            printRow(i, ' '); // Kontrol karakterleri ve boş karakterler
        } else {
            printRow(i, (char)i);
        }
    }
    printf("+-----+-----+-----+-----+--------+\n");
    return 0;
}
