#ifndef Matrix_H
#define Matrix_H

#include "../boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int Index; /* Index baris, kolom */
typedef char ElType;
typedef struct
{
   ElType contents[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m);

/* *** Selektor *** */
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define ELMTM(M, i, j) (M).contents[(i)][(j)]

typedef struct {
   char contentsword[100]; /* container penyimpan kata*/
   int lengthkata;
} Word;

typedef struct 
{
   Word contentskata[100];
   int length;
} matrixkata;

void printkata(matrixkata m);

#define ROW(M) (M).length
#define LWORD(M, i) (M).contentskata[(i)].lengthkata
#define ELMTK(M, i, j) (M).contentskata[(i)].contentsword[(j)]

#endif
