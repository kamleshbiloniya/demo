from multiprocessing import Process, Lock
import time
import threading
import sys
import pycurl
import StringIO
import json
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
print('overall start time ',overall_start_time)
count = 0
g_var = 0
overall_end_time = 0
def f(dir):
    DIR = 'uploads/'+str(dir)+'/premium'
    num_files =  len([name for name in os.listdir(DIR) if os.path.isfile(os.path.join(DIR, name))])
    b = StringIO.StringIO()
    start_time = time.time();
    print('starting time of directory',dir,'is',start_time)

    for i in range(num_files):
        c =pycurl.Curl()
        c.setopt(c.URL ,'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage')
        c.setopt(pycurl.WRITEFUNCTION, b.write)  #
        path = 'uploads/'+str(dir)+'/premium/'+ str(i)+'.jpg'          # enter path of images
        c.setopt(c.HTTPPOST, [
            ('fileupload', (
                # upload the contents of this file
                c.FORM_FILE,path,
            )),
        ])
        a = c.perform()
        body = b.getvalue()
        # output = json.loads(body)
        # old_stdout = sys.stdout
        # buffer = BytesIO()
        # sys.stdout = buffer
        # print(buffer)
        # body = buffer.getvalue()
        output =  str(body.decode(encoding))
        # print(output)
        # print(sys.stdout)
        #print('Status: %d' % c.getinfo(c.RESPONSE_CODE))

        c.close()

        #l.acquire()
        img_name = str(i)+'.jpg'
        file = str(dir) + ".txt"
        text = open(file,"a+")
        text.write("%s\n\n"%img_name)
        text.write("%s\n\n"%output)

        text.close()
    #l.release()
    end_time = time.time()
    time_taken = end_time - start_time
    print('ending time of directory',dir,'is',end_time)
    print('Total time taken in processing of',num_files,'from directory ',dir,'is',time_taken/60,'min')
    global overall_end_time
    global g_var
    if(overall_end_time < end_time):
        global g_var
        g_var = g_var + 1
        overall_end_time = end_time
        # print('current overall time = ',overall_end_time,g_var)
    else:
        print('overall end time =',overall_end_time)


if __name__ == '__main__':
    s_t = time.time()
    count = 0
    g_var = 0
def fun():
    now = time.time()
    global count
    if(count > 5 ):
        return 0
    else:
        threading.Timer(0.001,fun).start()
        # for num in range(5):
        Process(target=f, args=(count,)).start()
        count = count + 1;


# n = int(sys.argv[1])
# count = 0
fun()
