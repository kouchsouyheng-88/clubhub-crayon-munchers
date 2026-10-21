// src/banner.cpp
#include "clubhub/banner.hpp"
using namespace std;

namespace clubhub {

string banner(string_view teamName) {
    const string rule(40, '=');
    string out;
    // TODO: rule, "  ITC Club Hub  v" CLUBHUB_VERSION, "  Team: " + teamName,
    //       rule; every line ends in '\n'
    (void)teamName;
    return out;
}

}  // namespace clubhub