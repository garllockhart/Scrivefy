/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#ifndef inputText_H
#define inputText_H

#define COLUMNS 15
#define ROWS 2

typedef struct {
	char column[COLUMNS];
}text;

void inputText(text *newText, char file_name[]);
void setText(text *newText,char temp, char file_name[], int *top, int n);
void displayText(text newText, int top);

#endif
