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

//void openFile()
//{
//	char buff[255];
//	FILE *fptr;
//	char Location[30], FileName[25], Extension[5];
//	
//	//nama file yang akan di buka  
//	printf("\nNama File yang akan di buka :");
//	gets(namafile);
//	system("cls");
//	
//	//operasi file 
//	if((fptr = fopen(namafile,"r")) == NULL)
//	{
//		printf("ERORR! Data tidak ditemukan\n");
//		printf("\nTekan Enter Untuk Kembali");
//	}
//	while(fgets(buff, sizeof(buff),fptr))
//	{
//		printf("%s", buff);
//	}
//
//	fclose(fptr);
//}

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


//void help( )
//{
// 
//    // Declare the file pointer
//    FILE *filePointer ;
//     
//    // Declare the variable for the data to be read from file
//    char dataToBeRead[50];
// 
//    // Open the existing file GfgTest.c using fopen()
//    // in read mode using "r" attribute
//    filePointer = fopen("help.txt", "r") ;
//     
//    // Check if this filePointer is null
//    // which maybe if the file does not exist
//    if ( filePointer == NULL )
//    {
//        printf( "GfgTest.c file failed to open." ) ;
//    }
//    else
//    {
//         
//        printf("The file is now opened.\n") ;
//         
//        // Read the dataToBeRead from the file
//        // using fgets() method
//        while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
//        {
//         
//            // Print the dataToBeRead
//            printf( "%s" , dataToBeRead ) ;
//        }
//         
//        // Closing the file using fclose()
//        fclose(filePointer) ;
//    }      
//}
