// dummy code for mutual exclusion, this code won't run

const int n = 10; // number of processes

void P(int i){
    
   message msg; // instantiating a message (will have to use library for that)


    while (true)
    {
        receive(box, msg); // receive prem. to check whether mailbox is empty

        // critical section (will run if this process gets the message)

        send(box, msg); // after running critical section send message to mailbox so other blocked processes can run

        // rest of the code can be written here
    }
}

void main(){
    create_mailbox (box); // creating a mailbox named box (some library will be used)
    
    send(box,null); // initializing the mailbox with null

    parbegin(P(1),P(2),P(3),P(4),P(5),P(6),P(7),P(8),P(9),P(10));
}