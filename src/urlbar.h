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

#ifndef URL_H
#define URL_H

#include <FL/Fl_Widget.H>

#include "urlbutton.h"

class urlbar: public Fl_Widget {
public:
	urlbar(int x, int y, int w, int h);

	void draw() override;
	void resize(int x, int y, int w, int h) override;

private:
	void reposbuttons();
	urlbutton *prev, *back, *fwd, *next, *refresh;
};

#endif
