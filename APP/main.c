/*
 * main.c
 *
 *  Created on: May 20, 2022
 *      Author: Abo El-Naga
 */




#include"../HAL/LM35/LM35_int.h"
#include"../HAL/keypad/Keybad_int.h"
#include"../HAL/HLCD/HLCD_int.h"
#include"../HAL/DCmotor/Hdc_int.h"
#include"../HAL/LDR/LDR_int.h"
#include"../HAL/buzzer/buzzer_int.h"
#include"../HAL/LED/LED_int.h"
#include<util/delay.h>

#define MAX_TEMP 40U
#define MIN_BRIGHTNESS 20000U
volatile float32 G_u16ADCVALUE=0;
volatile uint8 G_u8ISRFlag=0;
volatile uint8 G_u8TempSensor=0;
volatile uint8 G_u8LDRSensor=0;
volatile float32 G_u16LDRval=0;
volatile uint16 G_u16Tempval=0;



void ADCISR()
{

	if(G_u8LDRSensor==1)
	    {
	    	MADC_vStartConversion(LDR_Pin);
	    	G_u16ADCVALUE=MADC_u16GetResult();
	    	G_u8LDRSensor=0;
	    	G_u16LDRval=HLDR_u16ReadValue(G_u16ADCVALUE);
	    	_delay_ms(200);


	    }


    else if(G_u8TempSensor==1)
    {

	MADC_vStartConversion(LM35_Pin);
	G_u16ADCVALUE=MADC_u16GetResult();
	G_u8TempSensor=0;
	G_u16Tempval=HLM35_vRead(G_u16ADCVALUE);
	_delay_ms(200);
    }

    G_u8ISRFlag=1;
}



void APP_vSetISR();
void APP_vMainMenu(uint8* A_u8MainChoice);
void APP_vMotorMenu(uint8* A_u8MotorMenuChoice);
void APP_vMotorControl(uint8* A_u8MotorChoice);
void APP_vBackMenu();
void APP_vTempSensorDisplay();
void APP_vLDRSensorDisplay();
void APP_vChecktemp();
void APP_vCheckLight();










int main(void )
{
LED_Init();
Buzzer_Init();
HLM35_vInit();
HLCD_vInit();
Keypad_vInit();
HLDR_vInit();
HDCM_vInit(&(DCconfig[0]));
 APP_vSetISR();


while(1)
		{

		   uint8 choice=0;

		   APP_vMainMenu(&choice);

	switch(choice)
	{

	case (1):
		{
		uint8 motor_choice=0;

		APP_vMotorMenu(&motor_choice);
		APP_vMotorControl(&motor_choice);

		APP_vBackMenu();

		break;

	}
	case(2):
	{
      APP_vTempSensorDisplay();

      APP_vBackMenu();
      break;

	}
	case(3):
	{
		 APP_vLDRSensorDisplay();
		APP_vBackMenu();
		break;

	}

		}

		}
return 0;




}



void APP_vMainMenu(uint8* A_u8MainChoice)
{

	while(*A_u8MainChoice==0)
	{
	HLCD_vDisplayStr("Choose:");
	           _delay_ms(200);
	          HLCD_vSendCommand(LCD_CLR_DISPLAY);
	           HLCD_vDisplayStr("For motor press1");
	           _delay_ms(200);
	           HLCD_vSendCommand(LCD_CLR_DISPLAY);
	           HLCD_vDisplayStr("For Temp  press2");
	           _delay_ms(200);
	           HLCD_vSendCommand(LCD_CLR_DISPLAY);
	           HLCD_vDisplayStr("For LDR  press3");
	           _delay_ms(200);
	           HLCD_vSendCommand(LCD_CLR_DISPLAY);
	           *A_u8MainChoice=Keypad_u8GetNum();
	            APP_vChecktemp();
	            APP_vCheckLight();

	}

}


void APP_vMotorMenu(uint8* A_u8MotorMenuChoice)
{

	while(*A_u8MotorMenuChoice==0)
	{

	                  HLCD_vDisplayStr("Choose:");
			           _delay_ms(200);
			          HLCD_vSendCommand(LCD_CLR_DISPLAY);
			           HLCD_vDisplayStr("To Start press1");
			           _delay_ms(500);
			           HLCD_vSendCommand(LCD_CLR_DISPLAY);
			           HLCD_vDisplayStr("To Stop press2");
			           _delay_ms(200);
			           HLCD_vSendCommand(LCD_CLR_DISPLAY);
			           *A_u8MotorMenuChoice=Keypad_u8GetNum();


	}
}

void APP_vMotorControl(uint8* A_u8MotorChoice)
{


	switch(*A_u8MotorChoice)
			{
			case (1):
		        {
				HDCM_vDirCW(&(DCconfig[0]));
				HLCD_vSendCommand(LCD_CLR_DISPLAY);
				HLCD_vDisplayStr("Motor ON");
				_delay_ms(1000);
				break;
		        }

			case(2):
		        {
				HDCM_vStop(&(DCconfig[0]));
				HLCD_vSendCommand(LCD_CLR_DISPLAY);
				HLCD_vDisplayStr("Motor OFF");
				_delay_ms(1000);
				break;
			    }
			default:
				break;

			}


}
void APP_vBackMenu()
{

uint8 L_u8BackChoice=0;
	while(L_u8BackChoice!=1)
	{
		HLCD_vSendCommand(LCD_CLR_DISPLAY);
		HLCD_vDisplayStr("To go back press1");
		L_u8BackChoice=Keypad_u8GetNum();
		_delay_ms(1000);
		 APP_vChecktemp();
		 APP_vCheckLight();

	}


}
void APP_vTempSensorDisplay()
{
	uint16 L_u16LM35VAl=0;

	       G_u8TempSensor=1;
	       MADC_vStartConversion(LM35_Pin);
	       HLCD_vDisplayStr("TEMP=");
	       _delay_ms(500);
	       if(G_u8ISRFlag==1)
	       L_u16LM35VAl=HLM35_vRead(G_u16ADCVALUE);
	       HLCD_vDisplayNum(L_u16LM35VAl);
	       HLCD_vDisplayChar('C');
	       _delay_ms(2000);
}

void APP_vLDRSensorDisplay()
{
	float32 L_u16LDRval=0;
             G_u8LDRSensor=1;
_delay_ms(150);
	           MADC_vStartConversion(LDR_Pin);
		       HLCD_vDisplayStr(" res=");
		       _delay_ms(500);

		       if(G_u8ISRFlag==1)
		       L_u16LDRval=HLDR_u16ReadValue(G_u16ADCVALUE);
		       HLCD_vDisplayNum(L_u16LDRval);
		       _delay_ms(2000);

}
void APP_vSetISR()
{
	MADC_vSetCallback(ADCISR);
}

void APP_vChecktemp()
{

	G_u8TempSensor=1;
	MADC_vStartConversion(LM35_Pin);
	_delay_ms(150);
	if(G_u16Tempval>MAX_TEMP)
	{

		BuzzerSet(BUZZER_ON);
	}
	else
	{
		BuzzerSet(BUZZER_OFF);

	}
	G_u16Tempval=0;

}

void APP_vCheckLight()
{

	G_u8LDRSensor=1;
	MADC_vStartConversion(LDR_Pin);
	_delay_ms(150);
	if(G_u16LDRval>MIN_BRIGHTNESS)
	{

		LED_SET(LED_ON);
	}
	else
	{
		LED_SET(LED_OFF);

	}
	G_u16LDRval=0;
}
