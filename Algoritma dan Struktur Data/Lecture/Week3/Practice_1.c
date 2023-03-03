#include <stdio.h>

struct menu
{
    char pesanan[50];
    int jumlah_order;
    int harga;
    int jumlah;
};


int main () {
    struct menu order[10];
    int i = 0 , j, total = 0;

    FILE *f1 = fopen("order.txt", "r");

    while (!feof(f1)) {
        fscanf(f1, "%[^#]#%d#%d\n", order[i].pesanan, &order[i].jumlah_order, &order[i].harga);
        order[i].jumlah = order[i].harga * order[i].jumlah_order;
        total += order[i].jumlah;
        i++;
    }
    fclose(f1);

    
    FILE *f2 = fopen("bill.txt", "w");

    for (j = 0; j < i; j++) {
        fprintf(f2, "%s\n", order[j].pesanan);
        fprintf(f2, "%d * %d = %d\n\n", order[j].jumlah_order, order[j].harga, order[j].jumlah);
    }

    fprintf(f2, "Total = %d\n", total);

    fclose(f2);

    return 0;
}