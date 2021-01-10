import matplotlib.pyplot as plt

path_1 = "C:\GitRepo\Some_Interesting_Projects\Sensor-Fusion\Sensor-Fusion\src\helper\ego_data.txt"
path_2 = "C:\GitRepo\Some_Interesting_Projects\Sensor-Fusion\Sensor-Fusion\src\helper\out.txt"

file_1 = open(path_1, 'r')
file_2 = open(path_2, 'r')

X = []
Y = []

K_X = []
K_Y = []
while(True):
    line_1 = file_1.readline()
    line_2 = file_2.readline()

    if not line_2:
        break

    split_string_1 = line_1.split()
    split_string_2 = line_2.split()

    
    x_1 = float(split_string_1[1])
    y_1 = float(split_string_1[2])

    x_2 = float(split_string_2[0])
    y_2 = float(split_string_2[1])

    X.append(x_1)
    Y.append(y_1)

    K_X.append(x_2)
    K_Y.append(y_2)
   

plt.scatter(X, Y, s=4)
plt.scatter(K_X, K_Y, s=4)
plt.show()
