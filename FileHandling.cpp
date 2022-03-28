/*
File Name		: FileHandling.cpp
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "InputText.h"
#include "FileHandling.h"
#include "KeyboardShortcuts.h"
#include "Welcome.h"
/* ======= End of Header File ====== */

void newFile()
{
	int top, baris;
	FILE *FileText;
	text newText;
	char Location[30], FileName[25], Extension[5];
	
	printf("Enter File Name (Without Extension) : \n");
	scanf("%s", &FileName);
	strcpy(Extension, ".txt");
	strcpy(Location, "Text/");
	
	strcat(Location, FileName);
	strcat(Location, Extension);
	system("cls");
	
	FileText = fopen(Location, "w+");
	
	if(!FileText){
		printf("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	
	fclose(FileText);
	
	inputText(&newText, Location);	
}

void openFile()
{
	char buff[255];
	bool isEnd = false;
	int countColumn[ROWS],i = 0,j;
	FILE *fptr;
	char Location[30], FileName[25], Extension[5];
	text newText;
	
	printf("Enter File Name (Without Extension) : \n");
	scanf("%s", &FileName);
	strcpy(Extension, ".txt");
	strcpy(Location, "Text/");
	
	strcat(Location, FileName);
	strcat(Location, Extension);
	system("cls");
	
	//operasi file 
	if((fptr = fopen(Location,"r")) == NULL)
	{
		printf("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
	}
	while(!feof(fptr) ) {
		    for(j=0; j<COLUMNS; j++) {
		    	
		        fscanf(fptr,"%c",&newText.text[i][j]);
		        if(newText.text[i][j] == '\n' || newText.text[i][j] == NULL){
		        	
		        	break;
				}
		        
		    }
		countColumn[i] = j;
		i++;
		
	}
	fclose(fptr);
	displayNewText(newText, countColumn, i-1);
	
	printf("Press Any Key to continue . . ."); 
		
	getch();
			
	system("cls");
		
	Welcome(); 
}

void deleteFile()
{
	FILE *FileText;
	char Location[30], FileName[25], Extension[5];
	
	printf("Enter File Name (Without Extension) : \n");
	scanf("%s", &FileName);
	strcpy(Extension, ".txt");
	strcpy(Location, "Text/");
	
	strcat(Location, FileName);
	strcat(Location, Extension);
	system("cls");
	
	FileText = fopen(Location, "r");
	
	if(!FileText)
	{
		printf("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	
	fclose(FileText);
	
	if(remove(Location) == 0) {
		printf("File has been deleted successfully!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	} else {
		printf("ERROR : Sorry, there are no files to delete!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
}


void saveFile(text newText, char file_name[], int baris, int countColumn[]){
	FILE *FileText;
	
	FileText = fopen(file_name, "w+");
	
	if(!FileText){
		printf("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	
	for(int i=0; i<baris; i++){
		for(int j=0; j<countColumn[i]; j++){
			fprintf(FileText, "%c", newText.text[i][j]);
		}
		fprintf(FileText, "\n");
	}
	
	for(int i=0; i<baris; i++){
		for(int j=0; j<=countColumn[i]; j++){
			printf( "%c", newText.text[i][j]);
		}
		printf("\n");
	}
	
	
	fclose(FileText);
	
	system("cls");
	
	Welcome(); 
}

void editFile(){
	int countColumn[ROWS],i = 0,j;
	int currentRow, row;
	FILE *fptr;
	char Location[30], FileName[25], Extension[5];
	text newText;
	
	printf("Enter File Name (Without Extension) : \n");
	scanf("%s", &FileName);
	strcpy(Extension, ".txt");
	strcpy(Location, "Text/");
	
	strcat(Location, FileName);
	strcat(Location, Extension);
	system("cls");
	
	//operasi file 
	if((fptr = fopen(Location,"r")) == NULL)
	{
		printf("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
//	for(char c = getc(fptr); c != EOF; c = getc(fptr)) {
//        if(c == '\n'){
//        	row++;
//		}
//
//	}
	while(!feof(fptr) ) {
		    for(j=0; j<COLUMNS; j++) {
		        fscanf(fptr,"%c",&newText.text[i][j]);
		        
		        if(newText.text[i][j] == '\n' || newText.text[i][j] == NULL){
		        	break;
				}
		        
		    }
		countColumn[i] = j;
		i++;
		
	}
	
	fclose(fptr);
	displayNewText(newText, countColumn, i-1);
	inputUpdateText(&newText, Location, i-1, countColumn);
}

void saveasFile(text newText, int baris, int countColumn[]) {
	FILE *FileText;
	char Location[30], FileName[25], Extension[5];
	
	printf("\n\n");
	printf("Enter File Name (Without Extension) : \n");
	scanf("%s", &FileName);
	strcpy(Extension, ".txt");
	strcpy(Location, "Text/");
	
	strcat(Location, FileName);
	strcat(Location, Extension);
	
	FileText = fopen(Location, "w+");
	
	if(!FileText){
		printf("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	
	for(int i=0; i<baris; i++){
		for(int j=0; j<countColumn[i]; j++){
			fprintf(FileText, "%c", newText.text[i][j]);
		}
		fprintf(FileText, "\n");
	}
	
	for(int i=0; i<baris; i++){
		for(int j=0; j<=countColumn[i]; j++){
			printf( "%c", newText.text[i][j]);
		}
		printf("\n");
	}
	
	
	fclose(FileText);
	
	system("cls");
	
	Welcome(); 
}
