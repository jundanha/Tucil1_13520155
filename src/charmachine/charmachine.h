/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "../boolean.h"

#define MARK '.'
#define BLANK ' '
#define NEWLINE '\n'

extern char currentChar;
extern boolean eot;

void start();

void adv();

void startfile(char fileloc[]);

void advfile();

void ignoreBlank();

void close();

void closeFile();

#endif
