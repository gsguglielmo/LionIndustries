#ifndef Arduino_h
#define Arduino_h

#include <stdio.h>
#include <unistd.h>
#include "arduino-serial-lib.h"
/*  Error codes (Throws)
 *  0x01    Unable to connected
 *  0x02    Unable to send byte
 *  0x03    Unable to read byte
 *  0x04    Not conneted
*/
class Arduino{
    public:
        Arduino(const char* serialPort,int baud);
        ~Arduino();
        void sendByte(char byte);
        char getByte();
        void flush();
        bool isConnected();
        void close();
    private:  
        int feed;
};

#endif