/*
File Name		: Welcome.cpp
Description		: 
Author			: 
Date			: 27/02/2022
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pulldown.h"
#include "FileHandling.h"
/* ======= End of Header File ====== */

int Welcome()
{
	int Menu;
	
	printf("|==================================================|\n");
	printf("|                 WELCOME TO SCRIVEFY              |\n");
	printf("|==================================================|\n");
	printf("|1. New File                                       |\n");
	printf("|2. Open File                                      |\n");
	printf("|3. Edit File                                      |\n");
	printf("|4. Delete File                                    |\n");
	printf("|5. Help                                           |\n");
	printf("|==================================================|\n");
	printf("|     Copyright 2022 - Develop by ReactOrganiz     |\n");
	printf("|==================================================|\n");
	
	
	printf("\n\n");
    
    printf("Select Menu : ");
	scanf("%d", &Menu);
	system("cls");
	
	switch(Menu){
		case 1 : 
			newFile();
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			deleteFile();
			break;
		case 5 : 
			break;
		default:
	 		printf("ERROR : Sorry I don't know the answer to this one!!!\n");
	 		printf("Press Any Key to continue . . .");
	 		getche();
	 		
	 		system("cls");
	 		
	 		/* Call Modul Welcome */
			Welcome();
			break;
	}
}
