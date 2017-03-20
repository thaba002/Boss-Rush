#include <avr/io.h>
#include <util/delay.h>
#include "hero.c"
#include "nokia5110.h"
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks

void TimerOn() {
	// AVR timer/counter controller register TCCR1
	TCCR1B = 0x0B;// bit3 = 0: CTC mode (clear timer on compare)
	// bit2bit1bit0=011: pre-scaler /64
	// 00001011: 0x0B
	// SO, 8 MHz clock or 8,000,000 /64 = 125,000 ticks/s
	// Thus, TCNT1 register will count at 125,000 ticks/s

	// AVR output compare register OCR1A.
	OCR1A = 125;	// Timer interrupt will be generated when TCNT1==OCR1A
	// We want a 1 ms tick. 0.001 s * 125,000 ticks/s = 125
	// So when TCNT1 register equals 125,
	// 1 ms has passed. Thus, we compare to 125.
	// AVR timer interrupt mask register
	TIMSK1 = 0x02; // bit1: OCIE1A -- enables compare match interrupt

	//Initialize avr counter
	TCNT1=0;

	_avr_timer_cntcurr = _avr_timer_M;
	// TimerISR will be called every _avr_timer_cntcurr milliseconds

	//Enable global interrupts
	SREG |= 0x80; // 0x80: 1000000
}

void TimerOff() {
	TCCR1B = 0x00; // bit3bit1bit0=000: timer off
}

void TimerISR() {
	TimerFlag = 1;
}

