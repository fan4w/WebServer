#include "config.h"

int main() {
    Config config;
    config.parse_config();
    std::cout << config.port << config.trigMode << config.timeoutMS << config.OptLinger,
        config.sqlPort;
    std::cout << config.sqlUser << config.sqlPwd << config.dbName <<
        config.connPoolNum << config.threadNum << config.openLog << config.logLevel << config.logQueSize;
    return 0;
}