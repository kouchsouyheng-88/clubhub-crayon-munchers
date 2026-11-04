#pragma once
// Lab 02 challenge, version 1.0, 2026-11-04.

#include <chrono>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace clubhub {

enum class SyncState { Pending, Sent, Accepted, Rejected };

struct QueuedCheckIn {
    std::string localId;  // Device-generated UUID, retained for every retry.
    std::string deviceId;
    std::string eventId;
    std::string studentId;
    std::chrono::sys_seconds scannedAt; // Device time, not authoritative.
    unsigned int attempts{0};
    SyncState state{SyncState::Pending};
    std::optional<std::string> rejectReason;
};

// In-memory C++ reference model for one phone's queue. The modelled PWA
// persists the equivalent records and transitions in IndexedDB transactions.
class CheckInQueue {
public:
    // False for a repeated localId or a student already queued for this event.
    // New captures start Pending, regardless of the caller's state fields.
    bool enqueue(QueuedCheckIn item) {
        if (item.localId.empty() || item.deviceId.empty() ||
            item.eventId.empty() || item.studentId.empty()) {
            throw std::invalid_argument{"check-in identifiers must not be empty"};
        }
        if (!items_.empty() && item.deviceId != items_.front().deviceId) {
            throw std::invalid_argument{"one queue must belong to one device"};
        }
        for (const auto& existing : items_) {
            if (existing.localId == item.localId ||
                (existing.eventId == item.eventId &&
                 existing.studentId == item.studentId)) {
                return false;
            }
        }
        item.attempts = 0;
        item.state = SyncState::Pending;
        item.rejectReason.reset();
        items_.push_back(std::move(item));
        return true;
    }

    // Oldest capture first: insertion order, independent of clock changes.
    // Sent items without a final answer are eligible for the next retry.
    // A sync coordinator must allow only one upload at a time per device.
    std::vector<QueuedCheckIn> pending() const {
        std::vector<QueuedCheckIn> result;
        for (const auto& item : items_) {
            if (item.state == SyncState::Pending || item.state == SyncState::Sent) {
                result.push_back(item);
            }
        }
        return result;
    }

    // Call immediately before each actual upload, including a retry.
    // Terminal records cannot be sent again.
    bool markSent(const std::string& localId) {
        auto& item = find(localId);
        if (isTerminal(item)) {
            return false;
        }
        ++item.attempts;
        item.state = SyncState::Sent;
        return true;
    }

    // Duplicate or late acknowledgements never replace a terminal decision.
    void markAccepted(const std::string& localId) {
        auto& item = find(localId);
        if (!isTerminal(item)) {
            item.state = SyncState::Accepted;
            item.rejectReason.reset();
        }
    }

    void markRejected(const std::string& localId, std::string reason) {
        auto& item = find(localId);
        if (isTerminal(item)) {
            return;
        }
        if (reason.empty()) {
            throw std::invalid_argument{"a rejected check-in needs a reason"};
        }
        item.state = SyncState::Rejected;
        item.rejectReason = std::move(reason);
    }

    // Includes rejected records so a front end can display the review list.
    const std::vector<QueuedCheckIn>& items() const noexcept {
        return items_;
    }

private:
    static bool isTerminal(const QueuedCheckIn& item) noexcept {
        return item.state == SyncState::Accepted || item.state == SyncState::Rejected;
    }

    QueuedCheckIn& find(const std::string& localId) {
        for (auto& item : items_) {
            if (item.localId == localId) {
                return item;
            }
        }
        throw std::out_of_range{"unknown local check-in ID"};
    }

    std::vector<QueuedCheckIn> items_;
};

} // namespace clubhub
