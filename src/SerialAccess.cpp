#include <SerialDevice.h>


//signleton class reference
SerialPort* SerialPort::m_pdeviceHandle = NULL;
char buffer[16*1024*1024]; 
int main()
{

    string errorString;    
    SerialPort::returnCode_t ret;	

    try {
	    //validate the input string with regex of "/dev/ttyUSB" 
	    //
	SerialPort *deviceHandle=SerialPort::GetDeviceHandle("/dev/ttyUSB0",errorString);
	if(deviceHandle == NULL) {		
		throw errorString;
	}

	ret = deviceHandle->SetBaudRate(2000000,errorString);
	if(ret != SUCCESS) {
		throw errorString;
	}



	unsigned int bytesReceived=0;
	FILE *fp;


	fp = fopen("/tmp/recpp.log","w");

	assert(fp != NULL);



	while(1) {
  	      bytesReceived = deviceHandle->ReceiveResponse(buffer,256,1); 	
	      if(bytesReceived == -1 ) {
		continue;
	      }
	      if((fwrite(&buffer[0],bytesReceived,1,fp)) != 1) {
                        printf("Unable to Write Data @ i =   ...! \n");
                        perror("Reason:");
                        break;
              }
	      printf("Data Read is this OK  == %ld Bytes \n",bytesReceived);	
	      break;
	
	}

	



	delete deviceHandle;
     } catch (string lastError) {

	cout<<"Exception Raised ....! "<<lastError<<"\n";


     }

}

