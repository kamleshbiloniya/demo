from multiprocessing import Process, Lock
import time
import threading
import sys
import pycurl
import StringIO

try:
    from urllib.parse import urlencode
    from io import BytesIO
except ImportError:
    from urllib import urlencode
    from StringIO import StringIO as BytesIO
c =pycurl.Curl()

encoding = 'iso-8859-1'
c.setopt(c.URL ,'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage')

n = 0
def f(i):
    b = StringIO.StringIO()
    c.setopt(pycurl.WRITEFUNCTION, b.write)  #c.setopt(pycurl.WRITEFUNCTION, b.write) specifies a callback to tell the program what to do with the data
    path = 'webcam/'+str(i)+'.jpg'          # enter path of images
    c.setopt(c.HTTPPOST, [
        ('fileupload', (
            # upload the contents of this file
            c.FORM_FILE,path,
        )),
    ])
    a = c.perform()
    body = b.getvalue()
    output =  str(body.decode(encoding))
    c.close()
    #l.acquire()
    file = str(i) + ".txt"
    text = open(file,"a+")
    text.write("%s\r\n"%output);
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
        Process(target=f, args=(0,)).start()


n = int(sys.argv[1])
fun()
