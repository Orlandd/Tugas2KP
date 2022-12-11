#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// Soal C No 1

void menu();
void tambahData();
void tampilData();
void editData();
void hapusData();
void close();

struct DATA {
    int id;
    char nama[100]; 
    float harga[3];
} tambah, cek, sort[100], temp, hapus;

int main(void) {
    // system("cls");
    FILE *produk1;
    int i = 0;

    produk1 = fopen("hardwere.dat", "r");

    if (produk1 == NULL) {
        printf("File tidak dapat diakses!\n");
    } else {
        fscanf(produk1, "%d;%[^;];%f;%f;%f", &tambah.id, tambah.nama, &tambah.harga[0], &tambah.harga[1], &tambah.harga[2]);
        fclose(produk1);
    }

    menu();
}

void menu() {
    int pilih ;

    menu:
        system("cls");
        printf("MENU");
        printf("\n[1]Tambah Data");
        printf("\n[2]Hapus Data");
        printf("\n[3]Edit Data");
        printf("\n[4]Lihat Data");
        printf("\n[5]EXIT");
        scanf("%d", &pilih);
        switch(pilih) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                editData();
                break;
            case 4:
                tampilData();
                break;
            case 5:
                close();
                break;
            default:
                printf("\nInput salah!");
                getche();
                goto menu;
        }
}

void close() {
}


void tambahData() {
    system("cls");
    int pilih;
    FILE *produk,*produk1;
    float satuan = 0;

    produk = fopen("hardwere.dat", "a");

    printf("---------------\n");
    printf("| TAMBAH DATA |\n");
    printf("---------------\n\n");
    tambah:
        printf("ID \t: ");
        scanf("%d", &tambah.id);
        printf("Nama \t: ");
        fflush(stdin);
        scanf("%[^\n]", tambah.nama);
        printf("Jumlah \t: ");
        scanf("%f", &tambah.harga[0]);
        printf("Harga satuan \t: ");
        scanf("%f", &tambah.harga[1]);
        tambah.harga[2] = tambah.harga[0] * tambah.harga[1];

        
        fprintf(produk, "%d;%s;%f;%f;%f\n", tambah.id, tambah.nama, tambah.harga[0], tambah.harga[1], tambah.harga[2]);
        printf("-----------\n");
        printf("| SUCCESS |\n");
        printf("-----------\n\n");
        fclose(produk);
        menu();
}

void tampilData() {
    system("cls");

    FILE *view;
    int count = 0,i, j;

    view = fopen("hardwere.dat", "r");
    while (fscanf(view, "%d;%[^;];%f;%f;%f", &tambah.id, tambah.nama, &tambah.harga[0], &tambah.harga[1], &tambah.harga[2]) != EOF) {
        // sort[count].harga[1] = tambah.harga[1];
        sort[count].harga[0] = tambah.harga[0];
        sort[count].harga[1] = tambah.harga[2]; // sort.harga[1] harusnya nilai arraynya sama tambah.harga[1]. Jika dimasukan nilai arraynya sama yang tampil hanya nilai array terakhir 
        sort[count].id = tambah.id;
        strcpy(sort[count].nama, tambah.nama);
        count++; 
    }
    
    for (i = 0 ; i < count -1 ; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(sort[j].nama, sort[j+1].nama) > 0) {
                temp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = temp;
            }
        }
    }

    printf("-------------------------\n");
    printf("|          DATA         |\n");
    printf("-------------------------\n");

    printf("Record#\t\tTool Name\t\tQuantity\tPrice\n");
    for(int i = 0 ; i < count; i++) {
        printf("%d\t\t%s\t\t\t%.0f\t\t%.2f\n", sort[i].id, sort[i].nama, sort[i].harga[0], sort[i].harga[1]);
    }

    fclose(view);
}

