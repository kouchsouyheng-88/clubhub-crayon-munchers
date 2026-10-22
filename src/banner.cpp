// src/banner.cpp
#include "clubhub/banner.hpp"
using namespace std;

namespace clubhub {

string banner(string_view teamName) {
    const string rule(40, '=');
    string out;
    out += rule + "\n";
    out += "  ITC Club Hub  v" + string("CLUBHUB_VERSION") + '\n';
    out += "  Team: " + string(teamName) + '\n'; 
    out += rule + "\n";
    (void)teamName;
    return out;
}

}  // namespace clubhub