#include "FindReplace.h"
#include <stdlib.h>
#include <stdio.h>

void find(text *newText, int countColumn[]){
	int baris;
	printf("\nMasukkan Baris Yang Akan Direplace : ");
	scanf("%d", &baris);
	fflush(stdin);
	replace(&(*newText), countColumn, baris);
}

void replace(text *newText, int countColumn[], int baris){
	char replaceText[80];
	int i =0;
	printf("Masukkan Text Baru : ");
	scanf("%79[^\n]", &replaceText);
	while(replaceText[i] != NULL){
		newText->text[baris][i] = replaceText[i];
		i++;
	}
	countColumn[baris] = i;
}
