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
	printf("\n\tEnter the file name: ");
	
	scanf("%s",fn);
	fp1=fopen(fn,"r");
	system("cls");
	
	if(fp1==NULL){
		printf("\n\tFile not found!");
		fclose(fp1);
		goto end3;
	}
	
	while(!feof(fp1)) {
		c=getc(fp1);
		printf("%c",c);
	}
	
	fclose(fp1);
	printf("\n\n\tType the text and press Ctrl+S to Update\n");
	fp1=fopen(fn,"a");
	
	while(1) {
		c=getch();
		if(c==19)
		goto end3;
		if(c==13) {
			c='\n';
			printf("\n\t");
			fputc(c,fp1);
		}
		else {
			printf("%c",c);
			fputc(c,fp1);
		}
	}
	
	end3: fclose(fp1);
	 
	getch();
	}
 }
