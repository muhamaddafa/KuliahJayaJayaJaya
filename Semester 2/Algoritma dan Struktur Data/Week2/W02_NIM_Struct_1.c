#include <stdio.h>

struct student {
    char name[50];
    char major[50];
    float gpa;
};

int main () {
    struct student dafa = {"Dafa", "Informatika", 3.99};

    printf("Name    : %s\n", dafa.name);
    printf("Major   : %s\n", dafa.major);
    printf("GPA     : %.2f\n", dafa.gpa);   

    return 0;
}
