/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#ifndef inputText_H
#define inputText_H

#define COLUMNS 5
#define ROWS 2

typedef struct {
	char text[ROWS][COLUMNS];
}text;

void inputText(text *newText, char file_name[]);
void setText(text *newText,char temp, char file_name[], int *top,int *baris,int n);
void displayText(text newText, int baris, int top);
#endif
