#include "Std_Types.h"
#include "LED.h"

u8 on;
u8 off;

int main ()
{	
	/*Initial Values for on/off Time*/
	on=1;
	off=3;
	
	APP_Init();
	
	while (1)
	{
		APP_Start (off,on);
	}
}

