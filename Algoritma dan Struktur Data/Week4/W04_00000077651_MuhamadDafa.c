#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa 
{
    char nim[12];
    char nama[100];
    char jurusan[60];
    struct Mahasiswa *next;
}Mahasiswa;

Mahasiswa *node, *head;

Mahasiswa *createNode () {
    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    char nim[12], nama[100], jurusan[60];

    printf("NIM: "); scanf("%[^\n]", nim); fflush(stdin);
    printf("Nama: "); scanf("%[^\n]", nama); fflush(stdin);
    printf("Jurusan: "); scanf("%[^\n]", jurusan); fflush(stdin);
    strcpy(newNode->nim, nim);
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;
    return newNode;
}

void hapusDataPertama () {
    Mahasiswa *trash;
    trash = head;
    head = head->next;
    free(trash);
}

void hapusSemuaData (Mahasiswa *head) {
    Mahasiswa *temp;
    temp = head;
    int i = 1;

    while (temp != NULL) {
        free(temp);
        temp = temp->next;
        i++;
    }

    head = NULL;
}

void printLL (Mahasiswa *head) {
    Mahasiswa *temp;
    temp = head;
    int i = 1;

    while (temp != NULL) {
        printf("\n");
        printf("Data ke %d\n", i);
        printf("NIM     : %s\n", temp->nim);
        printf("Nama    : %s\n", temp->nama);
        printf("Jurusan : %s\n\n", temp->jurusan);
        temp = temp->next;
        i++;
    }
}


int main () {
    int pilihan;
    head = NULL;

    printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
    printf("Welcome To Student Data Base\n");
    printf("Masukkan Data Pertama\n");
    node = createNode();
    head = node;

    Mahasiswa *tail;
    tail = node;

    printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
    menu:
    printf("Welcome To Student Data Base\n");
    printf("1. Insert New Student\n2. Print Students Data\n3. Delete All Data\n4. Delete First Data\n5. Delete Data by NIM\n6. Exit\nChoose: ");
    scanf("%d", &pilihan); fflush(stdin);

    switch (pilihan) {
    case 1:
        node = createNode();
        tail->next = node;
        tail = node;
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    case 2:
        if (head == NULL) {
            printf("-- DATA KOSONG --\n\n");
        } else {
            printLL(head);
        }
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    case 3:
        hapusSemuaData(head);
        printf("Semua Data Telah Terhapus....\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    case 4:
        hapusDataPertama();
        printf("Data Pertama Terhapus....\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    default:
        break;
    }
    return 0;
}