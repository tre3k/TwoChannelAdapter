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
#define STATUS_STOP_MOTION      0x10
#define STATUS_MOVE             0x20

class PciDevFunctions {
private:
    int file_descriptor;
    int channel;
    unsigned int status;

    /* functions for read data from the chip select 0 (2 bar from PCI space) */
    unsigned char read8CS0(int fd, long offset);                                        // read 1 byte
    unsigned short read16CS0(int fd, long offset);                                      // read 2 bytes
    unsigned read32CS0(int fd, long offset);                                            // read 4 bytes

    /* functions for read data from the chip select 1 (3 bar from PCI space) */
    unsigned char read8CS1(int fd, long offset);                                        // read 1 byte
    unsigned short read16CS1(int fd, long offset);                                      // read 2 bytes
    unsigned read32CS1(int fd, long offset);                                            // read 4 bytes

    /* functions for write data from the chip select 0 (2 bar from PCI space) */
    int write8CS0(int fd, long offset, char byte);                                      // write 1 byte
    int write16CS0(int fd, long offset, unsigned short word);                           // write 2 bytes
    int write24CS0(int fd, long offset, unsigned int twoword);                          // write 24 bits

    /* functions for write data from the chip select 1 (3 bar from PCI space) */
    int write8CS1(int fd, long offset, char byte);                                      // write 1 byte
    int write16CS1(int fd, long offset, unsigned short word);                           // write 2 bytes

    /* function for set the selective bit on CS0 region */
    void setBitCS0(int fd, long offset, int numbit);
    void unsetBitCS0(int fd, long offset, int numbit);
    // -- offset - number of byte
    // -- numbit - number of bit

public:
    PciDevFunctions(const char *filename);
    unsigned int getStatus(void);
    void initMove(void);

    void stopMotion(int channel);

};


#endif //TWOCHANNELADAPTER_PCIDEVFUNCTIONS_H
