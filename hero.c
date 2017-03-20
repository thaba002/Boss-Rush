#include <avr/io.h>
#include <util/delay.h>
#include "nokia5110.h"

unsigned char hero_health=0x03;
unsigned char hero_damage=0x01;
unsigned char hero_speed=0x02;
unsigned char jump_speed=0x03;
unsigned char lvlchoice=0x00;
unsigned char x1=3;
unsigned char x2=4;
unsigned char x3=5;
unsigned char x4=6;
unsigned char x5=7;
unsigned char y3=43;
unsigned char y4=44;
unsigned char y5=45;
unsigned char y6=46;
unsigned char y7=47;
unsigned char y8=48;
unsigned char sword1=41;
unsigned char sword2=42;
unsigned char sword3=43;
unsigned char sword4=44;
unsigned char swordx1=7;
unsigned char swordx2=7;
unsigned char swordx3=7;
unsigned char swordx4=7;
unsigned char button_hero=0x00;

void buid_hero_function() {
	nokia_lcd_clear();
	nokia_lcd_set_cursor(3,3);
	if(hero_health==0x06) {
		nokia_lcd_write_string("6",1);
	}
	else if(hero_health==0x05) {
		nokia_lcd_write_string("5",1);
	}
	else if(hero_health==0x04) {
		nokia_lcd_write_string("4",1);
	}
	else if(hero_health==0x03) {
		nokia_lcd_write_string("3",1);
	}
	else if(hero_health==0x02) {
		nokia_lcd_write_string("2",1);
	}
	else if(hero_health==0x01) {
		nokia_lcd_write_string("1",1);
	}
	nokia_lcd_set_pixel(swordx1,sword1,0x01);
	nokia_lcd_set_pixel(swordx2,sword2,0x01);
	nokia_lcd_set_pixel(swordx3,sword3,0x01);
	nokia_lcd_set_pixel(swordx4,sword4,0x01);
	nokia_lcd_set_pixel(x5,y5,0x01);
	nokia_lcd_set_pixel(x4,y4,0x01);
	nokia_lcd_set_pixel(x4,y7,0x01);
	nokia_lcd_set_pixel(x3,y6,0x01);
	nokia_lcd_set_pixel(x3,y5,0x01);
	nokia_lcd_set_pixel(x3,y4,0x01);
	nokia_lcd_set_pixel(x3,y3,0x01);
	nokia_lcd_set_pixel(x2,y4,0x01);
	nokia_lcd_set_pixel(x2,y7,0x01);
	nokia_lcd_set_pixel(x1,y5,0x01);
	nokia_lcd_render();
}

enum Hero_States {start, build_hero, hero_move,hero_attack } state;
	
