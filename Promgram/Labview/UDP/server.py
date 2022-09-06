# python3-udp-socket-server.py
"""
Created on Tue Aug 30 17:44:49 2022

@author: user
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket

HOST = '192.168.0.79'   #IP
PORT = 7000        #port

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

s.bind((HOST, PORT))

print('server start at: %s:%s' % (HOST, PORT))
print('wait for connection...')

while True:
    indata, addr = s.recvfrom(1024)
    print('recvfrom ' + str(addr) + ': ' + indata.decode())

    outdata = 'echo ' + indata.decode()
    s.sendto(outdata.encode(), addr)

    
