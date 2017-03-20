#include <avr/io.h>
#include <util/delay.h>

#include "nokia5110.h"
#include <avr/interrupt.h>

unsigned char lvl3_health=0x05;
unsigned char lvl3_x1=70;
unsigned char lvl3_x2=71;
unsigned char lvl3_x3=72;
unsigned char lvl3_x4=73;
unsigned char lvl3_x5=74;
unsigned char lvl3_x6=75;
unsigned char lvl3_x7=76;
unsigned char lvl3_x8=77;
unsigned char lvl3_x9=78;
unsigned char lvl3_y1=38;
unsigned char lvl3_y2=39;
unsigned char lvl3_y3=40;
unsigned char lvl3_y4=41;
unsigned char lvl3_y5=42;
unsigned char lvl3_y6=43;
unsigned char lvl3_y7=44;
unsigned char lvl3_y8=45;
unsigned char lvl3_y9=46;
unsigned char lvl3_y10=47;
unsigned char lvl3_y11=48;
unsigned char lvl3_distance_right;
unsigned char lvl3_distance_left;
unsigned char sword3_x1=70;
unsigned char sword3_x2=70;
unsigned char sword3_x3=70;
unsigned char sword3_x4=70;
unsigned char sword3_x5=70;
unsigned char sword3_x6=70;
unsigned char sword3_x7=70;
unsigned char sword3_x8=70;
unsigned char sword3_y1=40;
unsigned char sword3_y2=39;
unsigned char sword3_y3=38;
unsigned char sword3_y4=37;
unsigned char sword3_y5=36;
unsigned char sword3_y6=35;
unsigned char sword3_y7=34;
unsigned char sword3_y8=33;
unsigned char lvl3_sword_cooldown=0x05;
unsigned char grapple_cd=25;
unsigned char grapple3_1;
unsigned char grapple3_2;
unsigned char grapple3_3;
unsigned char grapple3_4;
unsigned char grapple3_5;
unsigned char grapple3_6;
unsigned char grapple3_7;
unsigned char grapple3_8;
unsigned char grapple3_9;
unsigned char grapple3_10;
unsigned char grapple3_11;
unsigned char grapple3_12;
unsigned char up_cd=20;
enum Lvl3_States {lvl3_start,lvl3_build_boss,lvl3_boss_move, lvl3_boss_attack, lvl3_grapple,lvl3_up_attack} lvl3_state;

