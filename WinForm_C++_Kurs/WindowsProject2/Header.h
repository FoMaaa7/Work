#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
#include <tchar.h>
using namespace std;

ostream& LineG(ostream&);
ostream& shapka(ostream&);
ostream& taskDesk(ostream& stream);

#ifdef UNICODE
//#define TCHAR wchar_t
#define TEXT(p) L##p
#define ostream wostream
#define fstream wfstream
#define cout wcout
#define cin wcin
#define setlocale _wsetlocale
#define strcpy wcscpy
#define strcmp wcscmp
#define strlen wcslen
#else
#define TCHAR char
#define TEXT(p) p
#endif UNICODE

//��������� ������ : ��� ����������(��������, �����������, ���������, ���������), 
//��� �����, ������� �����, �������������(������, ��������, ������������, ������� � ������), 
//���� ������ � ����������.