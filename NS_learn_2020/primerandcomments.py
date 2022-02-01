import matplotlib.pyplot as plt #создание графиков и чертежей
import matplotlib #создание графиков и чертежей
import torch #для нейросети
import numpy as np #библиотека для работ с массивами
matplotlib.rcParams['figure.figsize'] = (13.0, 5.0) #размерность окна для графиков и чертежей
"""готовим  тренировочные даные для нейросети, это может быть практически всё, что угодно"""
torch.manual_seed(0) #установить выборку рандома, чтоб вносить изменения и видеть разницу
x_train=torch.rand(100) #создание рандомного вектора чисел от 0 до 1 (равномерное распределение)
x_train=x_train*20.0-10.0 #домножаем каждую точку на 20 и вычитаем 10, чтоб выравнять график по центру
y_train=torch.sin(x_train) #создаём y_train с синусоидальной зависимостью от x_train
noise=torch.randn(y_train.shape)/5 #создание рандомного шума нормального распределения чисел от 0 до 1
y_train=y_train+noise #зашумление y_train
x_train.unsqueeze_(1) #работа будет со столбцами, поэтому превращаем вектор в столбцы
y_train.unsqueeze_(1) #работа будет со столбцами, поэтому превращаем вектор в столбцы
"""готовим  тестировочные даные для нейросети, это может быть практически всё, что угодно"""
"""это то, к чему надо стремиться"""
x_validation=torch.linspace(-10,10,100) #создадим 100 точек от -10 до 10 с pавномерным интервалом
y_validation=torch.sin(x_validation.data) #определим синус этих точек
x_validation.unsqueeze_(1) #работа будет со столбцами, поэтому превращаем вектор в столбцы
y_validation.unsqueeze_(1) #работа будет со столбцами, поэтому превращаем вектор в столбцы
"""создаем саму нейросеть"""
class SineNet(torch.nn.Module):
    def __init__(self,n_hidden_neurons): #конструктор нейросети
        super(SineNet,self).__init__()
        self.fc1=torch.nn.Linear(1,n_hidden_neurons)  #первый слой нейронов количество входов 1; выходов n_hidden_neurons
        self.act1=torch.nn.Sigmoid() #функция активации сигмоида, может быть любая другая
        self.fc2=torch.nn.Linear(n_hidden_neurons,n_hidden_neurons)#второй слой нейронов количество входов и выходов n_hidden_neurons
        self.act2 = torch.nn.Tanh() #тангенсная функция активации , может быть любая другая
        '''
        self.fc2=torch.nn.Linear(n_hidden_neurons,n_hidden_neurons)
        self.act2=torch.nn.Tanh()
        ....................... можем сделать слоёв столько, сколько нам надо
        '''
        self.fc3=torch.nn.Linear(n_hidden_neurons,1) #первый слой нейронов количество входов n_hidden_neurons; выходов 1
        #self.sm = torch.nn.Softmax(dim=1)  #для задачи классификации
    def forward(self,x): #перепишем конструктор в небольшую модель...
        x=self.fc1(x)
        x=self.act1(x)
        x = self.fc2(x)
        x = self.act2(x)
        '''
        x=self.fc2(x)
        x=self.act2(x)
        ....................... можем сделать слоёв столько, сколько нам надо
        '''
        x=self.fc3(x)
        return x
    def interference(self,x): #для задачи классификации, когда есть self.sm
        '''
        собирает функицю forward и софтмакс
        '''
        x=self.forward(x)
        x=self.sm(x)
        return x
sine_net=SineNet(40) #создаем объект класса с 40ю скрытыми нейронами
optimizer=torch.optim.Adam(sine_net.parameters(),lr=0.01) #создаем оптимизатор; "Adam" можем менять;
#lr-шаг градиентного спуска
'''создаем функцию потерь среднее квадратичное отклонение'''
"""нужна чтоб понять насколько эффективно работает наша нейросеть"""
def loss (pred,target):
    squares=(pred-target)**2 #средний квадрат ошибки
    return squares.mean() #mean- суммирует все элементы в тензоре и делит их на их кол-во
#loss=torch.nn.CrossEntropyLoss()  #это более удобная функция потерь кроссэнтропия
batch_size=10 #можно еще работать с батчами, чтоб не слишком много данных одновременно поступало в сеть (число- это кол-во элементов)
for epoch_index in range(2500): #каждую эпоху мы будем перемешивать датасет
    order = np.random.permutation(len(x_train)) #порядок индексов который нужно применить к датасету
    #переменная ордер отвечает за порядок переменных
    for start_index in range(0, len(x_train), batch_size): #будем вырезать участочки длиной batch_size
          optimizer.zero_grad() #обнуляем значение оптимазера, это важно!!!
          batch_indexes = order[start_index:start_index + batch_size] #из всего порядка order вычисляем подмножество
          x_batch = x_train[batch_indexes] #получаем данные
          y_batch = y_train[batch_indexes] #получаем и ответы
          y_pred=sine_net.forward(x_batch) #предсказываем y_pred с помощью нейросети на основе данных x_train
          loss_wall=loss(y_pred,y_batch) #определяем эффективность работы нейросети
          loss_wall.backward() #считаем производную от эффективности
          optimizer.step() #делаем шаг градиентного спуска
          """
          if epoch_index % 100 == 0: #делаем для задач классификации
              y_pred = wine_net(X_test) #вычисляем значения, чтоб посмотреть обучается нейросеть или нет (каждые 100 эпох)
              y_pred = y_pred.argmax(dim=1) #записываем максимальное значение из полученных (какой выход наибольший)
              print((y_pred == y_validation).float().mean()) #сравниваем с тем номером класса, который находится в y_validation
              #а так же в предыдущей строчке определяем долю совпадения (в рез-те сравнения Tensor типа int)
              # сделовательно используем float и считаем среднее значение
          """
y_pred=sine_net.forward(x_validation) #предсказываем У на основе данных Х

plt.plot(x_validation.numpy(), y_validation.numpy(), 'o', label='Groud truth') #чертим идеальную синусоиду
#первые два параметра в скобках- это координаты точек, цвет линии соединяющие их, название для линии
plt.plot(x_validation.numpy(), y_pred.data.numpy(), 'o', c='r', label='Prediction')#чертим синусоиду полученную нейросетью
"""дополнительные настройки графика"""
plt.legend(loc='upper left')
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.show() #показать график