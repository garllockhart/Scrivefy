/*
File Name		: UndoRedo.cpp
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

/* ========== Header File ========== */
#include "UndoRedo.h"
#include <stdlib.h>
#include <stdio.h>
/* ======= End of Header File ====== */

void saveLog(int *countLog, int top, char logText[], char currentText[]){
	int i;
	*countLog = 0;
	for(i = 0; i<top; i++){
		logText[i] = currentText[i]; // Menyalin isi dari current text lalu memasukkan nya ke log text
	}
	*countLog = i; 					// merubah nilai count log sesuai dengan variabel i
}

void undo(int *top, int countLog, char logText[], char *currentText){
	int i;
	*top = 0;
	for(i = 0; i<countLog; i++){
		currentText[i] = logText[i];	// menyalin isi dari log text lalu memasukkannya ke dalam current text
	}
	*top = countLog;					// mengubah nilai top menjadi sama dengan count log
}

void saveCurrent(int *countCurrent, int top, char oldText[], char currentText[]){
	int i;
	*countCurrent = 0;
	for(i = 0; i<top; i++){
		oldText[i] = currentText[i];  	// Menyalin current text dan memasukkannya ke old text
	}
	*countCurrent = i;					// Merubah nilai count current menjadi sesuai dengan i
}

void redo(int countCurrent, int *top, char oldText[], char currentText[]){
	int i;
	*top = 0;
	for(i = 0; i<countCurrent; i++){
		 currentText[i] = oldText[i];   // menyalin isi dari old text lalu memasukkannya ke dalam current text
	}
	*top = countCurrent-1;				// merubah nilai top
}
