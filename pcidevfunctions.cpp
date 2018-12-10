//
// Created by Kirill Pshenichnyi on 10.12.18.
//

#include "pcidevfunctions.h"

PciDevFunctions::PciDevFunctions(const char *filename, int channel) {
    status = STATUS_OK;
    file_descriptor = open(filename,O_RDWR);
    if(file_descriptor < 0){
        status |= STATUS_ERROR_OPEN_FILE;
        return;
    }
    g_channel = channel;
}

unsigned  int PciDevFunctions::getStatus() {
    return status;
}

void PciDevFunctions::setFrequency(double freq) {
    frequency = freq;
}

void PciDevFunctions::initMove() {
    write8CS0(file_descriptor,3,0x00);
    write8CS0(file_descriptor,3,0x01);
    write16CS0(file_descriptor,19,50);                                  // set speed SSI
    write8CS0(file_descriptor,3,0x03);                                  // ENSSI, CLRSSI

    write8CS0(file_descriptor,1+g_channel*16,0x00);

    write8CS0(file_descriptor,0+g_channel*16,0x00);
    setBitCS0(file_descriptor,0+g_channel*16,4);                        // set 4 bit in 0x00 offset

    write8CS0(file_descriptor,13+g_channel*16,26+1);                    // 26 bit - encoder

    /* set mask */
    write8CS1(file_descriptor,4+g_channel*16,0xff);
    write8CS1(file_descriptor,5+g_channel*16,0xff);
    write8CS1(file_descriptor,6+g_channel*16,0xff);
    write8CS1(file_descriptor,7+g_channel*16,0x03);

    setBitCS0(file_descriptor,0+g_channel*16,5);                        // ENSSI
    setBitCS0(file_descriptor,1+g_channel*16,6);

    /* default triggers value */
    unsetBitCS0(file_descriptor,1+g_channel*16,0);
    unsetBitCS0(file_descriptor,1+g_channel*16,5);
    unsetBitCS0(file_descriptor,1+g_channel*16,2);                      //unsetBitCS0(f,1,6);

    return;
}

void PciDevFunctions::startMove(int count_step,bool direction){

    bool enable_turnd = true;
    bool enable_end = true;


    setBitCS0(file_descriptor,0+g_channel*16,0);                        //REGISTER_CONTROL set 0 bit for enable step frequency
    unsetBitCS0(file_descriptor,0+g_channel*16,2);                      // enable step counter
    write24CS0(file_descriptor,4+g_channel*16,
               (int)(50000000/(frequency*2)));

    setBitCS0(file_descriptor,0+g_channel*16,6);                        // enable write step counter
    write24CS0(file_descriptor,7+g_channel*16, count_step);
    setBitCS0(file_descriptor,1+g_channel*16,0);

    /* REGISTER_OPTIONS */
    if(enable_turnd){
        setBitCS0(file_descriptor,1+g_channel*16,2);                    // not turned
    }else{
        unsetBitCS0(file_descriptor,1+g_channel*16,2);
    }

    if(enable_end){
        setBitCS0(file_descriptor,1+g_channel*16,6);                     // disable end
    }else{
        unsetBitCS0(file_descriptor,1+g_channel*16,6);
    }

    if(direction){
        setBitCS0(file_descriptor,1+g_channel*16,1);
    }else{
        unsetBitCS0(file_descriptor,1+g_channel*16,1);
    }

    unsetBitCS0(file_descriptor,1+g_channel*16,5);
    setBitCS0(file_descriptor,0+g_channel*16,1);
    setBitCS0(file_descriptor,0+g_channel*16,2);

    setBitCS0(file_descriptor,0+g_channel*16,3);                            //enable work step counter
    setBitCS0(file_descriptor,1+g_channel*16,3);                            //Power ON
    return;
}

void PciDevFunctions::stopMotion() {
    if(status & 0x0f) return;
    unsetBitCS0(file_descriptor,0+g_channel*16,3);
    unsetBitCS0(file_descriptor,1+g_channel*16,3);                          //Power OFF
    status = STATUS_STOP_MOTION;
    return;
}

int PciDevFunctions::getEncoder() {
    int value = 0;
    unsetBitCS0(file_descriptor, 1+g_channel*16, 0);
    setBitCS0(file_descriptor, 1+g_channel*16, 0);
    value = read32CS1(file_descriptor, 0+g_channel*16);
    return value;
}

