#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import numpy as np
import matplotlib.pyplot as plt


file = open("data.txt", "r");

Years = file.readline().split();
Years = [int(x) for x in Years];

Value = file.readline().split();
Value = [float(x) for x in Value];

coeff = np.polyfit(Years, Value, 4);
p = np.poly1d(coeff);
x = np.linspace(Years[0], Years[-1]);

print("The value estimation on the year 2007 is: ", p(2007), " (Green Point)");
print("The value estimation on the year 2012 is: ", p(2012), " (Purple Point)");
print("The value estimation on the year 2018 is: ", p(2018), " (Black Point)\n");

draw = p(x);
plt.scatter(Years, Value, color = "red");

plt.plot(x, draw, color = "blue");

plt.plot(2007, p(2007), "ro", color = "green"); 
plt.plot(2012, p(2012), "ro", color = "purple"); 
plt.plot(2018, p(2018), "ro", color = "black"); 

plt.grid();
plt.ylim(0, draw.max() * 1.5);
plt.show();