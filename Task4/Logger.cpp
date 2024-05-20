#include "pch.h"
#include "Logger.h"

Logger& Logger::Instance()
{
    static Logger instance;
    return instance;
}

void Logger::Log(const string& message)
{
    ofstream logFile;
    logFile.open("log.txt", ios_base::app);
    if (logFile.is_open())
    {
        logFile << GetCurrentTime() << " - " << message << endl;
        logFile.close();
    }
}

Logger::Logger() {}

string Logger::GetCurrentTime()
{
    time_t now = time(nullptr);
    struct tm timeinfo;
    char buf[80];
    localtime_s(&timeinfo, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &timeinfo);
    return string(buf);
}

Logger::~Logger()
{
}