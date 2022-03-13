/*
File Name		: InputText.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "inputText.h"
#include "KeyboardShortcuts.h"
#include "FileHandling.h"

void inputText(text *newText, char file_name[]){
	int i;
	int j;
	char temp;
	for(i = 0; i<ROWS; i++){
		baris = i;
		for(;;){
			temp = getch();
			top++;
			setText(&(*newText), temp, i, j);
			if(newText->column[j] == SAVE){
				saveFile(&(*newText), file_name);
			if(top < 0){
				break;
			}
			displayText(*newText);
		}
		
	}
}

void setText(text *newText,char temp, int i, int j){
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
//	
//	printf("%c", newText->column[j]);
text undoText;
	
    if(top>=n-1)
    {
        top = 0;
    	baris++;
        
    }
    else
    {
    	switch(temp){
    		case 8:
    			backspace(*newText, &undoText);
    			printf("\nini undo %c\n", undoText.column[baris][top]);
    			break;
    		case 13:
    			newText->column[baris][top] = '\n';
    			top = -1;
    			baris++;
				break;
			case 26:
				copyString(undoText, &(*newText));
				break;
    		default:
    			newText->column[baris][top] = temp;
    			break;
		}	
    }
}

void displayText(text newText){
	printf("\nTeks Anda\n");
	printf("%s", newText.column);
}
