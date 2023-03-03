// Muhamad Dafa 00000077651
// Tugas 2 Week 1
// Algoritma dan Struktur Data

#include <stdio.h>

//Deklarasi Variable
int hasilOperasi[3][3];
int i, j, k;
int matriks1_t[3][3], matriks2_t[3][3];
int matriks1[3][3], matriks2[3][3], menu;
int jumlah = 0;
char back;

//Function input matriks
void input (int matriks[3][3]) {
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Masukkan angka matriks [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriks[i][j]);
        }
    }

}

//Function untuk menampilkan matriks
void ngePrint (int matriks[3][3]) {
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }

}

//Function Perkalian Matriks
void perkalianMatriks (int hasilOperasi[3][3], int matriks1[3][3], int matriks2[3][3]) {
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                *&hasilOperasi[i][j] = *&hasilOperasi[i][j] + *&matriks1[i][k] * *&matriks2[k][j];
            }
        }
    }
    
}

//Function Penjumlahan Matriks
void penjumlahanMatriks(int hasilOperasi[3][3], int matriks1[3][3], int matriks2[3][3]) {
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            *&hasilOperasi[i][j] = *&matriks1[i][j] + *&matriks2 [i][j];
        }
    }

}

//Function Transpose Matriks
void transposeMatriks (int matriks1_t[3][3], int matriks1[3][3], int matriks2_t[3][3], int matriks2[3][3]) {
    
    //Operasi Transpose Matriks 1
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            *&matriks1_t[j][i] = *&matriks1[i][j];
        }
    }
    //Operasi Transpose Matriks 2
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            *&matriks2_t[j][i] = *&matriks2[i][j];
        }
    }

}

//Utama
int main () {
    
    // Input Matriks yg Pertama
    printf("Input Matriks Pertama (3x3)\n");
    input(matriks1);
    printf("\n");
    
    //Input Matriks yg Kedua
    printf("Input Matriks Kedua (3x3)\n");
    input(matriks2);
    printf("\n");
    
    //ngeprint semua matriks pertama dan kedua
    printf("=============================================\n");
    printf("Matriks Pertama (3x3)\n");
    ngePrint(matriks1);
    printf("\n");
    printf("Matriks Kedua (3x3)\n");
    ngePrint(matriks2);
    printf("=============================================\n");
    
    //Tampilan Menu Operasi Matriks
    printf("Pilih Menu:\n1. Perkalian Dua Buah Matriks\n2. Penjumlahan Dua Buah Matriks\n3. Transpose Dua Buah Matriks\n4. Keluar\nPilihan: ");
    scanf("%d", &menu);
    
    //Kondisi Pemilihan Menu
    //Perkalian Matriks
    if (menu == 1) {
        perkalianMatriks(hasilOperasi, matriks1, matriks2);
        printf("=============================================\n");
        printf("Hasil Perkalian Matriks\n");
        ngePrint(hasilOperasi);
    //Penjumlahan Matriks
    } else if (menu == 2) {
        penjumlahanMatriks(hasilOperasi, matriks1, matriks2);
        printf("=============================================\n");
        printf("Hasil Penjumlahan Matriks\n");
        ngePrint(hasilOperasi);
    //Transpose Matriks
    } else if (menu == 3) {
        transposeMatriks(matriks1_t, matriks1, matriks2_t, matriks2);
        printf("=============================================\n");
        printf("Hasil Transpose Matriks Pertama\n");
        ngePrint(matriks1_t);
        printf("Hasil Transpose Matriks Kedua\n");
        ngePrint(matriks2_t);
    //Keluar
    } else {
        printf("\n");
        printf("Thank You, Have A Good Day !!");
        printf("\n");
    }

    return 0;
}