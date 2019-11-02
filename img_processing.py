import matplotlib.image as img
import matplotlib.pyplot as plt
image = img.imread('face.jpeg')
print image.shape
image =image.reshape(image.shape[2],image.shape[0],image.shape[1])
arrR = image[0]
arrG = image[1]
arrB = image[2]
arrR.setflags(write=1)
# arrR[0]=0
plt.imshow(arrR, interpolation='none')
plt.show()
plt.imshow(arrG, interpolation='none')
plt.show()
plt.imshow(arrB, interpolation='none')
plt.show()
# print(arrR)
