#include "stdafx.h"
#include "rehcjdfz.h"
#include "resource.h"

//#include "Header.h"
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
StudEnd Object;
wfstream file;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK ViewDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK GetDataDlgProc(HWND, UINT,
	WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}


//ATOM MyRegisterClass
//ATOM MyRegisterClass
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}
//BOOL InitInstance
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//INT_PTR CALLBACK GetDataDlgProc
INT_PTR CALLBACK GetDataDlgProc(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		SetFocus(hDlg);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			get_Object(hDlg, Object); //получаем структуру
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDCANCEL:
			Object.fam[0] = 0; //контроль невведёных данных
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//INT_PTR CALLBACK ViewDlgProc
INT_PTR CALLBACK ViewDlgProc(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	///////////////////////
	static HWND hListBox2;
	hListBox2 = GetDlgItem(hDlg, IDC_LIST3);
	UNREFERENCED_PARAMETER(lParam);
	static HWND hListBox;
	static LOGFONT lf;
	HFONT	hFont1;
	int curItem = 0;
	wfstream file(FILE, ios::in | ios::out | ios::ate);
	if (!file)
	{
		file.close();
		file.open(FILE, ios::out);
		file.close();
		file.open(FILE, ios::in | ios::out | ios::ate);
	}
	file.imbue(locale(".1251"));
	switch (message)
	{
	case WM_INITDIALOG:
		hListBox = GetDlgItem(hDlg, IDC_LIST1);
		lf.lfHeight = 16;
		lstrcpy((LPWSTR)& lf.lfFaceName, TEXT("Courier"));
		hFont1 = CreateFontIndirect(&lf);
		SendMessage(hListBox, WM_SETFONT, (WPARAM)hFont1, TRUE);
		SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
		output_all(hListBox, file); //выводим в листбокс содержимое файла
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
			file.close();
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDCANCEL:
			file.close();
			EndDialog(hDlg, FALSE);
			return (INT_PTR)TRUE;
		case IDC_REC_ADD:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_GET), hDlg, GetDataDlgProc); //вызываем диалог добавления структуры
			if (Object.fam[0] != 0) {
				//запись структуры при успешном вводе данных
				write(file, Object);
				SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
				output_all(hListBox, file);
			}
			else
			{
				MessageBox(hDlg, TEXT("Ошибка ввода данных!"), TEXT("Ошибка!"), MB_OK);
			}
			break;
		case IDC_POM:
			curItem = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			if (curItem != LB_ERR) {

				mark(file, curItem+1); //отметка выбранной записи
				SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
				output_all(hListBox, file);
			}

			else
				MessageBox(hDlg, TEXT("Сначала нужно выделить элемент!"), TEXT("Ошибка!"), MB_OK);
			break;
		case IDC_DEL:
			curItem = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			if (curItem != LB_ERR) { //редактирование выбранного элемента листбокса
				read(file, Object, curItem + 1);
				DialogBox(hInst, MAKEINTRESOURCE(IDD_GET), hDlg, GetDataDlgProc);
				if (Object.fam[0] != 0) {
					write(file, Object, curItem + 1);
					SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
					output_all(hListBox, file);
				}
				else
				{
					MessageBox(hDlg, TEXT("Ошибка ввода данных!"), TEXT("Ошибка!"), MB_OK);
				}
			}
			else
				MessageBox(hDlg, TEXT("Сначала нужно выделить элемент!"), TEXT("Ошибка!"), MB_OK);
			break;
		//case IDC_ZADACHA1:
			///////
			//HWND hWnd;
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About);
			//task(file, hListBox2);
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ViewDlgProc);
			//ViewTaskDlgProc( hDlg,  message,
			//	 wParam,  lParam);
		//	break;
		case IDC_REC_DELETE: //удаление выбранного элемента листбокса по нажатию кнопки Удалить
			curItem = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			if (curItem != LB_ERR) {
				mark(file, curItem );
				udal_mark(file);
				SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
				output_all(hListBox, file);
			}
			else
				MessageBox(hDlg, TEXT("Сначала нужно выделить элемент!"), TEXT("Ошибка!"), MB_OK);
			break;
		case IDC_DELLETE: //удаление всех помеченных элементов листбокса
			udal_mark(file);
			SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
			output_all(hListBox, file);
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//INT_PTR CALLBACK ViewTaskDlgProc
INT_PTR CALLBACK ViewTaskDlgProc(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	static HWND hListBox2;
	int curItem = 0;
	static LOGFONT lf;
	HFONT	hFont1;
	wfstream file(FILE, ios::in | ios::out | ios::ate);
	if (!file)
	{
		file.close();
		file.open(FILE, ios::out);
		file.close();
		file.open(FILE, ios::in | ios::out | ios::ate);
	}
	file.imbue(locale(".1251"));
	switch (message)
	{
	case WM_INITDIALOG:
		hListBox2 = GetDlgItem(hDlg, IDC_LIST3);
		lf.lfHeight = 16;
		lstrcpy((LPWSTR)& lf.lfFaceName, TEXT("Courier"));
		hFont1 = CreateFontIndirect(&lf);
		SendMessage(hListBox2, WM_SETFONT, (WPARAM)hFont1, TRUE);
		SendMessage(hListBox2, LB_RESETCONTENT, 0, 0);
		task(file, hListBox2); //вывод в листбокса отсортированного списка объектов
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			SendMessage(hListBox2, LB_RESETCONTENT, 0, 0);
			file.close();
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDCANCEL:
			file.close();
			EndDialog(hDlg, FALSE);
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK ViewTaskDlgProc3(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	static HWND hListBox3;
	int curItem = 0;
	static LOGFONT lf;
	HFONT	hFont1;
	wfstream file(FILE, ios::in | ios::out | ios::ate);
	if (!file)
	{
		file.close();
		file.open(FILE, ios::out);
		file.close();
		file.open(FILE, ios::in | ios::out | ios::ate);
	}
	file.imbue(locale(".1251"));
	switch (message)
	{
	case WM_INITDIALOG:
		hListBox3 = GetDlgItem(hDlg, IDC_LIST6);
		lf.lfHeight = 16;
		lstrcpy((LPWSTR)& lf.lfFaceName, TEXT("Courier"));
		hFont1 = CreateFontIndirect(&lf);
		SendMessage(hListBox3, WM_SETFONT, (WPARAM)hFont1, TRUE);
		SendMessage(hListBox3, LB_RESETCONTENT, 0, 0);
		task2(file, hListBox3); //вывод в листбокса отсортированного списка объектов
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			SendMessage(hListBox3, LB_RESETCONTENT, 0, 0);
			file.close();
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDCANCEL:
			file.close();
			EndDialog(hDlg, FALSE);
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
//LRESULT CALLBACK WndProc
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static ShapeSize shapeSize = MIN;
	static HMENU hMenu = GetMenu(hWnd);
	static int palitra = 0;
	switch (message)
	{
	case WM_COMMAND:
	{
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		//case ID_REKLAMA: //смена логотипа и рекламы
		//	shapeSize = MIN;
		//	CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_REKLAMA, ID_LOGO, LOWORD(wParam), MF_BYCOMMAND);
		//	EnableMenuItem(hMenu, ID_REKLAMA, MF_BYCOMMAND | MFS_GRAYED);
		//	EnableMenuItem(hMenu, ID_LOGO, MF_BYCOMMAND | MFS_ENABLED);
		//	DrawMenuBar(hWnd);
		//	break;
		//case ID_LOGO:
		//	shapeSize = MAX;
		//	CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_REKLAMA, ID_LOGO, LOWORD(wParam), MF_BYCOMMAND);
		//	EnableMenuItem(hMenu, ID_LOGO, MF_BYCOMMAND | MFS_GRAYED);
		//	EnableMenuItem(hMenu, ID_REKLAMA, MF_BYCOMMAND | MFS_ENABLED);
		//	DrawMenuBar(hWnd);
		//	break;
		//case ID_COLOR1: //смена цвета
		//	palitra = 0;
		//	CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_COLOR1, ID_COLOR3, LOWORD(wParam), MF_BYCOMMAND);
		//	DrawMenuBar(hWnd);
		//	break;
		//case ID_COLOR2:
		//	palitra = 1;
		//	CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_COLOR1, ID_COLOR3, LOWORD(wParam), MF_BYCOMMAND);
		//	DrawMenuBar(hWnd);
		//	break;
		//case ID_COLOR3:
		//	palitra = 2;
		//	CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_COLOR1, ID_COLOR3, LOWORD(wParam), MF_BYCOMMAND);
		//	DrawMenuBar(hWnd);
		//	break;
		case IDM_VIEW: //вызов диалогового окна со списком объектов
			DialogBox(hInst, MAKEINTRESOURCE(IDD_VIEW), hWnd, ViewDlgProc);
			break;
		case IDM_ZAD1:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ViewTaskDlgProc);
		//case IDM_SPRAVKA: //вызов диалогового окна со справкой по объектам
		//	DialogBox(hInst, MAKEINTRESOURCE(IDD_SPRAVKA), hWnd, ViewTaskDlgProc);
		break;
		case IDM_ZAD2:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, ViewTaskDlgProc3);
			//case IDM_SPRAVKA: //вызов диалогового окна со справкой по объектам
			//	DialogBox(hInst, MAKEINTRESOURCE(IDD_SPRAVKA), hWnd, ViewTaskDlgProc);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
	case WM_CREATE:
	/*	CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_REKLAMA, ID_LOGO, ID_REKLAMA, MF_BYCOMMAND);
		CheckMenuRadioItem(GetSubMenu(hMenu, 2), ID_COLOR1, ID_COLOR3, ID_COLOR1, MF_BYCOMMAND);*/
		break;
	case WM_PAINT:
	//{hdc = BeginPaint(hWnd, &ps);
	//RECT rect;
	//POINT beg = { 0,0 }; //задаём начальную точку и rect в зависимости от выбранного режима рисовки
	//if (shapeSize == MIN) {
	//	rect.left = 0;
	//	rect.right = 400;
	//	rect.top = 400;
	//	rect.bottom = 800;
	//	POINT beg = { 0, 400 };
	//	inputText(hWnd, hdc, palitra);
	//}
	//else
	//	GetClientRect(hWnd, &rect);
	//draw(hdc, rect, beg, shapeSize, palitra);
	//EndPaint(hWnd, &ps);
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Добавьте сюда любой код прорисовки, использующий HDC...
		EndPaint(hWnd, &ps);
	}
	break; //}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
//INT_PTR CALLBACK About
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
