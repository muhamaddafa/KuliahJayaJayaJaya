// Muhamad Dafa 00000077651
// Tugas 1 Week 1
// Algoritma dan Struktur Data

#include <stdio.h>
#include <string.h>

//Deklarasi Variable
int menu, i;
char kata[50];

//Function Uppercase
void uppercase (char *kata) {

    for (i = 0; i < strlen(kata); i++) {
        if (*&kata[i] >= 'a' && *&kata[i] <= 'z') {
            *&kata[i] -= 32;
        }
    }
}

//Function Lowercase
void lowercase (char *kata) {

    for (i = 0; i < strlen(kata); i++) {
        if (*&kata[i] >= 'A' && *&kata[i] <= 'Z') {
            *&kata[i] += 32;
        }
    }
}

//Function Switching
void switching (char *kata) {

    for (i = 0; i<strlen(kata); i++) {
        if (*&kata[i] >= 'a' && *&kata[i] <= 'z') {
            *&kata[i] -= 32;
        } else if (*&kata[i] >= 'A' && *&kata[i] <= 'Z') {
            *&kata[i] += 32;
        }
    }
}

//Utama
int main () {

    printf("Pilih Menu:\n1. Uppercase\n2. Lowercase\n3. Switching\n4. Keluar\nPilihan: ");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("\n");
        printf("Masukkan Kata/Kalimat: ");
        scanf(" %[^\n]", kata);
        uppercase(kata);
        printf("\n");
        printf("Ini hasil konversinya: %s", kata);
        printf("\n");
        printf("\n");
    } else if (menu == 2) {
        printf("\n");
        printf("Masukkan Kata/Kalimat: ");
        scanf(" %[^\n]", kata);
        lowercase(kata);
        printf("\n");
        printf("Ini hasil konversinya: %s", kata);
        printf("\n");
        printf("\n");
    } else if (menu == 3) {
        printf("\n");
        printf("Masukkan Kata/Kalimat: ");
        scanf(" %[^\n]", kata);
        switching(kata);
        printf("\n");
        printf("Ini hasil konversinya: %s", kata);
        printf("\n");
        printf("\n");
    } else {
        printf("\n");
        printf("Thank You, Have A Good Day !!");
        printf("\n");
    }

    return 0;
}