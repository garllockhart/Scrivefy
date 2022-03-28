/*
File Name		: InputText.cpp
Description		: Berisi algorima modul-modul yang berguna untuk mengolah kata
Author			: Jeremia Edwin Hamonangan
Created at		: 27/02/2022
Updated at		: 28/03/2022
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "InputText.h"
#include "KeyboardShortcuts.h"
#include "InputHandlingNonStandard.h"
#include "FileHandling.h"
#include "UndoRedo.h"
#include "CopyPaste.h"
#include "FindReplace.h"
/* ======= End of Header File ====== */

void inputText(text *newText, char file_name[]){
	// KAMUS DATA
	int i; 
	int j; 
	int kolom;
	int top = 0;					// variabel penunjuk teks
	int baris = 0;					// variabel baris
	int countLog;					// variabel penghitung jumlah elemen log text
	int countCurrent;				// variabel penghitung jumlah elmen current text
	int countColumn[ROWS];			// variabel penyimpan panjang setiap baris textt
	
	char currentText[COLUMNS];		// variabel array yang menampung teks di baris baru
	char oldText[COLUMNS];			// menyimpan teks sebelum di undo yang nantinya akan dipanggil lagi dengan redo
	char logText[COLUMNS]; 			// menyimpan teks untuk log atau history, akan dipanggil ketika undo 
	char copyText[COLUMNS];			// menyimpan teks yang disalin
	char temp;						// menyimpan setiap karakter yang diinput
	
	printf("Input Teks Anda\n");
	
	for(i = 0; i <= ROWS; i++){ 
		
		if (baris == ROWS) {										// Jika baris sudah berada diakhir maka jalankan modul save
			printf("\n");
			saveFile(*newText, file_name, baris, countColumn);		// modul save
		}
		
		for(j = 0; j<=COLUMNS; j++){
			temp = getch();															// Menerima input karakter
			countColumn[baris] = top;												// Menambah banyaknya kolom pada baris saat ini
			setText(&(*newText), temp, file_name, oldText, logText, currentText, copyText, &top, &baris, &countLog, &countCurrent,  countColumn); // Memasukkan karakter yang telah diinput kedalam array
			displayCurrentText(currentText, top, *newText, countColumn, baris);		// Menampilkan text yang baru diinput
			
			if(temp == ENTER || j >= COLUMNS){																// Pengkondisian jika karakter input atau sudah melebihi batas kolom maka hentikan loop
				break;
			} else if(temp == COPY || temp == PASTE|| temp == UNDO || temp == REDO|| temp == BACKSPACE){	// Pengkondisian jika input merupakan shortcut maka variabel pencacah tidak menambah nilainya
				j--;
			}
			
			top++;																	// 	Menambah nilai top
		}
		
		addText(&(*newText), kolom, top, currentText, baris);						// Ketika memasuki baris baru maka current text dimasukkan ke dalam matrik
		top = 0;																	// Merubah nilai top menjadi 0 kembali
		countLog = 0;																// Merubah nilai count log menjadi 0 kembali
		countCurrent = 0;															// Merubah nilai count log menjadi 0 kembali
		baris++;																	// Menambah nilai baris
	}
}

void inputUpdateText(text *newText, char file_name[], int currentRow, int countColumn[]){	// Memiliki karakteristik yang sama dengan modul inputText hanya berbeda pada parameter
	int i,j,top =0,baris=currentRow;
	int countLog;
	int countCurrent;
	int kolom;
	char currentText[COLUMNS], oldText [COLUMNS],logText[COLUMNS],copyText[COLUMNS];
	int  row;
	char temp;
	int n = COLUMNS;
	
	printf("\nInput Teks Anda\n");
	
	for(i=0; i<=ROWS; i++){
		
		if (baris == ROWS) {
			printf("\n");
			saveFile(*newText, file_name, baris, countColumn);
		}
		for(j = 0; j<=COLUMNS; j++){
			temp = getch();
			countColumn[baris] = top;
			setText(&(*newText), temp, file_name, oldText, logText, currentText, copyText, &top, &baris, &countLog, &countCurrent,  countColumn);
			displayCurrentText(currentText, top, *newText, countColumn, baris);
			if(temp == ENTER || j >= COLUMNS){
				break;
			}else if(temp == COPY || temp == PASTE|| temp == UNDO || temp == REDO|| temp == BACKSPACE){
				j--;
			}
			
			top++;	
		}
		addText(&(*newText), kolom, top, currentText, baris);
		top = 0;
		countLog = 0;
		countCurrent = 0;
		baris++;
	}
}

void setText(text *newText,char temp, char file_name[], char *oldText, char *logText, char *currentText, char *copyText, int *top,int *baris, int *countCurrent, int *countLog, int countColumn[]){
	int kolom;
	int lenLog;
	switch(temp){
		case BACKSPACE:
			BackSpace(&(*top));
			break;
		case COPY:
			copy(copyText, *newText);
			break;
		case PASTE:
			paste(copyText, &(*newText), countColumn );
			system("CLS");
			break;
		case SPACE:
			currentText[*top] = temp;
			saveLog(&(*countLog) , *top, logText, currentText);
			lenLog = *countLog;
			break;
		case ENTER:
			currentText[*top] = temp;
			addText(&(*newText), kolom, *top, currentText, *baris);
			break;
		case UNDO:
			saveCurrent(&(*countCurrent), *top, oldText, currentText);
			undo(&(*top), *countLog,  logText, currentText);
			break;
		case REDO:
			redo(*countCurrent, &(*top), oldText, currentText);
			break;
		case SAVE:
			saveFile(*newText, file_name, *baris, countColumn);
			break;
		case REPLACE:
			find(&(*newText), countColumn);
		default:
			currentText[*top] = temp;
			break;
	}	
}

void displayCurrentText(char currentText[], int top, text newText, int countColumn[],int baris){
	system("cls");
	
	printf("|Column : %d|Line : %d| \n", top, baris);
	displayNewText(newText, countColumn, baris);

	printf("Current Text : ");
	
	int i,j;
	for(i= 0; i<=top; i++){
		printf("%c", currentText[i]);
	}
}

void displayNewText(text newText, int countColumn[],int baris){
	for(int i=0; i<baris; i++){
		printf("%d|", i);
		for(int j=0; j<=countColumn[i]; j++){
			if(j==countColumn[i]){
				printf("\n");
			} else{
				printf("%c", newText.text[i][j]);
			}
		}
	}
}

void displayOpenText(text newText, int countColumn[],int baris){
	for(int i=0; i<baris; i++){
		printf("%d|", i);
		
		for(int j=0; j<countColumn[i]; j++){
			printf("%c", newText.text[i][j]);
		}
	}
}

void addText(text *newText, int kolom, int top, char currentText[], int baris){
	kolom = 0;
	
	for(int i= 0; i<top; i++){
		newText->text[baris][kolom] = currentText[i];
		kolom++;
	}
}
