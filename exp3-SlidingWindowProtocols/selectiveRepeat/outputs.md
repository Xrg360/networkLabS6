# server.c

Socket created
Bind done
Server listening ..
Server acccept the client
acceptedEnter the window size of the server: 2
Frame 1 received ackknowledgement sent for 1
Frame 3 received instead of 2
 sending NAK -2Frame 2 received ackknowledgement sent for 3
Frame 4 received ackknowledgement sent for 4
Frame 6 received instead of 5
 sending NAK -5Frame 5 received ackknowledgement sent for 6



 # client.c

 Socket created
Connected to server
Enter the number of frames to be sent
6
Enter the window size
2
Frame 1 sent
Frame 2 sent
Ack not received for 1
RESENDING ...
Ack received 1
Frame 3 sent
Ack not received for -2
RESENDING ...
Ack not received for 2
RESENDING ...
Ack received 3
Frame 4 sent
Frame 5 sent
Ack not received for 4
RESENDING ...
Ack received 4
Frame 6 sent
Ack not received for -5
RESENDING ...
Ack not received for 5
RESENDING ...
Ack received 6
EXIT