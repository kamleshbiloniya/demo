import requests,json
data = json.dumps({'myImage':'nice.jpg'})
# data = 'nice.jpg'
# encoding = 'iso-8859-1'
files = {'media': open('nice.jpg', 'rb')}
url = 'http://www.alvinmcbride.com/FaceReaderPOSTv2/api/facereader/PostImage'
# r = requests.post(url,data)
# output =  str(r.decode(encoding))
r = requests.post(url, files=files)
print r.json()
