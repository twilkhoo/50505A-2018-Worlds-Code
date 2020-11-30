#pragma config(Sensor, in1,    potentiometer,  sensorPotentiometer)
#pragma config(Motor,  port4,           chainbar,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{


	while (true)
	{


		if (vexRT[Btn7U]==1)
		{
			motor[port4] = 127;

		}
		else if (vexRT[Btn7D]==1)
		{
			motor[port4]=-127;

		}
		else
		{
			if (SensorValue(potentiometer) < 300)
			{
				motor[port4]=0;
			}

			if (SensorValue(potentiometer) > 300 && SensorValue(potentiometer) < 1000)
			{
				motor[port4]=-20;
			}

			if (SensorValue(potentiometer) > 1000 && SensorValue(potentiometer) < 1500)
			{
				motor[port4]=0;
			}

			if (SensorValue(potentiometer) > 1500 && SensorValue(potentiometer) < 3800)
			{
				motor[port4]=20;
			}

			if (SensorValue(potentiometer) > 3800)
			{
				motor[port4]=0;
			}
		}
bLCDBacklight = true;
	clearLCDLine(0);
		clearLCDLine(1);
 setLCDPosition(0,0);
    displayNextLCDString("Potentiometer:");

    setLCDPosition(1,0);
    displayNextLCDNumber(SensorValue(potentiometer));


	}
}
