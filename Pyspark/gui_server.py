import socket
import threading
import tkinter as tk
from tkinter import scrolledtext

client_list = []

server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('',1034))
server_socket.listen()


def handle_client(client):
    while True:
        data = client.recv(1024).decode()
        text_area.insert(tk.END,f'{data}\n')
        
        for clien in client_list:
            clien.send(data.encode())    

def accept_conn():
    while True:
        client_socket,_ = server_socket.accept()
        client_list.append(client_socket)

        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

root = tk.Tk()
root.title('Server')

#text area
text_area = scrolledtext.ScrolledText(root, width=40, height=10)
text_area.pack(padx=10,pady=10)


conn_thread = threading.Thread(target=accept_conn)
conn_thread.start()

root.mainloop()

server_socket.close()
