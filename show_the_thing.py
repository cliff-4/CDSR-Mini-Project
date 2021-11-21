from mpl_toolkits import mplot3d
from matplotlib import pyplot as plt
import numpy as np

with open('Rikitake_ Data_0.001s_Timestep periodic 1l.txt') as f:
	a = f.readlines()

dataset = [[float(k) for k in b.split(" ")] for b in a]
end = len(dataset)

xmin = xmax = ymin = ymax = zmin = zmax = 0
for point in dataset:
	if point[0] > xmax: xmax = point[0]
	if point[0] < xmin: xmin = point[0]
	if point[1] > ymax: ymax = point[1]
	if point[1] < ymin: ymin = point[1]
	if point[2] > zmax: zmax = point[2]
	if point[2] < zmin: zmin = point[2]

######################################

x=[]
y=[]
z=[]

for i in dataset:
	x.append(i[0])
	y.append(i[1])
	z.append(i[2])

##################################################


start = 3000
datalimit = end
thicc = 0.2

ax = plt.axes(projection='3d')
plt.plot(x[start:end], y[start:end], z[start:end], color='r', lw = thicc)
ax.legend()
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")
plt.show()
