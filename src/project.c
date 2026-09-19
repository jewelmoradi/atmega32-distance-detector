#include <mega32.h>
#include <delay.h>
#include <alcd.h>  


#define TRIGGER_PIN PORTB.0
#define ECHO_PIN PINB.1


unsigned int distance = 0;

void init(){
    DDRB.0 = 1;
    DDRB.1 =0;
    DDRC = 0XFF;
    PORTC = 0X00;
}

void send_trigger_pulse() {
    TRIGGER_PIN = 1;
    delay_us(10);
    TRIGGER_PIN = 0;
}


unsigned int measure_distance() {
    unsigned long pulse_duration = 0;
    unsigned int distance  ;
    
    send_trigger_pulse();

    while (ECHO_PIN == 0);


    while (ECHO_PIN == 1) {
        pulse_duration += 1;
        delay_us(1); 
        if (pulse_duration > 60000) break;
    }

    distance = (pulse_duration * 343) / 2000;
    return distance;
}


void main() {

    init();
    lcd_init(16); 

    while (1) {
        
        distance = measure_distance();

        
        lcd_clear();
        lcd_gotoxy(0, 0);  
        lcd_printf("Distance: %d cm", distance);
        
        if (distance > 20) {
            PORTC.0 = 1;
            delay_ms (1000);
            PORTC.0 = 0 ;
        } else if (distance >= 10){
            PORTC.0 = 1;  
            delay_ms(333);  
            PORTC.0 = 0 ;
        } else {
            PORTC.0 = 1;  
            delay_ms(200);
            PORTC.0 = 0 ;
        }
    }
}
