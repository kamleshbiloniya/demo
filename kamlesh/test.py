from multiprocessing import Process, Lock
import time
import threading
import sys
n = 0
def f(i):
 
    t= time.time()
    print "function is called at time = ", t
    #l.acquire()
    file = str(i) + ".txt"
    text = open(file,"a+")
    text.write("%f\r\n"%t);
    text.close()
    #l.release()

if __name__ == '__main__':
    s_t = time.time()
def fun():
    now = time.time()
    if(now - s_t > n ):
        return 0
    else:
        threading.Timer(1.0,fun).start()   
        for num in range(5):
            Process(target=f, args=(num,)).start()
 

n = int(sys.argv[1])
fun()

