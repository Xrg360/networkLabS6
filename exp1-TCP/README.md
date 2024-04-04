# Network Lab - Experiment: Server-Client Communication using TCP

## Objective:
The objective of this experiment is to understand the basics of server-client communication using TCP (Transmission Control Protocol).

## Experiment Overview:
In this experiment, we implemented a simple client-server model using TCP sockets. The server listens for incoming connections from clients and responds to their requests. The client establishes a connection with the server, sends a message, and receives a response.

## Experiment Procedure:
1. **Setting up the Server:**
   - The server program is executed, which binds to a specific port and starts listening for incoming connections.
   - Upon receiving a connection request from a client, the server accepts the connection and handles client requests.

2. **Setting up the Client:**
   - The client program is executed, which initiates a connection request to the server's IP address and port number.
   - Once the connection is established, the client sends a message to the server.
   - The client receives a response from the server and displays it.

3. **Server-Client Communication:**
   - The client sends a message to the server requesting some action or information.
   - The server processes the request and sends back an appropriate response to the client.

4. **Termination:**
   - After communication is complete, both the client and server close their respective sockets and terminate the connection.

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
