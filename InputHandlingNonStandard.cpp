/*
File Name		: Welcome.cpp
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include "InputHandlingNonStandard.h"

void BackSpace(int *top){
	if(*top <= -1) {
        printf("\n\t Stack is under flow");
    } else {
        *top = *top - 2;
    }
}
