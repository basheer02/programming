import socket
import threading
import tkinter as tk
from tkinter import scrolledtext


client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
addr = ('',1034)
client_socket.connect(addr)

def send_message():
    msg = entry.get()
    client_socket.send(msg.encode('utf-8'))
    entry.delete(0,tk.END)
    


def receive_message():
    while True:
        data = client_socket.recv(1024)
        text_area.insert(tk.END,f'{data.decode()}\n')

root = tk.Tk()
root.title('Client')

frame = tk.Frame(root)
frame.pack(padx=20,pady=20)

#text area
text_area = scrolledtext.ScrolledText(frame, width=40, height=10)
text_area.pack(padx=10,pady=10)

#input
lab = tk.Label(frame,text='input')
lab.pack(padx=5)

entry = tk.Entry(frame,width=30)
entry.pack(pady=5)

#button
send_btn = tk.Button(frame,text='Send', command=send_message)
send_btn.pack(pady=5)

receive_thread = threading.Thread(target=receive_message)
receive_thread.start()

root.mainloop()

client_socket.close()
