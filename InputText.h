/*
File Name		: InputText.h
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

#ifndef InputText_H
#define InputText_H

#define COLUMNS 80
#define ROWS 40

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
