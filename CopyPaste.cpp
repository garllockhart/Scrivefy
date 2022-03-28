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
	
	int baris, kolomAwal, kolomAkhir;
	
	
	printf("\n");
	printf("Masukkan baris : ");
	scanf("%d", &baris);
	fflush(stdin);
	
	
	printf("Masukkan mulai kolom : ");
	scanf("%d", &kolomAwal);
	fflush(stdin);
	
	
	printf("Masukkan akhir kolom : ");
	scanf("%d", &kolomAkhir);
	fflush(stdin);
	
	
	setCopy(kolomAwal,kolomAkhir, baris, copyText,newText);
}

void setCopy(int kolomAwal, int kolomAkhir, int baris, char *copyText, text newText){
	
	for(int i = kolomAwal; i <= kolomAkhir; i++){
		
		copyText[i] = newText.text[baris][i];
	}
	
	
	system("pause");
}

void paste(char *copyText, text *newText, int countColumn[]){
	
	int baris, kolom;	
	
	printf("\n%s", copyText);
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
	size_t n = sizeof(copyText)/sizeof(copyText[0]);
	
	
	while(i<n){
		
		newText->text[baris][kolom] =  copyText[i] ;
		
		
		printf("%c", newText->text[baris][i]);
		kolom++;
		i++;	
	}
	
	
	countColumn[baris] = kolom;
	system("pause");
}
