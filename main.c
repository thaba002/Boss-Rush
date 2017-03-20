/*
 * final_proj.c
 *
 * Created: 3/6/2017 3:48:02 AM
 * Author : tamir pc
 */ 

 


#include <avr/io.h>
#include <util/delay.h>

#include "nokia5110.c"

#include "lvl1.c"
#include "lvl2.c"
#include "lvl3.c"
#include "powerup.c"
unsigned char button=0x00;
void menu(void) {
	nokia_lcd_clear();
	nokia_lcd_set_cursor(0, 0);
	nokia_lcd_write_string("Pick level",1);
	nokia_lcd_set_cursor(0, 7);
	nokia_lcd_write_string("1. LEVEL 1", 1);
	nokia_lcd_set_cursor(0, 14);
	nokia_lcd_write_string("2. LEVEL 2", 1);
	nokia_lcd_set_cursor(0, 21);
	nokia_lcd_write_string("3. LEVEL 3", 1);
	nokia_lcd_set_cursor(0, 28);
	nokia_lcd_write_string("4. CONTROLS", 1);
	nokia_lcd_render();
}

void check_hero_hit(){
	if(lvlchoice==0x01){
		if(swordx4==lvl1_x1){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x2){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x3){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x4){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x5){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x6){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x7){
			lvl1_health--;
		}
		else if(swordx4==lvl1_x8){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x1){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x2){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x3){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x4){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x5){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x6){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x7){
			lvl1_health--;
		}
		else if(swordx3==lvl1_x8){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x1){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x2){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x3){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x4){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x5){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x6){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x7){
			lvl1_health--;
		}
		else if(swordx2==lvl1_x8){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x1){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x2){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x3){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x4){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x5){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x6){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x7){
			lvl1_health--;
		}
		else if(swordx1==lvl1_x8){
			lvl1_health--;
		}
		
	}
	else if(lvlchoice==0x02){
		if(swordx4==lvl2_x1){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x2){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x3){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x4){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x5){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x6){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x7){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x8){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x9){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x10){
			lvl2_health--;
		}
		else if(swordx4==lvl2_x11){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x1){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x2){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x3){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x4){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x5){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x6){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x7){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x8){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x9){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x10){
			lvl2_health--;
		}
		else if(swordx3==lvl2_x11){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x1){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x2){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x3){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x4){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x5){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x6){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x7){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x8){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x9){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x10){
			lvl2_health--;
		}
		else if(swordx2==lvl2_x11){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x1){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x2){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x3){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x4){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x5){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x6){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x7){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x8){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x9){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x10){
			lvl2_health--;
		}
		else if(swordx1==lvl2_x11){
			lvl2_health--;
		}
	}
	else if(lvlchoice==0x03){
		if(swordx4==lvl3_x1){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x2){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x3){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x4){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x5){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x6){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x7){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x8){
			lvl3_health--;
		}
		else if(swordx4==lvl3_x9){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x1){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x2){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x3){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x4){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x5){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x6){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x7){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x8){
			lvl3_health--;
		}
		else if(swordx3==lvl3_x9){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x1){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x2){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x3){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x4){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x5){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x6){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x7){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x8){
			lvl3_health--;
		}
		else if(swordx2==lvl3_x9){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x1){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x2){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x3){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x4){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x5){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x6){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x7){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x8){
			lvl3_health--;
		}
		else if(swordx1==lvl3_x9){
			lvl3_health--;
		}
		
	}
}


void tot_reset() {
	hero_damage=0x01;
	hero_health=0x03;
	hero_speed=0x02;
	jump_speed=0x03;
	x1=3;
	x2=4;
	x3=5;
	x4=6;
	x5=7;
	swordx1=7;
	swordx2=7;
	swordx3=7;
	swordx4=7;
	lvl1_health=0x03;
	lvl1_x1=74;
	lvl1_x2=75;
	lvl1_x3=76;
	lvl1_x4=77;
	lvl1_x5=78;
	lvl1_x6=79;
	lvl1_x7=80;
	lvl1_x8=81;
	lvl2_health=0x04;
	lvl2_x1=70;
	lvl2_x2=71;
	lvl2_x3=72;
	lvl2_x4=73;
	lvl2_x5=74;
	lvl2_x6=75;
	lvl2_x7=76;
	lvl2_x8=77;
	lvl2_x9=78;
	lvl2_x10=79;
	lvl2_x11=80;
	lvl3_health=0x05;
	lvl3_x1=70;
	lvl3_x2=71;
	lvl3_x3=72;
	lvl3_x4=73;
	lvl3_x5=74;
	lvl3_x6=75;
	lvl3_x7=76;
	lvl3_x8=77;
	lvl3_x9=78;
	sword3_x1=70;
	sword3_x2=71;
	sword3_x3=70;
	sword3_x4=71;
	sword3_x5=70;
	sword3_x6=71;
	sword3_x7=70;
	sword3_x8=71;
	sword3_y1=40;
	sword3_y2=39;
	sword3_y3=38;
	sword3_y4=37;
	sword3_y5=36;
	sword3_y6=35;
	sword3_y7=34;
	sword3_y8=33;
	
}

void controls_for_game(void) {
	nokia_lcd_clear();
	nokia_lcd_set_cursor(0, 0);
	nokia_lcd_write_string("Button 1-Jump",1);
	nokia_lcd_set_cursor(0, 7);
	nokia_lcd_write_string("Button 2-Walk left",1);
	nokia_lcd_set_cursor(0, 14);
	nokia_lcd_write_string("Button 3-Walk right",1);
	nokia_lcd_set_cursor(0, 21);
	nokia_lcd_write_string("Button 4-Attack",1);
	nokia_lcd_set_cursor(0, 28);
	nokia_lcd_write_string("Release button to return",1);
	nokia_lcd_set_cursor(0, 35);
	nokia_lcd_render();
	while(button){
		button=~PINA &0x01;
	}

}

void main(void)
{

	DDRA=0x00; PORTA=0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    nokia_lcd_init();
	nokia_lcd_power(1);
	nokia_lcd_clear();
    

    while(1) {
		button=~PINA & 0x0F;
		if(button==0x01){
			controls_for_game();
		}
		if(button==0x08){
			state=start;
			lvlchoice=0x01;
			nokia_lcd_clear();
			lvl1_main();
			tot_reset();
		}
		else if(button==0x04){
			state=start;
			lvlchoice=0x02;
			nokia_lcd_clear();
			lvl2_main();
			tot_reset();
		}
		else if(button==0x02){
			state=start;
			lvlchoice=0x03;
			nokia_lcd_clear();
			lvl3_main();
			tot_reset();
		}
		else{
			menu();
		}
	}
	
}