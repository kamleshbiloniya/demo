from multiprocessing import Process, Lock
import time
import threading
import sys
import pycurl
import StringIO
import json
import requests
import os, os.path


try:
    from urllib.parse import urlencode
    from io import BytesIO
except ImportError:
    from urllib import urlencode
    from StringIO import StringIO as BytesIO
# c =pycurl.Curl()

encoding = 'iso-8859-1'
# c.setopt(c.URL ,'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage')
overall_start_time = time.time()
print ('overall start time ',overall_start_time)
print ("<br>")
count = 0
g_var = 0
n = 0
overall_end_time = 0

def f(dir,l):
    DIR = 'uploads/'+str(dir)+'/premium'
    num_files =  len([name for name in os.listdir(DIR) if os.path.isfile(os.path.join(DIR, name))])
    b = StringIO.StringIO()
    start_time = time.time();
    print('starting time of directory',dir,'is',start_time)

    for i in range(num_files):
        url = 'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage'
        path = 'uploads/'+str(dir)+'/premium/'+ str(i)+'.jpg'          # enter path of images
        files = {'media': open(path, 'rb')}
        r = requests.post(url, files=files).text

        #l.acquire()
        end_file = 'END'
        img_name = str(i)+'.jpg'
        file = str(dir) + ".txt"
        text = open(file,"a+")
        text.write("%s\n\n"%img_name)
        text.write("%s\n\n"%r)
        if(i==num_files-1):
            text.write("%s\n\n"%end_file)
        text.close()
    #l.release()
    end_time = time.time()
    time_taken = end_time - start_time
    print('ending time of directory',dir,'is',end_time)
    print ("<br>")
    print('Total time taken in processing of',num_files,'from directory ',dir,'is',time_taken/60,'min')
    print ("<br>")
    l.acquire()
    global overall_end_time
    global g_var
    if(overall_end_time < end_time and g_var < n ):
        print (g_var)
        g_var=g_var+1;
        overall_end_time = end_time
        # print ("time updated")
        print (g_var)
        l.release()
        # print('current overall time = ',overall_end_time,g_var)
    if(g_var == n):
        print ('overall end time = ',overall_end_time)
        print ("<br>")
        overall_end_time = end_time
        overall_time_taken = overall_end_time - overall_start_time
        print ("overall time taken = ",overall_time_taken)
        print("<br>")


if __name__ == '__main__':
    s_t = time.time()
    count = 0
    g_var = 0
def fun():
    l = threading.Lock()
    now = time.time()
    global count
    global n
    if(count >= n ):
        return 0
    else:
        threading.Timer(0.001,fun).start()
        # for num in range(5):
        Process(target=f, args=(count,l)).start()
        count = count + 1;


n = int(sys.argv[1])
# count = 0
fun()
