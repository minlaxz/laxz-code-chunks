import tkinter as tk
from tkinter import messagebox

root= tk.Tk() # create window
root.title("Laxz's")
root.minsize(200, 100)
#root.wm_iconbitmap('MyIcon.ico')

canvas1 = tk.Canvas(root, width = 180, height = 100)
canvas1.pack()

def ExitApplication():
    MsgBox = tk.messagebox.askquestion ('--Shutdown--','Are you sure you want to shutdown ?',icon = 'question')
    if MsgBox == 'yes':
        import os
        os.system('shutdown -s -f -t 60')
        root.destroy()
    else:
        tk.messagebox.showinfo('Return','Cancelled',icon='info')
        root.destroy()
        
button1 = tk.Button (root, text='Shutdown',command=ExitApplication , highlightbackground='#0000aa')
canvas1.create_window(90, 50, window=button1)

root.mainloop()