void editData() {
    FILE *lama, *baru;
    int pilih, test = 0, choice;
    lama = fopen("hardwere.dat","r");
    baru = fopen("baru.dat", "w");

    printf("-------------\n");
    printf("| EDIT DATA |\n");
    printf("-------------\n\n");

    printf("Masukan Record : #");
    scanf("%d", &cek.id);

    while (fscanf(lama, "%d;%[^;];%f;%f;%f", &tambah.id, tambah.nama, &tambah.harga[0], &tambah.harga[1], &tambah.harga[2]) != EOF) {
        if(tambah.id == cek.id) {
            test = 1;
            ganti:
                printf("\nNo. ID : %d dimiliki produk dengan Nama : %s", tambah.id, tambah.nama);
                printf("\n\nData yang akan diganti : ");
                printf("\n[1]. Nama");
                printf("\n[2]. Harga satuan");
                printf("\n[3]. jumlah");
                printf("\nInput Pilihan : ");
                scanf("%d", &pilih);
                
                if (pilih == 1) {
                    printf("\nMasukan Data Nama baru : ");
                    fflush(stdin);
                    scanf("%[^\n]", cek.nama);
                    strcpy(tambah.nama, cek.nama);
                    fprintf(baru, "%d;%s;%f;%f;%f\n", tambah.id, tambah.nama, tambah.harga[0], tambah.harga[1], tambah.harga[2]);
                    close();
                    printf("\nPerubahan Sudah Disimpan !");
                } else if(pilih == 2) {
                    printf("\nMasukan jumlah barang baru : ");
                    scanf("%f", &cek.harga[0]);
                    tambah.harga[2] = tambah.harga[1] * cek.harga[0];
                    tambah.harga[0] = cek.harga[0];
                    fprintf(baru, "%d;%s;%f;%f;%f\n", tambah.id, tambah.nama, tambah.harga[0], tambah.harga[1], tambah.harga[2]);
                    printf("\nPerubahan Sudah Disimpan !");
                    close();
                } else if(pilih == 3) {
                    printf("\nMasukan harga satuan baru : ");
                    scanf("%f", &cek.harga[1]);
                    tambah.harga[2] = tambah.harga[0] * cek.harga[1];
                    printf("%f", cek.harga[1]);
                    tambah.harga[1] = cek.harga[1];
                    fprintf(baru, "%d;%s;%f;%f;%f\n", tambah.id, tambah.nama, tambah.harga[0], tambah.harga[1], tambah.harga[2]);
                    printf("\nPerubahan Sudah Disimpan !");
                    close();
                } else
                {
                    printf("\n\nInput Anda Salah !");
                    getche();
                    goto ganti;
                }
        } else {
            fprintf(baru, "%d;%s;%f;%f;%f\n", tambah.id, tambah.nama, tambah.harga[0], tambah.harga[1], tambah.harga[2]);
            test++;
        }
    }

    fclose(lama);
    fclose(baru);
    remove("hardwere.dat");
    rename("baru.dat", "hardwere.dat");

    if(test != 1) {
        printf("Data tidak ditemukan");
    }
}

void hapusData() {
    FILE *lama, *baru;
    int test = 0, pilih;

    lama = fopen("hardwere.dat","r");
    baru = fopen("baru.dat", "w");
    system("cls");
    printf("--------------\n");
    printf("| HAPUS DATA |\n");
    printf("--------------\n\n");
    printf("Masukkan Record : #");
    scanf("%d", &cek.id);

    while (fscanf(lama, "%d;%[^;];%f;%f;%f", &tambah.id, tambah.nama, &tambah.harga[0], &tambah.harga[1], &tambah.harga[2]) != EOF) {
        if(tambah.id != cek.id) {
            fprintf(baru, "%d;%s;%f;%f;%f\n", tambah.id, tambah.nama, tambah.harga[0], tambah.harga[1], tambah.harga[2]);
        } else {
            test++;
            printf("\n\nData dengan record #%d\nBerhasil dihapus", tambah.id);
        }
    }

    fclose(lama);
    fclose(baru);

    remove("hardwere.dat");
    rename("baru.dat", "hardwere.dat");

    if(test = 0) {
        printf("Data tidak ditemukan");
    } else {
        menu();
    }
}
