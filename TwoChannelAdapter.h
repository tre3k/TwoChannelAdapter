/*----- PROTECTED REGION ID(TwoChannelAdapter.h) ENABLED START -----*/
//=============================================================================
//
// file :        TwoChannelAdapter.h
//
// description : Include file for the TwoChannelAdapter class
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef TwoChannelAdapter_H
#define TwoChannelAdapter_H

#include <tango.h>


#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stropts.h>

#include "plx9030c.h"


/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter.h

/**
 *  TwoChannelAdapter class description:
 *    
 */

namespace TwoChannelAdapter_ns
{
/*----- PROTECTED REGION ID(TwoChannelAdapter::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::Additional Class Declarations

class TwoChannelAdapter : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(TwoChannelAdapter::Data Members) ENABLED START -----*/

public:
	int file_descriptor;

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::Data Members

//	Device property data members
public:
	//	speed:	
	Tango::DevULong	speed;
	//	num_of_motor:	
	Tango::DevUShort	num_of_motor;
	//	general_device_name:	
	string	general_device_name;


//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TwoChannelAdapter(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TwoChannelAdapter(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	TwoChannelAdapter(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~TwoChannelAdapter() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : TwoChannelAdapter::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);


	//--------------------------------------------------------
	/**
	 *	Method      : TwoChannelAdapter::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command MotionRight related method
	 *	Description: 
	 *
	 */
	virtual void motion_right();
	virtual bool is_MotionRight_allowed(const CORBA::Any &any);
	/**
	 *	Command MotionLeft related method
	 *	Description: 
	 *
	 */
	virtual void motion_left();
	virtual bool is_MotionLeft_allowed(const CORBA::Any &any);
	/**
	 *	Command Stop related method
	 *	Description: 
	 *
	 */
	virtual void stop();
	virtual bool is_Stop_allowed(const CORBA::Any &any);
	/**
	 *	Command setCountSteps related method
	 *	Description: 
	 *
	 *	@param argin 
	 */
	virtual void set_count_steps(Tango::DevLong argin);
	virtual bool is_setCountSteps_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : TwoChannelAdapter::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(TwoChannelAdapter::Additional Method prototypes) ENABLED START -----*/

	void initMotion(int f, int channel);
	char read8CS0(int fd, long offset);
	char read8CS1(int fd, long offset);
	int write8CS0(int fd, long offset, char byte);
	int write8CS1(int fd, long offset, char byte);
	int write16CS0(int fd, long offset, unsigned short word);
	int write24CS0(int fd, long offset, unsigned int twoword);
	int write16CS1(int fd, long offset, unsigned short word);
	void setBitCS0(int fd, long offset, int numbit);
	void unsetBitCS0(int fd, long offset, int numbit);
	void stopMotion(int f,int channel);
	void startMotion(int f,int channel,int lspeed,bool direction);

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::Additional Method prototypes
};

/*----- PROTECTED REGION ID(TwoChannelAdapter::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::Additional Classes Definitions

}	//	End of namespace

#endif   //	TwoChannelAdapter_H
