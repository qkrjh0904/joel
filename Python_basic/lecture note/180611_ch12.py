#coding: utf-8
from tkinter import *

##def click_up():
##    counter.set(counter.get()+1)
##def click_down():
##    counter.set(counter.get()-1)
##if __name__=='__main__':
##    win = Tk()
##    win.title('Counter')
##    win.geometry('300x100+200+100')
##    counter = IntVar()
##    counter.set(0)
##    lbl = Label(win, textvariable=counter)
##    lbl.pack()
##    btn_up = Button(win, text="    Up    ", command=click_up)
##    btn_down = Button(win, text="  Down  ", command=click_down)
##    btn_up.pack()
##    btn_down.pack()
##    win.mainloop()




####  lambda(args):body
##
##def click(incr):
##    counter.set(counter.get()+incr)
##    
##if __name__=='__main__':
##    win = Tk()
##    win.title('Counter')
##    win.geometry('300x100+200+100')
##    counter = IntVar()
##    counter.set(0)
##    lbl = Label(win, textvariable=counter)
##    lbl.pack()
##    btn_up = Button(win, text="    Up    ", command = lambda:click(1))
##    btn_down = Button(win, text="  Down  ", command = lambda:click(-1))
##    btn_up.pack()
##    btn_down.pack()
##    win.mainloop()




##N = 0
##def incr(delta=1):
##    global N
##    N+=delta
##
##print(N)
##incr()
##print(N)
##incr(10)
##print(N)



##window = Tk()
##window.title('Python')
##frm1 = Frame(window)
##frm1.pack()
##frm2 = Frame(window, borderwidth=4,
##relief=GROOVE)
##frm2.pack(side=LEFT)
##frm3 = Frame(window, borderwidth=4,
##relief=GROOVE)
##frm3.pack(side=RIGHT)
##lbl1 = Label(frm1, text='First label')
##lbl1.pack()
##lbl2 = Label(frm2, text='Second label')
##lbl2.pack()
##lbl3 = Label(frm2, text='Third label')
##lbl3.pack()
##lbl4 = Label(frm3, text='Fourth label')
##lbl4.pack()
##window.mainloop()



##window = Tk()
##window.title('Python')
##frm1 = Frame(window, borderwidth=4, relief=RAISED)
##frm1.pack()
##btn1 = Button(frm1, text='First button')
##btn1.grid(row=0, column=0)
##btn2 = Button(frm1, text='Second button')
##btn2.grid(row=1, column=1)
##btn3 = Button(frm1, text='Third button')
##btn3.grid(row=0, column=1)
##window.mainloop()





##window = Tk()
##window.title('Python')
##window.geometry("250x200+30+30")
##btn1 = Button(window, text='First button')
##btn1.place(x=20, y=20)
##btn2 = Button(window, text='Second button')
##btn2.place(x=50, y=100)
##btn3 = Button(window, text='Third button')
##btn3.place(x=110, y=40)
##window.mainloop()




##window = Tk()
##window.title('Python')
##button = Button(window, text='Hello', font=('Courier', 14, 'bold'), bg='green', fg='blue')
##button.pack()
##window.mainloop()


##def enter(label):
##    if label == 'C':
##        entry.delete(0, END)
##    elif label == 'D':
##        ans = eval(entry.get())
##        ans *= 2
##        entry.delete(0, END)
##        entry.insert(0, ans)
##    else:
##        entry.insert(END, label)
##
##if __name__ == '__main__':
##    window = Tk()
##    window.title('Calc')
##    entry = Entry(window, width=12, justify=RIGHT)
##    entry.pack()
##    frm = Frame(window)
##    frm.pack()
##    for label in '10CD':
##        btn = Button(frm, text=label, width=3,
##            command=(lambda char=label: enter(char)))
##        btn.pack(side=LEFT)
##    window.mainloop()























