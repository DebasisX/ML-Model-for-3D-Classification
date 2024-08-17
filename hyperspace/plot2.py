import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import pandas as pd

filename = "model_ranges.csv"
data = pd.read_csv(filename)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

colors = {0.0: 'blue', 1.0: 'red'}

for index, row in data.iterrows():
    x_min, x_max = row['X_min'], row['X_max']
    y_min, y_max = row['Y_min'], row['Y_max']
    z_min, z_max = row['Z_min'], row['Z_max']
    result = row['Result']
    
    vertices = [
        [x_min, y_min, z_min],
        [x_max, y_min, z_min],
        [x_max, y_max, z_min],
        [x_min, y_max, z_min],
        [x_min, y_min, z_max],
        [x_max, y_min, z_max],
        [x_max, y_max, z_max],
        [x_min, y_max, z_max]
    ]
    
    faces = [
        [vertices[0], vertices[1], vertices[2], vertices[3]],  # Bottom face
        [vertices[4], vertices[5], vertices[6], vertices[7]],  # Top face
        [vertices[0], vertices[1], vertices[5], vertices[4]],  # Front face
        [vertices[2], vertices[3], vertices[7], vertices[6]],  # Back face
        [vertices[1], vertices[2], vertices[6], vertices[5]],  # Right face
        [vertices[4], vertices[7], vertices[3], vertices[0]]   # Left face
    ]
    
    cuboid = Poly3DCollection(faces, linewidths=1, edgecolors='black', alpha=0.25)
    cuboid.set_facecolor(colors[result])
    
    ax.add_collection3d(cuboid)

x_limits = [data['X_min'].min(), data['X_max'].max()]
y_limits = [data['Y_min'].min(), data['Y_max'].max()]
z_limits = [data['Z_min'].min(), data['Z_max'].max()]

ax.set_xlim(x_limits)
ax.set_ylim(y_limits)
ax.set_zlim(z_limits)

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Final')

# Show the plot
plt.show()
