#include "mbed.h"
using namespace std::chrono;
DigitalOut led(PC_9);
Ticker flipper;

void blink(){
    led = !led;
}

int main(){
    flipper.attach(&blink, 500ms);

}