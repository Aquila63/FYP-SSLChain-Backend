import sys, socket, struct, random

from Crypto.PublicKey import RSA
from Crypto.Util import asn1
from base64 import b64decode

class Client():

        def pem_cleanup(self, key):
                i1 = key.find('\n')
                i2 = key.rfind('\n')
                return key[i1+1:i2-28]

        def rsa_test(self, key):
                key = self.pem_cleanup(key)
		print key
                keyDER = b64decode(key)
		seq = asn1.DerSequence()
                seq.decode(keyDER)
                keyPub = RSA.construct( (seq[0], seq[1]) )
                testData = "Test Data"
                testData = keyPub.encrypt(testData, 32)
                print testData



	def __init__(self, port):

		#The client now connects to the backend server after each command is recieved
		#This emulates the current front-end behaviour, which is caused by NodeJS.

		while 1:
			print '\n'
			self.message = raw_input("Enter Command: ")

			#Create the socket and roll
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s.settimeout(1.5)
			self.port = port
			s.connect(("localhost", self.port))

			#Send command
			s.sendall(self.message)

			try:
				#Print server response
				recv_data = s.recv(4096)
				print recv_data + '\n'
				s.close()
				#self.rsa_test(recv_data)
			except socket.timeout:
				print "Timed Out...:("
				continue

if __name__ == '__main__':

	port = int(sys.argv[1])
	Client(port)
