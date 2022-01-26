/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;

static FILE * tape;
static FILE * filetape;
static int retval;


void start() {
	tape = stdin;
	adv();
}

void adv() {
retval = fscanf(tape,"%c",&currentChar);
}

void startfile(char fileloc[]) {
	filetape = fopen(fileloc, "r");
	advfile();
}

void advfile() {
	retval = fscanf(filetape,"%c",&currentChar);
}

void ignoreBlank(){
	while (currentChar == BLANK){
		advfile();
	}
}

void close(){
   fclose(tape);
}

void closeFile(){
   fclose(filetape);
}