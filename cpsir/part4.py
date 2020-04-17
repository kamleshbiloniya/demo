from scipy.integrate import quad
def g(x):
	return (9**x)/(3+9**x)

def f(x):
	return (9**g(x))/(3+9**g(x))

I = quad(f,1/5,4/5,args=())
print(I)