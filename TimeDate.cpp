/*
File Name		: TimeDate.cpp
Description		: 
Author			: 
Date			: 27/02/2022
*/

#include <stdio.h>
#include <time.h>
#define TIME 7
const char* const HARI[7] = {"Minggu","Senin","Selasa","Rabu","Kamis","Jumat","Sabtu"};
const char * const BULAN[12] = {"Januari","Februari","Maret","April","Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"};


int main(){
	time_t t;
	struct tm now;
	
	t = time (NULL);
	now = *localtime(&t);
	
	if (7 == TIME){
	printf ("%s,%d %s %d\n",HARI[now.tm_wday],now.tm_mday,BULAN [now.tm_mon],now.tm_year + 1900);
	}
	
	
	return 0;
}
