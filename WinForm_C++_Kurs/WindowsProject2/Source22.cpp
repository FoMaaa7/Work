#include "stdafx.h"
#include "rehcjdfz.h"
#include "resource.h"
extern StudEnd Object;

void get_Object(HWND hDlg, StudEnd& Object) {
	TCHAR buf[500] = TEXT("");
	BOOL 	lpFam = TRUE, lpImia = TRUE, lpOtch = TRUE, lpAdress = TRUE, lpWork = TRUE, lpPriviv = TRUE, lpDay=TRUE, lpMesyaz=TRUE, lpYear=TRUE;
	GetDlgItemText(hDlg, IDC_GET_FAM, Object.fam, 20);
	if (*Object.fam == 0)
	{
		wcscpy(buf, TEXT("  ������ ����� �������!"));
		lpFam = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_IMIA, Object.imia, 12);
	if (*Object.imia == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� �����!"));
		lpImia = FALSE;
	}
	///
	GetDlgItemText(hDlg, IDC_GET_OTCHESTVO, Object.otch, 12);
	if (*Object.otch == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ��������!"));
		lpOtch = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_ADRESS, Object.aress, 12);
	if (*Object.aress == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ������!"));
		lpAdress = FALSE;
	}
	GetDlgItemText(hDlg, IDC_GET_RABOTA, Object.work, 12);
	if (*Object.work == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ������!"));
		lpWork = FALSE;
	}
	Object.priviv= GetDlgItemInt(hDlg, IDC_GET_PRIVIV, &lpPriviv, FALSE);
	/*if (*Object.priviv == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ��������!"));
		lpPriviv = FALSE;
	}*/
   Object.day = GetDlgItemInt(hDlg, IDC_GET_DAY, &lpDay, FALSE);
	/*GetDlgItemText(hDlg, IDC_GET_DAY, Object.day, 2);
	if (Object.day == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ����!"));
		lpDay = FALSE;
	}*/

   Object.mesyaz = GetDlgItemInt(hDlg, IDC_GET_MESYAZ, &lpMesyaz, FALSE);
	/*GetDlgItemText(hDlg, IDC_GET_MESYAZ, Object.mesyaz, 2);
	if (Object.mesyaz == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ����!"));
		lpMesyaz = FALSE;
	}*/
	Object.year = GetDlgItemInt(hDlg, IDC_GET_YEAR, &lpYear, FALSE);
	/*GetDlgItemText(hDlg, IDC_GET_YEAR, Object.year, 4);
	if (Object.year == 0)
	{
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ����!"));
		lpYear = FALSE;
	}*/
	/*if ((lpDay == FALSE)
		|| (lpYear == FALSE)
		|| (lpMesyaz == FALSE))
		wcscpy(buf + wcslen(buf), TEXT("  ������ ����� ���� �������������!"));*/
	/*if (lpGod == FALSE ||
		studBeg.godRojd 	<	1970 ||
		lpFam == FALSE ||
		lpImia == FALSE)*/

		//MessageBox(hDlg, buf, TEXT("��������� �� ������ �����"), MB_OK);
		//// ��������� �������� ������ �� ��������� ����������         
	if ((lpFam == FALSE)
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
		MessageBox(hDlg, buf, TEXT("��������� �� ������ �����"), MB_OK);
		*Object.fam = 0;
		*Object.imia = 0;
		*Object.otch = 0;
		*Object.aress = 0;
		Object.year = 0;
		Object.priviv = 0;
		Object.day = 0;
		Object.mesyaz = 0;
		*Object.work = 0;
		Object.del = 0;
	}
	/*else {
		Object.sr_zat = (Object.zatrati) / (Object.year2 - Object.year1);
		Object.del = TEXT('*');
	}*/
}
