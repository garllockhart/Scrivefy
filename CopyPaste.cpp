/*
File Name		: CopyPaste.cpp
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

/* ========== Header File ========== */
#include "CopyPaste.h"
#include "InputText.h"
#include <stdio.h>
#include <stdlib.h>
/* ======= End of Header File ====== */

void copy(char *copyText, text newText){
	int baris, kolom1, kolom2;
	
	printf("\n");
	printf("Masukkan baris : ");
	scanf("%d", &baris);
	fflush(stdin);
	printf("Masukkan mulai kolom : ");
	scanf("%d", &kolom1);
	fflush(stdin);
	printf("Masukkan akhir kolom : ");
	scanf("%d", &kolom2);
	fflush(stdin);
	
	setCopy(kolom1,kolom2, baris, copyText,newText);
}

void setCopy(int kolom1, int kolom2, int baris, char *copyText, text newText){
	for(int i = kolom1; i <= kolom2; i++){
		copyText[i] = newText.text[baris][i];
	}
	
	system("pause");
}

void paste(char *copyText, text *newText, int countColumn[]){
	int baris, kolom;
	int i=0;
	int j = 0;
	
	printf("%s", copyText);
	printf("\n");
	printf("Masukkan baris : ");
	scanf("%d", &baris);
	fflush(stdin);
	printf("Masukkan mulai kolom : ");
	scanf("%d", &kolom);
	
	setPaste(copyText, &(*newText), baris, kolom, countColumn);
}

void setPaste(char *copyText, text *newText, int baris, int kolom, int countColumn[]){
	int i = 0;
	int j = 0;
	
	size_t n = sizeof(copyText)/sizeof(copyText[0]);
	
	while(i<n){
		newText->text[baris][kolom] =  copyText[i] ;
		printf("kolom %d", i);
		printf("%c", newText->text[baris][i]);
		kolom++;
		i++;
		j++;	
	}
	
	countColumn[baris] = kolom;
	system("pause");
}
