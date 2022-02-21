#include <iostream>
#include "pulldown.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int pilih_menu;
	
	printf("Menu Fitur Teks Editor\n");
	printf("1. New File\n");
	printf("2. Open File\n");
	printf("3. Edit File\n");
	printf("4. Delete File\n");
	printf("5. Help\n");
	printf("\n\tPilih : ");
	scanf("%d", &pilih_menu);
	
	switch(pilih_menu){
		case 1 : 
			newFile();
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 5 : 
			break;
	}
	
	
	return 0;
}
