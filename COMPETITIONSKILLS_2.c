#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    potconelift,    sensorPotentiometer)
#pragma config(Sensor, in2,    potchainbar,    sensorPotentiometer)
#pragma config(Sensor, in3,    potmobilelift,  sensorPotentiometer)
#pragma config(Sensor, in4,    gyro,           sensorGyro)
#pragma config(Sensor, in5,    linetracker,    sensorLineFollower)
#pragma config(Sensor, in6,    linetracker2,   sensorLineFollower)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           leftdrive1,    tmotorVex393HighSpeed_HBridge, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port2,           leftdrive2,    tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           conelift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           mobilelift,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           chainbarleft,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           chainbarright, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightdrive2,   tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port10,          rightdrive1,   tmotorVex393HighSpeed_HBridge, openLoop, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"



int value=1;

task mobilepickup()
{
	repeatUntil (SensorValue(potmobilelift)<=430)
	{
		motor[mobilelift] = 127;
	}
	motor[mobilelift] = 0;
}

task mobileputdown1()
{
	repeatUntil (SensorValue(potmobilelift)>=2350)
	{
		motor[mobilelift] = -127;
	}
	motor[mobilelift] = 0;
	value = 1;
}

task mobileputdown2()
{
	repeatUntil (SensorValue(potmobilelift)>=1000)
	{
		motor[mobilelift] = -127;
	}
	motor[mobilelift] = 0;
	value = 0;
}

void movedistance (int degrees, int power)
{
	SensorValue(I2C_1) = 0;
	SensorValue(I2C_2) = 0;
	repeatUntil(abs(SensorValue(I2C_1)) >= degrees)
	{
		motor[leftdrive1] = power;
		motor[leftdrive2]  = power;
		repeatUntil (abs(SensorValue(I2C_2)) >= degrees)
		{
			motor[rightdrive2] = power;
			motor[rightdrive1]  = power;
		}
	}

	SensorValue(I2C_1) = 0;
	SensorValue(I2C_2) = 0;
	if (power > 0)
	{
		motor[leftdrive1] = -10;
		motor[leftdrive2] = -10;
		motor[rightdrive2] = -10;
		motor[rightdrive1] =-10;
	}
	else
	{
		motor[leftdrive1] = 10;
		motor[leftdrive2] = 10;
		motor[rightdrive2] = 10;
		motor[rightdrive1] = 10;
	}
}

void movedistance1 (int degrees, int power)
{
	SensorValue(I2C_1) = 0;
	SensorValue(I2C_2) = 0;
	repeatUntil(abs(SensorValue(I2C_1)) >= degrees)
	{
		motor[leftdrive1] = power;
		motor[leftdrive2]  = power;
		repeatUntil (abs(SensorValue(I2C_2)) >= degrees)
		{
			motor[rightdrive2] = power;
			motor[rightdrive1]  = power;
		}
	}

	SensorValue(I2C_1) = 0;
	SensorValue(I2C_2) = 0;
	motor[leftdrive1] = 0;
	motor[leftdrive2] = 0;
	motor[rightdrive2] = 0;
	motor[rightdrive1] = 0;
}




void gyrocorrection(int gyrovalue)
{
	wait1Msec(300);
	if(SensorValue(gyro)<gyrovalue)
	{
		repeatUntil(SensorValue(gyro) >=gyrovalue)
		{
			motor[leftdrive1] = -40;
			motor[leftdrive2] = -40;
			motor[rightdrive2] = 40;
			motor[rightdrive1] =40;
		}
		motor[leftdrive1] = 10;
		motor[leftdrive2] = 10;
		motor[rightdrive2] = -10;
		motor[rightdrive1] =-10;
	}

	else if(SensorValue(gyro) >gyrovalue)
	{
		repeatUntil(SensorValue(gyro) <=gyrovalue)
		{
			motor[leftdrive1] = 40;
			motor[leftdrive2] = 40;
			motor[rightdrive2] = -40;
			motor[rightdrive1] =-40;
		}
		motor[leftdrive1] = -10;
		motor[leftdrive2] = -10;
		motor[rightdrive2] = 10;
		motor[rightdrive1] =10;
	}
	wait1Msec(300);
}




