#ifndef ATTENDANCE_STREAK_H
#define ATTENDANCE_STREAK_H

#include <vector>
#include <string>
#include <algorithm>

class AttendanceStreak {
public:
    struct DayRecord {
        std::string date;
        bool present;
    };

    void addRecord(const std::string& date, bool present) {
        records.push_back({date, present});
    }

    void clear() { records.clear(); }

    int getCurrentStreak() const {
        int streak = 0;
        for (int i = records.size() - 1; i >= 0; --i) {
            if (records[i].present) ++streak;
            else break;
        }
        return streak;
    }

    int getLongestStreak() const {
        int longest = 0, current = 0;
        for (const auto& r : records) {
            if (r.present) {
                ++current;
                if (current > longest) longest = current;
            } else {
                current = 0;
            }
        }
        return longest;
    }

    int getTotalPresent() const {
        return std::count_if(records.begin(), records.end(),
                             [](const DayRecord& r) { return r.present; });
    }

    int getTotalAbsent() const {
        return records.size() - getTotalPresent();
    }

    float getAttendanceRate() const {
        if (records.empty()) return 0;
        return (float)getTotalPresent() / records.size() * 100.0f;
    }

    int getAbsenceStreak() const {
        int streak = 0;
        for (int i = records.size() - 1; i >= 0; --i) {
            if (!records[i].present) ++streak;
            else break;
        }
        return streak;
    }

    size_t getTotalDays() const { return records.size(); }

private:
    std::vector<DayRecord> records;
};

#endif
