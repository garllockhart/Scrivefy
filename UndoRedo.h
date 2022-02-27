#ifndef UndoRedo_H
#define UndoRedo_H
#include <stdio.h>
#include <stdlib.h>

int choice,n,top,x,i;
char text[80];
char temp;


void undo(char text[], int top);
void redo(char text[], int top);
char addTempChar(char teks[], int i);

#endif
