import sys, socket, struct, random

class Client():

	
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
			#except socket.timeout:
				#print "Something went wrong\n"


if __name__ == '__main__':

	port = int(sys.argv[1])
	Client(port)
