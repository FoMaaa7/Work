
using System;
using System.IO;
using System.Net;
//using System.Windows.Forms;
using System.Net.NetworkInformation;
using System.Collections.Generic;
using Microsoft.Win32;
//using System.Management;
using System.Threading;
namespace ConsoleApp1
{
    class Program
    {
        string a, b, c, d, e;
        bool PingTest()
        {

            Ping ping = new Ping();

            PingReply pingStatus = ping.Send(IPAddress.Parse("8.8.8.8"));

            if (pingStatus.Status == IPStatus.Success)
                return true;
            else
                return false;
        }
        void Podkl()
        {
            if (PingTest())
            {
                a = "Подключение к интернету обнаружено!";
                Console.WriteLine("Подключение к интернету обнаружено!");
            }
            else
            { Console.WriteLine("Подключение к интернету не обнаружено!");
                a = "Подключение к интернету не обнаружено!";
            }
        }
        void CheckFirewall()
        {
            if (File.Exists("C:\\Program Files\\COMODO\\COMODO Internet Security\\cis.exe"))
            { Console.WriteLine("Фаервол обнаружен.");
                b = "Фаервол обнаружен.";
            }

            else
            { Console.WriteLine("Фаерволл обнаружен.");
                b = "Фаервол обнаружен.";
            }
        }
        void IsFirewallWork()
        {
            WebClient client = new WebClient();
            String Response;
            try
            {
                Response = client.DownloadString("https://195.201.201.32/");
            }
            catch
            {
                //Console.WriteLine("Фаерволл функцонирует корректно..");
                //c = "Фаерволл функцонирует корректно..";
            }
            Console.WriteLine("Фаерволл функцонирует некорректно..");
            c = "Фаерволл функцонирует некорректно..";
        }
        void AntivirusTest()
        {
            if (File.Exists("C:\\Program Files (x86)\\360\\Total Security\\QHSafeMain.exe"))
            {
                Console.WriteLine("Антивирус 360 Total Security установлен.");
                d = "Антивирус 360 Total Security установлен.";
            }
            else
            { Console.WriteLine("Антивирус 360 Total Security установлен.");
                d = "Антивирус 360 Total Security установлен.";
            }
        }
        void CheckAntivirus()
        {
            File.WriteAllText("C://lol//testVirus.img", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");
            File.WriteAllText("C://lol//testVirus.png", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");
            File.WriteAllText("C://lol//testVirus.txt", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H" + "+H*");
            if (File.Exists("C://lol//testVirus.img") && File.Exists("C://lol//testVirus.png") && File.Exists("C://lol//testVirus.txt"))
            {
                Thread.Sleep(15 * 1000);
                if (File.Exists("C://lol//testVirus.img") || File.Exists("C://lol//testVirus.png") || File.Exists("C://lol//testVirus.txt"))
                { Console.WriteLine("Антивирус не заблокировал проверочные файлы.");
                    e = "Антивирус не заблокировал проверочные файлы.";
                }

                else
                { Console.WriteLine("Антивирус не заблокировал проверочные файлы.");
                    e = "Антивирус не заблокировал проверочные файлы.";
                }
            }
        }
        void inFile()
        {
            string f = "Чванов Владислав БИБ1802";
            string txt = f+ System.Environment.NewLine + a+ System.Environment.NewLine+ b+ System.Environment.NewLine + c+ System.Environment.NewLine + d+ System.Environment.NewLine + e;
                string filename = "C://lol//otchet.txt";
                File.WriteAllText(filename, txt);
            
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            Console.WriteLine("БИБ1802");
            p.Podkl();
            p.CheckFirewall();
            p.IsFirewallWork();
            p.AntivirusTest();
            p.CheckAntivirus();
            p.inFile();
        }
       
    }
}
