#include "stdafx.h"
#include "Header.h"
#include "rehcjdfz.h"
//#include "WindowsProject2.h"
//Void write
void write(wfstream& file, StudEnd& Object, int n) { //функция записи в файл
	file.clear();
	if (n)
		file.seekg((n - 1)*(NLINE), file.beg);
	else
		file.seekg(0, file.end);
	/*if (Object.del != TEXT('^')) {
		Object.del = TEXT('*');
	}*/
	//Object.del = TEXT('*');
	/*if (Object.del == 1) {
		Object.del = 1;
	}
	if (Object.del != 1)
	{

		Object.del = 0;

	}*/
	file << Object.fam << setw(8) << Object.imia << setw(8) << Object.otch
		<< setw(8) << Object.aress << setw(8) << Object.work << setw(8) << Object.priviv
		<< setw(8) << Object.day<<setw(8)<<Object.mesyaz<<setw(8)<<Object.year<<setw(8)<<Object.del << endl;
	if (!file) {
		exit(6);
	}
}

//int kolvoStrok
int kolvoStrok(wfstream& file) { //функция расчёта кол-ва строк
	file.clear();
	file.seekg(0, file.end);
	return (int)(file.tellg() / MAXX);
}
//Wfstream& read
wfstream& read(wfstream & file, StudEnd& Object, int n) { //функция чтения из файла
	file.clear();
	if (n)
		file.seekg((n- 1)*(NLINE), file.beg);
	file >> Object.fam >> Object.imia >> Object.otch >> Object.aress >> Object.work>> Object.priviv
		>> Object.day>>Object.mesyaz>>Object.year>>Object.del;
	/*if (!file & !file.eof()) {
		exit(3);
	}*/
	return file;
}
//Void mark
void mark(wfstream & file, int n) { //функция отметки записи
	file.clear();
	StudEnd Object;
	
	//write(file, Object, n+1);
	read(file, Object, n);

	if (Object.del == 0) {
		Object.del = 1;
	}
	else {
		Object.del = 0;
	}
	write(file, Object, n);
}
//Void udal_mark
void udal_mark(wfstream & file) { //функция удаления всех записей
	file.clear();
	file.seekg(0, file.beg);
	wfstream tmp("tmp.txt", ios::out);
	tmp.imbue(locale(".1251"));
	for (StudEnd Object; read(file, Object);) {
		if (Object.del == 0)
			write(tmp, Object);
	}
	file.close();
	tmp.close();
	remove(FILE);
	rename("tmp.txt", FILE);
	file.open(FILE, ios::out | ios::in);
}
//Void output
void output(HWND hListBox, StudEnd Object) { //функция вывода записи в листбокс
	TCHAR buf[150];
	
	swprintf(buf, TEXT(" %-10s ║ %-10s ║ %-10s ║ %-8s ║ %-8s ║ %-8d ║ %-8d ║ %-8d ║ %-8d ║ %-2d  "), Object.fam, Object.imia, Object.otch, Object.aress, Object.work, Object.priviv, Object.day, Object.mesyaz, Object.year, Object.del);
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)buf);
}
//Void output_all
void output_all(HWND hListBox, wfstream & file) { //функция вывода всех записей в листбокс
	file.clear();
	file.seekg(0, file.beg);
	for (StudEnd Object; read(file, Object);)
		output(hListBox, Object);
}
