import imaplib
import pandas as pd #для работы с датасетами
import numpy as np #для массивов
from torch import nn #модуль для посторения самой нейросети
import seaborn as sns #модуль для работы с базами данных и датасетами формата csv
import torch #работа с тензорами(большими массивами)
from torch.autograd import Variable
from torch.utils.data import DataLoader, Dataset, TensorDataset
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt #черчение графиков
from keras.preprocessing.text import Tokenizer #токенизация текста
import torch.nn.functional as F #модуль с функциями активации

mail = imaplib.IMAP4_SSL('imap.mail.ru')
mail.login('katerina.test11@mail.ru', '3Rk-kCX-5Hp-JvY')
#print(mail.list())
# Выводит список папок в почтовом ящике.
mail.select("inbox")  # Подключаемся к папке "входящие".
result, data = mail.search(None, "ALL") #результат (ок или не ок) количество писем
#print(result, data)
ids = data[0] # Получаем сроку номеров писем
id_list = ids.split() # Разделяем ID писем
#print(id_list)
latest_email_id = id_list[18] # Берем последний ID
print(latest_email_id)
result, data = mail.fetch(latest_email_id, "(RFC822)")  # Получаем тело письма (RFC822) для данного ID
raw_email = data[0][1]  # Тело письма в необработанном виде
# включает в себя заголовки и альтернативные полезные нагрузки
#print(raw_email)
import email
email_message = email.message_from_bytes(raw_email) #переведем все в переменную и конвертируем из байтов
print(email_message['To']) #кому адресовано письмо
print(email.utils.parseaddr(email_message['From']) ) # получаем имя отправителя
#print (email_message.items())  # Выводит все заголовки.



maintype = email_message.get_content_maintype()
if maintype == 'multipart':
    for part in email_message.get_payload():
        if part.get_content_maintype() == 'text':
                test_message=part.get_payload()
elif maintype == 'text':
        test_message=email_message.get_payload()
#raw_email_string = get_first_text_block(email_message).decode('utf-8')
print(type(test_message))

num_words = 1000 #предел нумерации слов
#print(features.shape)
#print(labels.shape)
t = Tokenizer(num_words=1000) #токенизация(разбиение тектса на слова, предложени и тд)
t.fit_on_texts(test_message)# мы сначала нумеруем слова, затем разбиваем их
features = t.texts_to_matrix(test_message, mode='tfidf') #собираем массив из текста
print(features.shape)
