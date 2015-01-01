#ifndef METASHELL_SYSTEM_TEST_PROMPT_HPP
#define METASHELL_SYSTEM_TEST_PROMPT_HPP

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

#include "json_string.hpp"

#include <string>
#include <iosfwd>

namespace metashell_system_test
{
  class prompt
  {
  public:
    explicit prompt(const std::string& prompt_);
  
    const std::string& value() const;
  private:
    std::string _prompt;
  };
  
  std::ostream& operator<<(std::ostream& out_, const prompt& prompt_);

  json_string to_json_string(const prompt& p_);

  bool operator==(const prompt& prompt_, const json_string& s_);
}

#endif

