/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "inputText.h"
#include "KeyboardShortcuts.h"
#include "FileHandling.h"

void inputText(text *newText, char file_name[]){
	int i;
	int j;
	char temp;
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLUMNS; j++){
			temp = getch();
			setText(&(*newText), temp, i, j);
			if(newText->column[j] == SAVE){
				saveFile(&(*newText), file_name);
			}
		}
	}
	
	displayText(*newText);
}

void setText(text *newText,char temp, int i, int j){
	newText->rows[i] = i;
	switch(temp){
		case TAB : 
			temp = TAB;
			newText->column[j] = temp;
			break;
		case SPACE :
			temp = SPACE;
			newText->column[j] = temp;
			break;
		case SAVE :
			temp = SAVE;
			newText->column[j] = temp;
			break;
		default:
			newText->column[j] = temp;
			break;
	}
	
	printf("%c", newText->column[j]);
}

void displayText(text newText){
	printf("\nTeks Anda\n");
	printf("%s", newText.column);
}
