import matplotlib.pyplot as plt
import numpy as np

# Чтение данных из файлов
def read_data(filename):
    x = []
    y = []
    with open(filename, 'r') as file:
        for line in file:
            values = line.split()
            if len(values) == 2:
                x.append(float(values[0]))
                y.append(float(values[1]))
    return x, y

# Чтение данных из файлов
x1, y1_x = read_data('X1_out.txt')
_, y1_v = read_data('V1_out.txt')

# Чтение данных из файлов с разными h
xh1, yh1_x = read_data('X1_hout.txt')
_, yh1_v = read_data('V1_hout.txt')

# Удаление пустых значений из yh1_x и yh1_v
# Это необходимо, если в файлах есть пустые строки
yh1_x = [val for idx, val in enumerate(yh1_x) if idx % 2 == 0]
yh1_v = [val for idx, val in enumerate(yh1_v) if idx % 2 == 0]

# Создание фигуры и осей
fig, axs = plt.subplots(2, figsize=(10, 6))

# Построение графиков
axs[0].plot(x1, y1_x, label='X_1')
axs[0].plot(xh1[:len(yh1_x)], yh1_x, label='Xh_1')
axs[0].set_title('График X')
axs[0].set_xlabel('t')
axs[0].set_ylabel('X')
axs[0].legend()

axs[1].plot(x1, y1_v, label='V_1')
axs[1].plot(xh1[:len(yh1_v)], yh1_v, label='Vh_1')
axs[1].set_title('График V')
axs[1].set_xlabel('t')
axs[1].set_ylabel('V')
axs[1].legend()

# Layout так, чтобы подписи не перекрывались
fig.tight_layout()

plt.show()
