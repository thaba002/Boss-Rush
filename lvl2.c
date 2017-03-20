#include <avr/io.h>
#include <util/delay.h>

#include "nokia5110.h"
#include <avr/interrupt.h>

unsigned char lvl2_health=0x04;
unsigned char lvl2_x1=70;
unsigned char lvl2_x2=71;
unsigned char lvl2_x3=72;
unsigned char lvl2_x4=73;
unsigned char lvl2_x5=74;
unsigned char lvl2_x6=75;
unsigned char lvl2_x7=76;
unsigned char lvl2_x8=77;
unsigned char lvl2_x9=78;
unsigned char lvl2_x10=79;
unsigned char lvl2_x11=80;
unsigned char lvl2_y0=37;
unsigned char lvl2_y1=38;
unsigned char lvl2_y2=39;
unsigned char lvl2_y3=40;
unsigned char lvl2_y4=41;
unsigned char lvl2_y5=42;
unsigned char lvl2_y6=43;
unsigned char lvl2_y7=44;
unsigned char lvl2_y8=45;
unsigned char lvl2_y9=46;
unsigned char lvl2_y10=47;
unsigned char lvl2_y11=48;
unsigned char lvl2_distance_right;
unsigned char lvl2_distance_left;
unsigned char punch2_1;
unsigned char punch2_2;
unsigned char punch2_3;
unsigned char punch2_4;
unsigned char punch2_5;
unsigned char punch2_6;
unsigned char punch2_7;
unsigned char punch2_8;
unsigned char punch2_9;
unsigned char punch2_10;
unsigned char punch2_11;
unsigned char punch2_12;
unsigned char punch_cooldown=5;
unsigned char grapple_cooldown=25;
unsigned char grapple1;
unsigned char grapple2;
unsigned char grapple3;
unsigned char grapple4;
unsigned char grapple5;
unsigned char grapple6;
unsigned char grapple7;
unsigned char grapple8;
unsigned char grapple9;
unsigned char grapple10;

enum Lvl2_States {lvl2_start,lvl2_build_boss,lvl2_boss_move, lvl2_boss_attack, lvl2_grapple} lvl2_state;
	
