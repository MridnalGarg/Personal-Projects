from asyncio.windows_events import NULL
from tkinter import *
from tkinter import filedialog
import tkinter as tk
from PIL import Image, ImageTk
import os
from stegano import lsb
import ctypes
import tkinter.messagebox
root=Tk()
root.title("steganography-Hide a secret Text Message is an Image")
root.geometry("700x500+150+180")
root.resizable(False,False)
root.configure(bg="#2f4155")

def showimage():
    global filename
    filename=filedialog.askopenfilename(initialdir=os.getcwd(),
                                        title='Select Image File',
                                        filetype=(("PNG file","*.png"),
                                                  ("JPG File",".jpg"),("All file",".txt")))
    img=Image.open(filename)
    img=ImageTk.PhotoImage(img)
    lbl.configure(image=img,width=250,height=250)
    lbl.image=img
                                        

def Hide():
    global secret
    message=text1.get(1.0,END)
    secret=lsb.hide(str(filename),message)
    
def Show():
    clear_message=lsb.reveal(filename)
    text1.delete(1.0,END)
    text1.insert(END, clear_message)

def save():
    secret.save("hidden.png")

#icon on popups
image_icon=PhotoImage(file="logo.jpg")
root.iconphoto(False,image_icon)

#logo
logo=PhotoImage(file="logo.png")
Label(root,image=logo, bg="#2f4155").place(x=10,y=0)

Label(root,text="STEGANOGRAPHY",bg="#2f4155",fg="white",font="arial 25 bold").place(x=200,y=20)

#Image Frame
f=Frame(root,bd=3,bg="black",width=340,height=280,relief=GROOVE)
f.place(x=10,y=80)

lbl=Label(f,bg="black")
lbl.place(x=40,y=10)

#Message Frame
frame2=Frame(root,bd=3,width=340,height=120,bg="white",relief=GROOVE)
frame2.place(x=355,y=120)

Label(root,text="Message:",bg="#2f4155",fg="white",font="arial 20 bold").place(x=355,y=80)
text1=Text(frame2,font="Robote 16",bg="white",fg="black",relief=GROOVE,wrap=WORD)
text1.place(x=0,y=0,width=320,height=295)

scrollbar1=Scrollbar(frame2)
scrollbar1.place(x=320,y=0,height=300)

scrollbar1.configure(command=text1.yview)
text1.configure(yscrollcommand=scrollbar1.set)

#third Frame
frame3=Frame(root,bd=3,bg="#2f4155",width=330,height=100,relief=GROOVE)
frame3.place(x=10,y=370)

def onClick1():
    tkinter.messagebox.showinfo("Select image",  "Select Image!")
button =Button(frame3,text="Open Image",width=10,height=2,font="arial 14 bold",command=lambda: [onClick1(),showimage()]).place(x=20,y=20)

def onClick2():
    tkinter.messagebox.showinfo("Save",  "Image Saved!")
        
button =Button(frame3,text="Save Image",width=10,height=2,font="arial 14 bold",command=lambda: [onClick2(),save()]).place(x=180,y=20)

#Fourth Frame
frame4=Frame(root,bd=3,bg="#2f4155",width=330,height=100,relief=GROOVE)
frame4.place(x=360,y=370)

def onClick3():
    tkinter.messagebox.showinfo("Hide",  "Message successfully hidden !")
button = Button(frame4,text="Hide Data",width=10,height=2,font="arial 14 bold",command=lambda: [onClick3(),Hide()]).place(x=20,y=20)
Button(frame4,text="$how Data",width=10,height=2,font="arial 14 bold",command=lambda: [Show()]).place(x=180,y=20)

Label(root,text="Mady By:\n\nMridnal Garg 9919102032\nRaghav Joshi 9919102035\nPranati Tiwari 9919102056",bg="#2f4155",fg="white",font="arial 12").place(x=420,y=255)
root.mainloop()