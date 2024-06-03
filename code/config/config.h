#ifndef CONFIG_H
#define CONFIG_H

#include "../server/webserver.h"
#include "nlohmann/json.hpp"
#include <string>

class Config {
public:
    Config();
    ~Config() {};

    std::string config_path;
    int port;
    std::string resources_path;
    int trigMode;
    int timeoutMS;
    bool OptLinger;
    int sqlPort;
    std::string sqlUser;
    std::string sqlPwd;
    std::string dbName;
    int connPoolNum;
    int threadNum;
    bool openLog;
    int logLevel;
    int logQueSize;

    void parse_config();
};

#endif