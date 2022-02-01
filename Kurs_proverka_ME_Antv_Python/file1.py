import socket
import os.path
import requests
import time
import os
import winapps
import sys


def is_connected():
    try:
        info = socket.getaddrinfo("www.google.com", None)[0]
        ipAddr = info[4][0]
        if ipAddr != "192.168.56.1":
            print("Данный компьютер подключен к интернету")
            return True
    except:
        print("Данный компьютер не подключен к  интернету")
        pass
        return False

    '''
    try:
        socket.create_connection(("www.google.com", 80))
        print("Данный компьютер подключен к интернету")
        return True
    except OSError:
        print("Данный компьютер не подключен к  интернету")
        pass
    return False
    '''
def is_me():
    a=os.path.exists('C:/Program Files (x86)/CheckPoint/ZoneAlarm/zatray.exe')
    if (a==True):
        print("Фаервол ZoneAlarm установлен")
    else:
        print("Фаервол ZoneAlarm не установлен")

def is_me_work():

    try:
       r = requests.get('https://learn.python.ru')
       print("Межсетевой экран работает не правильно")
    except OSError:
        print("Межсетевой экран работает правильно")

def is_antv():
    a=''
    app=0
    try:
          [app]= winapps.search_installed('Avast Free Antivirus')
          print("Антивирус Avast Free Antivirus установлен в системе")
    except ValueError:
       print("Антивирус Avast Free Antivirus не установлен в системе")

def is_antv_work():
    file = open("virus.txt", "w")
    file.write("X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*")
    file.close()
    file = open("virus.doc", "w")
    file.write("X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*")
    file.close()
    file_not=open("not_virus.txt", 'w')
    file_not.write("X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H'+'H*")
    file_not.close()
    start = time.monotonic()
    time.sleep(30)
    end = time.monotonic()
    #print('start : {:>9.2f}'.format(start))
    #print('end   : {:>9.2f}'.format(end))
    #print('span  : {:>9.2f}'.format(end - start))
    r=0
    a = os.path.exists('C:/Users/Дмитрий/PycharmProjects/Kursovaya/virus.txt')
    b = os.path.exists('C:/Users/Дмитрий/PycharmProjects/Kursovaya/virus.doc')
    c = os.path.exists('C:/Users/Дмитрий/PycharmProjects/Kursovaya/not_virus.txt')
    #print(c)
    if (a == False and b==False and c==True):
        print("Антивирус Avast Free Antivirus работает")
    else:
        print("Антивирус Avast Free Antivirus не работает")

te = open('rezult.txt','w')

class Unbuffered:

   def __init__(self, stream):

       self.stream = stream

   def write(self, data):

       self.stream.write(data)
       self.stream.flush()
       te.write(data)

   def flush(self):
       pass


try:
    sys.stdout=Unbuffered(sys.stdout)
    print("Водиченков Антон БИБ1802")
    is_connected()
    is_me()
    is_me_work()
    is_antv()
    is_antv_work()
except AttributeError:
    print("ERR")
#sys.stdout.close()