void hero_sm(void) {
	switch(state){
		case start:
			state=build_hero;
			break;
		
		case build_hero:
			state=hero_move;
			break;
		
		case hero_move:
			button_hero=~PINA & 0x0F;
			if(button_hero==0x01) {
				state=hero_attack;
			}
			else{
				state=hero_move;
			}
		
			break;
		case hero_attack:
			state=hero_move;
			break;
				
		default:
			state=start;	
			break;	
	}
	
	switch(state) {
		case build_hero:
			buid_hero_function();
			break;
	case hero_move:
		button_hero=~PINA & 0x0E;
		if(button_hero==0x02) {
			if(x5<83){	
				if(swordx1 < x3) {
					
					swordx1=x5;
					swordx2=x5;
					swordx3=x5;
					swordx4=x5;
				}
				x1=x1+hero_speed;
				x2=x2+hero_speed;
				x3=x3+hero_speed;
				x4=x4+hero_speed;
				x5=x5+hero_speed;
				swordx1=swordx1+hero_speed;
				swordx2=swordx2+hero_speed;
				swordx3=swordx3+hero_speed;
				swordx4=swordx4+hero_speed;
			}
			
		}
		else if(button_hero==0x04) {
			if(x1>1) {
				if(swordx1 > x3) {
					
					swordx1=x1;
					swordx2=x1;
					swordx3=x1;
					swordx4=x1;
				}
				x1=x1-hero_speed;
				x2=x2-hero_speed;
				x3=x3-hero_speed;
				x4=x4-hero_speed;
				x5=x5-hero_speed;
				swordx1=swordx1-hero_speed;
				swordx2=swordx2-hero_speed;
				swordx3=swordx3-hero_speed;
				swordx4=swordx4-hero_speed;
			}
			
		}
		else if(button_hero==0x08) {
			if(swordx1 > x3) {
				for(unsigned char i=0;i<8;i++) {
					if(x5<=83){
						x1=x1+jump_speed;
						x2=x2+jump_speed;
						x3=x3+jump_speed;
						x4=x4+jump_speed;
						x5=x5+jump_speed;
						swordx1=swordx1+jump_speed;
						swordx2=swordx2+jump_speed;
						swordx3=swordx3+jump_speed;
						swordx4=swordx4+jump_speed;
					}
					y3=y3-jump_speed;
					y4=y4-jump_speed;
					y5=y5-jump_speed;
					y6=y6-jump_speed;
					y7=y7-jump_speed;
					sword1=sword1-jump_speed;
					sword2=sword2-jump_speed;
					sword3=sword3-jump_speed;
					sword4=sword4-jump_speed;
					buid_hero_function();
					if(lvlchoice==0x01){
						lvl1_boss();
						lvl1_sm();
					}
					else if(lvlchoice==0x02){
						lvl2_boss();
						lvl2_sm();
					}
					else if(lvlchoice==0x03){
						lvl3_boss();
						lvl3_sm();
					}
				}
				for(unsigned char j=0;j<8;j++) {
					if(x5<=82){
						x1=x1+jump_speed;
						x2=x2+jump_speed;
						x3=x3+jump_speed;
						x4=x4+jump_speed;
						x5=x5+jump_speed;
						swordx1=swordx1+jump_speed;
						swordx2=swordx2+jump_speed;
						swordx3=swordx3+jump_speed;
						swordx4=swordx4+jump_speed;
					}
					y3=y3+jump_speed;
					y4=y4+jump_speed;
					y5=y5+jump_speed;
					y6=y6+jump_speed;
					y7=y7+jump_speed;
					sword1=sword1+jump_speed;
					sword2=sword2+jump_speed;
					sword3=sword3+jump_speed;
					sword4=sword4+jump_speed;
					buid_hero_function();
					if(lvlchoice==0x01){
						lvl1_boss();
						lvl1_sm();
					}
					else if(lvlchoice==0x02){
						lvl2_boss();
						lvl2_sm();
					}
					else if(lvlchoice==0x03){
						lvl3_boss();
						lvl3_sm();
					}
				}
			}
			else if(swordx1 < x3) {
				for(unsigned char i=0;i<8;i++) {
					if(x1>=2){
						x1=x1-jump_speed;
						x2=x2-jump_speed;
						x3=x3-jump_speed;
						x4=x4-jump_speed;
						x5=x5-jump_speed;
						swordx1=swordx1-jump_speed;
						swordx2=swordx2-jump_speed;
						swordx3=swordx3-jump_speed;
						swordx4=swordx4-jump_speed;
					}
					y3=y3-jump_speed;
					y4=y4-jump_speed;
					y5=y5-jump_speed;
					y6=y6-jump_speed;
					y7=y7-jump_speed;
					sword1=sword1-jump_speed;
					sword2=sword2-jump_speed;
					sword3=sword3-jump_speed;
					sword4=sword4-jump_speed;
					buid_hero_function();
					if(lvlchoice==0x01){
						lvl1_boss();
						lvl1_sm();
					}
					else if(lvlchoice==0x02){
						lvl2_boss();
						lvl2_sm();
					}
					else if(lvlchoice==0x03){
						lvl3_boss();
						lvl3_sm();
					}
				}
				for(unsigned char j=0;j<8;j++) {
					if(x1>=1){
						x1=x1-jump_speed;;
						x2=x2-jump_speed;
						x3=x3-jump_speed;
						x4=x4-jump_speed;
						x5=x5-jump_speed;
						swordx1=swordx1-jump_speed;
						swordx2=swordx2-jump_speed;
						swordx3=swordx3-jump_speed;
						swordx4=swordx4-jump_speed;
					}
					y3=y3+jump_speed;
					y4=y4+jump_speed;
					y5=y5+jump_speed;
					y6=y6+jump_speed;
					y7=y7+jump_speed;
					sword1=sword1+jump_speed;
					sword2=sword2+jump_speed;
					sword3=sword3+jump_speed;
					sword4=sword4+jump_speed;
					buid_hero_function();
					if(lvlchoice==0x01){
						lvl1_boss();
						lvl1_sm();
					}
					else if(lvlchoice==0x02){
						lvl2_boss();
						lvl2_sm();
					}
					else if(lvlchoice==0x03){
						lvl3_boss();
						lvl3_sm();
					}
					
				}
			}
		}
			buid_hero_function();

		break;
		
	case hero_attack:
		if(swordx1 > x3) {
			swordx1=x5+1;
			swordx2=x5+2;
			swordx3=x5+3;
			swordx4=x5+4;
			sword1=y5;
			sword2=y5;
			sword3=y5;
			sword4=y5;
			check_hero_hit();
			buid_hero_function();
			swordx1=x5;
			swordx2=x5;
			swordx3=x5;
			swordx4=x5;
			sword1=41;
			sword2=42;
			sword3=43;
			sword4=44;
			buid_hero_function();
		} 
		else if(swordx1 < x3) {
			swordx1=x1-1;
			swordx2=x1-2;
			swordx3=x1-3;
			swordx4=x1-4;
			sword1=y5;
			sword2=y5;
			sword3=y5;
			sword4=y5;
			check_hero_hit();
			buid_hero_function();
			swordx1=x1;
			swordx2=x1;
			swordx3=x1;
			swordx4=x1;
			sword1=41;
			sword2=42;
			sword3=43;
			sword4=44;
			buid_hero_function();
		}
		break;
	default:	
		break;
	}
}
