/*
File Name		: FileHandling.cpp
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "inputText.h"
#include "FileHandling.h"

void newFile(){
	FILE *file_text;
	text newText;
	char file_name[25];
	char extension[5];
	printf("Masukkan Nama File : \n");
	scanf("%s", &file_name);
	strcpy(extension, ".txt");
	strcat(file_name,extension);
	printf("%s", file_name);
	if((file_text = fopen(file_name, "w+") )== NULL){
		printf("Couldn't open this file! \n");
		return;
	}
	inputText(&newText);
	
	fprintf(file_text, " %s %s", newText.column, newText.rows);
	
	fclose(file_text);
	
}
