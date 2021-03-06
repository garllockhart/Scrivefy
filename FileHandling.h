/*
File Name		: FileHandling.h
Description		: 
Author			: 
Created at		: 27/02/2022
Updated at		: 
*/

#ifndef FileHandling_H
#define FileHandling_H
#include "inputText.h"

#include "KeyboardShortcuts.h"
#include "Welcome.h"

void newFile();
void openFile();
void deleteFile();
void editFile();
void saveFile(text newText, char file_name[], int baris, int countColumn[]);
void saveasFile(text newText, int baris, int countColumn[]);

#endif
