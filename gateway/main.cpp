#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

std::string getCurrentTime()
{
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%F %T", std::localtime(&now));
    return std::string(buf);
}

std::string getRandomHand()
{
    const char *hands[] = {"scissors", "stone", "paper"};
    return hands[std::rand() % 3];
}

std::string escapeJson(const std::string &str)
{
    std::ostringstream oss;
    for (char c : str)
    {
        if (c == '"')
            oss << "\\\"";
        else
            oss << c;
    }
    return oss.str();
}

int main()
{
    std::srand(std::time(nullptr));
    std::string logFile = "/home/ec2-user/gateway.log";
    std::ofstream log(logFile, std::ios::app);

    if (!log.is_open())
    {
        std::cerr << "로그 파일 열기 실패: " << logFile << std::endl;
        return 1;
    }

    while (true)
    {
        std::string timeStr = getCurrentTime();
        std::string hand = getRandomHand();

        // JSON 형식으로 로그 출력
        log << "{"
            << "\"timestamp\": \"" << escapeJson(timeStr) << "\", "
            << "\"type\": \"rps\", "
            << "\"choice\": \"" << hand << "\""
            << "}" << std::endl;

        log.flush();
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }

    return 0;
}
