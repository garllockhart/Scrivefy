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

int top = -1; 
int n;
int baris = 0;
int kolom = 0;

void inputText(text *newText, char file_name[]);
void setText(text *newText,char temp, char file_name[]);
void displayText(text newText);
#endif
