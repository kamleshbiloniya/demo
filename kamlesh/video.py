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

encoding = 'iso-8859-1'
overall_start_time = time.time()
print('overall start time ',overall_start_time)

count = 0
g_var = 0
overall_end_time = 0

def f(dir):
    DIR = 'thumbnails/'+str(dir)+'/premium'
    num_files =  len([name for name in os.listdir(DIR) if os.path.isfile(os.path.join(DIR, name))])
    b = StringIO.StringIO()
    start_time = time.time();
    print('starting time of directory',dir,'is',start_time)

    for i in range(num_files):
        url = 'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage'
        path = 'thumbnails/'+str(dir)+'/premium/'+ str(i)+'.jpg'          # enter path of images
        files = {'media': open(path, 'rb')}
        r = requests.post(url, files=files).text
        img_name = str(i)+'.jpg'
        file = str(dir) + ".txt"
        text = open(file,"a+")
        text.write("%s\n\n"%img_name)
        text.write("%s\n\n"%r)

        text.close()

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
        bash_cmd = 'ffmpeg -i movies/'+str(count)+'.mp4 -an  -vf fps=1 -start_number 0 thumbnails/'+str(count)+'/%d.jpg'
        os.system(bash_cmd)
        Process(target=f, args=(count,)).start()
        count = count + 1;

fun()










# <html>
# <body>
# <?php
# if(isset($_POST["submit"])){
#         //$t = $_POST["time"];
#         echo "Running.........";
#         echo " <br>";
#         for($i =0 $i; < ;5 $i++){
#         $bash_cmd = echo 'ffmpeg -i uploads/'.$i.'.mp4 -an  -vf fps=1 -start_number 0 uploads/'.$i.'/%d.jpg';
#         shell_exec($bash_cmd);
#         }
#         shell_exec("sh clean.sh");
#         $out =  shell_exec("python updated_processing.py ".$t);
#         //echo $t;
#         echo $out ;
#         echo "done";
#
# }
#
# echo "<br>";
# //echo "user of this directory::kamlesh  ";
# //$out =  shell_exec("python processing.py ".$t);
# //echo $t;
# //echo $out ;
#
#
# ?>
#  <form method="post" name="myform" action="index.php">
# <input type="submit" name="submit" value="Run">
# </form>
# see output at <br><br>
# <a href="http://34.215.205.90/IIT2018/kamlesh/0.txt">0.txt</a><br>
# <a href="http://34.215.205.90/IIT2018/kamlesh/1.txt">1.txt</a><br>
# <a href="http://34.215.205.90/IIT2018/kamlesh/2.txt">2.txt</a><br>
# <a href="http://34.215.205.90/IIT2018/kamlesh/3.txt">3.txt</a><br>
# <a href="http://34.215.205.90/IIT2018/kamlesh/4.txt">4.txt</a><br>
# </body>
# </html>
