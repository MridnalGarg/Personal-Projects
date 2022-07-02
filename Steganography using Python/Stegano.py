import cv2
import numpy as np
import types
from google.colab.patches import cv2_imshow

#Here we are using 08b as we require 8 bit representation of binary digits.
#If we will be using only b then it will not add 0 to convert it into 8 bits 
# and returns the binary converted value

def messageToBinary(message):
  if type(message) == str:
    return ''.join([ format(ord(i), "08b") for i in message ])

  elif type(message) == bytes or type(message) == np.ndarray:
    return [ format(i, "08b") for i in message ]
  elif type(message) == int or type(message) == np.uint8:
    return format(message, "08b")
  else:
    raise TypeError("Input type not supported")

# Function to hide the secret message into the image

def Hide(image, secret_message):

  # calculate the maximum bytes to encode
  n_bytes = image.shape[0] * image.shape[1] * 3 // 8
  print("Maximum bytes to encode:", n_bytes)

  #Check if the number of bytes to encode is less than the maximum bytes in the image
  if len(secret_message) > n_bytes:
      raise ValueError("Error encountered insufficient bytes, need bigger image or less data !!")
  
  secret_message += "#####" # you can use any string as the delimeter

  data_index = 0
  # convert input data to binary format using messageToBinary() fucntion
  binary_secret_msg = messageToBinary(secret_message)

  data_len = len(binary_secret_msg) #Find the length of data that needs to be hidden
  for values in image:
      for pixel in values:
          # convert RGB values to binary format
          r, g, b = messageToBinary(pixel)
          # modify the least significant bit only if there is still data to store
          if data_index < data_len:
              # hide the data into least significant bit of red pixel
              pixel[0] = int(r[:-1] + binary_secret_msg[data_index], 2)
              data_index += 1
          if data_index < data_len:
              # hide the data into least significant bit of green pixel
              pixel[1] = int(g[:-1] + binary_secret_msg[data_index], 2)
              data_index += 1
          if data_index < data_len:
              # hide the data into least significant bit of  blue pixel
              pixel[2] = int(b[:-1] + binary_secret_msg[data_index], 2)
              data_index += 1
          # if data is encoded, just break out of the loop
          if data_index >= data_len:
              break
  return image

def showData(image):

  binary_data = ""
  for values in image:
      for pixel in values:
          r, g, b = messageToBinary(pixel) 
          #extracting data from the least significant bits of red, green and blue
          binary_data += r[-1] 
          binary_data += g[-1]
          binary_data += b[-1]
  # split by 8-bits
  all_bytes = [ binary_data[i: i+8] for i in range(0, len(binary_data), 8) ]
  # convert from bits to characters
  decoded_data = ""
  for byte in all_bytes:
      decoded_data += chr(int(byte, 2))
      if decoded_data[-5:] == "#####": #check if we have reached the delimiter which is "#####"
          break
  return decoded_data[:-5] #remove the delimiter to show the original hidden message


# Function to Encode data
def encode():
  imgfile1 = input("Enter the name of image(with extension): ")
  image = cv2.imread(imgfile1)
  
  print("\n\n~Original Image~\n")
  resized_image = cv2.resize(image, (500, 500))
  cv2_imshow(resized_image)
  
  data = input("Enter data to be encoded : ") 

  if (len(data) == 0): 
    print("Data is empty")

  imgfile2 = input("\nEnter the name of new encoded image(with extension): ")

# Function to Decode data
def decode():
  image_name = input("Enter the name of the image to be decode (with extension): ") 
  image = cv2.imread(image_name)

  print("\n\n~ Encoded Image ~ \n")
  resized_image = cv2.resize(image, (500, 500))
  cv2_imshow(resized_image)
  print("\n\n---------------------------------------------") 
  print("\tDecoded Message: " + showData(image))
  print("---------------------------------------------") 

def steganography():
    a = 0
    while a!=3: 
      a = input("\n\nImage Steganography \n 1. Encode the data \n 2. Decode the data \n 3. Exit \n\n Your input is: ")
      choice = int(a)
      if (choice == 1):
        print("\nEncoding....")
        encode() 
          
      elif (choice == 2):
        print("\nDecoding....") 
        decode()
      elif (choice == 3):
        print("\nExiting...")
        return
      else: 
        print("Please enter correct input...\n") 

#steganography()