void gyroturn(int gyrovalue)
{
	wait1Msec(300);
	if(SensorValue(gyro)<gyrovalue)
	{
		repeatUntil(SensorValue(gyro) >=gyrovalue)
		{
			motor[leftdrive1] = -63;
			motor[leftdrive2] = -63;
			motor[rightdrive2] = 63;
			motor[rightdrive1] =63;
		}
		motor[leftdrive1] = 10;
		motor[leftdrive2] = 10;
		motor[rightdrive2] = -10;
		motor[rightdrive1] =-10;
	}

	else if(SensorValue(gyro) >gyrovalue)
	{
		repeatUntil(SensorValue(gyro) <=gyrovalue)
		{
			motor[leftdrive1] = 63;
			motor[leftdrive2] = 63;
			motor[rightdrive2] = -63;
			motor[rightdrive1] =-63;
		}
		motor[leftdrive1] = -10;
		motor[leftdrive2] = -10;
		motor[rightdrive2] = 10;
		motor[rightdrive1] =10;
	}
	wait1Msec(300);
}

void linetrack1(int sensor, int speed)
{
	if (sensor==1)
	{
		repeatUntil(SensorValue(linetracker) <=1700)
		{
			motor[leftdrive1] = speed;
			motor[leftdrive2] = speed;
			motor[rightdrive2] = speed;
			motor[rightdrive1] =speed;
		}
		motor[leftdrive1] = 0;
		motor[leftdrive2] = 0;
		motor[rightdrive2] = 0;
		motor[rightdrive1] = 0;
	}
	if (sensor == 2)
	{
		repeatUntil(SensorValue(linetracker2) <=1700)
		{
			motor[leftdrive1] = speed;
			motor[leftdrive2] = speed;
			motor[rightdrive2] = speed;
			motor[rightdrive1] =speed;
		}
		motor[leftdrive1] = 0;
		motor[leftdrive2] = 0;
		motor[rightdrive2] = 0;
		motor[rightdrive1] = 0;
	}
}


void linetrack(int sensor, int speed)
{
	if (sensor==1)
	{
		repeatUntil(SensorValue(linetracker) <=1700)
		{
			motor[leftdrive1] = speed;
			motor[leftdrive2] = speed;
			motor[rightdrive2] = speed;
			motor[rightdrive1] =speed;
		}
		if (speed>0)
		{
			motor[leftdrive1] = -10;
			motor[leftdrive2] = -10;
			motor[rightdrive2] = -10;
			motor[rightdrive1] = -10;
		}

		if (speed<0)
		{

			motor[leftdrive1] = 10;
			motor[leftdrive2] = 10;
			motor[rightdrive2] = 10;
			motor[rightdrive1] = 10;
		}
	}
	if (sensor == 2)
	{
		repeatUntil(SensorValue(linetracker2) <=1700)
		{
			motor[leftdrive1] = speed;
			motor[leftdrive2] = speed;
			motor[rightdrive2] = speed;
			motor[rightdrive1] =speed;
		}
		if (speed>0)
		{
			motor[leftdrive1] = -10;
			motor[leftdrive2] = -10;
			motor[rightdrive2] = -10;
			motor[rightdrive1] = -10;
		}

		if (speed<0)
		{

			motor[leftdrive1] = 10;
			motor[leftdrive2] = 10;
			motor[rightdrive2] = 10;
			motor[rightdrive1] = 10;
		}
	}

}




task sensorcheck()
{
	while(true)
	{
		clearLCDLine(0);
		clearLCDLine(1);
		displayNextLCDNumber(SensorValue(I2C_1));
		displayNextLCDNumber(SensorValue(gyro));
		wait1Msec(100);
	}
}

