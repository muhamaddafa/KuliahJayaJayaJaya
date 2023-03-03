#include <stdio.h>
#include <string.h>

struct student
{
    char nim [12];
    char nama [60];
    char jurusan [30];
    float tugas;
    float uts;
    float uas;
    float nilai;
    char grade[3];
};

int main () {

    struct student mahasiswa[100];
    int pilihan, jumlah=0, i;

    menu:
    printf("Welcome To Simple Student Database (%d/100)\n", jumlah);
    printf("1. Show All Students\n2. Input New Student\n3. Exit\nChoose: ");
    scanf("%d", &pilihan);
    printf("\n");

    if (pilihan == 1) {
        printf("                                      List Of Students Information                                    \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("|No.|               Name               |     NIM     |  Tugas  |   UTS   |   UAS   |  Final  | Grade |\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        for (i = 1; i <= jumlah; i++) {
            printf("|%-3d| %-33s| %s |  %-7.2f|  %-7.2f|  %-7.2f|  %-7.2f|  %-5s|\n", i, mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].tugas, mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].nilai, mahasiswa[i].grade);
            printf("------------------------------------------------------------------------------------------------------\n");  
        }
        printf("DATABASE SIZE = %d/100\n", jumlah); fflush(stdin);
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;

    } else if (pilihan == 2 && jumlah<100) {
        FILE *fdata = fopen ("dataMahaswisa.txt", "w");
        FILE *fnilai = fopen ("nilaiMahasiswa.txt", "w");
        printf("Insert Student Information\t\n");
        printf("------------------------------\n"); fflush(stdin);
        printf("NIM     : "); scanf("%[^\n]", mahasiswa[jumlah+1].nim); fflush(stdin);
        printf("Nama    : "); scanf("%[^\n]", mahasiswa[jumlah+1].nama); fflush(stdin);
        printf("Jurusan : "); scanf("%[^\n]", mahasiswa[jumlah+1].jurusan); fflush(stdin);
        printf("\n");
        printf("Insert Student Grade\t\n");
        printf("------------------------------\n"); fflush(stdin);
        printf("Tugas   : "); scanf("%f", &mahasiswa[jumlah+1].tugas); fflush(stdin);
        printf("UTS     : "); scanf("%f", &mahasiswa[jumlah+1].uts); fflush(stdin);
        printf("UAS     : "); scanf("%f", &mahasiswa[jumlah+1].uas); fflush(stdin);
        printf("Inserting Data.....\n");
        printf("New Students Input\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        jumlah++;
        for (i = 1; i <= jumlah; i++) {
            mahasiswa[i].nilai = (mahasiswa[i].tugas * 0.3) + (mahasiswa[i].uts * 0.3) + (mahasiswa[i].uas * 0.4);
            if (mahasiswa[i].nilai >= 95) {
                strcpy(mahasiswa[i].grade, "A+");
            } else if (mahasiswa[i].nilai >= 85) {
                strcpy(mahasiswa[i].grade, "A");
            } else if (mahasiswa[i].nilai >= 80) {
                strcpy(mahasiswa[i].grade, "A-");
            } else if (mahasiswa[i].nilai >= 75) {
                strcpy(mahasiswa[i].grade, "B+");
            } else if (mahasiswa[i].nilai >= 70) {
                strcpy(mahasiswa[i].grade, "B");
            } else if (mahasiswa[i].nilai >= 65) {
                strcpy(mahasiswa[i].grade, "C");
            } else if (mahasiswa[i].nilai >= 60) {
                strcpy(mahasiswa[i].grade, "C-");
            } else if (mahasiswa[i].nilai >= 55) {
                strcpy(mahasiswa[i].grade, "D");
            } else {
                strcpy(mahasiswa[i].grade, "E");
            } 
            fprintf(fdata, "NIM     : %s\nNama    : %s\nJurusan : %s\n\n", mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].jurusan);
            fprintf(fnilai, "%s - %s\nTugas: %.2f\nUTS: %.2f\nUAS: %.2f\nNilai Akhir: %.2f\nGrade: %s\n\n", mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].tugas, mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].nilai, mahasiswa[i].grade);
        }
        fclose(fnilai);
        fclose(fdata);
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