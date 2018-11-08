/*----- PROTECTED REGION ID(TwoChannelAdapter.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        TwoChannelAdapter.cpp
//
// description : C++ source for the TwoChannelAdapter class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               TwoChannelAdapter are implemented in this file.
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


#include <TwoChannelAdapter.h>
#include <TwoChannelAdapterClass.h>


/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter.cpp

/**
 *  TwoChannelAdapter class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  MotionRight   |  motion_right
//  MotionLeft    |  motion_left
//  Stop          |  stop
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//  EncoderValue  |  Tango::DevLong	Scalar
//================================================================

namespace TwoChannelAdapter_ns
{
/*----- PROTECTED REGION ID(TwoChannelAdapter::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::TwoChannelAdapter()
 *	Description : Constructors for a Tango device
 *                implementing the classTwoChannelAdapter
 */
//--------------------------------------------------------
TwoChannelAdapter::TwoChannelAdapter(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(TwoChannelAdapter::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::constructor_1
}
//--------------------------------------------------------
TwoChannelAdapter::TwoChannelAdapter(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(TwoChannelAdapter::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::constructor_2
}
//--------------------------------------------------------
TwoChannelAdapter::TwoChannelAdapter(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(TwoChannelAdapter::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void TwoChannelAdapter::delete_device()
{
	DEBUG_STREAM << "TwoChannelAdapter::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::delete_device) ENABLED START -----*/
	
	close(file_descriptor);
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::delete_device
	delete[] attr_EncoderValue_read;
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void TwoChannelAdapter::init_device()
{
	DEBUG_STREAM << "TwoChannelAdapter::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	
	attr_EncoderValue_read = new Tango::DevLong[1];
	/*----- PROTECTED REGION ID(TwoChannelAdapter::init_device) ENABLED START -----*/
	
	//	Initialize device

	file_descriptor = open(general_device_name.c_str(),O_RDWR);
	if(file_descriptor<0){
		device_status = "Error open device!!! "+general_device_name;
	}
	device_status = "device "+general_device_name+" is open =)\n";

	int channel = num_of_motor;

	initMotion(file_descriptor,channel);

	device_state = Tango::ON;

	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::init_device
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void TwoChannelAdapter::get_device_property()
{
	/*----- PROTECTED REGION ID(TwoChannelAdapter::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("speed"));
	dev_prop.push_back(Tango::DbDatum("num_of_motor"));
	dev_prop.push_back(Tango::DbDatum("general_device_name"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on TwoChannelAdapterClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		TwoChannelAdapterClass	*ds_class =
			(static_cast<TwoChannelAdapterClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize speed from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  speed;
		else {
			//	Try to initialize speed from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  speed;
		}
		//	And try to extract speed value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  speed;

		//	Try to initialize num_of_motor from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  num_of_motor;
		else {
			//	Try to initialize num_of_motor from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  num_of_motor;
		}
		//	And try to extract num_of_motor value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  num_of_motor;

		//	Try to initialize general_device_name from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  general_device_name;
		else {
			//	Try to initialize general_device_name from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  general_device_name;
		}
		//	And try to extract general_device_name value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  general_device_name;

	}

	/*----- PROTECTED REGION ID(TwoChannelAdapter::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void TwoChannelAdapter::always_executed_hook()
{
	DEBUG_STREAM << "TwoChannelAdapter::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void TwoChannelAdapter::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "TwoChannelAdapter::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::read_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute EncoderValue related method
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void TwoChannelAdapter::read_EncoderValue(Tango::Attribute &attr)
{
	DEBUG_STREAM << "TwoChannelAdapter::read_EncoderValue(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::read_EncoderValue) ENABLED START -----*/

    *(attr_EncoderValue_read) = (Tango::DevLong) readEncoder(file_descriptor,num_of_motor);

	//	Set the attribute value
	attr.set_value(attr_EncoderValue_read);
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::read_EncoderValue
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void TwoChannelAdapter::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(TwoChannelAdapter::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command MotionRight related method
 *	Description: 
 *
 *	@param argin 
 */
//--------------------------------------------------------
void TwoChannelAdapter::motion_right(Tango::DevLong argin)
{
	DEBUG_STREAM << "TwoChannelAdapter::MotionRight()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::motion_right) ENABLED START -----*/

	long int counter_step = argin;

	startMotion(file_descriptor,num_of_motor,speed,counter_step,false);
	device_state = Tango::DevState::MOVING;

	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::motion_right
}
//--------------------------------------------------------
/**
 *	Command MotionLeft related method
 *	Description: 
 *
 *	@param argin 
 */
//--------------------------------------------------------
void TwoChannelAdapter::motion_left(Tango::DevLong argin)
{
	DEBUG_STREAM << "TwoChannelAdapter::MotionLeft()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::motion_left) ENABLED START -----*/

	long int counter_step = argin;

	startMotion(file_descriptor,num_of_motor,speed,counter_step,true);
	device_state = Tango::DevState::MOVING;
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::motion_left
}
//--------------------------------------------------------
/**
 *	Command Stop related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void TwoChannelAdapter::stop()
{
	DEBUG_STREAM << "TwoChannelAdapter::Stop()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(TwoChannelAdapter::stop) ENABLED START -----*/
	
	stopMotion(file_descriptor,num_of_motor);
	device_state = Tango::DevState::DISABLE;
	
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::stop
}
//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapter::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void TwoChannelAdapter::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(TwoChannelAdapter::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::add_dynamic_commands
}

/*----- PROTECTED REGION ID(TwoChannelAdapter::namespace_ending) ENABLED START -----*/


char TwoChannelAdapter::read8CS0(int fd, long offset){
	char byte = 0x00;
	ioctl(fd,CS0_SET_ADDR,offset);
	read(fd,&byte,1);
	return byte;
}

short TwoChannelAdapter::read16CS0(int fd, long offset) {
	short int retval = 0x0000;
	retval = read8CS0(fd,offset);
	retval |= (read8CS0(fd,offset+1) << 8);
	return  retval;
}

int TwoChannelAdapter::read32CS0(int fd, long offset) {
	int retval = 0x00000000;
	retval = read16CS0(fd,offset) & 0xffff;
	retval |= (read16CS0(fd,offset+2) << 16);
	return retval;
}

char TwoChannelAdapter::read8CS1(int fd, long offset){
	char byte = 0x00;
	ioctl(fd,CS1_SET_ADDR,offset);
	read(fd,&byte,1);
	return byte;
}

short TwoChannelAdapter::read16CS1(int fd, long offset) {
	short int retval = 0x0000;
	retval = read8CS1(fd,offset);
	retval |= (read8CS1(fd,offset+1) << 8);
	return  retval;
}

int TwoChannelAdapter::read32CS1(int fd, long offset) {
	int retval = 0x00000000;
	retval = read16CS1(fd,offset) & 0xffff;
	retval |= (read16CS1(fd,offset+2) << 16);
	return retval;
}

int TwoChannelAdapter::write8CS0(int fd, long offset, char byte){
  int retval;
  retval = ioctl(fd,CS0_SET_ADDR,offset);
  retval = (int) write(fd,&byte,1);
  return retval;
}

int TwoChannelAdapter::write8CS1(int fd, long offset, char byte){
    int retval;
    retval = ioctl(fd,CS1_SET_ADDR,offset);
    retval = (int) write(fd,&byte,1);
    return retval;
}

int TwoChannelAdapter::write16CS0(int fd, long offset, unsigned short word){
  int retval;
  char byte1 = (char)(word & 0x00ff);
  char byte2 = (char)((word >> 8) & 0x00ff);
  retval = write8CS0(fd,offset,byte1);
  retval = write8CS0(fd,offset+1,byte2);
  return retval;
}

int TwoChannelAdapter::write24CS0(int fd, long offset, unsigned int twoword){
	int retval;
	char byte1 = (char)(twoword & 0xff);
	char byte2 = (char)((twoword >> 8) & 0xff);
	char byte3 = (char)((twoword >> 16) &0xff);

	retval = write8CS0(fd,offset,byte1);
	retval = write8CS0(fd,offset+1,byte2);
	retval = write8CS0(fd,offset+2,byte3);
	return retval;
}

int TwoChannelAdapter::write16CS1(int fd, long offset, unsigned short word){
	int retval;
	char byte1 = (char)(word & 0x00ff);
	char byte2 = (char)((word >> 8) & 0x00ff);
	retval = write8CS1(fd,offset,byte1);
	retval = write8CS1(fd,offset+1,byte2);
	return retval;
}

void TwoChannelAdapter::setBitCS0(int fd, long offset, int numbit){
	char tmp_byte;
	tmp_byte = read8CS0(fd,offset);
	tmp_byte |= (1<<numbit);
	write8CS0(fd,offset,tmp_byte);
	return;
}

void TwoChannelAdapter::unsetBitCS0(int fd, long offset, int numbit){
	char tmp_byte;
	tmp_byte = read8CS0(fd,offset);
	tmp_byte &= ~(1<<numbit);
	write8CS0(fd,offset,tmp_byte);
	return;
}


void TwoChannelAdapter::initMotion(int f,int channel){
	write8CS0(f,3,0x00);
	write8CS0(f,3,0x01);
	write16CS0(f,19,50); //set speed SSI
	write8CS0(f,3,0x03); // ENSSI, CLRSSI

	write8CS0(f,1+channel*16,0x00);

	write8CS0(f,0+channel*16,0x00);
	setBitCS0(f,0+channel*16,4);    // set 4 bit in 0x00 offset

	write8CS0(f,13+channel*16,26+1); //26 bit - encoder

	write8CS1(f,4+channel*16,0xff);
    write8CS1(f,5+channel*16,0xff);
    write8CS1(f,6+channel*16,0xff);
    write8CS1(f,7+channel*16,0x03);


    setBitCS0(f,0+channel*16,5);    //ENSSI

	setBitCS0(f,1+channel*16,6);


	  /* сброс триггеров */
	unsetBitCS0(f,1+channel*16,0);
	unsetBitCS0(f,1+channel*16,5);
	unsetBitCS0(f,1+channel*16,2); //unsetBitCS0(f,1,6);


	return;
}

void TwoChannelAdapter::stopMotion(int f,int channel){
  unsetBitCS0(f,0+channel*16,3);
  unsetBitCS0(f,1+channel*16,3);  //Power OFF
  return;
}

void TwoChannelAdapter::startMotion(int f,int channel,int lspeed,int count_steps,bool direction){
  int freq = 500000;
  //int freq = 100000;
  //int speed = 50000000/(freq*2);
  //unsigned int step_number = 1677721;
  unsigned int step_number = count_steps;

  bool enable_turnd = true;
  bool enable_end = true;


  setBitCS0(f,0+channel*16,0);     //REGISTER_CONTROL set 0 bit for enable step frequency

  unsetBitCS0(f,0+channel*16,2);     // enable step counter

  //speed = 0x018000;                  //!!!!!!!!!!!!!!
  //speed = 0x020000;
  write24CS0(f,4+channel*16,(int)(50000000/(lspeed*2)));

  setBitCS0(f,0+channel*16,6);     //enable write step counter
  write24CS0(f,7+channel*16,step_number);
  setBitCS0(f,1+channel*16,0);

  /* REGISTER_OPTIONS */
  if(enable_turnd){
    setBitCS0(f,1+channel*16,2);      //not turned
  }else{
    unsetBitCS0(f,1+channel*16,2);
  }

  if(enable_end){
    setBitCS0(f,1+channel*16,6);    //disable end
  }else{
    unsetBitCS0(f,1+channel*16,6);
  }

  if(direction){
    setBitCS0(f,1+channel*16,1);
  }else{
    unsetBitCS0(f,1+channel*16,1);
  }

  unsetBitCS0(f,1+channel*16,5);
  setBitCS0(f,0+channel*16,1);
  setBitCS0(f,0+channel*16,2);

  setBitCS0(f,0+channel*16,3);     //enable work step counter
  setBitCS0(f,1+channel*16,3);     //Power ON
  return;
}

long int TwoChannelAdapter::readEncoder(int f, int channel) {
    long int value = 0;
    long int retval = 0;

    char status = 0x00;

    /*
    struct timeval tv;
    gettimeofday(&tv,NULL);

    value=tv.tv_sec;
    */


    unsetBitCS0(f, 1 + channel * 16, 0);
    setBitCS0(f, 1 + channel * 16, 0);

    //printf("Channel: %d\n",channel);

    /*
    printf("0 byte: 0x%.2x\n",0xff&read8CS0(f,1+channel*16));
    printf("2 byte: 0x%.2x\n",0xff&read8CS0(f,2+channel*16));
    printf("2 byte: 0x%.2x\n",0xff&read8CS0(f,2+channel*16));
    printf("2 byte: 0x%.2x\n",0xff&read8CS0(f,2+channel*16));
    printf("2 byte: 0x%.2x\n",0xff&read8CS0(f,2+channel*16));
    */

    /*
    while(!(status&0x01)){
        status = read8CS0(f,2+channel*16);
        //printf("status: 0x%.2x\n",status & 0xff);
    }
     */


    //value = read32CS1(f, 0 + channel * 16);
    //std::cout << value << "\n";

    if (channel == 1) {
        printf("0x%.2x ", 0xff & read8CS1(f, 3 + channel * 16));
        printf("0x%.2x ", 0xff & read8CS1(f, 2 + channel * 16));
        printf("0x%.2x ", 0xff & read8CS1(f, 1 + channel * 16));
        printf("0x%.2x\n", 0xff & read8CS1(f, 0 + channel * 16));
    }

	/*
    for (retval=0;value;)
    {
        retval^=value;
        value=value>>1;
    }
    */

	retval = value;

    //if(channel==1) printf("%d\n",retval);

    return retval;
}


/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapter::namespace_ending
} //	namespace
