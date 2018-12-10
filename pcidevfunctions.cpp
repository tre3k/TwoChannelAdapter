//
// Created by kirill on 10.12.18.
//

#include "pcidevfunctions.h"

PciDevFunctions::PciDevFunctions(char *filename) {
    status = STATUS_OK;
    file_name = filename;
    file_descriptor = open(file_name,O_RDWR);
    if(file_descriptor < 0) status |= STATUS_ERROR_OPEN_FILE;

}

unsigned  int PciDevFunctions::getStatus() {
    return status;
}

/* private functions */
unsigned char PciDevFunctions::read8CS0(int fd, long offset){
    unsigned char byte = 0x00;
    ioctl(fd,CS0_SET_ADDR,offset);
    read(fd,&byte,1);
    return byte;
}

unsigned  short PciDevFunctions::read16CS0(int fd, long offset) {
    unsigned  short int retval = 0x0000;
    retval = (unsigned int) (read8CS0(fd,offset) & 0xff);
    retval |= (read8CS0(fd,offset+1) << 8);
    return  retval;
}

unsigned  int PciDevFunctions::read32CS0(int fd, long offset) {
    unsigned int retval = 0x00;
    retval = (unsigned int) (read16CS0(fd,offset) & 0xffff);
    retval |= (read16CS0(fd,offset+2) << 16);
    return retval;
}