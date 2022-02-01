import torch
import random
import numpy as np

random.seed(0)
np.random.seed(0)
torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.backends.cudnn.deterministic = True
"""готовим иходные данные"""
from keras.datasets import mnist  # из базы данных keras импортируем изображения чисел (mnist)

(X_train, y_train), (X_test, y_test) = mnist.load_data()  # записываем данные в переменные
X_train = torch.from_numpy(X_train)  # преобразуем данные из numpy.array в torch.tensor
y_train = torch.from_numpy(y_train)  # преобразуем данные из numpy.array в torch.tensor
X_test = torch.from_numpy(X_test)  # преобразуем данные из numpy.array в torch.tensor
y_test = torch.from_numpy(y_test)  # преобразуем данные из numpy.array в torch.tensor
y_train = y_train.int()  # преобразуем к целочисленному значению
X_train = X_train.float()  # преобразуем к значению с плавающей точкой
X_test = X_test.float()  # преобразуем к значению с плавающей точкой
print(X_train.shape)
print(X_test.shape)
print(y_train)
print(y_test)
"""выведем на экран и сверим цифру"""
import matplotlib.pyplot as plt  # создание графиков и чертежей

plt.imshow(X_test[0, :, :])  # выведем нулевую картинку из тензора
plt.show()  # показать картинку

print(y_test[0])  # выведем цифру, которая соответствует этой картинке
"""сделаем размерность трехмерной 6000,1,28,28 (6000 изображений 1х28х28)"""
X_train = X_train.unsqueeze(1).float()  # добавим в тензор размерность между 0 и 2 местом (1)
X_test = X_test.unsqueeze(1).float()  # добавим в тензор размерность между 0 и 2 местом (1)
# torch.permute(0,3,2,1) меняет тензор [0,1,2,3] на тензор [0,3,2,1]
print(X_train)
"""создаем класс нейронной сети
похожа на обычную сверточную сеть, только можно взять разные параметры"""


