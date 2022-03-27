/*
File Name		: InputHandlingNonStandard.cpp
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

/* ========== Header File ========== */
#include <stdio.h>
#include "InputHandlingNonStandard.h"
/* ======= End of Header File ====== */

void BackSpace(int *top){
	if(*top <= -1) {
		printf("\n");
        printf("Stack is under flow");
    } else {
        *top = *top - 2;
    }
}