void lvl3_boss(){
	nokia_lcd_clear();
	nokia_lcd_set_cursor(77,3);
	if(lvl3_health==0x05){
		nokia_lcd_write_string("5",1);
	}
	else if(lvl3_health==0x04){
		nokia_lcd_write_string("4",1);
	}
	else if(lvl3_health==0x03) {
		nokia_lcd_write_string("3",1);
	}
	else if(lvl3_health==0x02) {
		nokia_lcd_write_string("2",1);
	}
	else if(lvl3_health==0x01) {
		nokia_lcd_write_string("1",1);
	}
	nokia_lcd_render();
	nokia_lcd_set_pixel(lvl3_x1,lvl3_y11,0x01);
	nokia_lcd_set_pixel(lvl3_x1,lvl3_y10,0x01);
	nokia_lcd_set_pixel(lvl3_x1,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x1,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x1,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x2,lvl3_y11,0x01);
	nokia_lcd_set_pixel(lvl3_x2,lvl3_y10,0x01);
	nokia_lcd_set_pixel(lvl3_x2,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x2,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x2,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y11,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y10,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x3,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y8,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y7,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y6,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y5,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y2,0x01);
	nokia_lcd_set_pixel(lvl3_x4,lvl3_y1,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y8,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y7,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y6,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y5,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y2,0x01);
	nokia_lcd_set_pixel(lvl3_x5,lvl3_y1,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y8,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y7,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y6,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y5,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y2,0x01);
	nokia_lcd_set_pixel(lvl3_x6,lvl3_y1,0x01);
	nokia_lcd_set_pixel(lvl3_x7,lvl3_y11,0x01);
	nokia_lcd_set_pixel(lvl3_x7,lvl3_y10,0x01);
	nokia_lcd_set_pixel(lvl3_x7,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x7,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x7,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x8,lvl3_y11,0x01);
	nokia_lcd_set_pixel(lvl3_x8,lvl3_y10,0x01);
	nokia_lcd_set_pixel(lvl3_x8,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x8,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x8,lvl3_y3,0x01);
	nokia_lcd_set_pixel(lvl3_x9,lvl3_y11,0x01);
	nokia_lcd_set_pixel(lvl3_x9,lvl3_y10,0x01);
	nokia_lcd_set_pixel(lvl3_x9,lvl3_y9,0x01);
	nokia_lcd_set_pixel(lvl3_x9,lvl3_y4,0x01);
	nokia_lcd_set_pixel(lvl3_x9,lvl3_y3,0x01);
	nokia_lcd_set_pixel(sword3_x1,sword3_y1,0x01);
	nokia_lcd_set_pixel(sword3_x2,sword3_y2,0x01);
	nokia_lcd_set_pixel(sword3_x3,sword3_y3,0x01);
	nokia_lcd_set_pixel(sword3_x4,sword3_y4,0x01);
	nokia_lcd_set_pixel(sword3_x5,sword3_y5,0x01);
	nokia_lcd_set_pixel(sword3_x6,sword3_y6,0x01);
	nokia_lcd_set_pixel(sword3_x7,sword3_y7,0x01);
	nokia_lcd_set_pixel(sword3_x8,sword3_y8,0x01);
	if(lvl3_state==lvl3_grapple){
		nokia_lcd_set_pixel(grapple3_1,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_2,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_3,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_4,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_5,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_6,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_7,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_8,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_9,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_10,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_11,lvl3_y4,0x01);
		nokia_lcd_set_pixel(grapple3_12,lvl3_y4,0x01);
	}
	else{
		nokia_lcd_set_pixel(grapple3_1,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_2,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_3,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_4,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_5,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_6,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_7,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_8,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_9,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_10,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_11,lvl3_y4,0x00);
		nokia_lcd_set_pixel(grapple3_12,lvl3_y4,0x00);
	}
	nokia_lcd_render();
}
void lvl3_sm(){
	switch(lvl3_state){
		case lvl3_start:
		lvl3_state=lvl3_build_boss;
		break;
		
		case lvl3_build_boss:
		lvl3_state=lvl3_boss_move;
		break;
		
		case lvl3_boss_move:
		lvl3_distance_left=lvl3_x4-x3;
		lvl3_distance_right=x3-lvl3_x6;
		if(lvl3_x4>x3 && lvl3_distance_left <= 11 && lvl3_distance_left>0 && y5==45 && lvl3_sword_cooldown==5) {
			lvl3_state=lvl3_boss_attack;
		}
		
		else if(lvl3_x6 < x3 && lvl3_distance_right<=11 && lvl3_distance_right>0 && y5==45 && lvl3_sword_cooldown==5){
			lvl3_state=lvl3_boss_attack;
		}
		else if(lvl3_x4>x3 && lvl3_distance_left <= 40 && lvl3_distance_left>15 && y5==45 && grapple_cd==25) {
			lvl3_state=lvl3_grapple;
		}
		
		else if(lvl3_x7 < x3 && lvl3_distance_right<=40 && lvl3_distance_right>15 && y5==45 && grapple_cd==25){
			lvl3_state=lvl3_grapple;
		}
		else if((lvl3_x5==x3 || lvl3_x4==x3 || lvl3_x6==x3 ||lvl3_x5==x2 || lvl3_x4==x2 || lvl3_x6==x2 ||lvl3_x5==x4 || lvl3_x4==x4 || lvl3_x6==x4) && y5!=45 && up_cd==20){
			lvl3_state=lvl3_up_attack;
		}
		else {
			lvl3_state=lvl3_boss_move;
		}
		
		break;
		
		case lvl3_boss_attack:
		lvl3_state=lvl3_boss_move;
		break;
		
		case lvl3_grapple:
		lvl3_state=lvl3_boss_move;
		break;
		
		case lvl3_up_attack:
		lvl3_state=lvl3_boss_move;
		break;
		
		default:
		lvl3_state=lvl3_start;
		break;
	}
	switch(lvl3_state){
		case lvl3_build_boss:
		lvl3_boss();
		break;
		
		case lvl3_boss_move:
				if(lvl3_sword_cooldown<5){
					lvl3_sword_cooldown++;
				}
				if(grapple_cd<25){
					grapple_cd++;
				}
				if(up_cd<20){
					up_cd++;
				}
				if(x5 < lvl3_x1){
					if (sword3_x1>lvl3_x4){
						sword3_x1=lvl3_x1;
						sword3_x2=lvl3_x1;
						sword3_x3=lvl3_x1;
						sword3_x4=lvl3_x1;
						sword3_x5=lvl3_x1;
						sword3_x6=lvl3_x1;
						sword3_x7=lvl3_x1;
						sword3_x8=lvl3_x1;
					}
					lvl3_x1=lvl3_x1-2;
					lvl3_x2=lvl3_x2-2;
					lvl3_x3=lvl3_x3-2;
					lvl3_x4=lvl3_x4-2;
					lvl3_x5=lvl3_x5-2;
					lvl3_x6=lvl3_x6-2;
					lvl3_x7=lvl3_x7-2;
					lvl3_x8=lvl3_x8-2;
					lvl3_x9=lvl3_x9-2;
					sword3_x1=sword3_x1-2;
					sword3_x2=sword3_x2-2;
					sword3_x3=sword3_x3-2;
					sword3_x4=sword3_x4-2;
					sword3_x5=sword3_x5-2;
					sword3_x6=sword3_x6-2;
					sword3_x7=sword3_x7-2;
					sword3_x8=sword3_x8-2;
					
				}
				else if(x1> lvl3_x9){
					if (sword3_x1 < lvl3_x6){
						sword3_x1=lvl3_x9;
						sword3_x2=lvl3_x9;
						sword3_x3=lvl3_x9;
						sword3_x4=lvl3_x9;
						sword3_x5=lvl3_x9;
						sword3_x6=lvl3_x9;
						sword3_x7=lvl3_x9;
						sword3_x8=lvl3_x9;
					}
					lvl3_x1=lvl3_x1+2;
					lvl3_x2=lvl3_x2+2;
					lvl3_x3=lvl3_x3+2;
					lvl3_x4=lvl3_x4+2;
					lvl3_x5=lvl3_x5+2;
					lvl3_x6=lvl3_x6+2;
					lvl3_x7=lvl3_x7+2;
					lvl3_x8=lvl3_x8+2;
					lvl3_x9=lvl3_x9+2;
					sword3_x1=sword3_x1+2;
					sword3_x2=sword3_x2+2;
					sword3_x3=sword3_x3+2;
					sword3_x4=sword3_x4+2;
					sword3_x5=sword3_x5+2;
					sword3_x6=sword3_x6+2;
					sword3_x7=sword3_x7+2;
					sword3_x8=sword3_x8+2;
					
					
				}
				lvl3_boss();
		break;
		
		case lvl3_boss_attack: 
			lvl3_sword_cooldown=0;
			if(sword3_x1<lvl3_x4){
				sword3_x1=lvl3_x1-1;
				sword3_x2=lvl3_x1-2;
				sword3_x3=lvl3_x1-3;
				sword3_x4=lvl3_x1-4;
				sword3_x5=lvl3_x1-5;
				sword3_x6=lvl3_x1-6;
				sword3_x7=lvl3_x1-7;
				sword3_x8=lvl3_x1-8;
				sword3_y1=lvl3_y4;
				sword3_y2=lvl3_y4;
				sword3_y3=lvl3_y4;
				sword3_y4=lvl3_y4;
				sword3_y5=lvl3_y4;
				sword3_y6=lvl3_y4;
				sword3_y7=lvl3_y4;
				sword3_y8=lvl3_y4;
				lvl3_boss();
				hero_health--;
				sword3_x1=lvl3_x1;
				sword3_x2=lvl3_x1;
				sword3_x3=lvl3_x1;
				sword3_x4=lvl3_x1;
				sword3_x5=lvl3_x1;
				sword3_x6=lvl3_x1;
				sword3_x7=lvl3_x1;
				sword3_x8=lvl3_x1;
				sword3_y1=40;
				sword3_y2=39;
				sword3_y3=38;
				sword3_y4=37;
				sword3_y5=36;
				sword3_y6=35;
				sword3_y7=34;
				sword3_y8=33;
				lvl3_boss();
			}
			else if(sword3_x1>lvl3_x6) {
				sword3_x1=lvl3_x9+1;
				sword3_x2=lvl3_x9+2;
				sword3_x3=lvl3_x9+3;
				sword3_x4=lvl3_x9+4;
				sword3_x5=lvl3_x9+5;
				sword3_x6=lvl3_x9+6;
				sword3_x7=lvl3_x9+7;
				sword3_x8=lvl3_x9+8;
				sword3_y1=lvl3_y4;
				sword3_y2=lvl3_y4;
				sword3_y3=lvl3_y4;
				sword3_y4=lvl3_y4;
				sword3_y5=lvl3_y4;
				sword3_y6=lvl3_y4;
				sword3_y7=lvl3_y4;
				sword3_y8=lvl3_y4;
				lvl3_boss();
				hero_health--;
				sword3_x1=lvl3_x9;
				sword3_x2=lvl3_x9;
				sword3_x3=lvl3_x9;
				sword3_x4=lvl3_x9;
				sword3_x5=lvl3_x9;
				sword3_x6=lvl3_x9;
				sword3_x7=lvl3_x9;
				sword3_x8=lvl3_x9;
				sword3_y1=40;
				sword3_y2=39;
				sword3_y3=38;
				sword3_y4=37;
				sword3_y5=36;
				sword3_y6=35;
				sword3_y7=34;
				sword3_y8=33;
				lvl3_boss();
			}
		break;
		
		case lvl3_grapple: 
			grapple_cd=0;
			if(lvl3_distance_left<=40 && lvl3_distance_left>15){
				grapple3_1=lvl3_x1-3;
				grapple3_2=lvl3_x1-6;
				grapple3_3=lvl3_x1-9;
				grapple3_4=lvl3_x1-12;
				grapple3_5=lvl3_x1-15;
				grapple3_6=lvl3_x1-18;
				grapple3_7=lvl3_x1-21;
				grapple3_8=lvl3_x1-24;
				grapple3_9=lvl3_x1-27;
				grapple3_10=lvl3_x1-30;
				grapple3_11=lvl3_x1-33;
				grapple3_12=lvl3_x1-38;
				lvl3_boss();
				if(grapple3_12<=x3 || grapple3_9<x3 || grapple3_6<x3 || grapple3_3<x3 && y5==45){
					
					x1=grapple3_1-2;
					x2=grapple3_1-1;
					x3=grapple3_1;
					x4=grapple3_1+1;
					x5=grapple3_1+2;
					swordx1=x5;
					swordx2=x5;
					swordx3=x5;
					swordx4=x5;
					buid_hero_function();
				}
				
			}
			else{
				
				grapple3_1=lvl3_x9+3;
				grapple3_2=lvl3_x9+6;
				grapple3_3=lvl3_x9+9;
				grapple3_4=lvl3_x9+12;
				grapple3_5=lvl3_x9+15;
				grapple3_6=lvl3_x9+18;
				grapple3_7=lvl3_x9+21;
				grapple3_8=lvl3_x9+24;
				grapple3_9=lvl3_x9+27;
				grapple3_10=lvl3_x9+30;
				grapple3_11=lvl3_x9+33;
				grapple3_12=lvl3_x9+38;
				lvl3_boss();
				if(grapple3_12>=x3 || grapple3_9>x3 || grapple3_6>3 || grapple3_3>x3 && y5==45){
					
					x1=grapple3_1-2;
					x2=grapple3_1-1;
					x3=grapple3_1;
					x4=grapple3_1+1;
					x5=grapple3_1+2;
					swordx1=x1;
					swordx2=x1;
					swordx3=x1;
					swordx4=x1;
					buid_hero_function();
				}
				
			}
			buid_hero_function();
			lvl3_boss();
		break;
		
		case lvl3_up_attack: 
			up_cd=0;
			unsigned char stor=sword3_x1;
			sword3_x1=lvl3_x5;
			sword3_x2=lvl3_x5;
			sword3_x3=lvl3_x5;
			sword3_x4=lvl3_x5;
			sword3_x5=lvl3_x5;
			sword3_x6=lvl3_x5;
			sword3_x7=lvl3_x5;
			sword3_x8=lvl3_x5;
			sword3_y1=30;
			sword3_y2=31;
			sword3_y3=32;
			sword3_y4=33;
			sword3_y5=34;
			sword3_y6=35;
			sword3_y7=36;
			sword3_y8=37;
			lvl3_boss();
			hero_health--;
			sword3_x1=stor;
			sword3_x2=stor;
			sword3_x3=stor;
			sword3_x4=stor;
			sword3_x5=stor;
			sword3_x6=stor;
			sword3_x7=stor;
			sword3_x8=stor;
			sword3_y1=40;
			sword3_y2=39;
			sword3_y3=38;
			sword3_y4=37;
			sword3_y5=36;
			sword3_y6=35;
			sword3_y7=34;
			sword3_y8=33;
			lvl3_boss();
			break;
		default:
		break;
	}
}
void lvl3_main(){
	lvl3_state=lvl3_start;
	TimerSet(50);
	TimerOn();
	while(1){
		if(lvl3_health==0x00 || hero_health==0x00) {
			break;
		}
		lvl3_sm();
		hero_sm();
		
		while (!TimerFlag);	// Wait 1 sec
		TimerFlag = 0;

		
	}
	if(lvl3_health==0x00){
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