class LeNet5(torch.nn.Module):
    def __init__(self, activation='tanh', pooling='avg', conv_size=5,
                 use_batch_norm=False):  # задали параметры по умолчанию
        super(LeNet5, self).__init__()
        self.conv_size = conv_size  # зададим размер ядра
        self.use_batch_norm = use_batch_norm  # использовать нормирование или нет
        if activation == 'tanh':  # если функцией активации выбран tanh
            activation_function = torch.nn.Tanh()  # функция активации tanh
        elif activation == 'relu':  # если функцией активации выбран relu
            activation_function = torch.nn.ReLU()  # функция активации relu
        else:  # иначе обработаем ошибку
            raise NotImplementedError  # обработка ошибки
        if pooling == 'avg':  # выбираем вид пуллинга(сокрашения размера изображения) по среднему(avg)
            pooling_layer = torch.nn.AvgPool2d(kernel_size=2, stride=2)  # пуллинг по среднему
        elif pooling == 'max':  # выбираем вид пуллинга(сокрашения размера изображения) по максимальному(max)
            pooling_layer = torch.nn.MaxPool2d(kernel_size=2, stride=2)  # пуллинг по максимальному
        else:  # иначе обработаем ошибку
            raise NotImplementedError  # обработка ошибки
        if conv_size == 5:  # если размер ядра свертки 5
            # ходим свёрткой размером 5х5; с размером паддинга 2 (добавляем по 2 нуля со всех четырех сторон изображения)
            # пример работы паддинга с размером 1 для тензора [1,2][3,4] будет тензор [0,0,0,0][0,1,2,0][0,3,4,0][0,0,0,0]
            # входных каналов 1, тк входит 1 зображение; выходных каналов 6
            self.conv1 = torch.nn.Conv2d(in_channels=1, out_channels=6, kernel_size=5, padding=2)
            # изображение не изменится в размерах
        elif conv_size == 3:  # если размер ядра свертки 3
            # ходим 2 раза свёрткой размером 3*3; с размером паддинга1 (добавляем по 1 нулю со всех четырех сторон изображения)
            # пример работы паддинга с размером 1 для тензора [1,2][3,4] будет тензор [0,0,0,0][0,1,2,0][0,3,4,0][0,0,0,0]
            # входных каналов 1, тк входит 1 зображение; выходных каналов 6
            self.conv1_1 = torch.nn.Conv2d(in_channels=1, out_channels=6, kernel_size=3, padding=1)
            self.conv1_2 = torch.nn.Conv2d(in_channels=6, out_channels=6, kernel_size=3, padding=1)
            # изображение не изменится в размерах
        else:  # иначе обработаем ошибку
            raise NotImplementedError  # обработка ошибки
        self.act1 = activation_function  # применение функции активации
        self.bn1 = torch.nn.BatchNorm2d(num_features=6)  # применяем нормализацию (от переобучения сети); 6 входов
        self.pool1 = pooling_layer  # производим пуллинг, определенный ранее
        if conv_size == 5:  # если размер ядра свертки 5
            # ходим свёрткой размером 5х5; с размером паддинга 2 (добавляем по 2 нуля со всех четырех сторон изображения)
            # пример работы паддинга с размером 1 для тензора [1,2][3,4] будет тензор [0,0,0,0][0,1,2,0][0,3,4,0][0,0,0,0]
            # входных каналов 6; выходных каналов 16
            self.conv2 = self.conv2 = torch.nn.Conv2d(in_channels=6, out_channels=16, kernel_size=5, padding=0)
        elif conv_size == 3:  # если размер ядра свертки 3
            # ходим 2 раза свёрткой размером 3*3; с размером паддинга1 (добавляем по 1 нулю со всех четырех сторон изображения)
            # пример работы паддинга с размером 1 для тензора [1,2][3,4] будет тензор [0,0,0,0][0,1,2,0][0,3,4,0][0,0,0,0]
            # входных каналов 6; выходных каналов 16
            self.conv2_1 = torch.nn.Conv2d(in_channels=6, out_channels=16, kernel_size=3, padding=0)
            self.conv2_2 = torch.nn.Conv2d(in_channels=16, out_channels=16, kernel_size=3, padding=0)
        else:  # иначе обработаем ошибку
            raise NotImplementedError  # обработка ошибки
        self.act2 = activation_function  # применение функции активации
        self.bn2 = torch.nn.BatchNorm2d(num_features=16)  # применяем нормализацию (от переобучения сети); 6 входов
        self.pool2 = pooling_layer  # производим пуллинг, определенный ранее
        self.fc1 = torch.nn.Linear(5 * 5 * 16, 120)  # прогоняем всё через сеть линейных нейронов
        # выходы--кол-во выходов в предыдущей операции
        self.act3 = activation_function  # применение функции активации
        self.fc2 = torch.nn.Linear(120, 84)  # прогоняем всё через сеть линейных нейронов
        self.act4 = activation_function  # применение функции активации
        self.fc3 = torch.nn.Linear(84,
                                   10)  # прогоняем всё через сеть линейных нейронов; выходов 10, тк всего 10 классов чисел

    def forward(self, x):  # перепишем конструктор в небольшую модель...
        if self.conv_size == 5:
            x = self.conv1(x)
        elif self.conv_size == 3:
            x = self.conv1_2(self.conv1_1(x))
        x = self.act1(x)
        if self.use_batch_norm:
            x = self.bn1(x)
        x = self.pool1(x)
        if self.conv_size == 5:
            x = self.conv2(x)
        elif self.conv_size == 3:
            x = self.conv2_2(self.conv2_1(x))
        x = self.act2(x)
        if self.use_batch_norm:
            x = self.bn2(x)
        x = self.pool2(x)
        x = x.view(x.size(0), x.size(1) * x.size(2) * x.size(3))
        x = self.fc1(x)
        x = self.act3(x)
        x = self.fc2(x)
        x = self.act4(x)
        x = self.fc3(x)
        #print(x.shape)
        return x


