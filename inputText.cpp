/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "inputText.h"
#include "KeyboardShortcuts.h"
#include "InputHandlingNonStandard.h"
#include "FileHandling.h"

void inputText(text *newText, char file_name[]){
	char temp;
	int baris = 0;
	int kolom = 0;
	int top = -1; 
	int n = COLUMNS;
	printf("Input Teks Anda\n");
	while(baris<=ROWS){
		while(true){
			temp = getch();
			top++;
			setText(&(*newText), temp, file_name, &top, n);
			kolom++;
			displayText(*newText, top);
			if(top == 80){
				break;
			}
		}
		baris++;
//		newText.column[baris][top];
	}
	
	
}

void setText(text *newText,char temp, char file_name[], int *top, int n){
//	newText->rows[i] = i;
//	switch(temp){
//		case TAB : 
//			temp = TAB;
//			newText->column[j] = temp;
//			break;
//		case SPACE :
//			temp = SPACE;
//			newText->column[j] = temp;
//			break;
//		case SAVE :
//			temp = SAVE;
//			newText->column[j] = temp;
//			break;
//		default:
//			newText->column[j] = temp;
//			break;
//	}
	if(*top>n-1)
    {
//    	newText->column[top] = 32;
    }
    else
    {
    	switch(temp){
    		case SPACE:
    			newText->column[*top] = 32;
    			break;
    		case BACKSPACE:
    			BackSpace(*newText, top);
    			break;
    		case SAVE :
				saveFile(&(*newText),file_name);
    		default:
    			newText->column[*top] = temp;
    			break;
		}		
    }
	
}

void displayText(text newText, int top){
	system("cls");
	int i= 0;
	int j = 0;
//	while(j<=baris){
		while(i<=top){
			printf("%c", newText.column[i] );
			i++;
		}
//		j++;
//	}
}
