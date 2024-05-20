
#pragma once
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Logger
{
public:
    enum LogLevel {
        INFO,
        WARNING,
        ERR
    };

    static Logger& Instance();
    void Log(const string& message, LogLevel level = INFO);

private:
    Logger();
    ~Logger();
    string GetCurrentTime();
    string LogLevelToString(LogLevel level);
};
