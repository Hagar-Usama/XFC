/*  XFC: Xfce Foundation Classes (User Interface Library)
 *  Copyright (C) 2004-2005 The XFC Development Team.
 *
 *  checkbutton.cc - GtkCheckButton C++ wrapper implementation
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

#include "checkbutton.hh"
#include "private/checkbuttonclass.hh"

using namespace Xfc;

/*  Gtk::CheckButton
 */

Gtk::CheckButton::CheckButton(GtkCheckButton *check_button, bool owns_reference)
: ToggleButton((GtkToggleButton*)check_button, owns_reference)
{
}

Gtk::CheckButton::CheckButton() 
: ToggleButton((GtkToggleButton*)CheckButtonClass::create())
{
}

Gtk::CheckButton::CheckButton(const char *label, bool use_underline)
: ToggleButton((GtkToggleButton*)CheckButtonClass::create())
{
	set_label(label);
	set_use_underline(use_underline);
}

Gtk::CheckButton::CheckButton(const String& label, bool use_underline)
: ToggleButton((GtkToggleButton*)CheckButtonClass::create())
{
	set_label(label);
	set_use_underline(use_underline);
}

Gtk::CheckButton::~CheckButton()
{
}

/*  Gtk::CheckButtonClass
 */

void
Gtk::CheckButtonClass::init(GtkCheckButtonClass *g_class)
{
	ToggleButtonClass::init((GtkToggleButtonClass*)g_class);
}

GType
Gtk::CheckButtonClass::get_type()
{
	static GType type = 0;
	if (!type)
	{
		type = G::TypeInstance::register_type(GTK_TYPE_CHECK_BUTTON, (GClassInitFunc)&init);
	}
	return type;
}

void*
Gtk::CheckButtonClass::create()
{
	return g_object_new(get_type(), 0);
}

