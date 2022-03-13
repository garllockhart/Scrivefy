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
	int i,j;
	int top = -1; 
	int baris = -1;
	j = top;
	int n = COLUMNS;
	printf("%d", n);
	printf("Input Teks Anda\n");
	for(i = 0; i<=ROWS; i++){
		printf(" nilai i %d \n", i);
		baris = i;
		for(;;){
			temp = getch();
			top++;
			j++;
			setText(&(*newText),temp, file_name, &top, &baris, n);
			printf("Ini new Text\n ");
			printf("BARIS = %d, ", baris);
			printf("TOP = %d, ", top);
			printf("CHAR = %c\n", newText->text[i][top]);
			if(top < 0 || baris > i){
				break;
			}
			displayText(*newText, top);
		}
	}
	
	
}

void setText(text *newText,char temp, char file_name[], int *top,int *baris, int n){
	if(*top>=n-1)
    {
        *top = -1;
    	*baris++;   
    }
    else
    {
    	switch(temp){
    		case SAVE :
				saveFile(&(*newText),file_name);
    		case BACKSPACE:
    			BackSpace(*newText, &(*top));
//    			printf("\nini undo %c\n", undoText.text[baris][top]);
    			break;
    		case ENTER:
    			*top = -1;
    			*baris++;
				break;
			case UNDO:
//				copyString(undoText, &(*newText));
				break;
    		default:
    			newText->text[*baris][*top] = temp;
    			break;
		}		
    }
	
}

void displayText(text newText, int top){
//	system("cls");
	int i= 0;
	int j = 0;
//	while(j<=baris){
		while(i<=top){
			printf("%c", newText.text[i] );
			i++;
		}
//		j++;
//	}
}
