#include <iostream>
#include <vector>
#include <memory>

// ================= 子系统组件 =================
class LightSystem {
public:
    void setBrightness(int level) {
        std::cout << "[灯光] 亮度设置为 " << level << "%\n";
    }
    void setColorTemperature(int kelvin) {
        std::cout << "[灯光] 色温调整为 " << kelvin << "K\n";
    }
};

class ClimateControl {
private:
    bool isACOn = false;
public:
    void startAC(int targetTemp) {
        isACOn = true;
        std::cout << "[空调] 启动，目标温度 " << targetTemp << "°C\n";
    }
    void stopAC() {
        if(isACOn) {
            std::cout << "[空调] 关闭\n";
            isACOn = false;
        }
    }
    bool checkAirQuality() {
        // 模拟空气质量检测
        return rand() % 2;
    }
};

class EntertainmentSystem {
public:
    void startProjector() {
        std::cout << "[影音] 投影仪启动\n";
    }
    void setAudioMode(const std::string& mode) {
        std::cout << "[影音] 音频模式：" << mode << "\n";
    }
    void playContent(const std::string& source) {
        std::cout << "[影音] 播放内容源：" << source << "\n";
    }
};

class SecuritySystem {
public:
    void armAlarm() {
        std::cout << "[安防] 警报系统激活\n";
    }
    void disarmAlarm() {
        std::cout << "[安防] 警报系统解除\n";
    }
    bool checkDoors() {
        // 模拟门禁检测
        return rand() % 2;
    }
};

// ================= 外观层 =================
class SmartHomeFacade {
private:
    LightSystem lights;
    ClimateControl climate;
    EntertainmentSystem entertainment;
    SecuritySystem security;

    // 环境预设配置
    struct EnvironmentPreset {
        int brightness;
        int colorTemp;
        int roomTemp;
        std::string audioMode;
    };

    void applyPreset(const EnvironmentPreset& preset) {
        lights.setBrightness(preset.brightness);
        lights.setColorTemperature(preset.colorTemp);
        climate.startAC(preset.roomTemp);
        entertainment.setAudioMode(preset.audioMode);
    }

public:
    void enterHomeMode() {
        std::cout << "\n=== 进入家庭模式 ===\n";

        // 安全检查
        if(!security.checkDoors()) {
            std::cerr << "错误：检测到未关闭的门窗！\n";
            return;
        }
        security.disarmAlarm();

        // 环境设置
        EnvironmentPreset preset = {70, 4000, 22, "立体声"};
        applyPreset(preset);

        // 空气质量处理
        if(!climate.checkAirQuality()) {
            std::cout << "检测到空气污染，启动净化模式\n";
            climate.startAC(20); // 强力通风模式
        }

        std::cout << "准备就绪\n";
    }

    void startMovieNight() {
        std::cout << "\n=== 启动影院模式 ===\n";

        EnvironmentPreset preset = {30, 2700, 20, "杜比全景声"};
        applyPreset(preset);

        entertainment.startProjector();
        entertainment.playContent("蓝光播放器");

        climate.startAC(22);
        security.armAlarm(); // 启用安防
    }

    void leaveHome() {
        std::cout << "\n=== 离家模式 ===\n";
        lights.setBrightness(0);
        climate.stopAC();
        security.armAlarm();
        entertainment.setAudioMode("关闭");
    }
};

// ================= 客户端 =================
int main() {
    SmartHomeFacade smartHome;

    // 日常使用场景
    smartHome.enterHomeMode();    // 一键开启家庭模式
    smartHome.startMovieNight();  // 切换影院模式
    smartHome.leaveHome();        // 一键关闭所有系统

    return 0;
}
