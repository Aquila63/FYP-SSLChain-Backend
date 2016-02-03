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

		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.settimeout(1.5)
		#self.ip = socket.inet_ntoa(struct.pack('>I', random.randint(1, 0xffffffff)))
		self.port = port
		s.connect(("localhost", self.port))			
		
		while 1:
			print '\n'
			self.message = raw_input("Enter Command: ")
			
			s.sendall(self.message)
			
			#try:
			recv_data = s.recv(4096)
			print recv_data + '\n'
			self.rsa_test(recv_data)
			#except socket.timeout:
				#print "Something went wrong\n"

if __name__ == '__main__':

	port = int(sys.argv[1])
	Client(port)
