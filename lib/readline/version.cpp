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

#include <metashell/readline/version.hpp>
#include <metashell/to_string.hpp>

#ifdef USE_EDITLINE
#  include <editline/readline.h>
#else
#  include <readline/readline.h>
#endif

#include <string>

std::string metashell::readline::version()
{
#ifdef USE_EDITLINE
  return " ";
#elif defined(RL_VERSION_MAJOR) && defined(RL_VERSION_MINOR)
  return TO_STRING(RL_VERSION_MAJOR) "." TO_STRING(RL_VERSION_MINOR);
#elif defined(RL_READLINE_VERSION)
  return
    std::to_string(RL_READLINE_VERSION / 0x100) + "." +
    std::to_string(RL_READLINE_VERSION % 0x100);
#else
  return "unknown";
#endif
}

