#include "mbed.h"
using namespace std::chrono;
DigitalOut led(PC_9);
/*Ticker flipper;

void blink(){
    led = !led;
}

int main(){
    flipper.attach(&blink, 500ms);

}*/

EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;
Ticker ledTicker;
using namespace std::chrono;
void blink(){
    led = !led;
}

int main(){
    t.start(callback(&queue, &EventQueue::dispatch_forever));
    
    ledTicker.attach(queue.event(&blink), 500ms);
    /*queue.call_every(500ms, blink);
    queue.dispatch();*/
    //while(1);
}