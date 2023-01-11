#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import numpy as np
import matplotlib.pyplot as plt
import scipy.interpolate

def f(x):
    return abs(x); 

x = np.linspace(-1,1,15);
y = f(x);

p = scipy.interpolate.lagrange(x,y);

val_x = np.linspace(-1,1,500);
val_y = f(val_x);

plt.plot(xs,val_y);
plt.plot(x,y,'o');

val_y = p(val_x);
plt.plot(val_x,val_y);

plt.xticks(np.arange(min(x), max(x) + 1, 0.5));
plt.yticks(np.arange(min(y), max(y) + 1, 0.5));

plt.grid();
plt.legend();
plt.show(); 