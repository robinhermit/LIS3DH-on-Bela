#include <Bela.h>
#include <I2C_LIS3DH.h>
#include <libraries/Scope/Scope.h>

AuxiliaryTask i2cTask;
void i2cTaskProcess (void*);

int gCount = 0;
float gInterval = 0.0001;

int accelMax = 65535;
float accelX = 0;
float accelY = 0;
float accelZ = 0;

// initialise scope
Scope scope;

I2C_LIS3DH lis3dh; // Object to handle LIS3DH sensing

bool setup(BelaContext *context, void *userData)
{
	scope.setup(3, context->audioSampleRate);
	i2cTask = Bela_createAuxiliaryTask(i2cTaskProcess, 50, "bela-task");

	if(!lis3dh.begin()){
		rt_printf("Error initialising LIS3DH\n");
		return false;
	}
	return true;
}

void render(BelaContext *context, void *userData)
{
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		
		// Print a message every second indicating the number of seconds elapsed
		//if (++gCount % (int)(context->audioSampleRate*gInterval) == 0) {
		Bela_scheduleAuxiliaryTask (i2cTask);
		//}
		
		scope.log(accelX, accelY, accelZ);
	}
}

void i2cTaskProcess (void*) 
{
	accelX = map(lis3dh.readX(), 0, accelMax, -1, 1);
	accelY = map(lis3dh.readY(), 0, accelMax, -1, 1);
	accelZ = map(lis3dh.readZ(), 0, accelMax, -1, 1);
	//rt_printf("X: %2f, Y: %2f, Z: %2f\n", accelX, accelY, accelZ);
}

void cleanup(BelaContext *context, void *userData)
{
}