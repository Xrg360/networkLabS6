# Network Lab - Experiment: Server-Client Communication using TCP

## Objective:
The objective of this experiment is to understand the basics of server-client communication using TCP (Transmission Control Protocol).

## Experiment Overview:
In this experiment, we implemented a simple client-server model using TCP sockets. The server listens for incoming connections from clients and responds to their requests. The client establishes a connection with the server, sends a message, and receives a response.

## Experiment Procedure:
###ALGORITHM

   -SERVER
   1. Include necessary header files such as `stdio.h`, `string.h`, `sys/socket.h`, and `arpa/inet.h`.

   2. Declare variables for socket descriptors, server and client addresses, and messages to be sent and received,and Initialize the server and client messages with null characters using `memset()`.
   
   3. Call `socket()` to create a socket for communication, and Check if the socket creation was successful. If not, print an error message and exit.
   
   4. **Bind to Port:**
      - Set up the server address structure (`server_addr`) with the desired port and IP address (`127.0.0.1` in this case).
      - Call `bind()` to bind the socket to the server address.
      - Check for errors in binding. If there's an error, print a message and exit.
   
   5. Call `listen()` to make the server listen for incoming connections.
   
   6. Call `accept()` to accept incoming client connections. If the connection is accepted successfully, print the client's IP address and port number.
   
   7.  Call `recv()` to receive data from the client.
   
   8.  Print the message received from the client.
   
   9.  Prepare a response message for the client.
      - Call `send()` to send the response message to the client.
      - Check for errors in sending. If there's an error, print a message and exit.
   
   10. Close Connections:
   
   11.  Exit the program with status `0`.
   


## Viva Questions:
1. What is TCP (Transmission Control Protocol), and how does it differ from UDP (User Datagram Protocol)?
2. Explain the process of establishing a TCP connection between a client and server.
3. What is the purpose of the `bind()` and `listen()` functions in server socket programming?
4. Describe the role of the `accept()` function in server socket programming.
5. How does the client-side socket differ from the server-side socket in a TCP connection?
6. What is a socket address? Explain the components of a socket address structure.
7. What are the advantages of using TCP for communication over the Internet?
8. Discuss the concept of TCP's flow control and congestion control mechanisms.
9. How does TCP ensure reliable data transmission?
10. Explain the steps involved in handling multiple client connections by a single server using TCP.
11. What are the potential issues that may arise during TCP communication, and how can they be addressed?
12. Compare and contrast blocking and non-blocking socket operations in TCP programming.
13. How can you handle timeouts and connection failures in TCP communication?
14. Discuss the significance of error handling in TCP socket programming.
15. Explain the role of the `send()` and `recv()` functions in sending and receiving data over TCP sockets.
