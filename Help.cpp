#include <stdio.h>

void help()
{
    FILE *filePointer;
    
    char dataToBeRead[50];

    filePointer = fopen("help.txt", "r");
    
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
}
