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
 
/// @file xfc/gtk/adjustmentsignals.hh
/// @brief Gtk::Adjustment virtual signal handlers.
///
/// Provides Gtk::AdjustmentSignals, an abstract base class that implements
/// the overridable virtual signal handlers for Gtk::Adjustment.

#ifndef XFC_GTK_ADJUSTMENT_SIGNALS_HH
#define XFC_GTK_ADJUSTMENT_SIGNALS_HH

#ifndef XFC_GTK_OBJECT_SIGNALS_HH
#include <xfc/gtk/objectsignals.hh>
#endif

namespace Xfc {

namespace Gtk {

/// @class AdjustmentSignals adjustmentsignals.hh xfc/gtk/adjustmentsignals.hh
/// @brief Abstract base class that implements the virtual signal handlers for Gtk::Adjustment.

class AdjustmentSignals : public ObjectSignals
{
protected:
/// @name Constructors
/// @{

	AdjustmentSignals(Adjustment *adjustment);
	///< Constructs a new AdjustmentSignals.
	///< @param adjustment An Adjustment object inheriting the AdjustmentSignals implementation.

	virtual ~AdjustmentSignals() = 0;
	///< Destructor.
	
/// @}

public:
/// @name Signal Handlers
/// @{

	virtual void on_changed();
	///< Called when one or more of the Adjustment fields have been changed, other than the value field.

	virtual void on_value_changed();
	///< Called when the Adjustment value field has been changed.

/// @}
};

} // namespace Gtk

} // namespace Xfc

#endif // XFC_GTK_ADJUSTMENT_SIGNALS_HH

