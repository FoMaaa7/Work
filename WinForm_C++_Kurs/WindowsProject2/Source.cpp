#include "stdafx.h"
#include <time.h>
#include "Header.h"
#include "WindowsProject2.h"
using namespace std;
extern int koll;
extern const char* nameFile = "medest.bin";

fstream p(nameFile, ios::binary | ios::in | ios::out);

int fptr = 0;//указатель позиции

//#include "WindowsProject2.cpp"
StudBeg studBeg = { TEXT(""),TEXT(""),0 };
StudBeg   GetStud(HWND);
void putStudEndToStroka(StructEnd& );
BOOL CALLBACK GetDataDlgProc(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		// с помощью функции SetFocus здесь нужно установить  фокус ввода 
		// на элемент  управления с идентификатором IDC_GET_FAM
		SetFocus(hDlg);
		return FALSE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			/*case ID_GET:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_GET), hWnd, GetDataDlgProc);*/
		case IDOK:

			// Здесь необходимо организовать чтение информации из элементов
			// управления –вызвать функцию, которая будет это осуществлять
			studBeg = GetStud(hDlg);
			
			//obrabotkaInfo(studBeg);
			EndDialog(hDlg, TRUE);
			
			return TRUE;

		case IDCANCEL:
			//MessageBox(hDlg, buf, TEXT("Сообщение об ошибке ввода"), MB_OK);
			studBeg = GetStud(hDlg);
			*studBeg.fam = 0;
			*studBeg.imia = 0;
			*studBeg.otch= 0;
			*studBeg.aress = 0;
			studBeg.year = 0;
			*studBeg.priviv = 0;
			studBeg.day = 0;
			studBeg.mesyaz= 0;
			*studBeg.work = 0;
			EndDialog(hDlg, FALSE);
			return TRUE;
		}
		break;
	}
	return FALSE;

}

StudBeg  GetStud(HWND hDlg)
{
	TCHAR buf[400] = TEXT("");
	/*const char* nameFile = "medest.bin";

	fstream p(nameFile, ios::binary | ios::in | ios::out);*/
	p.open(nameFile, ios::binary | ios::in | ios::out | ios::trunc);
	if (!p.is_open())
	{
		wcscpy(buf, TEXT("  Файл не найден..."));
		MessageBox(hDlg, buf, TEXT("Сообщение об ошибке"), MB_OK);
		p.close();
		if (!p.is_open())
		{
			wcscpy(buf, TEXT("Файл не может быть открыт или создан"));
			MessageBox(hDlg, buf, TEXT("Сообщение об ошибке"), MB_OK);
			system("pause");
			exit(0);
		}
		wcscpy(buf, TEXT(" Создан новый файл."));
		MessageBox(hDlg, buf, TEXT("Сообщение"), MB_OK);
	}
	else
	{
		wcscpy(buf, TEXT("Открыт файл "));
		MessageBox(hDlg, buf, TEXT("Сообщение"), MB_OK);
	}



	
	p.clear();
	p.seekp(0, ios::beg);
	//while (!p.read((TCHAR*)& med, len).eof()) kolstr++;

	TCHAR ans;
	////////////////////////////////////////////////////////////////////////////
	StudBeg     studBeg;
	/*p.clear();
	p.seekg(0, ios::end);
	out(p, med, len, 0);*/
	BOOL 	lpFam = TRUE, lpImia = TRUE, lpOtch = TRUE, lpAdress = TRUE, lpWork = TRUE, lpPriviv = TRUE, lpDay, lpMesyaz, lpYear;
	GetDlgItemText(hDlg, IDC_GET_FAM, studBeg.fam, 20);
	if (*studBeg.fam == 0)
	{
		wcscpy(buf, TEXT("  ошибка ввода фамилии!"));
		lpFam = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_IMIA, studBeg.imia, 12);
	if (*studBeg.imia == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ошибка ввода имени!"));
		lpImia = FALSE;
	}
	///
	GetDlgItemText(hDlg, IDC_GET_OTCHESTVO, studBeg.otch, 12);
	if (*studBeg.otch == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ошибка ввода отчества!"));
		lpOtch = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_ADRESS, studBeg.aress, 12);
	if (*studBeg.aress == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ошибка ввода адреса!"));
		lpAdress = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_RABOTA, studBeg.work, 12);
	if (*studBeg.work == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ошибка ввода работы!"));
		lpWork = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_PRIVIV, studBeg.priviv, 12);
	if (*studBeg.priviv == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ошибка ввода прививки!"));
		lpPriviv = FALSE;
	}
	studBeg.day = GetDlgItemInt(hDlg, IDC_GET_DAY, &lpDay, FALSE);
	studBeg.mesyaz = GetDlgItemInt(hDlg, IDC_GET_MESYAZ, &lpMesyaz, FALSE);
	studBeg.year = GetDlgItemInt(hDlg, IDC_GET_YEAR, &lpYear, FALSE);
	if ( (lpDay == FALSE)
		|| (lpYear == FALSE)
		|| (lpMesyaz == FALSE))
		wcscpy(buf + wcslen(buf), TEXT("  ошибка ввода даты флюрорографии!"));
	/*if (lpGod == FALSE ||
		studBeg.godRojd 	<	1970 ||
		lpFam == FALSE ||
		lpImia == FALSE)*/

		//MessageBox(hDlg, buf, TEXT("Сообщение об ошибке ввода"), MB_OK);
		//// установки признака пустой не введенной информации         
	if ((lpFam== FALSE)
		|| (lpImia == FALSE)
		|| (lpOtch == FALSE)
		|| (lpAdress == FALSE)
		|| (lpWork == FALSE)
		|| (lpPriviv == FALSE)
		|| (lpDay == FALSE)
		|| (lpYear == FALSE)
		|| (lpMesyaz == FALSE)
		)
	{
		MessageBox(hDlg, buf, TEXT("Сообщение об ошибке ввода"), MB_OK);
		*studBeg.fam = 0;
		*studBeg.imia = 0;
		*studBeg.otch = 0;
		*studBeg.aress = 0;
		studBeg.year = 0;
		*studBeg.priviv = 0;
		studBeg.day = 0;
		studBeg.mesyaz = 0;
		*studBeg.work = 0;
	}
	 return  studBeg; 
}
//fstream& out(fstream& p, StructEnd& obj, int len, int n)

	//if (!p.is_open())
	//{
	//	//cout << "Файл не открыт\n";
	//	//system("pause");
	//	//exit(0);
	//}
	//if (n) p.seekg(len * (n - 1));
	//p.write((TCHAR*)& obj, len);

	//if (p.bad())
	//{
	//	//cout << "Ошибка записи!" << endl;
	//	//system("pause");
	//	//exit(0);
	//}

	//return p;
	//p.close();
