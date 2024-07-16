import socket
import threading


def handle(client,client_ad):
    while True:
        data = client.recv(1024)
        print(f'{client_ad}:{data.decode()}')
        response = 'message received'
        client.send(response.encode())
        if data.decode().lower() == 'exit':
            break


server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
address = ('',1042)
server_socket.bind(address)
server_socket.listen()
print('server is listening...')

while True:
    client_socket,client_addr = server_socket.accept()
    client_thread = threading.Thread(target=handle, args=(client_socket,client_addr))
    client_thread.start()

server_socket.close()