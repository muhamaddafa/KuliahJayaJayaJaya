// Muhamad Dafa 00000077651
// Tugas Week 2
// Algoritma dan Sturktur Data

#include <stdio.h>

struct mahasiswa
{
    char name[50];
    char major[50];
    float gpa;
};


int main () {
    
    int pilihan, i, jumlah=0;
    struct mahasiswa siswa[20];
    
    menu:
    printf("Welcome To Simple Student Database (%d/20)\n", jumlah);
    printf("1. Show All Students\n2. Input New Student\n3. Exit\nChoose: ");
    scanf("%d", &pilihan);
    printf("\n");

    if (pilihan == 1) {
        printf("                        List Of Students Information                       \n");
        printf("--------------------------------------------------------------------------\n");
        printf("|No.|               Name               |          Major          |  GPA  |\n");
        printf("--------------------------------------------------------------------------\n");
        for (i = 1; i <= jumlah; i++) {
            printf("|%-3d| %-33s| %-24s| %.2f  |\n", i, siswa[i].name, siswa[i].major, siswa[i].gpa);
            printf("--------------------------------------------------------------------------\n");   
        }
        printf("DATABASE SIZE = %d/20\n", jumlah); fflush(stdin);
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
        
    } else if (pilihan == 2 && jumlah<20) {
        printf("Insert Student Information\t\n");
        printf("------------------------------\n"); fflush(stdin);
        printf("Name    : "); scanf("%[^\n]", siswa[jumlah+1].name); fflush(stdin);
        printf("Major   : "); scanf("%[^\n]", siswa[jumlah+1].major);
        printf("GPA     : "); scanf("%f", &siswa[jumlah+1].gpa); fflush(stdin);
        printf("Inserting Data.....\n");
        printf("New Students Input\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        jumlah++;
        goto menu;
    } else if (pilihan == 3) {
        return 0;
    } else {
        printf("DATABASE IS FULL\n");
        printf("Press Any Key To Continue"); fflush(stdin);
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    }
}