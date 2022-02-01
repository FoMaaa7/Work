import matplotlib.pyplot as plt
import numpy as np
def target(x):
    return np.exp(-(x - 2)**2) + np.exp(-(x - 6)**2/10) + 1/ (x**2 + 1)
# Независимая (x) и зависимая (y) переменные
x = np.linspace(0, 10, 50)
y = x
# Построение графика
plt.title("Уровни шума",fontsize=24) #заголовок
plt.xlabel("x") # ось абсцисс
plt.ylabel("y") # ось ординат
plt.grid()      # включение отображение сетки
plt.plot(x, y)  # построение графика
#plt.show()
x=[0, 150, 300, 450, 600, 750, 900, 1050, 1200, 1350, 1500, 1650, 1800, 1950, 2100, 2250, 2400, 2550, 2700, 2850, 3000, 3150, 3300, 3450, 3600, 3750, 3900, 4050, 4200, 4350, 4500, 4650, 4800, 4950, 5100, 5250, 5400, 5550, 5700, 5850, 6000, 6150, 6300, 6450, 6600, 6750, 6900, 7050, 7200, 7350, 7500, 7650, 7800, 7950, 8100, 8250, 8400, 8550]
y= [1, 1.7, 3, 4.5, 6, 7.5, 8.7, 10, 11, 13, 16, 18.5, 21, 25, 29, 32.5, 35, 36, 36.5, 37, 37, 36.5, 36, 35, 31, 25, 20, 16, 13.3, 12, 10.5, 9, 8, 7.4, 7.1, 7, 6.8, 6.4, 6, 5.8, 5.6, 5.5, 5.3, 5, 4.7, 3.6, 3.2, 3, 2.8, 2.5, 2.1, 1.8, 1.5, 1.1, 0.9, 0.7, 0.5, 0.3]

print(y)
plt.plot(x, y)
#plt.show()
#k=t0/t0+tb
plt.plot(x,y, color='k')
z = np.polyfit(x, y, 2)
p = np.poly1d(z)
plt.plot([100,100],[0,40], color='b')
plt.plot([100,0],[1.25,1.25],color='r')
plt.plot([200,200],[0,40], color='b')
plt.plot([200,100],[1.75,1.75],color='r')
plt.plot([400,400],[0,40], color='b')
plt.plot([800,400],[6.8,6.8],color='r')
plt.plot([800,800],[0,40], color='b')
plt.plot([1600,800],[12.2,12.2],color='r')
plt.plot([1600,1600],[0,40], color='b')
plt.plot([3200,1600],[28.3,28.3],color='r')
plt.plot([3200,3200],[0,40], color='b')
plt.plot([6400,3200],[26.3,26.3],color='r')
plt.plot([6400,6400],[0,40], color='b')
#plt.plot([8000,8000],[0,35], color='b')
plt.grid(which='major',
        color = 'k')
plt.minorticks_on()
#  Теперь можем отдельно задавать внешний вид
#  вспомогательной сетки:
plt.grid(which='minor',
        color = 'gray',
        linestyle = ':')
plt.ylabel("S(h),Дб", fontsize=24)
plt.xlabel("v,Гц",fontsize=24)


plt.show()
plt.title("Белый шум", fontsize=24)
standardDev = 3.65
noise = np.random.normal(0, standardDev, 58)
plt.ylabel("u(t)", fontsize=24)
plt.xlabel("t",fontsize=24)
y=y+noise
plt.plot(x, y)
plt.show()
plt.title("Спектральная плотность мощности", fontsize=24)
data = np.random.rand(5000)-0.5
ps = np.abs(np.fft.fft(data))**2

time_step = 1 / 30
freqs = np.fft.fftfreq(data.size, time_step)
idx = np.argsort(freqs)

plt.plot(freqs[idx], ps[idx])
plt.ylabel("W,Дб", fontsize=24)
plt.xlabel("v,Гц",fontsize=24)
plt.show()