/*
 *      Copyright (C) 2007-2013 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "IJoystick.h"

#include <SDL/SDL_joystick.h>
#include <string>

union SDL_Event;

class CJoystickSDL : public IJoystick
{
public:
  static void Initialize(JoystickArray &joysticks);
  static void DeInitialize(JoystickArray &joysticks);

  virtual ~CJoystickSDL() { }
  virtual void Update();
  virtual void Update(SDL_Event *joyEvent);
  virtual const SJoystick &GetState() const { return m_state; }

private:
  CJoystickSDL(std::string name, SDL_Joystick *pJoystick, unsigned int id);
  
  SDL_Joystick *m_pJoystick;
  SJoystick m_state;
};
