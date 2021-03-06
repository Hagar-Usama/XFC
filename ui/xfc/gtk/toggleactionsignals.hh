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

/// @file xfc/gtk/toggleactionsignals.hh
/// @brief Gtk::ToggleAction virtual signal handlers.
///
/// Provides Gtk::ToggleActionSignals, an abstract base class that implements
/// the overridable virtual signal handlers for Gtk::ToggleAction objects.

#ifndef XFC_GTK_TOGGLE_ACTION_SIGNALS_HH
#define XFC_GTK_TOGGLE_ACTION_SIGNALS_HH

#ifndef XFC_GTK_ACTION_SIGNALS_HH
#include <xfc/gtk/actionsignals.hh>
#endif

namespace Xfc {

namespace Gtk {

/// @class ToggleActionSignals toggleactionsignals.hh xfc/gtk/toggleactionsignals.hh
/// @brief Abstract base class that implements the virtual signal handlers for Gtk::ToggleAction.

class ToggleActionSignals : public ActionSignals
{
protected:
/// @name Constructors
/// @{

	ToggleActionSignals(ToggleAction *action);
	///< Construct a new ToggleActionSignals object.
	///< @param action A ToggleAction object inheriting the ToggleActionSignals implementation.

	virtual ~ToggleActionSignals() = 0;
	///< Destructor.

/// @}

public:
/// @name Signal Handlers
/// @{

	virtual void on_toggled();
	///< Called when the action is toggled between its two states.

/// @}
};

} // namespace Gtk

} // namespace Xfc

#endif // XFC_GTK_TOGGLE_ACTION_SIGNALS_HH

