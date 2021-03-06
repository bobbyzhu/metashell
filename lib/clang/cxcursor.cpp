// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2013, Abel Sinkovics (abel@sinkovics.hu)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <metashell/clang/cxcursor.hpp>
#include <metashell/clang/cxstring.hpp>
#include <metashell/clang/cxtype.hpp>

using namespace metashell::clang;

cxcursor::cxcursor(CXCursor cursor_) : _cursor(cursor_) {}

std::string cxcursor::spelling() const
{
  return cxstring(clang_getCursorDisplayName(_cursor));
}

std::unique_ptr<metashell::iface::cxtype> cxcursor::type() const
{
  return
    std::unique_ptr<metashell::iface::cxtype>(
      new cxtype(clang_getCursorType(_cursor))
    );
}

bool cxcursor::variable_declaration() const
{
  return clang_getCursorKind(_cursor) == CXCursor_VarDecl;
}

