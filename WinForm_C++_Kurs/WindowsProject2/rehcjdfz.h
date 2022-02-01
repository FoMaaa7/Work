#pragma once
#pragma once
#include "resource.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define FILE "file.txt"
#define NAME 20
#define NUM 5
#define YEAR1 6
#define YEAR2 6
#define ZAT 7
#define SRZAT 7
#define DEL 2
#define ZAPLEN (NAME+NUM+YEAR1+YEAR2+ZAT+SRZAT+DEL+2)
#define NF 30
#define NI 20
#define NL 8
#define N 5
#define NLINE (NF*4+NI+4+11)
#define MAXX 3*NLINE
enum ShapeSize { MIN, MAX };
//struct object //объ€вл€ем структуру
//{
//	unsigned short int num;
//	TCHAR name[NAME];
//	unsigned short int year1;
//	unsigned short int year2;
//	unsigned short int zatrati;
//	unsigned short int sr_zat;
//	TCHAR del;
//};
struct StudEnd {
	TCHAR fam[NF]; 	// фамили€ 
	TCHAR imia[NI];
	TCHAR otch[NF];
	TCHAR aress[NF];
	TCHAR work[NF];
	unsigned short int priviv;
	int day;
	int mesyaz;
	int year;
	int del=0;
};
void get_Object(HWND hDlg, StudEnd& Object);
void write(wfstream& file, StudEnd& Object, int n=0 );
void write_N(wfstream& file, int n);
wfstream& read(wfstream& file, StudEnd& Object, int n=0);
//void output(StudEnd Object);
void output_all(HWND hListBox, wfstream& file);
int kolvoStrok(wfstream& file);
void mark(wfstream& file, int n);
void udal_mark(wfstream& file);
//void sortirovka(StudEnd* massiv, int dlina);
void output_massiv(StudEnd* massiv, int dlina, HWND hListBox);
void output_massiv2(StudEnd* massiv, int dlina, HWND hListBox);
void task(wfstream& file, HWND hListBox);
void task2(wfstream& file, HWND hListBox);
//void readZap(HWND hDlg, int n);
void output_all(HWND hListBox, wfstream& file);
void output(HWND hListBox, StudEnd Object);

