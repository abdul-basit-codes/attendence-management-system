#ifndef ATTENDANCE_STATS_H
#define ATTENDANCE_STATS_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>

class AttendanceStats {
public:
    struct StudentData {
        std::string name;
        int totalDays;
        int presentDays;
        float percentage;
    };

    void addStudent(const std::string& name, int totalDays, int presentDays) {
        float pct = totalDays > 0 ? (float)presentDays / totalDays * 100.0f : 0;
        data.push_back({name, totalDays, presentDays, pct});
    }

    void clear() { data.clear(); }

    float getMeanPercentage() const {
        if (data.empty()) return 0;
        float sum = 0;
        for (const auto& s : data) sum += s.percentage;
        return sum / data.size();
    }

    float getMedianPercentage() const {
        if (data.empty()) return 0;
        std::vector<float> pcts;
        for (const auto& s : data) pcts.push_back(s.percentage);
        std::sort(pcts.begin(), pcts.end());
        size_t n = pcts.size();
        if (n % 2 == 0)
            return (pcts[n / 2 - 1] + pcts[n / 2]) / 2;
        return pcts[n / 2];
    }

    float getModePercentage() const {
        if (data.empty()) return 0;
        std::map<float, int> freq;
        for (const auto& s : data) freq[s.percentage]++;
        float mode = data[0].percentage;
        int maxCount = 0;
        for (const auto& [pct, count] : freq) {
            if (count > maxCount) { maxCount = count; mode = pct; }
        }
        return mode;
    }

    float getStdDeviation() const {
        if (data.size() < 2) return 0;
        float mean = getMeanPercentage();
        float sumSq = 0;
        for (const auto& s : data)
            sumSq += (s.percentage - mean) * (s.percentage - mean);
        return std::sqrt(sumSq / (data.size() - 1));
    }

    StudentData getTopPerformer() const {
        if (data.empty()) return {};
        auto it = std::max_element(data.begin(), data.end(),
            [](const StudentData& a, const StudentData& b) { return a.percentage < b.percentage; });
        return *it;
    }

    StudentData getLowestPerformer() const {
        if (data.empty()) return {};
        auto it = std::min_element(data.begin(), data.end(),
            [](const StudentData& a, const StudentData& b) { return a.percentage < b.percentage; });
        return *it;
    }

    int getAboveThreshold(float threshold) const {
        return std::count_if(data.begin(), data.end(),
            [threshold](const StudentData& s) { return s.percentage >= threshold; });
    }

    int getBelowThreshold(float threshold) const {
        return std::count_if(data.begin(), data.end(),
            [threshold](const StudentData& s) { return s.percentage < threshold; });
    }

    std::string generateReport() const {
        std::ostringstream ss;
        ss << "=== Attendance Statistics ===\n";
        ss << "Total Students: " << data.size() << "\n";
        ss << "Mean Rate: " << getMeanPercentage() << "%\n";
        ss << "Median Rate: " << getMedianPercentage() << "%\n";
        ss << "Mode Rate: " << getModePercentage() << "%\n";
        ss << "Std Deviation: " << getStdDeviation() << "\n";
        ss << "Top: " << getTopPerformer().name << " (" << getTopPerformer().percentage << "%)\n";
        ss << "Lowest: " << getLowestPerformer().name << " (" << getLowestPerformer().percentage << "%)\n";
        ss << "Above 75%: " << getAboveThreshold(75) << " students\n";
        ss << "Below 50%: " << getBelowThreshold(50) << " students\n";
        return ss.str();
    }

    size_t getCount() const { return data.size(); }

private:
    std::vector<StudentData> data;
};

#endif
