/*
File Name		: InputText.cpp
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "InputText.h"
#include "KeyboardShortcuts.h"
#include "InputHandlingNonStandard.h"
#include "FileHandling.h"
#include "UndoRedo.h"
#include "CopyPaste.h"
/* ======= End of Header File ====== */

void inputText(text *newText, char file_name[]){
	int i, j, top = 0, baris=0;
	int countLog;
	int countCurrent;
	char currentText[COLUMNS], oldText [COLUMNS],logText[COLUMNS], copyText[COLUMNS];
	int countColumn[ROWS], row;
	char temp;
	
	printf("Enter Your Text\n");
	
	for(i=0; i<=ROWS; i++){
		if (baris == ROWS) {
			printf("\n");
			saveFile(*newText, file_name, baris, countColumn);
		}
		
		for(j = 0; j<=COLUMNS; j++){
			temp = getch();
			countColumn[baris] = top;
			setText(&(*newText), temp, file_name, oldText, logText, currentText, copyText, &top, &baris, &countLog, &countCurrent,  countColumn);
			
			if(temp == 13 || top >COLUMNS){
				break;
			}
			
			displayCurrentText(currentText, top, *newText, countColumn, baris);
			top++;
		}
		row++;
		baris++;
	}
}

void inputUpdateText(text *newText, char file_name[], int currentRow, int countColumn[]){
	int i,j,top =0,baris=currentRow;
	int countLog;
	int countCurrent;
	char currentText[COLUMNS], oldText [COLUMNS],logText[COLUMNS],copyText[COLUMNS];
	int  row;
	char temp;
	int n = COLUMNS;
	
	printf("\nEnter Your Text\n");
	
	for(i=currentRow+1; i<=ROWS; i++){
		if (baris == ROWS) {
			printf("\n");
			saveFile(*newText, file_name, baris, countColumn);
		}
		
		for(j = 0; j<=COLUMNS; j++){
			temp = getch();
			
			if(temp == 13 || top >n){
				j = COLUMNS;
			}
			
			countColumn[baris] = top;
			setText(&(*newText), temp, file_name, oldText, logText, currentText, copyText, &top, &baris, &countLog, &countCurrent,  countColumn);
			
			top++;
			displayCurrentText(currentText, top, *newText, countColumn, baris);
		}
		row++;
		baris++;
	}
}

void setText(text *newText,char temp, char file_name[], char *oldText, char *logText, char *currentText, char *copyText, int *top,int *baris, int *countCurrent, int *countLog, int countColumn[]){
	int kolom;
	int lenLog;
	switch(temp){
		case BACKSPACE:
//			isOld = 0;
			BackSpace(&(*top));
			break;
		case COPY:
			copy(copyText, *newText);
			break;
		case PASTE:
			paste(copyText, &(*newText), countColumn );
			system("CLS");
			break;
		case SPACE:
			currentText[*top] = temp;
			saveLog(&(*countLog) , *top, logText, currentText);
			lenLog = *countLog;
			break;
		case ENTER:
			currentText[*top] = temp;
			addText(&(*newText), kolom, *top, currentText, *baris);
			
			*top = 0;
			*countLog = 0;
			*countCurrent = 0;
			
//			memset(oldText, 0, sizeof oldText);;
//			memset(logText, 0, sizeof logText);;
			
			break;
		case UNDO:
			saveCurrent(&(*countCurrent), *top, oldText, currentText);
			undo(&(*top), *countLog,  logText, currentText);
			break;
		case REDO:
			redo(*countCurrent, &(*top), oldText, currentText);
			break;
		case SAVE:
			saveFile(*newText, file_name, *baris, countColumn);
			break;
		default:
			
			currentText[*top] = temp;
			break;
	}	
}

void displayCurrentText(char currentText[], int top, text newText, int countColumn[],int baris){
	system("cls");
	
	printf("|Column : %d|Line : %d| \n", top, baris);
	displayNewText(newText, countColumn, baris);

	printf("Current Text : ");
	
	int i,j;
	for(i= 0; i<=top; i++){
		printf("%c", currentText[i]);
	}
}

void displayNewText(text newText, int countColumn[],int baris){
	for(int i=0; i<baris; i++){
		printf("%d|", i);
		for(int j=0; j<=countColumn[i]; j++){
			if(j==countColumn[i]){
				printf("\n");
			}else{
				printf("%c", newText.text[i][j]);
			}
		}
	}
}

void displayOpenText(text newText, int countColumn[],int baris){
	for(int i=0; i<baris; i++){
		printf("%d|", i);
		for(int j=0; j<countColumn[i]; j++){
			printf("%c", newText.text[i][j]);
		}
	}
}

void addText(text *newText, int kolom, int top, char currentText[], int baris){
	kolom = 0;
	
	for(int i= 0; i<top; i++){
		newText->text[baris][kolom] = currentText[i];
		kolom++;
	}
}
