#include "undo_redo.h"

void undo(char text[], int top)
{
	if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else{
    	printf("\n\t The popped elements is %d",text[top]);
    	top--;
	}
    
}
