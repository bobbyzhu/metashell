// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2015, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/clang/version.hpp>
#include <metashell/clang/cxstring.hpp>

#include <metashell/clang_revision.hpp>

#include <clang-c/Index.h>

#include <boost/preprocessor/stringize.hpp>

using namespace metashell::clang;

std::string metashell::clang::libclang_version()
{
  return
    std::string(cxstring(clang_getClangVersion()))
    + " (r" BOOST_PP_STRINGIZE(METASHELL_CLANG_REVISION) ")";
}

