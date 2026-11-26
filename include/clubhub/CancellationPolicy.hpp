#ifndef CANCELLATIONPOLICY_HPP
#define CANCELLATIONPOLICY_HPP

#include <chrono>

namespace clubhub {
    [[nodiscard]] constexpr bool canCancel(std::chrono::sys_seconds now,
                                        std::chrono::sys_seconds start) {
        using namespace std::chrono_literals;
        return start - now >= 24h;
    }
}

#endif