const int capacity = 100; // buffering capacity (buffer = temp. storage)
const int null = 0; // empty (dummy) message;

void producer(){

    // using blocking receive & non blocking send

    message pmsg; // creating pmsg for mayproduce

    while (true)
    {
        receive(mayproduce, pmsg);
        pmsg = produce();
        send(mayconsume,pmsg);
    }   
}

void consumer(){

    // using blocking receive & non blocking send

    message cmsg; // creating cmsg for mayconsume

    while (true)
    {
        receive(mayconsume, cmsg);
        consume(cmsg);
        send(mayproduce,null);
    }   
}


void main(){

    // creating 2 mailboxes each for producer and consumer
    create_mailbox(mayproduce);
    create_mailbox(mayconsume);

    // filling mayproduce with dummy messages equal to capacity of buffer
    for(int i=1; i <=capacity; i++){
        send(mayproduce, null);
    }

    parbegin(producer,consumer);
}

