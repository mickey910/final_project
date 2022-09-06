# python3-udp-socket-client.py
"""
Created on Tue Aug 30 19:37:09 2022

@author: user
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket

HOST = '192.168.1.103'
PORT = 50001
server_addr = (HOST, PORT)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    outdata = input('please input message: ')
    print('sendto ' + str(server_addr) + ': ' + outdata)
    s.sendto(outdata.encode(), server_addr)
    
    indata, addr = s.recvfrom(1024)
    print('recvfrom ' + str(addr) + ': ' + indata.decode())

