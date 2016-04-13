This is the back end for my final year project, submitted as part of the B.A. (Mod) Computer Science degree, Trinity College Dublin, April 2016.

This is an implementation of the Bitcoin blockchain (https://github.com/bitcoin/bitcoin) that replaces transactions for X.509 SSL Certificates; a simple C++ server for accessing the blockchain and a simple test client written in Python to query the server.

#Installation & Use

To compile the code, run `make ..` under the `build` directory. To run the code, run `./SSLChain` within the same directory. I did neglect to clean up my builds during development, so you're better off running a `make clean` beforehand to be safe.

When started, the server will initiate and begin calculating proof-of-work for the three test blocks; these should take anywhere from 0 - 20 seconds, but usually takes about 5-10 seconds on average.

To run the test client; run `python test/client.py 2048`.

The commands that the server (and the test client) accepts are as follows:

```
HELP
PRINT GENESIS BLOCK
PRINT CHAIN
GET BLOCK <block hash>
PRINT CERTS <block hash>
GET CERT <email>
GET PUB KEY <email>
SHUTDOWN
```
