from multiprocessing import Process, Lock
from os import listdir
from os.path import isfile, join
import time
import os
import threading
import sys
import pycurl
import requests
import StringIO

try:
    from urllib.parse import urlencode
    from io import BytesIO
except ImportError:
    from urllib import urlencode
    from StringIO import StringIO as BytesIO
# c =pycurl.Curl()

encoding = 'iso-8859-1'
# c.setopt(c.URL ,'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage')
count = 0
n = 0
exit_call = 0
def f(i):
    th_creation = time.time()
    global exit_call
    path = 'webcam/'+str(i)+'.jpg'          # enter path of images
    mypath = 'webcam/'
    file = str(i) + ".jpg"
    onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
    if file not in onlyfiles:
        print('file not found',i)
        exit_call = 1
        return
    url = 'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage'

    files = {'media': open(path, 'rb')}
    req_sent = time.time()
    r = requests.post(url, files=files).text
    res_received = time.time()
    time_taken = res_received - req_sent;
    b = StringIO.StringIO()
    num_th =threading.active_count()
    num_pro = os.getpid()
    txt1 = 'thread created at '
    txt2 = 'api request sent at '
    txt3 = 'response received at '
    print("number of threads currently executing ",num_th,num_pro)
    text = open("1.txt","a+")
    text.write("%s\r\n\n"%file)
    text.write("%s"%txt1)
    text.write("%s\r\n\n"%th_creation)
    text.write("%s"%txt2)
    text.write("%s\r\n\n"%req_sent)
    text.write("%s\r\n\n"%r);
    text.write("%s"%txt3)
    text.write("%s\r\n\n" %time_taken)
    text.close()
    return
    #l.release()

if __name__ == '__main__':
    s_t = time.time()
# def fun():
#     global count
#     global exit_call
#     if(exit_call):
#         t=threading.Thread(target=sys.exit)
#         t.setDaemon(True)
#         t.start()
#     else:
#         threading.Timer(1.0,fun).start()
#         threading.Thread(target=f, args=(count,)).start()
#
#
#     count = count + 1

n = int(sys.argv[1])
f(n)
