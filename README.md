# TwoChannelAdapter

The tango-CS server for the "2 channel adapter" PNPI custom device.

Commands:
-----------------------------------
MotionLeft(int long step_count) <br>
MotionRight(int long step_count) <br>
Stop()      -- turn off power <br>

Attributes:
-----------------------------------
EncoderValue - read the value from encoder evry 500ms 

Install:
-----------------------------------
Just run "make". For this need the tango-cs library and C++ include

Regestration in jive (get started):
-----------------------------------
