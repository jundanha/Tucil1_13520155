#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matrix/matrix.h"
#include "matrix/matrix.c"
#include "charmachine/charmachine.h"
#include "charmachine/charmachine.c"
#include "filereader/reader.h"
#include "filereader/reader.c"
#include "boolean.h"

boolean idxvalid(Matrix m, int i, int j) {
    return (i>=0 && i<ROWS(m) && j>=0 && j<COLS(m));
}

void solve(Matrix mh, matrixkata mk) {
    int a, b, c, d, e, f, g, h;
    int i,j;
    boolean found=false;
    int count;
    int finalcount=0;
    int xfound, yfound;

    for (a=0; a<ROW(mk); a++) { // daftar kata
    
        e = 0; // simpan i huruf pertama kata yang ditemukan
        f = 0; // simpan j huruf pertama kata yang ditemukan
        g = 0; // simpan arah
        found = false;

        printf("Kata ke-%d : ", (a+1));
        int x;
        for (x=0;x<LWORD(mk, a);x++){
            printf("%c", ELMTK(mk, a, x));
        }
        printf("\n");
        
        count = 0;
        i=0;
        while (!found && i<ROWS(mh)){
            j=0;
            while (!found && j<COLS(mh)){
                count++;
                if (ELMTK(mk, a, 0) == ELMTM(mh, i, j)){
                    
                    b = i; // nyimpen i /baris
                    c = j; // nyimpen j /kolom
                    d = 0; // buat panjang string yang udah dicek
                    
                    // atas kode: 1
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        b--;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 1;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah atas \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }

                    // kanan atas kode: 2
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        b--; c++;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 2;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah kanan atas \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }
                    
                    // kanan kode: 3
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        // printf("%c ", ELMTM(mh, b, c));
                        // printf("%c \n", ELMTK(mk, a, d));
                        c++;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 3;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah kanan \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }
                    
                    // kanan bawah kode: 4
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        b++; c++;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 4;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah kanan bawah \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }
                    
                    // bawah kode: 5
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        
                        b++;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 5;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah bawah \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }

                    // kiri bawah kode: 6
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        b++; c--;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 6;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah kiri bawah \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }
                    
                    // kiri kode: 7
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        c--;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 7;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah kiri \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }
                    
                    // kiri atas kode: 8
                    b = i; c = j; d=0;
                    while (!found && idxvalid(mh, b, c) && (ELMTK(mk, a, d)==ELMTM(mh, b, c)) && d <LWORD(mk, a)){
                        b--; c--;
                        d++;
                        count++;
                    }
                    if (d == LWORD(mk, a)){
                        found = true;
                        g = 8;
                        yfound = i; xfound =j;
                        printf("Kata ditemukan pada baris %d kolom %d ke arah kiri atas \n", i+1, j+1);
                        printf("Jumlah perbandingan : %d \n", count);
                    }
                }
            j++;  
            }
        i++;
        }

        if (!found) {
            printf("Kata tidak ditemukan\n\n");
        } else {
            printf("\n");
            finalcount = finalcount + count;
            int y, z;
            int leng=LWORD(mk, a);
            int l=LWORD(mk, a);
            int k=0;
            if (g == 1) { // atas
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((yfound-leng+1 == y) && (xfound == z) && leng>0) {
                            printf("%c ", ELMTM(mh, y, z));
                            leng--;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 2) { //kanan atas
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((yfound-leng+1 == y) && (xfound+leng-1 == z) && leng>0) {
                            printf("%c ", ELMTM(mh, y, z));
                            leng--;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 3) { // kanan
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if (((xfound+k) == z) && yfound == y && k<l) {
                            printf("%c ", ELMTM(mh, y, z));
                            k++;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 4) { // kanan bawah
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((yfound+k == y) && (xfound+k == z) && k<l) {
                            printf("%c ", ELMTM(mh, y, z));
                            k++;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 5) { // bawah
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((yfound+k == y) && (xfound == z) && k<l) {
                            printf("%c ", ELMTM(mh, y, z));
                            k++;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 6) { // kiri bawah
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((yfound+k == y) && (xfound-k == z) && k<l) {
                            printf("%c ", ELMTM(mh, y, z));
                            k++;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 7) { // kiri
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((xfound-leng+1 == z) && yfound==y && leng>0) {
                            printf("%c ", ELMTM(mh, y, z));
                            leng--;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            } else if (g == 8) { // kiri atas
                for(y=0;y<ROWS(mh);y++){
                    for (z=0;z<COLS(mh);z++){
                        if ((xfound-leng+1 == z) && (yfound-leng == y) && leng>0) {
                            printf("%c ", ELMTM(mh, y, z));
                            leng--;
                        } else {
                           printf("- "); 
                        }
                    }
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
    printf("Total perbandingan yang dilakukan: %d \n", finalcount);
}

int main() {
    Matrix mhuruf;
    matrixkata mkata;
    int i,j;
    CreateMatrix(0,0,&mhuruf);
    printf("\n");
    printf("\n");
    printf("==============================WORD SEARCH PUZZLE==============================\n");
    printf("\n");
    printf("Masukkan nama file: ");
    char fileloc[50] = "../test/";
    char fileName[50];
    scanf("%s", &fileName);
    strcat(fileloc, fileName);
    bacaFile(fileloc, &mhuruf, &mkata);
    printf("\n");
    printf("Puzzle yang akan diselesaikan : ");
    printf("\n");
    printf("\n");
    for (i=0;i<ROWS(mhuruf);i++) {
        for (j=0;j<COLS(mhuruf);j++) {
            printf("%c ", ELMTM(mhuruf, i,j));
        }
        printf("\n");
    }
    printf("\n");
    printf("Jumlah baris: %d", ROWS(mhuruf));
    printf("\n");
    printf("Jumlah kolom: %d", COLS(mhuruf));
    printf("\n");
    printf("\n");
    printf("Daftar kata yang dicari : ");
    printf("\n");
    printf("\n");
    printkata(mkata);
    printf("\n");
    printf("Jumlah kata : %d\n", ROW(mkata));
    printf("\n");
    printf("\n");
    
    printf("===================================HASIL===================================");
    printf("\n");
    printf("\n");

    clock_t start, end;
    start = clock();
    solve(mhuruf, mkata);
    end = clock();
    double timeused = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total waktu yang dibutuhkan : %f detik\n", timeused);
    printf("\n");

    return 0;
}