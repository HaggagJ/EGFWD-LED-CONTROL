#include "IntCtrl.h"
#include "Port.h"
#include "Dio.h"
#include "Systick.h"

static volatile uint32 Tick;
void SysTick_Handler(void){
	Tick++;
	}

int main(){
	uint32 OnTime=5000;
	uint32 OffTime=3000;
	uint8 OnFlag=1;
	IntCtrl_Init();
	Port_Init(&Port_Configuration);
	Systick_Off();
		//set period to trigger an interrupt every 1 second
		Systick_SetPeriod(1000);
		//Light up the Led
		Dio_WriteChannel(Dio_PF1_INDEX,STD_HIGH);
		//start timer
		Systick_Enable();
	
	while(1){
		if(Tick ==(OnTime/1000) && OnFlag==1){
			Dio_FlipChannel(Dio_PF1_INDEX);
			Tick=0;
			OnFlag=0;
		}
		else if(Tick == (OffTime/1000) && OnFlag==0){
			Dio_FlipChannel(Dio_PF1_INDEX);
			Tick=0;
			OnFlag=1;
		}

	}
}