//}
StructEnd  obrabotkaInfo(StudBeg studBeg)
{
	//// получить текущую дату - текущий год newtime.tm_year+1900
	////  смотрите в Help пример применения функции _localtime64_s
	//char buf[230];
	//time_t ltime;
	//time(&ltime);
	//errno_t    err = ctime_s(buf, 26, &ltime);
	//// struct tm 
	//tm  newtime;
	//_localtime64_s(&newtime, &ltime);
	//int let = 0;
	//// вычисление возраста относительно текущего года
	///*if (studBeg.godRojd)
	//	let = (newtime.tm_year + 1900) - studBeg.godRojd;*/
	/*SYSTEMTIME st;
	GetLocalTime(&st);
	int god = st.wYear;
	int mes = st.wMonth;
	int den = st.wDay;*/

	StructEnd u;

	// запись информации о студенте в новом виде		
	/*if (let > 0 && studBeg.godRojd >= 1980)
	{*/
		//int lenF = wcslen(studBeg.fam), lenI = wcslen(studBeg.imia);
		wcscpy(u.studEnd.fam, studBeg.fam);
		wcscpy(u.studEnd.imia, studBeg.imia);
		wcscpy(u.studEnd.otch, studBeg.otch);
		wcscpy(u.studEnd.aress, studBeg.aress);
		wcscpy(u.studEnd.work, studBeg.work);
		wcscpy(u.studEnd.priviv, studBeg.priviv);
		swprintf(u.studEnd.day, TEXT("%d"), studBeg.day);
		swprintf(u.studEnd.mesyaz, TEXT("%d"), studBeg.mesyaz);
		swprintf(u.studEnd.year, TEXT("%d"), studBeg.year);
	//?	swprintf(u.studEnd.data, TEXT("%d"), let);*/
		StudBeg k;
		
		putStudEndToStroka(u);
	/*}*/
	return u;
}


void putStudEndToStroka(StructEnd& u)
{
	// запись информации из  трех строк данного  u.studEnd 
	//в одну строку u.str

	swprintf(u.str, TEXT(" %-10s ║ %-10s ║ %-10s ║ %-8s ║ %-8s ║ %-8s ║ %-4s ║ %-4s ║ %-4s "), u.studEnd.fam, u.studEnd.imia, u.studEnd.otch, u.studEnd.aress, u.studEnd.work, u.studEnd.priviv, u.studEnd.day, u.studEnd.mesyaz, u.studEnd.year);
	//vvod(med);
	//delete studEnd;
	/*p.open(nameFile, ios::binary | ios::in | ios::out | ios::trunc);
	p.clear();
	p.seekg(0, ios::end);
	p << endl;
	p<< u.studEnd.fam<< TEXT("  ")<<u.studEnd.imia <<TEXT("  ")<< u.studEnd.otch << TEXT("  " )<< u.studEnd.aress << TEXT("  ") << u.studEnd.work << TEXT("  ") << u.studEnd.priviv << TEXT("  ") << u.studEnd.day << TEXT("  ") << u.studEnd.mesyaz << TEXT("  ") << u.studEnd.year<<TEXT('\n');
	koll++;*/
	//len = sizeof(StudBeg);
	//p.write((TCHAR*)& u.studEnd, len);
	//p.close();
	/*p.clear();
	p.seekg(0, ios::end);
	out(p, u , len, 0);*/
}