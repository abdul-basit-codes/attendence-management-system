#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

class DateUtils {
public:
    static std::string today() {
        time_t now = time(nullptr);
        tm ltm;
        localtime_s(&ltm, &now);
        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(4) << (ltm.tm_year + 1900) << "-"
           << std::setw(2) << (ltm.tm_mon + 1) << "-"
           << std::setw(2) << ltm.tm_mday;
        return ss.str();
    }

    static std::string now() {
        time_t now = time(nullptr);
        tm ltm;
        localtime_s(&ltm, &now);
        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(2) << ltm.tm_hour << ":"
           << std::setw(2) << ltm.tm_min << ":"
           << std::setw(2) << ltm.tm_sec;
        return ss.str();
    }

    static std::string datetime() {
        return today() + " " + now();
    }

    static int dayOfWeek() {
        time_t now = time(nullptr);
        tm ltm;
        localtime_s(&ltm, &now);
        return ltm.tm_wday; // 0=Sunday, 6=Saturday
    }

    static std::string dayOfWeekName() {
        const char* names[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        return names[dayOfWeek()];
    }

    static bool isWeekend() {
        int dow = dayOfWeek();
        return dow == 0 || dow == 6;
    }

    static int daysBetween(const std::string& date1, const std::string& date2) {
        tm t1 = {}, t2 = {};
        std::istringstream s1(date1), s2(date2);
        int y, m, d;
        char sep;
        s1 >> y >> sep >> m >> sep >> d; t1.tm_year = y - 1900; t1.tm_mon = m - 1; t1.tm_mday = d;
        s2 >> y >> sep >> m >> sep >> d; t2.tm_year = y - 1900; t2.tm_mon = m - 1; t2.tm_mday = d;
        return std::abs((int)difftime(mktime(&t2), mktime(&t1)) / 86400);
    }

    static std::string formatDate(int year, int month, int day) {
        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(4) << year << "-"
           << std::setw(2) << month << "-" << std::setw(2) << day;
        return ss.str();
    }
};

#endif
