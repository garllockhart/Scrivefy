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

void inputText(text *newText){
	int i;
	int j;
	char temp;
	
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLUMNS; j++){
			temp = getch();
			setText(&(*newText), temp, i, j);
		}
	}
	
	displayText(*newText);
}

void setText(text *newText,char temp, int i, int j){
	newText->rows[i] = i;
	 
	if(temp == SPACE){
		temp = SPACE;
		newText->column[j] = temp;
	}
	else{
		newText->column[j] = temp;
	}
	
	printf("%c", newText->column[j]);
}

void displayText(text newText){
	printf("\nTeks Anda\n");
	printf("%s", newText.column);
}
