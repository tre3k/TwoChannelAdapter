//
// Created by kirill on 10.12.18.
//

#include "pcidevfunctions.h"

PciDevFunctions::PciDevFunctions(const char *filename) {
    status = STATUS_OK;
    file_descriptor = open(filename,O_RDWR);
    if(file_descriptor < 0) status |= STATUS_ERROR_OPEN_FILE;
}

unsigned  int PciDevFunctions::getStatus() {
    return status;
}

void PciDevFunctions::stopMotion(int channel) {
    unsetBitCS0(file_descriptor,0+channel*16,3);
    unsetBitCS0(file_descriptor,1+channel*16,3);  //Power OFF
    status = STATUS_STOP_MOTION;
    return;
}

/* private functions */
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
