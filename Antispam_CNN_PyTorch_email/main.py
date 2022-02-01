#LSTM применяется для задач угадывания и генерации, а для классификации применятся свртоные и линейные методы
#они несут в себе меньшую нагрузку на GPU и CPU
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
#from keras.preprocessing.text import Tokenizer #токенизация текста
import torch.nn.functional as F #модуль с функциями активации


#прочитаем датасет
data = pd.read_csv("./spam.csv", delimiter=',', header=None, names=['outcome','message','n','n1', 'n2'])
data = data.iloc[1:] #вырежем ненужную первю строку (шаблон) из датасета
#print(data.head())
data.outcome = data.outcome.map({'ham':0, 'spam':1}) #присвоим значение спаму 1, а не спаму 0
#print(data.head())
features = data.message.values #переменная в которой лежат сами сообщения
labels = data.outcome.values  #переменная с данными спам это или нет
num_words = 1000 #предел нумерации слов
#print(features)
#print(labels.shape)
import re
def tokenize(text):
    text = text.lower()
    text = re.sub(r'[^a-zA-Z ^0-9]', '', str(text))
    return text.split()
# Используем оригинал текста выше
tokens = tokenize(features )
tokens[:10]
#t = Tokenizer(num_words=1000) #токенизация(разбиение тектса на слова, предложени и тд)
#t.fit_on_texts(features)# мы сначала нумеруем слова, затем разбиваем их
#features = t.texts_to_matrix(features, mode='tfidf') #собираем массив из текста
#print(features.shape)
class Model(nn.Module):  #нейросеть
    def LSTM_(self, input, hidden ):
        return nn.Linear(input, hidden)
    def __init__(self, input, hidden, output): #конструктор нашей нейросети, где пропишем её слои
        super(Model, self).__init__()
        self.l1 = self.LSTM_(input, hidden) #линейные слои
        self.l2 = self.LSTM_(hidden, hidden)
        self.l3 = self.LSTM_(hidden, 2)

    def forward(self, x): #пропишем что будет делать каждая переменная в нейросети по слоям
        out = F.relu(self.l1(x)) #с учетом наложения функции активации РЕЛУ
        out = F.relu(self.l2(out))
        out = self.l3(out)
        return out #вернем выход в виде числа 0 или 1

input = 1000 #тк слов 1000 в каждом сообщении
hidden = 100 #параметры для нейросети
output = 2
model = Model(input, hidden, output) #создаем объект нейросети
#подготовим данные для тренировок и проверки правильности нейросети
#так же перемешаем эти данные
print(features.shape)
features_train, features_test, labels_train, labels_test = train_test_split(features, labels, shuffle=True, random_state=34)
print(features_train.shape)
optimizer = torch.optim.Adam(model.parameters(), lr=0.01) #создаем оптимизатор; "Adam" можем менять;
#lr-шаг градиентного спуска
criterion = nn.CrossEntropyLoss() #определим функцию потерь (будем использовать Кроссэнтропию)
def train(epochs): #начинаем тренировать нейросеть
    """создадим тензоры из массивов, чтоб работать с нейросетью"""
    x_train = Variable(torch.from_numpy(features_train)).float()
    y_train = Variable(torch.from_numpy(labels_train)).long()
    model.train() #сообщим нейросети, что сейчас будем её тренировать
    #начинаем тренировку и будем тренировать К-эпох (сколько раз тренировать)
    for epoch in range(epochs):
        optimizer.zero_grad() #обнулим оптимизатор
        y_pred = model(x_train) #проведем предсказание нейросети на основе данных
        loss = criterion(y_pred, y_train) #вычислим функцию потерь (отклонение предсказания от правильного)
        #print ("epoch #",epoch)
        #print ("loss: ", loss.item())
        """ормируем предсказание (0%-100%)"""
        pred = torch.max(y_pred, 1)[1].eq(y_train).sum()
        print ("acc:(%) ", 100*pred/len(x_train))
        loss.backward() #высчитаем производную эффективности
        optimizer.step() #делаем шаг градиентного спуска

def test(epochs): #прогоним сеть через тестовые данные
    model.eval()
    x_test = Variable(torch.from_numpy(features_test)).float()
    y_test = Variable(torch.from_numpy(labels_test)).long()
    for epoch in range(epochs):
        with torch.no_grad():
            y_pred = model(x_test)
            loss = criterion(y_pred, y_test)
            #print ("epoch #",epoch)
            #print ("loss: ", loss.item())
            pred = torch.max(y_pred, 1)[1].eq(y_test).sum()
            print ("acc (%): ", 100*pred/len(x_test))

train(20)
print("----------------------------------------------------------")
test(20)

pred = model(torch.from_numpy(features_test).float())
pred = torch.max(pred,1)[1]
pred = pred.data.numpy()
"""
print(accuracy_score(labels_test, pred))
p_train = model(torch.from_numpy(features_train).float())
p_train = torch.max(p_train,1)[1]
p_train = p_train.data.numpy()
print((labels_train, p_train))
"""
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(labels_test, pred) #построим матрицу ошибок
print (cm)

"""---------------------------------------------------------------------------"""
import imaplib

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
#test_message="SIX chances to win CASH! From 100 to 20,000 pounds txt>; CSH11 and send to 87575. Cost 150p/day, 6days, 16+ TsandCs apply Reply HL 4 info"
#test_message=test_message.values
num_words1 = 1000 #предел нумерации слов
#print(features.shape)
#print(labels.shape)
features1=np.array([test_message])
print(features1)
t1 = Tokenizer(num_words=1000) #токенизация(разбиение тектса на слова, предложени и тд)
t1.fit_on_texts(features1)# мы сначала нумеруем слова, затем разбиваем их
features1 = t1.texts_to_matrix(features1, mode='tfidf') #собираем массив из текста
print(features1.shape)
#прогоним сеть через тестовые данные
#model.eval()
x_test1 = Variable(torch.from_numpy(features1)).float()
print(x_test1.shape)
#y_test = Variable(torch.from_numpy(labels_test)).long()

y_pred = model(x_test1)
print(y_pred)
print(y_pred.shape)
if(y_pred[0][0]>y_pred[0][1]):
    print("Это спам")
"""
            loss = criterion(y_pred, y_test)
            #print ("epoch #",epoch)
            #print ("loss: ", loss.item())
            pred = torch.max(y_pred, 1)[1].eq(y_test).sum()
            print ("acc (%): ", 100*pred/len(x_test))
"""
