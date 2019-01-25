#coding: utf-8
from tkinter import *

def enter(label):
    if label == 'C':
        entry.delete(0, END)
    elif label == '/':
        ans = eval(entry.get())
        entry.insert(END, label)
    elif label == '*':
        ans = eval(entry.get())
        entry.insert(END, label)
    elif label == '-':
        ans = eval(entry.get())
        entry.insert(END, label)
    elif label == '+':
        ans = eval(entry.get())
        entry.insert(END, label)
    elif label == '=':
        ans = eval(entry.get())
    else:
        entry.insert(END, label)

if __name__ == '__main__':
    window = Tk()
    window.title('Calc')
    window.geometry('200x150+200+100')
    entry = Entry(window, width=20, justify=RIGHT)
    entry.pack()
    frm1 = Frame(window)
    frm1.pack()
    frm2 = Frame(window)
    frm2.pack()
    frm3 = Frame(window)
    frm3.pack()
    frm4 = Frame(window)
    frm4.pack()
    for label in '789C':
        btn = Button(frm1, text=label, width=3,
            command=(lambda char=label: enter(char)))
        btn.pack(side=LEFT)
    for label in '456/':
        btn = Button(frm2, text=label, width=3,
            command=(lambda char=label: enter(char)))
        btn.pack(side=LEFT)
    for label in '123*':
        btn = Button(frm3, text=label, width=3,
            command=(lambda char=label: enter(char)))
        btn.pack(side=LEFT)
    for label in '0=+-':
        btn = Button(frm4, text=label, width=3,
            command=(lambda char=label: enter(char)))
        btn.pack(side=LEFT)
    window.mainloop()
