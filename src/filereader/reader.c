#include<stdio.h>
#include<stdlib.h>

#include "reader.h"
#include "../boolean.h"

void bacaFile(char fileloc[],  Matrix *Mhuruf, matrixkata *Mkata){
    int baris, kolom;
    boolean stop = false;
    baris = 0;
    startfile(fileloc);
    while (!stop) {
        kolom = 0;
        while (currentChar != NEWLINE) {
            ignoreBlank();
            ELMTM(*Mhuruf, baris, kolom) = currentChar;
            kolom++;
            advfile();
        }
        baris++;
        advfile();
        if (currentChar == NEWLINE ) {
            stop = true;
        }
    }
    ROWS(*Mhuruf) = baris;
    COLS(*Mhuruf) = kolom;

    advfile();

    stop = false;
    baris = 0;
    while (!stop) {
        kolom = 0;
        while (currentChar != NEWLINE) {
            ignoreBlank();
            ELMTK(*Mkata, baris, kolom) = currentChar;
            kolom++;
            advfile();
        }
        LWORD(*Mkata, baris) = kolom;
        baris++;
        advfile();
        if (currentChar == NEWLINE ) {
            stop = true;
        }
    }
    ROW(*Mkata) = baris;

    closeFile();
}