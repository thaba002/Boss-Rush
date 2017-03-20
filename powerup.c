#include <avr/io.h>
#include <util/delay.h>

#include "nokia5110.h"
#include <avr/interrupt.h>
#include <time.h>
#include <stdlib.h>
unsigned char check=0;
unsigned char r;
void spawnh(){
	if(check==1){
		nokia_lcd_set_pixel(20,48,0x01);
		nokia_lcd_set_pixel(20,47,0x01);
		nokia_lcd_set_pixel(20,46,0x01);
		nokia_lcd_set_pixel(20,45,0x01);
		nokia_lcd_set_pixel(20,44,0x01);
		nokia_lcd_set_pixel(20,43,0x01);
		nokia_lcd_render();
	}
	else{
		nokia_lcd_set_pixel(20,48,0x00);
		nokia_lcd_set_pixel(20,47,0x00);
		nokia_lcd_set_pixel(20,46,0x00);
		nokia_lcd_set_pixel(20,45,0x00);
		nokia_lcd_set_pixel(20,44,0x00);
		nokia_lcd_set_pixel(20,43,0x00);
		nokia_lcd_render();
	}
}



void checkcontacth(){
	spawnh();
	if((x1==20 || x2==20 || x3==20 || x4==20 || x5==20)&& check==1){
		hero_health++;
		check=0;

	}
}

void pu() {
	srand(time(NULL));
  // should only be called once
	r = rand()%10;
	if(check==1 && hero_health<6){
		checkcontacth();	
	}
	else if(r==1){
		check=1;
		spawnh();
	}

}