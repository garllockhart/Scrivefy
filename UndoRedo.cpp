#include "UndoRedo.h"
#include <stdlib.h>
#include <stdio.h>

void saveLog(int *countLog, int top, char logText[], char currentText[]){
	int i;
	*countLog = 0;
	for(i = 0; i<top; i++){
		logText[i] = currentText[i];
		
	}
	*countLog = i; 
}

void undo(int *top, int countLog, char logText[], char *currentText){
	int i;
	*top = 0;
	for(i = 0; i<countLog; i++){
		printf("%d", i);
		currentText[i] = logText[i];
	}
	*top = countLog;
}

void saveCurrent(int *countCurrent, int top, char oldText[], char currentText[]){
	int i;
	*countCurrent = 0;
	for(i = 0; i<top; i++){
		oldText[i] = currentText[i];
	}
	*countCurrent = i;
}

void redo(int countCurrent, int *top, char oldText[], char currentText[]){
	int i;
	*top = 0;
	for(i = 0; i<countCurrent; i++){
		 currentText[i] = oldText[i];
	}
	*top = countCurrent-1;
}