void lvl2_boss(){
	nokia_lcd_clear();
	nokia_lcd_set_cursor(77,3);
	if(lvl2_health==0x04){
		nokia_lcd_write_string("4",1);
	}
	else if(lvl2_health==0x03) {
		nokia_lcd_write_string("3",1);
	}
	else if(lvl2_health==0x02) {
		nokia_lcd_write_string("2",1);
	}
	else if(lvl2_health==0x01) {
		nokia_lcd_write_string("1",1);
	}
	nokia_lcd_set_pixel(lvl2_x1,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x1,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x1,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y9,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y10,0x01);
	nokia_lcd_set_pixel(lvl2_x2,lvl2_y11,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y9,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y10,0x01);
	nokia_lcd_set_pixel(lvl2_x3,lvl2_y11,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y9,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y10,0x01);
	nokia_lcd_set_pixel(lvl2_x4,lvl2_y11,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y0,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y1,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y2,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y3,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y7,0x01);
	nokia_lcd_set_pixel(lvl2_x5,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y2,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y3,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y7,0x01);
	nokia_lcd_set_pixel(lvl2_x6,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y0,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y1,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y2,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y3,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y7,0x01);
	nokia_lcd_set_pixel(lvl2_x7,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y9,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y10,0x01);
	nokia_lcd_set_pixel(lvl2_x8,lvl2_y11,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y9,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y10,0x01);
	nokia_lcd_set_pixel(lvl2_x9,lvl2_y11,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y6,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y8,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y9,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y10,0x01);
	nokia_lcd_set_pixel(lvl2_x10,lvl2_y11,0x01);
	nokia_lcd_set_pixel(lvl2_x11,lvl2_y4,0x01);
	nokia_lcd_set_pixel(lvl2_x11,lvl2_y5,0x01);
	nokia_lcd_set_pixel(lvl2_x11,lvl2_y6,0x01);
	if(lvl2_state==lvl2_boss_attack){
		
		nokia_lcd_set_pixel(punch2_1,lvl2_y5,0x01);
		nokia_lcd_set_pixel(punch2_2,lvl2_y6,0x01);
		nokia_lcd_set_pixel(punch2_3,lvl2_y5,0x01);
		nokia_lcd_set_pixel(punch2_4,lvl2_y6,0x01);
		nokia_lcd_set_pixel(punch2_5,lvl2_y7,0x01);
		nokia_lcd_set_pixel(punch2_6,lvl2_y5,0x01);
		nokia_lcd_set_pixel(punch2_7,lvl2_y6,0x01);
		nokia_lcd_set_pixel(punch2_8,lvl2_y7,0x01);
		nokia_lcd_set_pixel(punch2_9,lvl2_y5,0x01);
		nokia_lcd_set_pixel(punch2_10,lvl2_y6,0x01);
		nokia_lcd_set_pixel(punch2_11,lvl2_y7,0x01);
		nokia_lcd_set_pixel(punch2_12,lvl2_y4,0x01);
		
		
		hero_health--;
	}
	else if(lvl2_state==lvl2_grapple){
		nokia_lcd_set_pixel(grapple1,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple2,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple3,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple4,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple5,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple6,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple7,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple8,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple9,lvl2_y6,0x01);
		nokia_lcd_set_pixel(grapple10,lvl2_y6,0x01);
		
	}
	else{
		nokia_lcd_set_pixel(punch2_1,lvl2_y5,0x00);
		nokia_lcd_set_pixel(punch2_2,lvl2_y6,0x00);
		nokia_lcd_set_pixel(punch2_3,lvl2_y5,0x00);
		nokia_lcd_set_pixel(punch2_4,lvl2_y6,0x00);
		nokia_lcd_set_pixel(punch2_5,lvl2_y7,0x00);
		nokia_lcd_set_pixel(punch2_6,lvl2_y5,0x00);
		nokia_lcd_set_pixel(punch2_7,lvl2_y6,0x00);
		nokia_lcd_set_pixel(punch2_8,lvl2_y7,0x00);
		nokia_lcd_set_pixel(punch2_9,lvl2_y5,0x00);
		nokia_lcd_set_pixel(punch2_10,lvl2_y6,0x00);
		nokia_lcd_set_pixel(punch2_11,lvl2_y7,0x00);
		nokia_lcd_set_pixel(punch2_12,lvl2_y4,0x00);
		nokia_lcd_set_pixel(grapple1,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple2,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple3,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple4,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple5,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple6,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple7,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple8,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple9,lvl2_y6,0x00);
		nokia_lcd_set_pixel(grapple10,lvl2_y6,0x00);
	}
	nokia_lcd_render();
}
void lvl2_sm(){
	switch(lvl2_state){
		case lvl2_start:
		lvl2_state=lvl2_build_boss;
		break;
		
		case lvl2_build_boss:
		lvl2_state=lvl2_boss_move;
		break;
		
		case lvl2_boss_move:
		lvl2_distance_left=lvl2_x5-x3;
		lvl2_distance_right=x3-lvl2_x7;
		if(lvl2_x5>x3 && lvl2_distance_left <= 10 && lvl2_distance_left>0 && y5==45 && punch_cooldown==5) {
			lvl2_state=lvl2_boss_attack;
		}
		
		else if(lvl2_x7 < x3 && lvl2_distance_right<=10 && lvl2_distance_right>0 && y5==45 && punch_cooldown==5){
			lvl2_state=lvl2_boss_attack;
		}
		else if(lvl2_x5>x3 && lvl2_distance_left <= 25 && lvl2_distance_left>10 && y5==45 && grapple_cooldown==25) {
			lvl2_state=lvl2_grapple;
		}
		
		else if(lvl2_x7 < x3 && lvl2_distance_right<=25 && lvl2_distance_right>10 && y5==45 && grapple_cooldown==25){
			lvl2_state=lvl2_grapple;
		}
		else{
			lvl2_state=lvl2_boss_move;
		}
		break;
		
		case lvl2_boss_attack:
		lvl2_state=lvl2_boss_move;
		break;
		
		case lvl2_grapple:
		lvl2_state=lvl2_boss_move;
		break;
		
		default:
		lvl2_state=lvl2_start;
		break;
	}
	switch(lvl2_state){
		case lvl2_build_boss:
		lvl2_boss();
		break;
		
		case lvl2_boss_move:
		if(punch_cooldown<5){
			punch_cooldown++;
		}
		if(grapple_cooldown<25){
			grapple_cooldown++;
		}
		if(x5 < lvl2_x1){
			lvl2_x1=lvl2_x1-2;
			lvl2_x2=lvl2_x2-2;
			lvl2_x3=lvl2_x3-2;
			lvl2_x4=lvl2_x4-2;
			lvl2_x5=lvl2_x5-2;
			lvl2_x6=lvl2_x6-2;
			lvl2_x7=lvl2_x7-2;
			lvl2_x8=lvl2_x8-2;
			lvl2_x9=lvl2_x9-2;
			lvl2_x10=lvl2_x10-2;
			lvl2_x11=lvl2_x11-2;
			
		}
		else if(x1> lvl2_x11){
			lvl2_x1=lvl2_x1+2;
			lvl2_x2=lvl2_x2+2;
			lvl2_x3=lvl2_x3+2;
			lvl2_x4=lvl2_x4+2;
			lvl2_x5=lvl2_x5+2;
			lvl2_x6=lvl2_x6+2;
			lvl2_x7=lvl2_x7+2;
			lvl2_x8=lvl2_x8+2;
			lvl2_x9=lvl2_x9+2;
			lvl2_x10=lvl2_x10+2;
			lvl2_x11=lvl2_x11+2;
			
		}
		lvl2_boss();
		break;
		
		case lvl2_boss_attack:
		punch_cooldown=0;
		if(lvl2_distance_left<=10 && lvl2_distance_left>0){
			punch2_1=lvl2_x1-1;
			punch2_2=lvl2_x1-1;
			punch2_3=lvl2_x1-2;
			punch2_4=lvl2_x1-2;
			punch2_5=lvl2_x1-2;
			punch2_6=lvl2_x1-3;
			punch2_7=lvl2_x1-3;
			punch2_8=lvl2_x1-3;
			punch2_9=lvl2_x1-4;
			punch2_10=lvl2_x1-4;
			punch2_11=lvl2_x1-4;
			punch2_12=lvl2_x1-4;
		}
		else{
			punch2_1=lvl2_x11+1;
			punch2_2=lvl2_x11+1;
			punch2_3=lvl2_x11+2;
			punch2_4=lvl2_x11+2;
			punch2_5=lvl2_x11+2;
			punch2_6=lvl2_x11+3;
			punch2_7=lvl2_x11+3;
			punch2_8=lvl2_x11+3;
			punch2_9=lvl2_x11+4;
			punch2_10=lvl2_x11+4;
			punch2_11=lvl2_x11+4;
			punch2_12=lvl2_x11+4;
		}
		lvl2_boss();
		break;
		
		case lvl2_grapple:
			grapple_cooldown=0;
			
			if(lvl2_distance_left<=25 && lvl2_distance_left>10){
				grapple1=lvl2_x1-2;
				grapple2=lvl2_x1-4;
				grapple3=lvl2_x1-6;
				grapple4=lvl2_x1-8;
				grapple5=lvl2_x1-10;
				grapple6=lvl2_x1-12;
				grapple7=lvl2_x1-14;
				grapple8=lvl2_x1-16;
				grapple9=lvl2_x1-18;
				grapple10=lvl2_x1-21;
				lvl2_boss();
				if(grapple10<=x3 || grapple8<x3 || grapple6<x3 || grapple4<x3 && y5==45){
					
					x1=grapple1-2;
					x2=grapple1-1;
					x3=grapple1;
					x4=grapple1+1;
					x5=grapple1+2;
					swordx1=x5;
					swordx2=x5;
					swordx3=x5;
					swordx4=x5;
				}
				
			}
			else{
			
				grapple1=lvl2_x11+2;
				grapple2=lvl2_x11+4;
				grapple3=lvl2_x11+6;
				grapple4=lvl2_x11+8;
				grapple5=lvl2_x11+10;
				grapple6=lvl2_x11+12;
				grapple7=lvl2_x11+14;
				grapple8=lvl2_x11+16;
				grapple9=lvl2_x11+18;
				grapple10=lvl2_x11+21;
				lvl2_boss();
				if(grapple10>=x3 || grapple8>x3 || grapple6>x3 || grapple4>x3 && y5==45){
				
					x1=grapple1-2;
					x2=grapple1-1;
					x3=grapple1;
					x4=grapple1+1;
					x5=grapple1+2;
					swordx1=x1;
					swordx2=x1;
					swordx3=x1;
					swordx4=x1;
				}
				
			}
			buid_hero_function();
			lvl2_boss();
			break;
		default:
		break;
	}
}
void lvl2_main(){
	lvl2_state=lvl2_start;
	TimerSet(50);
	TimerOn();
	while(1){
		if(lvl2_health==0x00 || hero_health==0x00) {
			break;
		}
		lvl2_sm();
		hero_sm();
		
		while (!TimerFlag);	// Wait 1 sec
		TimerFlag = 0;

		
	}
	if(lvl2_health==0x00){
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
	return;
}