////////////////////////////////////////////////////////////////////


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	resetMotorEncoder(leftdrive2);
	resetMotorEncoder(rightdrive2);
	SensorValue[gyro] = 0;

	bStopTasksBetweenModes = true;

	bDisplayCompetitionStatusOnLcd = false;

	startTask(sensorcheck);


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

	stopTask(sensorcheck);
	resetMotorEncoder(leftdrive2);
	resetMotorEncoder(rightdrive2);
	SensorValue[gyro] = 0;
	wait1Msec(50);

	startTask(mobileputdown1);

	repeatUntil(SensorValue(potconelift)>= 600)
	{
		motor[conelift] = 127;
	}
	motor[conelift] = 0;

	movedistance1(1000,80);

	linetrack1(1,80);

	movedistance1(200,127);

	wait1Msec(500);


	startTask(mobilepickup);  ///////////////////////////first cone pickup///////////////

	wait1Msec(800);

	movedistance1(700,-127);

	linetrack1(1,-127);

	movedistance(175,-127);


	gyroturn(360);

	movedistance(750,-127);

	gyroturn(1300);


	movedistance(450,127);

	startTask(mobileputdown2); ///////////////////////////first cone drop off/////////////////

	wait1Msec(250);
	movedistance(275,127);
	wait1Msec(500);

	movedistance1(450,-63);

	linetrack(1,-63);

	startTask(mobileputdown1);
	gyroturn(570);


	movedistance(375,127);

	gyroturn(-360);

	movedistance1(600,127);
	wait1Msec(500);
	startTask(mobilepickup); //////////////////////////second cone pickup////////////////////
	wait1Msec(500);

	gyroturn(1320);

	movedistance1(300,127);

	startTask(mobileputdown2);////////////////////////second cone drop off///////////////////////

	linetrack1(1,127);

	movedistance(100,127);
	wait1Msec(250);

	movedistance1(500,-100);

	linetrack(2,-100);

	startTask(mobileputdown1);
	gyroturn(2240);

	movedistance1(600,127);
	wait1Msec(500);

	startTask(mobilepickup); //////////////////third cone pick up///////////////
	wait1Msec(500);

	gyroturn(1600);


	movedistance(400,127);

	startTask(mobileputdown2);////////////////////////third cone drop off///////////////////////

	linetrack1(1,127);


	movedistance(100,127);
	wait1Msec(250);

	movedistance(200,-127);
	wait1Msec(250);

	motor[leftdrive1] = 40;
	motor[leftdrive2] = 40;
	motor[rightdrive2] = 40;
	motor[rightdrive1] =40;
	wait1Msec(800);

	motor[leftdrive1] = 0;
	motor[leftdrive2] = 0;
	motor[rightdrive2] = 0;
	motor[rightdrive1] =0;

	wait1Msec(500);

	startTask(mobileputdown1);

	linetrack(1,-127);

	gyroturn(-300);

	movedistance1(300,100);

	linetrack(2,100);

	gyrocorrection(-400);

	movedistance1(700,127);


	startTask(mobilepickup);///////////////////////fourth cone pickup/////////////////
	wait1Msec(1200);

	linetrack(1,100);


	gyroturn(400);

	movedistance(250,100);

	gyroturn(-400);
	movedistance(400,127);

	startTask(mobileputdown2); ///////////////////////////fourth cone drop off/////////////////

	movedistance(200,127);

	wait1Msec(250);

	movedistance1(450,-63);

	linetrack(1,-63);

	gyroturn(400);
	startTask(mobileputdown1);
	movedistance(300,100);

	gyroturn(1400);

	movedistance1(600,127);
	wait1Msec(500);
	startTask(mobilepickup); /////////////////////////////////fifth cone pickup////////////////////
	wait1Msec(500);
	gyroturn(-450);
	movedistance1(200,127);
	startTask(mobileputdown2); ///////////////////fifth cone drop off////////////////////////////////
	linetrack1(1,127);

	movedistance(100,127);
	wait1Msec(250);
	movedistance(300,-127);

	gyroturn(-1200);

	movedistance1(1000,-127); ////////////////////////park///////////////////////////



}


task usercontrol()
{
	stopTask(sensorcheck);
	while (true)
	{

		motor[leftdrive1] = abs(vexRT[Ch3]) > 10 ? vexRT[Ch3] : 0;
		motor[leftdrive2] = abs(vexRT[Ch3]) > 10 ? vexRT[Ch3] : 0;
		motor[rightdrive2] = abs(vexRT[Ch2]) > 10 ? vexRT[Ch2] : 0;
		motor[rightdrive1] = abs(vexRT[Ch2]) > 10 ? vexRT[Ch2] : 0;





		if (vexRT[Btn5U]==1)
		{
			motor[conelift] = 127;
		}
		else if (vexRT[Btn5D]==1)
		{
			motor[conelift] = -127;
		}

		else
		{
			motor[conelift] = 0;
		}


		if (vexRT[Btn6D]==1)
		{
			stopTask(mobilepickup);

			if (value==1)
			{
				startTask(mobileputdown2);
			}

			if (value==0)
			{
				startTask(mobileputdown1);
			}

		}

		if (vexRT[Btn6U]==1)
		{
			stopTask(mobileputdown1);
			stopTask(mobileputdown2);
			startTask(mobilepickup);
		}

	}
}
