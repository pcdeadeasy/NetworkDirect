# dmpring

This is a program to demonstrate how to use the Network Direct
interface to communicate between two peers.

## This is how it should work


In relative time order

```
Server                                  Client

- initialize Network Direct
- initiate Receive of message T
- wait for a connection
                                        - initialize Network Direct
                                        - initiate Receive of message A
                                        - open connection
- accept connection
- initiate Send of message A
- complete Send of message A
                                        - complete Receive of message A
                                        - do work
                                        - initiate Send of Message T
                                        - complete Send of Message T
- complete Receive of message T
```

- Message A contains information about the location and size of the 
server's memory window.
- Message T is the termination message. No data is sent.

Messages are written into a registered memory window of the peer.
The location in the memory window is specfied by the array of 
ND2_SGE structures specified as the argument to the Send method.