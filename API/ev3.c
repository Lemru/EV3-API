/*
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Initial Developer of this code is Simón Rodriguez Perez.
 * Portions created by Simón Rodriguez Perez are Copyright (C) 2014-2015 Simón Rodriguez Perez.
 * All Rights Reserved.
 *
 */

#include "ev3.h"

static bool initialized;
int InitEV3()
{
	OutputInit();
	InitSensors();
	ButtonLedInit();
	LcdInit();
	LcdClean();
	SoundInit();
	initialized = true;

	return 1;
}


int CloseEV3()
{
	OutputClose();
	ButtonLedClose();
	SoundClose();

	return 1;
}


int ExitEV3()
{

	OutputExit();
	ButtonLedExit();
	LcdExit();
	SoundExit();
	initialized = false;

	return 1;
}

int FreeEV3()
{
	OutputClose();
	ButtonLedClose();
	SoundClose();
	OutputExit();
	ButtonLedExit();
	LcdExit();
	SoundExit();
	initialized = false;

	return 1;
}

bool EV3IsInitialized(void)
{
	return initialized;
}
