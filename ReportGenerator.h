#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

struct ReportEntry {
    int id;
    std::string name;
    int totalDays;
    int presentDays;
    int absentDays;
    float percentage;

    ReportEntry() : id(0), totalDays(0), presentDays(0), absentDays(0), percentage(0) {}
    ReportEntry(int id, const std::string& name, int total, int present)
        : id(id), name(name), totalDays(total), presentDays(present),
          absentDays(total - present),
          percentage(total > 0 ? (float)present / total * 100.0f : 0) {}
};

class ReportGenerator {
private:
    std::vector<ReportEntry> entries;

public:
    void addEntry(int id, const std::string& name, int totalDays, int presentDays) {
        entries.push_back(ReportEntry(id, name, totalDays, presentDays));
    }

    void clear() { entries.clear(); }

    std::string generateTextReport() const {
        std::ostringstream ss;
        ss << "╔══════════════════════════════════════════════════════════╗\n";
        ss << "║              ATTENDANCE REPORT                          ║\n";
        ss << "╠══════════════════════════════════════════════════════════╣\n";
        ss << "║ ID   │ Name               │ Present │ Absent │ Rate    ║\n";
        ss << "╠══════════════════════════════════════════════════════════╣\n";

        for (const auto& e : entries) {
            ss << "║ " << std::setw(4) << std::left << e.id << " │ "
               << std::setw(18) << std::left << e.name.substr(0, 18) << " │ "
               << std::setw(7) << std::right << e.presentDays << " │ "
               << std::setw(6) << std::right << e.absentDays << " │ "
               << std::setw(5) << std::right << std::fixed << std::setprecision(1) << e.percentage << "% ║\n";
        }

        ss << "╠══════════════════════════════════════════════════════════╣\n";

        // Summary
        int totalStudents = entries.size();
        float avgRate = 0;
        int bestIdx = 0, worstIdx = 0;
        for (size_t i = 0; i < entries.size(); i++) {
            avgRate += entries[i].percentage;
            if (entries[i].percentage > entries[bestIdx].percentage) bestIdx = i;
            if (entries[i].percentage < entries[worstIdx].percentage) worstIdx = i;
        }
        if (totalStudents > 0) avgRate /= totalStudents;

        ss << "║ Summary                                                ║\n";
        ss << "║ Students: " << totalStudents << "                                        ║\n";
        ss << "║ Average Rate: " << std::fixed << std::setprecision(1) << avgRate << "%                        ║\n";
        if (totalStudents > 0) {
            ss << "║ Best:  " << entries[bestIdx].name.substr(0, 15) << " (" << entries[bestIdx].percentage << "%)          ║\n";
            ss << "║ Worst: " << entries[worstIdx].name.substr(0, 15) << " (" << entries[worstIdx].percentage << "%)          ║\n";
        }
        ss << "╚══════════════════════════════════════════════════════════╝\n";

        return ss.str();
    }

    std::string generateCSV() const {
        std::ostringstream ss;
        ss << "ID,Name,TotalDays,Present,Absent,Rate%\n";
        for (const auto& e : entries) {
            ss << e.id << "," << e.name << "," << e.totalDays << ","
               << e.presentDays << "," << e.absentDays << ","
               << std::fixed << std::setprecision(1) << e.percentage << "\n";
        }
        return ss.str();
    }

    ReportEntry getBestStudent() const {
        if (entries.empty()) return ReportEntry();
        auto best = entries[0];
        for (const auto& e : entries)
            if (e.percentage > best.percentage) best = e;
        return best;
    }

    ReportEntry getWorstStudent() const {
        if (entries.empty()) return ReportEntry();
        auto worst = entries[0];
        for (const auto& e : entries)
            if (e.percentage < worst.percentage) worst = e;
        return worst;
    }

    void sortByName() {
        std::sort(entries.begin(), entries.end(),
                  [](const ReportEntry& a, const ReportEntry& b) { return a.name < b.name; });
    }

    void sortByRate() {
        std::sort(entries.begin(), entries.end(),
                  [](const ReportEntry& a, const ReportEntry& b) { return a.percentage > b.percentage; });
    }

    size_t getEntryCount() const { return entries.size(); }
};

#endif
