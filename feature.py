data = []
f = open("files.txt","r")
for i in range(10):
    line = f.readline()
    # lst = line.split(' ')
    data.append([line])
print(data)