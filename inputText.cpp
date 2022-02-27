#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "inputText.h"

void inputText(text *newText){
	int i;
	int j;
	char temp;
	printf("\nMasukkan Teks\n");
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
	newText->column[j] = temp;
	printf("%c", newText->column[j]);
}

void displayText(text newText){
	printf("\nTeks Anda\n");
	printf("%s", newText.column);
}
