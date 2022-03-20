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

//void inputText(text *newText, char file_name[]){
//	char temp;
//	int i,j;
//	int top = -1; 
//	int baris = -1;
//	j = top;
//	int n = COLUMNS;
//	printf("%d", n);
//	printf("Input Teks Anda\n");
//	for(i = 0; i<=ROWS; i++){
//	//	printf(" nilai i %d \n", i);
//		baris = i;
//		for(;;){
//			temp = getch();
//			top++;
//			j++;
//			setText(&(*newText),temp, file_name, &top, &baris, n);
////			printf("Ini new Text\n ");
////			printf("BARIS = %d, ", baris);
////			printf("TOP = %d, ", top);
////			printf("CHAR = %c\n", newText->text[i][top]);
//			if(top < 0 || baris > i){
//				break;
//			}
//			displayText(*newText, baris, top);
//		}
//	}
//	
//	
//}
//
//void setText(text *newText,char temp, char file_name[], int *top,int *baris, int n){
//	if(*top>=n-1)
//    {
//        *top = -1;
//    	*baris++;   
//    }
//    else
//    {
//    	switch(temp){
//    		case SAVE :
//				saveFile(&(*newText),file_name);
//    		case BACKSPACE:
//    			BackSpace(*newText, &(*top));
////    			printf("\nini undo %c\n", undoText.text[baris][top]);
//    			break;
//    		case ENTER:
//    			*top = -1;
//    			*baris++;
//				break;
//			case UNDO:
////				copyString(undoText, &(*newText));
//				break;
//    		default:
//    			newText->text[*baris][*top] = temp;
//    			break;
//		}		
//    }
//	
//}
//
//void displayText(text newText, int baris, int top){
//	system("cls");
//	int i= 0;
//	int j = 0;
//	while(i<=baris){
//		j = 0;
//		while(j<=top){
////			printf(" | %d %d | ", i ,j);
//			
//			printf("%c", newText.text[i][j] );
//			j++;
//		}
//		i++;	
//		printf("\n");
//		
//	}
//}

void inputText(text *newText, char file_name[]){
	int i,j,top =0,baris=0;
	char currentText[COLUMNS];
	int countColumn[ROWS], row;
	char temp;
	int n = COLUMNS;
	printf("Input Teks Anda\n");
	for(i=0; i<=ROWS; i++){
		
		countColumn[baris] = 0;
		for(j = 0; j<=COLUMNS; j++){
			temp = getch();
			setText(&(*newText), temp, file_name, currentText, &top, &baris, n);
			countColumn[row] = top;
			
			displayCurrentText(currentText, top, *newText, countColumn, baris);
			top++;
			
		}
		row++;
		
	}
	
	
	
}

void setText(text *newText,char temp, char file_name[],char *currentText, int *top,int *baris,int n){
	int kolom;
	switch(temp){
//		case 8:
//			isOld = 0;
//			backspace();
//			break;
//		case 32:
//			saveLog();
//			currentText[top] = temp;
//			break;
		case 13:
			addText(&(*newText), kolom, *top, currentText, *baris);
			
//			countLog = 0;
//			countCurrent = 0;
//			memset(oldText, 0, sizeof oldText);;
//			memset(logText, 0, sizeof logText);;
			
			break;
//		case 26:
//			saveCurrent();
//			undo();
//			break;
//		case 25:
//			redo();
//			break;
		default:
			
			currentText[*top] = temp;
			break;
	}	
}

void displayCurrentText(char currentText[], int top, text newText, int countColumn[],int baris){
	system("cls");
	displayNewText(newText, countColumn, baris);

	printf("current text : ");
	int i,j;
	for(i= 0; i<=top; i++){
		printf("%c", currentText[i]);
	}
}


void displayNewText(text newText, int countColumn[],int baris){
	
}


void addText(text *newText, int kolom, int top, char currentText[], int baris){
	kolom = 0;
	for(int i= 0; i<top; i++){
		newText->text[baris][kolom] = currentText[i];
		kolom++;
	}
	
}
