/*  XFC: Xfce Foundation Classes (User Interface Library)
 *  Copyright (C) 2004 The XFC Development Team.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */

/// @file xfc/gdk/displaymanagersignals.hh
/// @brief Gdk::DisplayManager virtual signal handlers.
///
/// Provides Gdk::DisplayManagerSignals, an abstract base class that implements
/// the overridable virtual signal handlers for Gdk::DisplayManager objects.

#ifndef XFC_GDK_DISPLAY_MANAGER_SIGNALS_HH
#define XFC_GDK_DISPLAY_MANAGER_SIGNALS_HH

#ifndef XFC_G_OBJECT_SIGNALS_HH
#include <xfc/glib/objectsignals.hh>
#endif

namespace Xfc {

namespace Gdk {

/// @class DisplayManagerSignals displaymanagersignals.hh xfc/gdk/displaymanagersignals.hh
/// @brief Abstract base class that implements the virtual signal handlers for Gdk::DisplayManager.

class DisplayManagerSignals : public G::ObjectSignals
{
protected:
/// @name Constructors
/// @{

	DisplayManagerSignals(DisplayManager *display_manager);
	///< Constructs a new DisplayManagerSignals object.
	///< @param display_manager A DisplayManager object inheriting the DisplayManagerSignals implementation.

	virtual ~DisplayManagerSignals() = 0;
	///< Destructor.

/// @}

public:
/// @name Signal Handlers
/// @{

	virtual void on_display_opened(Display& display);
	///< Called when a display is opened.
	///< @param display The Display being opened.

/// @}
};

} // namespace Gdk

} // namespace Xfc

#endif // XFC_GDK_DISPLAY_MANAGER_SIGNALS_HH

