/*----- PROTECTED REGION ID(TwoChannelAdapterClass.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        TwoChannelAdapterClass.cpp
//
// description : C++ source for the TwoChannelAdapterClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the TwoChannelAdapter once per process.
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


#include <TwoChannelAdapterClass.h>

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass.cpp

//-------------------------------------------------------------------
/**
 *	Create TwoChannelAdapterClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_TwoChannelAdapter_class(const char *name) {
		return TwoChannelAdapter_ns::TwoChannelAdapterClass::init(name);
	}
}

namespace TwoChannelAdapter_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
TwoChannelAdapterClass *TwoChannelAdapterClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		TwoChannelAdapterClass::TwoChannelAdapterClass(string &s)
 * description : 	constructor for the TwoChannelAdapterClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
TwoChannelAdapterClass::TwoChannelAdapterClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering TwoChannelAdapterClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::constructor

	cout2 << "Leaving TwoChannelAdapterClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		TwoChannelAdapterClass::~TwoChannelAdapterClass()
 * description : 	destructor for the TwoChannelAdapterClass
 */
//--------------------------------------------------------
TwoChannelAdapterClass::~TwoChannelAdapterClass()
{
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		TwoChannelAdapterClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
TwoChannelAdapterClass *TwoChannelAdapterClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new TwoChannelAdapterClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		TwoChannelAdapterClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
TwoChannelAdapterClass *TwoChannelAdapterClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		StopMoveClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *StopMoveClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "StopMoveClass::execute(): arrived" << endl;
	((static_cast<TwoChannelAdapter *>(device))->stop_move());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ResetMotorClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ResetMotorClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "ResetMotorClass::execute(): arrived" << endl;
	((static_cast<TwoChannelAdapter *>(device))->reset_motor());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		MoveToLeftStepsClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *MoveToLeftStepsClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "MoveToLeftStepsClass::execute(): arrived" << endl;
	Tango::DevLong argin;
	extract(in_any, argin);
	((static_cast<TwoChannelAdapter *>(device))->move_to_left_steps(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		MoveToRightStepsClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *MoveToRightStepsClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "MoveToRightStepsClass::execute(): arrived" << endl;
	Tango::DevLong argin;
	extract(in_any, argin);
	((static_cast<TwoChannelAdapter *>(device))->move_to_right_steps(argin));
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum TwoChannelAdapterClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum TwoChannelAdapterClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum TwoChannelAdapterClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "channel";
	prop_desc = "0 channel or 1 channel";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "port_path";
	prop_desc = "";
	prop_def  = "/dev/plxdev0";
	vect_data.clear();
	vect_data.push_back("/dev/plxdev0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "frequency";
	prop_desc = "Frequency in Hz";
	prop_def  = "100";
	vect_data.clear();
	vect_data.push_back("100");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new TwoChannelAdapter(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		TwoChannelAdapter *dev = static_cast<TwoChannelAdapter *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::attribute_factory_before
	//	Attribute : Position
	PositionAttrib	*position = new PositionAttrib();
	Tango::UserDefaultAttrProp	position_prop;
	//	description	not set for Position
	//	label	not set for Position
	position_prop.set_unit("mm");
	//	standard_unit	not set for Position
	//	display_unit	not set for Position
	//	format	not set for Position
	//	max_value	not set for Position
	//	min_value	not set for Position
	//	max_alarm	not set for Position
	//	min_alarm	not set for Position
	//	max_warning	not set for Position
	//	min_warning	not set for Position
	//	delta_t	not set for Position
	//	delta_val	not set for Position
	
	position->set_default_properties(position_prop);
	//	Not Polled
	position->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(position);

	//	Attribute : ZeroPosition
	ZeroPositionAttrib	*zeroposition = new ZeroPositionAttrib();
	Tango::UserDefaultAttrProp	zeroposition_prop;
	//	description	not set for ZeroPosition
	//	label	not set for ZeroPosition
	//	unit	not set for ZeroPosition
	//	standard_unit	not set for ZeroPosition
	//	display_unit	not set for ZeroPosition
	//	format	not set for ZeroPosition
	//	max_value	not set for ZeroPosition
	//	min_value	not set for ZeroPosition
	//	max_alarm	not set for ZeroPosition
	//	min_alarm	not set for ZeroPosition
	//	max_warning	not set for ZeroPosition
	//	min_warning	not set for ZeroPosition
	//	delta_t	not set for ZeroPosition
	//	delta_val	not set for ZeroPosition
	
	zeroposition->set_default_properties(zeroposition_prop);
	//	Not Polled
	zeroposition->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(zeroposition);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::pipe_factory_before
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::command_factory()
{
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::command_factory_before


	//	Command StopMove
	StopMoveClass	*pStopMoveCmd =
		new StopMoveClass("StopMove",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pStopMoveCmd);

	//	Command ResetMotor
	ResetMotorClass	*pResetMotorCmd =
		new ResetMotorClass("ResetMotor",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pResetMotorCmd);

	//	Command MoveToLeftSteps
	MoveToLeftStepsClass	*pMoveToLeftStepsCmd =
		new MoveToLeftStepsClass("MoveToLeftSteps",
			Tango::DEV_LONG, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pMoveToLeftStepsCmd);

	//	Command MoveToRightSteps
	MoveToRightStepsClass	*pMoveToRightStepsCmd =
		new MoveToRightStepsClass("MoveToRightSteps",
			Tango::DEV_LONG, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pMoveToRightStepsCmd);

	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		TwoChannelAdapterClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		TwoChannelAdapterClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void TwoChannelAdapterClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		TwoChannelAdapter *dev = static_cast<TwoChannelAdapter *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(TwoChannelAdapterClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : TwoChannelAdapterClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *TwoChannelAdapterClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(TwoChannelAdapterClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	TwoChannelAdapterClass::Additional Methods
} //	namespace
