# Network Direct FAQ

1.	Suppose a peer initiates a sequence of messages to the receiver. Send-1, Send-2, ... . The documentation says that if there is a single completion queue then the sender it is guaranteed that the corresponding completions will occur in the same order. Great, everything makes sense to the sender. Of course, prior to sender initiating the sends the receiver has initiated a matching number of Receives in anticipation of the incoming message sequence. As the messages come in, the receiver will pick up Receive completions off the receiver’s completion queue. Now the question – “Will the receiver get the messages in the same sequence that was send by the sender?” In other words is the integrity of a Send sequence guaranteed? If not, it implies that the only way to be sure is to have (Send, Receive, Send, Recieve, ...) type sequences. Am I confused?

[JJ]: Yes, receiver will get the messages in the same order as it was sent by the sender.
InfiniBand supports UD queue pair (not exposed through ND interfaces), where receivers can get out-of-order receives.
