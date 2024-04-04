# Network Lab - Experiment: Sliding Window Protocol

## Objective:
The objective of this experiment is to understand the principles and implementations of the sliding window protocol in computer networks. This includes exploring three variations: Stop-and-Wait, Go-Back-N, and Selective Repeat.

## Experiment Overview:
In this experiment, we explore the sliding window protocol, which is used for reliable data transfer in computer networks. The sliding window protocol allows for efficient utilization of network resources by allowing multiple packets to be in transit simultaneously.

## Experiment Procedure:
1. **Stop-and-Wait Protocol:**
   - Implement the stop-and-wait protocol, where the sender sends one packet and waits for an acknowledgment from the receiver before sending the next packet.

2. **Go-Back-N Protocol:**
   - Implement the Go-Back-N protocol, where the sender can transmit multiple packets before receiving acknowledgments from the receiver. However, if an acknowledgment for a packet is not received within a specified timeout period, the sender retransmits all packets starting from the lost packet.

3. **Selective Repeat Protocol:**
   - Implement the Selective Repeat protocol, where the sender can transmit multiple packets before receiving acknowledgments from the receiver. In this protocol, the receiver individually acknowledges each packet, allowing the sender to retransmit only the lost packets.

4. **Performance Evaluation:**
   - Evaluate the performance of each protocol in terms of throughput, efficiency, and reliability under different network conditions and window sizes.

## Viva Questions:
1. What is the sliding window protocol, and what problem does it solve in computer networks?
2. Explain the concept of flow control in the sliding window protocol.
3. What is the difference between Stop-and-Wait, Go-Back-N, and Selective Repeat protocols?
4. How does the Stop-and-Wait protocol work? Discuss its advantages and limitations.
5. Describe the operation of the Go-Back-N protocol. What is the significance of the window size in this protocol?
6. How does the Selective Repeat protocol differ from Go-Back-N? Discuss its advantages and limitations.
7. What are the key parameters affecting the performance of the sliding window protocol?
8. Explain the concept of acknowledgment and acknowledgment number in sliding window protocols.
9. How does the sender handle timeouts and retransmissions in Go-Back-N and Selective Repeat protocols?
10. Discuss the impact of window size on the efficiency and reliability of the sliding window protocol.
11. What are the common scenarios in which Go-Back-N outperforms Selective Repeat, and vice versa?
12. Explain the role of sequence numbers in the sliding window protocol.
13. Discuss the mechanisms used for error detection and correction in sliding window protocols.
14. How does the sliding window protocol handle out-of-order packets and packet loss?
15. Compare and contrast the performance of Stop-and-Wait, Go-Back-N, and Selective Repeat protocols under various network conditions.
