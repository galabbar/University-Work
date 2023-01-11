import matplotlib.pyplot as plt
import math
import numpy as np

file = open("primes.txt", "r");

primes = [];
Y_axis = [];
i = 0;
Accum = 1;

while i < 100:

    num = file.readline();
    Accum *= int(num);

    primes.append(Accum ** (1 / int(num)));
    Y_axis.append(i + 1);

    i += 1;

primes = np.array(primes);
Y_axis = np.array(Y_axis);

plt.plot(primes, Y_axis, color = "blue");
plt.grid();
plt.legend();
plt.show();