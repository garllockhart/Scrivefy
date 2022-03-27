/*
File Name		: Welcome.cpp
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "FileHandling.h"
#include "Help.h"
#include "TimeDate.h"
/* ======= End of Header File ====== */

int Welcome()
{
	time_t t;
	int Menu;
	struct tm now;
	
	t = time(NULL);
	now = *localtime(&t);
	
	printf("Date : %s, %s %d, %d", DAY[now.tm_wday], MONTH[now.tm_mon], now.tm_mday, now.tm_year + 1900);
	printf("\n\n");
	
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
			/* Call Modul newFile */
			newFile();
			break;
		case 2 : 
			/* Call Modul openFile */
			openFile();
			break;
		case 3 : 
			/* Call Modul editFile */
			editFile();
			break;
		case 4 : 
			/* call Modul deleteFile */
			deleteFile();
			break;
		case 5 : 
			/* Call Modul Help */
			Help();
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
