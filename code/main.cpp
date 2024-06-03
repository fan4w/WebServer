/*
 * @Author       : mark
 * @Date         : 2020-06-18
 * @copyleft Apache 2.0
 */
#include <unistd.h>
#include "config/config.h"
#include "server/webserver.h"

int main() {
    /* 守护进程 后台运行 */
    //daemon(1, 0); 
    Config config;
    // WebServer server(
    //     1316, 3, 60000, false,             /* 端口 ET模式 timeoutMs 优雅退出  */
    //     3306, "root", "00000000", "webserver", /* Mysql配置 */
    //     12, 6, true, 1, 1024);             /* 连接池数量 线程池数量 日志开关 日志等级 日志异步队列容量 */
    config.parse_config();

    WebServer server(
        config.port, config.trigMode, config.timeoutMS, config.OptLinger, config.resources_path.c_str(),
        config.sqlPort, config.sqlUser.c_str(), config.sqlPwd.c_str(), config.dbName.c_str(),
        config.connPoolNum, config.threadNum, config.openLog, config.logLevel, config.logQueSize);
    server.Start();
}
