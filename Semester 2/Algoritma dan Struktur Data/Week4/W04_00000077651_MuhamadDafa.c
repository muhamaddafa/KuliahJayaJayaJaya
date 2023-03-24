#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nim[12];
    char nama[100];
    char jurusan[60];
    struct Mahasiswa *next;
}Mahasiswa; // Deklarasi Struct

Mahasiswa *node, *head, *tail; // Variable Global

// Function Membuat List Baru
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

// Function Hapus Data Pertama
void hapusDataPertama () {
    Mahasiswa *trash;
    trash = head;
    head = head->next;
    free(trash);
}

// Function Hapus Semua Data
void hapusSemuaData () {
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

void hapusDataNIM () {
    Mahasiswa *trash, *temp;
    char nomorInduk [12];
    trash = head;

    printf("Masukkan NIM: "); scanf("%[^\n]", &nomorInduk); fflush(stdin);

    if (strcmp(trash->nim, nomorInduk) == 0) {
        head = head->next;
        free(trash);
    } else {
        while (strcmp(trash->next->nim, nomorInduk) == 1) {
            trash = trash->next;
        }

        if (trash->next->next != NULL) {
            temp =  trash;
            trash = trash->next;
            temp->next = trash->next;
            free(trash);
        } else {
            tail = trash;
            trash = tail->next;
            tail->next = NULL;
            free(trash);
        }
    }
}

// Function Print Data Mahasiswa
void printLL (Mahasiswa *head) {
    Mahasiswa *temp;
    temp = head;
    int i = 1;

    while (temp != NULL) {
        printf("Data ke %d\n", i);
        printf("NIM     : %s\n", temp->nim);
        printf("Nama    : %s\n", temp->nama);
        printf("Jurusan : %s\n\n", temp->jurusan);
        temp = temp->next;
        i++;
    }
}

// Function Utama
int main () {
    int pilihan;
    head = NULL;

    printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
    menu:
    printf("Welcome To Student Data Base\n");
    printf("1. Insert New Student\n2. Print Students Data\n3. Delete All Data\n4. Delete First Data\n5. Delete Data by NIM\n6. Exit\nChoose: ");
    scanf("%d", &pilihan); fflush(stdin);
    printf("\033[2J\033[1;1H");

    if (pilihan == 1) {
        if (head == NULL) {
            node = createNode();
            head = node;
            tail = node;
        } else {
            node = createNode();
            tail->next = node;
            tail = node;
            tail->next = NULL;
        }
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    } else if (pilihan == 2) {
        if (head == NULL) {
            printf("-- DATA KOSONG --\n");
        } else {
            printLL(head);
        }
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    } else if (pilihan == 3) {
        hapusSemuaData();
        printf("Semua Data Telah Terhapus....\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    } else if (pilihan == 4) {
        hapusDataPertama();
        printf("Data Pertama Terhapus....\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    } else if (pilihan == 5) {
        hapusDataNIM();
        printf("Data Telah Terhapus....\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H"); // Untuk Clear Terminal
        goto menu;
    } else {
        return 0;
    }
}

