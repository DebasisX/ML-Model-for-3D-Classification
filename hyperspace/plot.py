import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import pandas as pd
# Replace 'file.csv' with the path to your CSV file
df = pd.read_csv('dataset.csv', header=None)


df = df.iloc[:1500, :]
X = df.iloc[:, :-1].values  
labels = df.iloc[:, -1].values 

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

label_0 = X[labels == 0]
label_1 = X[labels == 1]

ax.scatter(label_0[:, 0], label_0[:, 1], label_0[:, 2], color='blue', label='Label 0')
ax.scatter(label_1[:, 0], label_1[:, 1], label_1[:, 2], color='red', label='Label 1')

ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.legend()

plt.show()
