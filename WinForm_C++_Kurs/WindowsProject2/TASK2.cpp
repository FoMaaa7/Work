#include "stdafx.h"
#include "rehcjdfz.h"
#include "resource.h"
void output_massiv2(StudEnd* massiv, int dlina, HWND hListBox)
{ //вывод массива в листбокс
	TCHAR buf[50];

	SYSTEMTIME st;
	GetLocalTime(&st);
	int yea = st.wYear;
	int mon = st.wMonth;
	int da = st.wDay;
	
	int a;
	int b;
	int c;
	for (int i = 0; i < dlina; i++)
	{
		a=_wtoi(massiv[i].year);

		if ((yea-a)>1)// massiv[i + 1].sr_zat)
		{
			swprintf(buf, TEXT(" %-20s ║ %-17s"), massiv[i].fam,TEXT("просрочена"));
			/*swprintf (buf1, TEXT(" %-20s ║ %-17s"), massiv2[i].fam, TEXT(" просрочена "));*/
			SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)buf);
		}
	}

}
//Void task
void task2(wfstream& file, HWND hListBox) {
	int n = kolvoStrok(file);
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