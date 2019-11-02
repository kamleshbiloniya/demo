import pycurl
c = pycurl.Curl()
c.setopt(c.URL, 'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage')
c.setopt(c.POST, 1)
c.setopt(c.HTTPPOST, [("images_file", (c.FORM_FILE, "4.jpg"))])
#c.setopt(c.HTTPPOST, [("parameters", (c.FORM_FILE, "myparams.json"))])
c.setopt(pycurl.HTTPHEADER, ['Accept-Language: en'])
c.perform()
c.close()
