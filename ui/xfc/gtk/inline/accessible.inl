/*  XFC: Xfce Foundation Classes (User Interface Library)
 *  Copyright (C) 2004 The XFC Development Team.
 *
 *  accessible.inl - Gtk::Accessible inline functions
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

inline GtkAccessible*
Xfc::Gtk::Accessible::gtk_accessible() const
{
	return reinterpret_cast<GtkAccessible*>(instance_);
}

inline Xfc::Gtk::Accessible::operator GtkAccessible* () const
{
	return this ? gtk_accessible() : 0;
}

inline void
Xfc::Gtk::Accessible::connect_widget_destroyed()
{
	gtk_accessible_connect_widget_destroyed(gtk_accessible());
}

