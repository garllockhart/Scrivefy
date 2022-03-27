/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#ifndef InputText_H
#define InputText_H

#define COLUMNS 30
#define ROWS 10

typedef struct {
	char text[ROWS][COLUMNS];
}text;

void inputText(text *newText, char file_name[]);
void inputUpdateText(text *newText, char file_name[],int currentRow, int countColumn[]);
void setText(text *newText,char temp, char file_name[], char *oldText, char *logText, char *currentText, char *copyText, int *top,int *baris, int *countCurrent, int *countLog, int countColumn[]);
void displayCurrentText(char currentText[], int top, text newText, int countColumn[],int baris);
void displayOpenText(text newText, int countColumn[],int baris);
void addText(text *newText, int kolom, int top, char currentText[], int baris);
void displayNewText(text newText, int countColumn[], int baris);

#endif
