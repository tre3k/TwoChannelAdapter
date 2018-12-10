/*----- PROTECTED REGION ID(TwoChannelAdapterClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        TwoChannelAdapterClass.h
//
// description : Include for the TwoChannelAdapter root class.
//               This class is the singleton class for
//                the TwoChannelAdapter device class.
//               It contains all properties and methods which the 
//               TwoChannelAdapter requires only once e.g. the commands.
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


#ifndef TwoChannelAdapterClass_H
#define TwoChannelAdapterClass_H

#include <tango.h>
#include <TwoChannelAdapter.h>


/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass.h


namespace TwoChannelAdapter_ns
{
/*----- PROTECTED REGION ID(TwoChannelAdapterClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Position class definition
class PositionAttrib: public Tango::Attr
{
public:
	PositionAttrib():Attr("Position",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~PositionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<TwoChannelAdapter *>(dev))->read_Position(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<TwoChannelAdapter *>(dev))->write_Position(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<TwoChannelAdapter *>(dev))->is_Position_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command StopMove class definition
class StopMoveClass : public Tango::Command
{
public:
	StopMoveClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopMoveClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopMoveClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<TwoChannelAdapter *>(dev))->is_StopMove_allowed(any);}
};

//	Command RestMotor class definition
class RestMotorClass : public Tango::Command
{
public:
	RestMotorClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	RestMotorClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~RestMotorClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<TwoChannelAdapter *>(dev))->is_RestMotor_allowed(any);}
};


/**
 *	The TwoChannelAdapterClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  TwoChannelAdapterClass : public Tango::DeviceClass
#else
class TwoChannelAdapterClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static TwoChannelAdapterClass *init(const char *);
		static TwoChannelAdapterClass *instance();
		~TwoChannelAdapterClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		TwoChannelAdapterClass(string &);
		static TwoChannelAdapterClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	TwoChannelAdapter_H
