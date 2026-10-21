// include/clubhub/banner.hpp
#ifndef BANNER_HPP
#define BANNER_HPP

#include <string>
#include <string_view>
using namespace std;

namespace clubhub {

// The team name printed at start-up. TODO: your team name.
inline constexpr string_view kTeamName = "Crayon Munchers";

// Returns the start-up banner, one line per row, ending in '\n'.
[[nodiscard]] string banner(string_view teamName);

}  // namespace clubhub

#endif  // BANNER_HPP