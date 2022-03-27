#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Welcome.h"

void help()
{
    FILE *filePointer;
    
    char dataToBeRead[50];

    filePointer = fopen("Help.txt", "r");
    
    if (filePointer == NULL) {
        printf( "GfgTest.c file failed to open." );
    } else {
        printf("The file is now opened.\n");
        
        while(fgets(dataToBeRead, 50, filePointer) != NULL)
        {
            printf( "%s" , dataToBeRead);
        }
         
        fclose(filePointer) ;
    }      
    
    printf("\n\n");
    printf("Press Any Key to continue . . ."); 
		
	getch();
		
	system("cls");
		
	/* Call Modul Welcome */
	Welcome(); 
}
