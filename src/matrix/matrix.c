#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void CreateMatrix(int nRow, int nCol, Matrix *m){
    COLS(*m) = nCol;
    ROWS(*m) = nRow;
}

void printkata(matrixkata m){
    int i,j;
    for (i=0;i<ROW(m);i++){
        for (j=0;j<LWORD(m, i);j++){
            printf("%c", ELMTK(m, i, j));
        }
        printf("\n");
    }
}