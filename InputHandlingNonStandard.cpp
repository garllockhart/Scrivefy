#include <stdio.h>
#include "InputHandlingNonStandard.h"

void BackSpace(text newText, int *top){
	if(*top <= -1) {
        printf("\n\t Stack is under flow");
    } else {
        *top = *top - 2;
    }
}
