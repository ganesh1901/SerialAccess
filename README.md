# SerialAccess
SerialAccess 
Input string serial port only accepts the "/dev/ttyUSB" only 
have to close the application properly to call the destructor of the SerialDevice library otherwise next time serialport will open for futher operations
the lock file with serialport name in the /tmp directory
read and write wrapper are there


class instance of the SerialDevice has to be the static instance initialised to NULL 
because the serialDevice is singleton instance 


