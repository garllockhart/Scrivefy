/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#ifndef inputText_H
#define inputText_H

#define COLUMNS 30
#define ROWS 3

typedef struct {
	char text[ROWS][COLUMNS];
}text;

void inputText(text *newText, char file_name[]);
void setText(text *newText,char temp, char file_name[],char *currentText, int *top,int *baris,int n);
void displayCurrentText(char currentText[], int top, text newText, int countColumn[],int baris);
void addText(text *newText, int kolom, int top, char currentText[], int baris);
void displayNewText(text newText, int countColumn[], int baris);

#endif
