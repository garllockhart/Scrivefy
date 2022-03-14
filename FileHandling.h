/*
File Name		: FileHandling.h
Description		: 
Author			: 
Date			: 27/02/2022
*/

#ifndef FileHandling_H
#define FileHandling_H
#include "inputText.h"

#include "KeyboardShortcuts.h"
#include "Welcome.h"

void newFile(); // modul untuk membuat file baru
//void openFIle():
void deleteFile();
void saveFile(text *newText, char file_name[]);
void help();

#endif
