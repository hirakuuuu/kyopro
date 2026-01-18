#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

std::string getFirstDayOfNextMonth(const std::string& currentTimeStr) {
    std::istringstream ss(currentTimeStr);
    std::tm currentTime = {};

    ss >> std::get_time(&currentTime, "%Y-%m-%dT%H:%M");

    if (ss.fail()) {
        std::cerr << "Error: Failed to parse time string." << std::endl;
        return ""; // エラーを示す空文字列を返す
    }

    std::tm nextMonth = currentTime;
    nextMonth.tm_mon++;
    nextMonth.tm_mday = 1;
    nextMonth.tm_hour = 0;
    nextMonth.tm_min = 0;
    nextMonth.tm_sec = 0;

    // 年と月を調整
    if (nextMonth.tm_mon > 11) {
        nextMonth.tm_mon = 0;
        nextMonth.tm_year++;
    }

    std::mktime(&nextMonth); // tm_year, tm_mon の範囲を正規化

    std::stringstream output_ss;
    output_ss << std::put_time(&nextMonth, "%Y-%m-%dT%H:%M");
    return output_ss.str();
}

int main() {
    std::string now1 = "2025-05-24T18:45";
    std::string nextMonth1 = getFirstDayOfNextMonth(now1);
    std::cout << "\"" << now1 << "\" の次の月の最初の時刻: " << nextMonth1 << std::endl;

    std::string now2 = "2025-12-31T23:59";
    std::string nextMonth2 = getFirstDayOfNextMonth(now2);
    std::cout << "\"" << now2 << "\" の次の月の最初の時刻: " << nextMonth2 << std::endl;

    return 0;
}