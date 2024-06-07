# server.c

```
socket created successfully
Bind done
server listening ..
Frame 0 received
Acknowledgement sent:0
Frame 1 received
Acknowledgement sent:1
Frame 2 not received
Frame 3 discarded
 acknoledgement sent:1
Frame 4 discarded
 acknoledgement sent:1
Frame 2 received
Acknowledgement sent:2
Frame 3 received
Acknowledgement sent:3
Frame 4 received
Acknowledgement sent:4
Frame 5 received
Acknowledgement sent:5
Frame 6 not received
Frame 7 discarded
 acknoledgement sent:5
Frame 8 discarded
 acknoledgement sent:5
Frame 6 not received
Frame 7 discarded
 acknoledgement sent:5
Frame 8 discarded
 acknoledgement sent:5
Frame 6 received
Acknowledgement sent:6
Frame 7 received
Acknowledgement sent:7
Frame 8 received
Acknowledgement sent:8
Frame 9 received
Acknowledgement sent:9
Frame 0 discarded
 acknoledgement sent:9
Frame 0 discarded
 acknoledgement sent:9
```


# clent.c

```
Socket created
Connected successfully
Enter the number of frames: 10
Enter the window size: 3
Frame 0 sent
Frame 1 sent
Frame 2 sent
Ack received 0
Frame 3 sent
Ack received 1
Frame 4 sent
Ack not received for 1
RESENDING ...
Frame 2 sent
Frame 3 sent
Frame 4 sent
Ack received 2
Frame 5 sent
Ack received 3
Frame 6 sent
Ack received 4
Frame 7 sent
Ack received 5
Frame 8 sent
Ack not received for 5
RESENDING ...
Frame 6 sent
Frame 7 sent
Frame 8 sent
Ack not received for 5
RESENDING ...
Frame 6 sent
Frame 7 sent
Frame 8 sent
Ack received 6
Frame 9 sent
Ack received 7
Ack received 8
Ack received 9
EXIT
```