// In our approach, the C programmer does not touch this ISR, but rather TimerISR()
ISR(TIMER1_COMPA_vect) {
	// CPU automatically calls when TCNT1 == OCR1 (every 1 ms per TimerOn settings)
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0) { // results in a more efficient compare
		TimerISR(); // Call the ISR that the user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

// Set TimerISR() to tick every M ms
void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

unsigned char lvl1_health=0x03;
unsigned char lvl1_attack=0x01;
unsigned char lvl1_x1=74;
unsigned char lvl1_x2=75;
unsigned char lvl1_x3=76;
unsigned char lvl1_x4=77;
unsigned char lvl1_x5=78;
unsigned char lvl1_x6=79;
unsigned char lvl1_x7=80;
unsigned char lvl1_x8=81;
unsigned char lvl1_y1=40;
unsigned char lvl1_y2=41;
unsigned char lvl1_y3=42;
unsigned char lvl1_y4=43;
unsigned char lvl1_y5=44;
unsigned char lvl1_y6=45;
unsigned char lvl1_y7=46;
unsigned char lvl1_y8=47;
unsigned char lvl1_y9=48;
unsigned char distance_left=0x00;
unsigned char distance_right=0x00;
unsigned char punch1=0x00;
unsigned char punch2=0x00;
unsigned char punch3=0x00;
unsigned char punch4=0x00;
unsigned char punch5=0x00;
unsigned char punch6=0x00;
unsigned char lvl1_cooldown=5;


enum Lvl1_States {lvl1_start, lvl1_build_boss, lvl1_boss_move,lvl1_boss_attack } lvl1_state;

void lvl1_boss(){
	nokia_lcd_clear();
	nokia_lcd_set_cursor(77,3);
	if(lvl1_health==0x03) {
		nokia_lcd_write_string("3",1);
	}
	else if(lvl1_health==0x02) {
		nokia_lcd_write_string("2",1);
	}
	else if(lvl1_health==0x01) {
		nokia_lcd_write_string("1",1);
	}
	nokia_lcd_set_pixel(lvl1_x1,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x1,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x1,lvl1_y5,0x01);
	nokia_lcd_set_pixel(lvl1_x2,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x2,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x2,lvl1_y7,0x01);
	nokia_lcd_set_pixel(lvl1_x2,lvl1_y8,0x01);
	nokia_lcd_set_pixel(lvl1_x2,lvl1_y9,0x01);
	nokia_lcd_set_pixel(lvl1_x3,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x3,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x3,lvl1_y7,0x01);
	nokia_lcd_set_pixel(lvl1_x3,lvl1_y8,0x01);
	nokia_lcd_set_pixel(lvl1_x3,lvl1_y9,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y1,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y2,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y5,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y6,0x01);
	nokia_lcd_set_pixel(lvl1_x4,lvl1_y7,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y1,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y2,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y5,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y6,0x01);
	nokia_lcd_set_pixel(lvl1_x5,lvl1_y7,0x01);
	nokia_lcd_set_pixel(lvl1_x6,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x6,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x6,lvl1_y7,0x01);
	nokia_lcd_set_pixel(lvl1_x6,lvl1_y8,0x01);
	nokia_lcd_set_pixel(lvl1_x6,lvl1_y9,0x01);
	nokia_lcd_set_pixel(lvl1_x7,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x7,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x7,lvl1_y7,0x01);
	nokia_lcd_set_pixel(lvl1_x7,lvl1_y8,0x01);
	nokia_lcd_set_pixel(lvl1_x7,lvl1_y9,0x01);
	nokia_lcd_set_pixel(lvl1_x8,lvl1_y3,0x01);
	nokia_lcd_set_pixel(lvl1_x8,lvl1_y4,0x01);
	nokia_lcd_set_pixel(lvl1_x8,lvl1_y5,0x01);
	if(lvl1_state==lvl1_boss_attack){
		
		nokia_lcd_set_pixel(punch1,lvl1_y4,0x01);
		nokia_lcd_set_pixel(punch2,lvl1_y5,0x01);
		nokia_lcd_set_pixel(punch3,lvl1_y4,0x01);
		nokia_lcd_set_pixel(punch4,lvl1_y5,0x01);
		nokia_lcd_set_pixel(punch5,lvl1_y4,0x01);
		nokia_lcd_set_pixel(punch6,lvl1_y5,0x01);
		hero_health--;
	}
	else{
		nokia_lcd_set_pixel(punch1,lvl1_y4,0x00);
		nokia_lcd_set_pixel(punch2,lvl1_y5,0x00);
		nokia_lcd_set_pixel(punch3,lvl1_y4,0x00);
		nokia_lcd_set_pixel(punch4,lvl1_y5,0x00);
		nokia_lcd_set_pixel(punch5,lvl1_y4,0x00);
		nokia_lcd_set_pixel(punch6,lvl1_y5,0x00);
	}
	nokia_lcd_render();
}
	
void lvl1_sm() {
	switch(lvl1_state){
		case lvl1_start:
			lvl1_state=lvl1_build_boss;
			break;
		
		case lvl1_build_boss:
			lvl1_state=lvl1_boss_move;
			break;
			
		case lvl1_boss_move:
			distance_left=lvl1_x4-x3;
			distance_right=x3-lvl1_x5;
			if(lvl1_x4>x3 && distance_left <= 8 && distance_left>0 && y5==45 && lvl1_cooldown==5) {
				lvl1_state=lvl1_boss_attack;
			}
			
			else if(lvl1_x5 < x3 && distance_right<=8 && distance_right>0 && y5==45 && lvl1_cooldown==5){
				lvl1_state=lvl1_boss_attack;	
			}
			else{
				lvl1_state=lvl1_boss_move;
			}
			break;
		
		case lvl1_boss_attack:
			lvl1_state=lvl1_boss_move;
			break;
			
		default:
			lvl1_state=lvl1_start;
			break;	
	}
	
	switch(lvl1_state){
		case lvl1_build_boss:
			lvl1_boss();
			break;
			
		case lvl1_boss_move:
			if(lvl1_cooldown < 5) {
				lvl1_cooldown++;
			}
			if(x5 < lvl1_x1){
				lvl1_x1=lvl1_x1-2;
				lvl1_x2=lvl1_x2-2;
				lvl1_x3=lvl1_x3-2;					
				lvl1_x4=lvl1_x4-2;
				lvl1_x5=lvl1_x5-2;
				lvl1_x6=lvl1_x6-2;
				lvl1_x7=lvl1_x7-2;
				lvl1_x8=lvl1_x8-2;
				lvl1_boss();
			}
			else if(x1> lvl1_x8){
				lvl1_x1=lvl1_x1+2;
				lvl1_x2=lvl1_x2+2;
				lvl1_x3=lvl1_x3+2;
				lvl1_x4=lvl1_x4+2;
				lvl1_x5=lvl1_x5+2;
				lvl1_x6=lvl1_x6+2;
				lvl1_x7=lvl1_x7+2;
				lvl1_x8=lvl1_x8+2;
				lvl1_boss();
			}
			
			lvl1_boss();
			break;
		
		case lvl1_boss_attack:
			lvl1_cooldown=0;
			if(distance_left<=8 && distance_left>0){
				punch1=lvl1_x1-1;
				punch2=lvl1_x1-1;
				punch3=lvl1_x1-2;
				punch4=lvl1_x1-2;
				punch5=lvl1_x1-3;
				punch6=lvl1_x1-3;
				lvl1_boss();
			}
			else{
				punch1=lvl1_x8+1;
				punch2=lvl1_x8+1;
				punch3=lvl1_x8+2;
				punch4=lvl1_x8+2;
				punch5=lvl1_x8+3;
				punch6=lvl1_x8+3;
				lvl1_boss();
			}
			break;	
			
			default:
			break;
	}
}



void lvl1_main(){
	lvl1_state=lvl1_start;
	TimerSet(50);
	TimerOn();
	while(1){
		if(lvl1_health==0x00 || hero_health==0x00) {
			break;
		}
		lvl1_sm();
		hero_sm();
	
		while (!TimerFlag);	// Wait 1 sec
		TimerFlag = 0;
	}
	if(lvl1_health==0x00){
		nokia_lcd_clear();
		while(button_hero != 0x0C){
			button_hero=~PINA & 0x0C;
			nokia_lcd_set_cursor(5,10);
			nokia_lcd_write_string("YOU WIN",2);
			nokia_lcd_set_cursor(5,25);
			nokia_lcd_write_string("Press buttons 1 and 2 to continue",1);
			nokia_lcd_render();
		}
	}
	else if(hero_health==0x00){
		nokia_lcd_clear();
		while(button_hero != 0x0C){
			button_hero=~PINA & 0x0C;
			nokia_lcd_set_cursor(5,10);
			nokia_lcd_write_string("YOU LOSE",1);
			nokia_lcd_set_cursor(5,25);
			nokia_lcd_write_string("Press buttons 1 and 2 to continue",1);
			nokia_lcd_render();
		}
	}
	TimerOff();
	return;
}