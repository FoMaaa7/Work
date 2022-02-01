#include "stdafx.h"
#include "rehcjdfz.h"
#include "resource.h"

void output_massiv2(StudEnd* massiv, int dlina, HWND hListBox)
{ //вывод массива в листбокс
	SYSTEMTIME st;
	GetLocalTime(&st);
	int yea = st.wYear;
	int mon = st.wMonth;
	TCHAR buf[100];
	for (int i = 0; i < (dlina-1); i++)
	{
		
		if (((yea - massiv[i].year) >= 1) || ((yea == massiv[i].year) && (mon - massiv[i].mesyaz>=6)))
		{
			wsprintf(buf, TEXT(" %-20s ║ %-17s "), massiv[i].fam,  TEXT("просрочена"));
			SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)buf);
		}
		//delete[] buf;
	}

}
//Void task
void task2(wfstream& file, HWND hListBox) {
	char* str = new char[1024];
	int n = 0;
	ifstream base("file.txt");
	while (!base.eof())
	{
		base.getline(str, 1024, '\n');
		n++;

	}
	base.close();
	delete str;
	//int n = kolvoStrok(file);
	file.seekg(0, file.beg);
	StudEnd* K = new StudEnd[n + 1]; //создаём динамический массив структур
	int k = 0;
	for (StudEnd Object; read(file, Object);) {
		*(K + k) = Object;
		k++;
	}
	//sortirovka(I, n);
	output_massiv2(K, n, hListBox);
	delete[] K;
}