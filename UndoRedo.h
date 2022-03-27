#ifndef UndoRedo_h
#define UndoRedo_h
#include "InputText.h"

void saveLog(int *countLog, int top, char logText[], char currentText[]);
void undo(int *top, int countLog, char logText[], char *currentText);
void saveCurrent(int *countCurrent, int top, char oldText[], char currentText[]);
void redo(int countCurrent, int *top, char oldText[], char currentText[]);

#endif
