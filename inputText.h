/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#ifndef inputText_H
#define inputText_H

#define COLUMNS 80
#define ROWS 1

typedef struct {
	char column[COLUMNS];
	int rows[ROWS];
}text;

void inputText(text *newText);
void setText(text *newText,char temp, int i, int j);
void displayText(text newText);
#endif