/* convert to noraml value from gray code */
int PciDevFunctions::fromGrayCode(int value){
    int retval = 0;
    for (retval=0;value;){
        retval^=value;
        value=value>>1;
    }
    return retval;
}

/* convert step to milimeters */
double PciDevFunctions::stepTomm(long int value) {
    return  (double)value/coeff_step_on_mm +
            (double)zero_position/coeff_step_on_mm;
}

void PciDevFunctions::setZeroPoint(long int value) {
    zero_position = value;
    return;
}

/* **************** private functions **************** */

unsigned char PciDevFunctions::read8CS0(int fd, long offset){
    unsigned char byte = 0x00;
    ioctl(fd,CS0_SET_ADDR,offset);
    read(fd,&byte,1);
    return byte;
}

unsigned short PciDevFunctions::read16CS0(int fd, long offset) {
    unsigned  short int retval = 0;
    retval = read8CS0(fd,offset);
    retval |= (read8CS0(fd,offset+1) << 8);
    return  retval;
}

unsigned int PciDevFunctions::read32CS0(int fd, long offset) {
    unsigned int retval = 0;
    retval  = (read16CS0(fd,offset) & 0xffff);
    retval |= (read16CS0(fd,offset+2) << 16);
    return retval;
}

unsigned char PciDevFunctions::read8CS1(int fd, long offset){
    unsigned char byte = 0x00;
    ioctl(fd,CS1_SET_ADDR,offset);
    read(fd,&byte,1);
    return byte;
}

unsigned short PciDevFunctions::read16CS1(int fd, long offset) {
    unsigned short int retval = 0;
    retval = read8CS1(fd,offset);
    retval |= (read8CS1(fd,offset+1) << 8);
    return  retval;
}

unsigned int PciDevFunctions::read32CS1(int fd, long offset) {
    unsigned int retval = 0x00000000;
    retval  = (read16CS1(fd,offset) & 0xffff);
    retval |= (read16CS1(fd,offset+2) << 16);
    return retval;
}

int PciDevFunctions::write8CS0(int fd, long offset, char byte){
    int retval;
    retval = ioctl(fd,CS0_SET_ADDR,offset);
    retval = (int) write(fd,&byte,1);
    return retval;
}

int PciDevFunctions::write8CS1(int fd, long offset, char byte){
    int retval;
    retval = ioctl(fd,CS1_SET_ADDR,offset);
    retval = (int) write(fd,&byte,1);
    return retval;
}

int PciDevFunctions::write16CS0(int fd, long offset, unsigned short word){
    int retval;
    char byte1 = (char)(word & 0x00ff);
    char byte2 = (char)((word >> 8) & 0x00ff);
    retval = write8CS0(fd,offset,byte1);
    retval = write8CS0(fd,offset+1,byte2);
    return retval;
}

int PciDevFunctions::write24CS0(int fd, long offset, unsigned int twoword){
    int retval;
    char byte1 = (char)(twoword & 0xff);
    char byte2 = (char)((twoword >> 8) & 0xff);
    char byte3 = (char)((twoword >> 16) &0xff);

    retval = write8CS0(fd,offset,byte1);
    retval = write8CS0(fd,offset+1,byte2);
    retval = write8CS0(fd,offset+2,byte3);
    return retval;
}

int PciDevFunctions::write16CS1(int fd, long offset, unsigned short word){
    int retval;
    char byte1 = (char)(word & 0x00ff);
    char byte2 = (char)((word >> 8) & 0x00ff);
    retval = write8CS1(fd,offset,byte1);
    retval = write8CS1(fd,offset+1,byte2);
    return retval;
}

void PciDevFunctions::setBitCS0(int fd, long offset, int numbit){
    char tmp_byte;
    tmp_byte = read8CS0(fd,offset);
    tmp_byte |= (1<<numbit);
    write8CS0(fd,offset,tmp_byte);
    return;
}

void PciDevFunctions::unsetBitCS0(int fd, long offset, int numbit){
    char tmp_byte;
    tmp_byte = read8CS0(fd,offset);
    tmp_byte &= ~(1<<numbit);
    write8CS0(fd,offset,tmp_byte);
    return;
}
