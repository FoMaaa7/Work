///////////////////////////////////////
////Task.cpp
////void sortirovka
#include "stdafx.h"
#include "rehcjdfz.h"
#include "resource.h"
//void sortirovka(StudEnd* massiv, int dlina) { //сортировка массива пузырьком
//StudEnd TEMP = { 0,TEXT(""),0,0,0,0,TEXT('*') };
////bool exit = false;
////while (!exit)
////{
////	exit = true;
//	for (int i = 0; i < (dlina - 1); i++)
//		
//		{
//			TEMP = massiv[i];
//			massiv[i] = massiv[i + 1];
//			massiv[i + 1] = TEMP;
//			exit = false;
//		}
////}

//Void output_massiv
void output_massiv(StudEnd* massiv, int dlina, HWND hListBox) 
{ //вывод массива в листбокс
	TCHAR buf[50];
	for (int i = 0; i < dlina; i++) 
	{
		if (massiv[i].priviv == 0)// massiv[i + 1].sr_zat)
		{
			swprintf(buf, TEXT(" %-20s ║ %-7s"), massiv[i].fam, TEXT(" не привит"));
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)buf);
		}
	}

}
//Void task
void task(wfstream& file, HWND hListBox) {
	
	int n = kolvoStrok(file);
	file.seekg(0, file.beg);
	StudEnd* I = new StudEnd[n + 1]; //создаём динамический массив структур
	int k = 0;
	for (StudEnd Object; read(file, Object);) {
		*(I + k) = Object;
		k++;
	}
	//sortirovka(I, n);
	output_massiv(I, n, hListBox);
	delete[] I;
}

