import matplotlib.pyplot as plt

input = [100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000]
time = [0.000, 0.001, 0.006, 0.018, 0.056, 0.284, 1.086, 4.257, 26.976, 107.953]
plt.plot(input, time, marker='x')
plt.xlabel('Input Length')
plt.ylabel('Time taken (in s)')
plt.title('Input Length vs Time')
plt.show()
