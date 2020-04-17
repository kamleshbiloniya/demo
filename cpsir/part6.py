from scipy.integrate import quad
import numpy as np
def integrand(x,t):
	return (t**x) / (1+2*t+3*t**2+4*t**3+3*t**4+2*t**5+t**6)


def expint(x):
	return quad(integrand, 0, np.inf, args=(x))[0]
for i in range(0,6):
	print(i,expint(i))
