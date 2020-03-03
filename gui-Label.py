from tkinter import *
root = Tk()
root.geometry("500x150")
root.title("Testing label")

l1 = Text(root)
l1.pack()
l1.insert(END , "Text")
l1.delete('1.0', END)
l1.insert(END , "SO LONG")
mainloop()