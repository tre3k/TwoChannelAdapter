//
// Created by kirill on 10.12.18.
//

#ifndef TWOCHANNELADAPTER_PCIDEVFUNCTIONS_H
#define TWOCHANNELADAPTER_PCIDEVFUNCTIONS_H

#include <plx9030c.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stropts.h>

#define STATUS_OK               0x00
#define STATUS_ERROR_OPEN_FILE  0x01
#define STATUS_ERROR_INIT_MOVE  0x02

class PciDevFunctions {
private:
    int file_descriptor;
    char *file_name;
    int channel;
    unsigned int status;

    /* functions for read data from chip select 0 (2 bar from PCI space) */
    unsigned char read8CS0(int fd, long offset);                                      //read 8 bytes
    unsigned short read16CS0(int fd, long offset);
    unsigned read32CS0(int fd, long offset);

    char read8CS1(int fd, long offset);

public:
    PciDevFunctions(char *filename);
    unsigned int getStatus(void);
    void initMove(void);

};


#endif //TWOCHANNELADAPTER_PCIDEVFUNCTIONS_H
