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


void help( )
{
 
    // Declare the file pointer
    FILE *filePointer ;
     
    // Declare the variable for the data to be read from file
    char dataToBeRead[50];
 
    // Open the existing file GfgTest.c using fopen()
    // in read mode using "r" attribute
    filePointer = fopen("help.txt", "r") ;
     
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "GfgTest.c file failed to open." ) ;
    }
    else
    {
         
        printf("The file is now opened.\n") ;
         
        // Read the dataToBeRead from the file
        // using fgets() method
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
        {
         
            // Print the dataToBeRead
            printf( "%s" , dataToBeRead ) ;
        }
         
        // Closing the file using fclose()
        fclose(filePointer) ;
    }      
}
