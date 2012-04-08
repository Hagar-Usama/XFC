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

/// @file xfc/gtk/plugsignals.hh
/// @brief Gtk::Plug virtual signal handlers.

#ifndef XFC_GTK_PLUG_SIGNALS_HH
#define XFC_GTK_PLUG_SIGNALS_HH

#ifndef XFC_GTK_WINDOW_SIGNALS_HH
#include <xfc/gtk/windowsignals.hh>
#endif

namespace Xfc {

namespace Gtk {

/// @class PlugSignals plugsignals.hh xfc/gtk/plugsignals.hh
/// @brief Abstract base class that implements the virtual signal handlers for Gtk::Plug.

class PlugSignals : public WindowSignals
{
protected:
/// @name Constructors
/// @{

	PlugSignals(Plug *plug);
	///< Constructs a new PlugSignals object.
	///< @param plug A Plug object inheriting the PlugSignals implementation.

	virtual ~PlugSignals() = 0;
	///< Destructor.
	
/// @}

public:
/// @name Signal Handlers
/// @{

	virtual void on_embedded();
	///< Called when a plug is embedded into a socket.

/// @}
};

} // namespace Gtk

} // namespace Xfc

#endif // XFC_GTK_PLUG_SIGNALS_HH

