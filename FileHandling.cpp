/*
File Name		: FileHandling.cpp
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "inputText.h"
#include "FileHandling.h"
#include "KeyboardShortcuts.h"
#include "Welcome.h"

void newFile()
{
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
		printf ("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	fclose(FileText);
	inputText(&newText, Location);
	
//	fprintf(FileText, "%s %s", newText.column, newText.rows);
	
	
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
		printf ("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	
	fclose(FileText);
	
	if(remove(Location) == 0) {
		printf ("File has been deleted successfully!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	} else {
		printf ("ERROR : Sorry, there are no files to delete!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
}

void saveFile(text *newText, char file_name[]){
	FILE *FileText;
	
	FileText = fopen(file_name, "w+");
	
	if(!FileText){
		printf ("ERROR : Sorry the file is unavailable!!!\n");
		printf("Press Any Key to continue . . ."); 
		
		getch();
			
		system("cls");
		
		/* Call Modul Welcome */
		Welcome(); 
	}
	
	fprintf(FileText, "%s", newText->text);
	
	fclose(FileText);
	
	system("cls");
	
	Welcome(); 
}

void editFile(){
	char inpedit;

	printf("Edit File (Y/N) ");
	scanf("%s",&inpedit);
	if(inpedit == 'y' || inpedit == 'Y'){
	int inp;
    	printf("Pilih index yang mau di edit :  ");
    	scanf("%d",&inp);
    	
    	printf("Data Lama : ");
    	for(j = 0; text[ inp ][ j ]; j++){
		putchar(text[ inp ][ j ]);}
		printf ("\ninput Data baru :");
		
	//	gets(text[t]);
    	
		scanf("%s",text[inp]);
    
    	printf("Data setelah Update : \n%s", text[t]);
	    	// JANGAN DIHAPUS, CODE ASLI
	 	for(i = 0; i < t; i++) {
	   for(j = 0; text[ i ][ j ]; j++) 
	      putchar(text[ i ][ j ]);
	   putchar('\n');
 }
