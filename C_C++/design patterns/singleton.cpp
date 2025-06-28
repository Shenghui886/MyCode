// class Logger {
// public:
//     static Logger& getInstance() {
//         static Logger instance;
//         return instance;
//     }
//     void log(const std::string& msg) {
//         std::lock_guard<std::mutex> lock(mtx);
//         logFile << msg << std::endl;
//     }
// private:
//     std::ofstream logFile;
//     std::mutex mtx;
//     Logger() { logFile.open("app.log"); }
// };
