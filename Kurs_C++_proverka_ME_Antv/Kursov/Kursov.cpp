#include <iostream>
#include "locale.h"
#include <sstream>
#include <fstream>

#include <Windows.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Wininet.h>
#include <string>
#pragma comment(lib, "wininet.lib")

using namespace std;
ofstream Otchet("otch.txt");
///////////////////////////
string replaceAll(string subject, const string& search,
    const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

string DownloadString(string URL) {
    HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
    HINTERNET urlFile;
    string rtn;
    if (interwebs) {
        urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
        if (urlFile) {
            char buffer[2000];
            DWORD bytesRead;
            do {
                InternetReadFile(urlFile, buffer, 2000, &bytesRead);
                rtn.append(buffer, bytesRead);
                memset(buffer, 0, 2000);
            } while (bytesRead);
            InternetCloseHandle(interwebs);
            InternetCloseHandle(urlFile);
            string p = replaceAll(rtn, "|n", "\r\n");
            return p;
        }
    }
    InternetCloseHandle(interwebs);
    string p = replaceAll(rtn, "|n", "\r\n");
    return p;
}
///////////////////////////
void is_connect() {
    int a = system("ping www.google.com");
    system("cls");
    cout << "БИБ-1802" << endl;
    Otchet << "БИБ-1802" << endl;
    if (a == 0) {
        cout << "Данный компьютер подключен к интернету" << endl;
        Otchet << "Данный компьютер подключен к интернету" << endl;
    }
    else {
        cout << "Данный компьютер не подключен к интернету" << endl;
        Otchet << "Данный компьютер не подключен к интернету" << endl;
    }
}

void is_ME() {
    
    ifstream file(L"C:\\Program Files (x86)\\CheckPoint\\ZoneAlarm\\zatray.exe");
    if (file.is_open()) {
        cout << "Фаервол TinyWall установлен!" << endl;
        Otchet << "Фаервол TinyWall установлен!" << endl;
    }
    else {
        cout << "Фаервол ZoneAlarm не установлен!" << endl;
        Otchet << "Фаервол ZoneAlarm установлен!" << endl;
    }
    file.close();
}

void is_antivirus() {
    ifstream file(L"C:\\Program Files\\Avast SoftWare\\Avast\\AvastUI.exe");
    if (file.is_open()) {
        cout << "Антивирус AVG установлен!" << endl;
        Otchet<< "Антивирус AVG установлен!" << endl;
    }
    else {
        cout << "Антивирус Avast Free Antivirus не установлен!" << endl;
        Otchet << "Антивирус Avast Free Antivirus не установлен!" << endl;
    }
    file.close();
    
}

void is_ME_work() {
    
    string lol = DownloadString("https://pastebin.com/raw/0JswrdPd");
    
    if (lol !="lol hi") {
        cout << "Межсетевой экран функционирует правильно!" << endl;
        Otchet << "Межсетевой экран функционирует правильно!" << endl;
    }
    else {
        cout << "Межсетевой экран функционирует не правильно!" << endl;
        Otchet << "Межсетевой экран функционирует не правильно!" << endl;

    }
}
void is_antivirus_work() {
    ofstream file("virus.docx");
    file << "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*" << endl;
    file.close();
    ofstream file1("virus.txt");
    file1 << "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*" << endl;
    file1.close();
    ofstream file2("not_virus.doc");
    file2 << "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H'+'+H*" << endl;
    file2.close();
    Sleep(15000);
    ifstream fileP1("virus.docx");
    ifstream fileP2("virus.txt");
    ifstream fileP3("not_virus.doc");
    if (fileP3.is_open()) {
        if (fileP2.is_open()) {
            cout << "Антивирус AVG  не работает" << endl;
            Otchet << "Антивирус AVG  не работает" << endl;
       }
        else {
            if (fileP1.is_open()) {
                cout << "Антивирус AVG  не работает" << endl;
                Otchet << "Антивирус AVG  не работает" << endl;
            }
            else {
                cout << "Антивирус AVG работает" << endl;
                Otchet << "Антивирус AVG работает" << endl;
            }
        }
    }
    else {
        cout << "Антивирус AVG  не работает" << endl;
        Otchet << "Антивирус AVG  не работает" << endl;
    }

    fileP1.close();
    fileP2.close();
    fileP3.close();

}
int main()
{
    

    setlocale(LC_ALL, "Russian");
    //freopen("otchet.txt", "A", stdout);
    
    is_connect();
    is_ME();
    is_antivirus();
    is_ME_work();
    is_antivirus_work();
    Otchet.close();
    return 0;
}