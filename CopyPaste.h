#ifndef CopyPaste_H
#define CopyPaste_H
#include "InputText.h"

void redo(int countCurrent, int *top, char oldText[], char currentText[]);
void copy(char *copyText, text newText);
void setCopy(int kolom1, int kolom2, int baris, char *copyText, text newText);
void paste(char *copyText, text *newText, int countColumn[]);
void setPaste(char *copyText, text *newText, int baris, int kolom, int countColumn[]);

#endif
