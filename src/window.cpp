/*
Copyright (C) 2014 Lauri Kasanen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "main.h"

void window::hide() {
	g->run = 0;

	// Save the last used window position and size
	setting *s = getSetting("window.x", NULL);
	s->val.u = x();
	s = getSetting("window.y", NULL);
	s->val.u = y();
	s = getSetting("window.w", NULL);
	s->val.u = w();
	s = getSetting("window.h", NULL);
	s->val.u = h();

	Fl_Widget::hide();
}

static void cb(Fl_Widget *w, void*) {
	if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
		return;
	w->hide();
}

window::window(int x, int y, int w, int h): Fl_Double_Window(x, y, w, h) {
	callback(cb);
	color(fl_rgb_color(63, 72, 81));
}

int window::handle(const int e) {
	if (e == FL_SHORTCUT) {
		return 1;
	}

	return Fl_Window::handle(e);
}
