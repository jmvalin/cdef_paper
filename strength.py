#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np

def constraint(d, S, D):
    return (d>0)*np.minimum(d,np.maximum(0, S - d/(2**D/S))) + (d<0)*np.maximum(d,np.minimum(0, -d/(2**D/S)-S))

d=np.arange(-40, 40, .5)

f = plt.figure(figsize=(7, 3))
plt.rc('text', usetex=True)
plt.rc('font', family='serif')

line1, = plt.plot(d, constraint(d, 2, 5), color='#000070', label='$S=2, D=5$')
line2, = plt.plot(d, constraint(d, 4, 5), color='#70D050', linestyle='--', label='$S=4, D=5$')
line3, = plt.plot(d, constraint(d, 8, 5), color='#C02020', linestyle=':', label='$S=8, D=5$')
plt.xlabel('Pixel difference ($d$)', fontsize=14)
plt.ylabel('$f(d,S,D)$', fontsize=14)
plt.legend(handles=[line1, line2, line3], loc=4)
plt.grid(True)
#plt.show()

f.savefig("strength.pdf", bbox_inches='tight')
