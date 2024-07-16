import socket

client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
addr = ('',1042)
client_socket.connect(addr)

while True:
    msg = input(' Enter message : ')
    client_socket.send(msg.encode())
    data = client_socket.recv(1024)
    print(f'server : {data.decode()}')
    if msg.lower() == 'exit':
        break
    
client_socket.close()