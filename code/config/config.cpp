#include "config.h"
#include <fstream>
#include <string>

Config::Config() {
    config_path = "config.json";

    port = 8080;
    resources_path = "resources";
    trigMode = 3;
    timeoutMS = 60000;
    OptLinger = false;
    sqlPort = 3306;
    connPoolNum = 16;
    threadNum = 8;
    openLog = true;
    logLevel = 1;
    logQueSize = 1024;
}

void Config::parse_config() {
    using json = nlohmann::json;
    std::ifstream file(config_path);
    if ( !file ) {
        std::cerr << "Cannot open the config file" << std::endl;
        exit(1);
    }
    json config = json::parse(file);
    port = config["port"];
    resources_path = config["resources_path"];
    trigMode = config["trigMode"];
    timeoutMS = config["timeoutMS"];
    OptLinger = config["OptLinger"];
    sqlPort = config["sqlPort"];
    sqlUser = config["sqlUser"];
    sqlPwd = config["sqlPwd"];
    dbName = config["dbName"];
    connPoolNum = config["connPoolNum"];
    threadNum = config["threadNum"];
    openLog = config["openLog"];
    logLevel = config["logLevel"];
    logQueSize = config["logQueSize"];
}