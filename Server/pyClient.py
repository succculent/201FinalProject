import socket

message = "1234123412341234123412341234123412341234123412341234123412341234 100"
ip = '127.0.0.1'
port = 42069

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.sendto(message.encode('utf-8'), (ip, port))