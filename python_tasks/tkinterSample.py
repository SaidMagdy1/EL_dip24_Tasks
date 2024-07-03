from tkinter import *

def up():
    pass

def down():
    pass

def right():
    pass

def left():
    pass

tk=Tk()
tk.title("+ Buttons")
tk.geometry("300x300")


b1=Button(tk,text="UP",bg="beige",font="Helvatica 20 bold",command=up())
b1.pack(side=TOP)

b3=Button(tk,text="Right",bg="red",font="Helvatica 20 bold",command=right())
b3.pack(side=LEFT)

b4=Button(tk,text="Left",bg="green",font="Helvatica 20 bold",command=left())
b4.pack(side=RIGHT)

b2=Button(tk,text="Down",bg="yellow",font="Helvatica 20 bold",command=down())
b2.pack(side=BOTTOM)



tk.mainloop()