def train(net, X_train, y_train, X_test, y_test):
    """определяем девайс видеокарта или процессор """
    device = torch.device(
        'cuda:0' if torch.cuda.is_available() else 'cpu')  # если есть видеокарта, то будем ее применять
    # если есть видеокарта, device=видеокарта, иначе device=процесор
    net = net.to(device)  # создаем объект нейросети и перекладываем его на девайс
    loss = torch.nn.CrossEntropyLoss()  # определяем функицию потерь
    optimizer = torch.optim.Adam(net.parameters(), lr=1.0e-3)  # создаем оптимизатор; "Adam" можем менять;
    batch_size = 100  # можно еще работать с батчами, чтоб не слишком много данных одновременно поступало в сеть (число-это кол-во элементов)
    test_accuracy_history = []  # сюда будем сохранять результаты работы нейросети
    test_loss_history = []  # сюда сохраняем результаты функции потерь
    X_test = X_test.to(device)  # перекладываем данные на девайс
    y_test = y_test.to(device)  # перекладываем данные на девайс
    for epoch in range(30):  # каждую эпоху мы будем перемешивать датасет
        order = np.random.permutation(len(X_train))  # порядок индексов который нужно применить к датасету
        for start_index in range(0, len(X_train), batch_size):  # будем вырезать участочки длиной batch_size
            optimizer.zero_grad()  # обнуляем значение оптимазера, это важно!!!
            net.train()  # флажок тренировки,чтоб нормализатор мог изменять параметры
            batch_indexes = order[start_index:start_index + batch_size]  # из всего порядка order вычисляем подмножество
            X_batch = X_train[batch_indexes].to(device)  # получаем данные
            y_batch = y_train[batch_indexes].to(device)  # получаем и ответы
            y_batch = y_batch.type(torch.LongTensor)

            #print(X_batch)# из-за разницы типов преобразум в ЛонгТензор
            preds = net.forward(X_batch)
            #print(preds)# предсказываем y_pred с помощью нейросети на основе данных x_train
            loss_value = loss(preds, y_batch)  # определяем эффективность работы нейросети
            loss_value.backward()  # считаем производную от эффективности
            optimizer.step()  # делаем шаг градиентного спуска
        net.eval()  # флажок тестирования чтоб батч-норм не изменял параметры
        test_preds = net.forward(X_test)  # предсказываем test_preds на основе данных X_test
        print(test_preds.shape)
        print(y_test.shape)
        test_loss_history.append(loss(test_preds, y_test).data.cpu())  # сохраняем историю функций потерь
        accuracy = (test_preds.argmax(
            dim=1) == y_test).float().mean().data.cpu()  # сравниваем с тем номером класса, который находится в y_test
        # а так же в предыдущей строчке определяем долю совпадения
        test_accuracy_history.append(accuracy)  # сохраняем историю доли совпадения
        print(accuracy)  # выводим на экран долю совпадений
    print('---------------')
    return test_accuracy_history, test_loss_history  # возвращем массивы историй функции потерь и доль совпадения


accuracies = {}  # словари для данных доль совпадения
losses = {}  # словари для данных функций потерь
y_test = y_test.type(torch.LongTensor)  # из-за разницы типов преобразум в ЛонгТензор
"""ЗАПУСКАЕМ ТЕРНИРОВКИ НЕЙРОСЕТИ С РАЗНЫМИ ПАРАМЕТРАМИ"""
accuracies['tanh'], losses['tanh'] = train(LeNet5(activation='tanh', conv_size=5), X_train, y_train, X_test, y_test)
accuracies['relu'], losses['relu'] = train(LeNet5(activation='relu', conv_size=5), X_train, y_train, X_test, y_test)
accuracies['relu_3'], losses['relu_3'] = train(LeNet5(activation='relu', conv_size=3), X_train, y_train, X_test, y_test)
accuracies['relu_3_max_pool'], losses['relu_3_max_pool'] = train(LeNet5(activation='relu', conv_size=3, pooling='max'),
                                                                 X_train, y_train, X_test, y_test)
accuracies['relu_3_max_pool_bn'], losses['relu_3_max_pool_bn'] = train(
    LeNet5(activation='relu', conv_size=3, pooling='max', use_batch_norm=True), X_train, y_train, X_test, y_test)
