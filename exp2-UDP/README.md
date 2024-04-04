# Network Lab - Experiment: Server-Client Communication using UDP

## Objective:
The objective of this experiment is to understand the basics of server-client communication using UDP (User Datagram Protocol).

## Experiment Overview:
In this experiment, we implemented a simple client-server model using UDP sockets. Unlike TCP, UDP provides a connectionless communication model, where data is sent as packets without establishing a direct connection between the client and server. This experiment focuses on understanding UDP's characteristics and its application in network communication.

## Experiment Procedure:
1. **Setting up the Server:**
   - The server program is executed, which binds to a specific port and starts listening for incoming packets.
   - Upon receiving a packet from a client, the server processes the data and sends back a response (if required).

2. **Setting up the Client:**
   - The client program is executed, which sends packets containing data to the server's IP address and port number.
   - The client may or may not receive a response from the server, depending on the application logic.

3. **Server-Client Communication:**
   - The client sends data packets to the server without establishing a direct connection.
   - The server processes incoming packets and responds accordingly, if necessary.

4. **Termination:**
   - After communication is complete, both the client and server close their respective sockets and terminate the connection.

## Viva Questions:
1. What is UDP (User Datagram Protocol), and how does it differ from TCP (Transmission Control Protocol)?
2. Explain the advantages and disadvantages of UDP compared to TCP.
3. What is the purpose of the checksum field in the UDP header? How does it ensure data integrity?
4. Describe the process of establishing a connection in UDP communication.
5. How does UDP handle packet loss and reordering?
6. Discuss the significance of the connectionless nature of UDP.
7. Explain the role of ports in UDP communication.
8. How does UDP ensure message delivery without acknowledgments or retransmissions?
9. What are the common applications of UDP in networking?
10. Describe the differences in error handling between UDP and TCP.
11. Discuss the impact of packet size on UDP communication.
12. How can you implement reliability and flow control mechanisms in UDP applications?
13. Explain the concept of multicast in UDP communication.
14. How does UDP handle congestion control?
15. Compare and contrast UDP socket programming with TCP socket programming.

