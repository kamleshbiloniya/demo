import pycurl
try: 
    from urllib.parse import urlencode
    from io import BytesIO
except ImportError:
    from urllib import urlencode
    from StringIO import StringIO as BytesIO

c =pycurl.Curl()
buffer = BytesIO()
encoding = 'iso-8859-1'
c.setopt(c.URL ,'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage')
path = 'nice.jpg'
c.setopt(c.HTTPPOST, [
    ('fileupload', (
        # upload the contents of this file
        c.FORM_FILE,path,
    )),
])
c.perform()
body = buffer.getvalue()
print(body.decode(encoding))
#print('Status: %d' % c.getinfo(c.RESPONSE_CODE))

c.close()
