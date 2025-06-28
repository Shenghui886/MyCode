// #include <iostream>
// #include <memory>

// // 抽象状态接口
// class PlayerState {
// public:
//     virtual void play() = 0;
//     virtual void pause() = 0;
//     virtual void stop() = 0;
//     virtual ~PlayerState() = default;
// };

// // 具体状态类：播放状态
// class PlayingState : public PlayerState {
// public:
//     void play() override {
//         std::cout << "▶️ 已在播放状态，保持播放" << std::endl;
//     }

//     void pause() override {
//         std::cout << "⏸️ 暂停播放，切换至暂停状态" << std::endl;
//     }

//     void stop() override {
//         std::cout << "⏹️ 停止播放，切换至停止状态" << std::endl;
//     }
// };

// // 具体状态类：暂停状态
// class PausedState : public PlayerState {
// public:
//     void play() override {
//         std::cout << "▶️ 继续播放，切换至播放状态" << std::endl;
//     }

//     void pause() override {
//         std::cout << "⏸️ 已在暂停状态，无需操作" << std::endl;
//     }

//     void stop() override {
//         std::cout << "⏹️ 停止播放，切换至停止状态" << std::endl;
//     }
// };

// // 具体状态类：停止状态
// class StoppedState : public PlayerState {
// public:
//     void play() override {
//         std::cout << "▶️ 开始播放，切换至播放状态" << std::endl;
//     }

//     void pause() override {
//         std::cout << "⏸️ 停止状态无法暂停" << std::endl;
//     }

//     void stop() override {
//         std::cout << "⏹️ 已在停止状态，无需操作" << std::endl;
//     }
// };

// // 上下文类（音乐播放器）
// class MusicPlayer {
// private:
//     std::unique_ptr<PlayerState> currentState;

// public:
//     explicit MusicPlayer() : currentState(std::make_unique<StoppedState>()) {}

//     void setState(std::unique_ptr<PlayerState> newState) {
//         currentState = std::move(newState);
//     }

//     void play() {
//         currentState->play();
//         updateState();
//     }

//     void pause() {
//         currentState->pause();
//         updateState();
//     }

//     void stop() {
//         currentState->stop();
//         updateState();
//     }

// private:
//     void updateState() {
//         // 根据当前状态类型自动切换（此处简化逻辑，实际可基于具体业务）
//         if (dynamic_cast<PlayingState*>(currentState.get())) {
//             setState(std::make_unique<PausedState>());
//         } else if (dynamic_cast<PausedState*>(currentState.get())) {
//             setState(std::make_unique<PlayingState>());
//         }
//     }
// };

// int main() {
//     MusicPlayer player;

//     // 初始停止状态
//     player.play();  // 触发播放
//     player.pause(); // 暂停播放
//     player.play();  // 继续播放
//     player.stop();  // 停止播放
//     player.pause(); // 无效操作

//     return 0;
// }

// #include <iostream>
// #include <memory>

// // 前置声明（解决循环依赖）
// class MusicPlayer;

// // 抽象状态接口（参考网页3的状态接口设计[3](@ref)）
// class PlayerState {
// public:
//     virtual void play(MusicPlayer* player) = 0;
//     virtual void pause(MusicPlayer* player) = 0;
//     virtual void stop(MusicPlayer* player) = 0;
//     virtual ~PlayerState() = default;
// };

// // 具体状态类：停止状态（参考网页5的怪物状态实现[5](@ref)）
// class StoppedState : public PlayerState {
// public:
//     void play(MusicPlayer* player) override;
//     void pause(MusicPlayer* /*player*/) override {
//         std::cout << "❌ 停止状态无法暂停" << std::endl;
//     }
//     void stop(MusicPlayer* /*player*/) override {
//         std::cout << "⏹️ 已在停止状态" << std::endl;
//     }
// };

// // 具体状态类：播放状态（参考网页2的草稿状态流转[2](@ref)）
// class PlayingState : public PlayerState {
// public:
//     void play(MusicPlayer* /*player*/) override {
//         std::cout << "▶️ 保持播放状态" << std::endl;
//     }

//     void pause(MusicPlayer* player) override;

//     void stop(MusicPlayer* player) override {
//         std::cout << "⏹️ 停止播放，切换至停止状态" << std::endl;
//         player->setState(std::make_unique<StoppedState>());
//     }
// };

// // 具体状态类：暂停状态（参考网页4的订单状态转换[4](@ref)）
// class PausedState : public PlayerState {
// public:
//     void play(MusicPlayer* player) override {
//         std::cout << "▶️ 恢复播放，切换至播放状态" << std::endl;
//         player->setState(std::make_unique<PlayingState>());
//     }

//     void pause(MusicPlayer* /*player*/) override {
//         std::cout << "⏸️ 已在暂停状态" << std::endl;
//     }

//     void stop(MusicPlayer* player) override {
//         std::cout << "⏹️ 停止播放，切换至停止状态" << std::endl;
//         player->setState(std::make_unique<StoppedState>());
//     }
// };

// // 实现StoppedState的play方法（分离定义避免循环依赖）
// void StoppedState::play(MusicPlayer* player) {
//     std::cout << "▶️ 开始播放，切换至播放状态" << std::endl;
//     player->setState(std::make_unique<PlayingState>());
// }

// // 实现PlayingState的pause方法
// void PlayingState::pause(MusicPlayer* player) {
//     std::cout << "⏸️ 暂停播放，切换至暂停状态" << std::endl;
//     player->setState(std::make_unique<PausedState>());
// }

// // 上下文类（参考网页1的交通灯上下文设计[1](@ref)）
// class MusicPlayer {
// private:
//     std::unique_ptr<PlayerState> currentState;

// public:
//     MusicPlayer() : currentState(std::make_unique<StoppedState>()) {}

//     void setState(std::unique_ptr<PlayerState> newState) {
//         currentState = std::move(newState);
//     }

//     void play()  { currentState->play(this); }
//     void pause() { currentState->pause(this); }
//     void stop()  { currentState->stop(this); }
// };

// int main() {
//     MusicPlayer player;

//     // 测试用例（验证状态转换）
//     player.play();  // 停止 → 播放
//     player.pause(); // 播放 → 暂停
//     player.play();  // 暂停 → 播放
//     player.stop();  // 播放 → 停止
//     player.pause(); // 停止 → 无效操作

//     return 0;
// }

#include <iostream>

// 前向声明
class Elevator;

// 抽象状态接口
class State {
public:
    virtual void open(Elevator* elevator) = 0;
    virtual void close(Elevator* elevator) = 0;
    virtual void run(Elevator* elevator) = 0;
    virtual void stop(Elevator* elevator) = 0;
    virtual ~State() = default;
};

// 具体状态类声明（提前声明，便于后续定义）
class StoppedState;
class RunningState;
class OpenedState;
class ClosedState;

// 上下文类：电梯
class Elevator {
private:
    State* state;  // 当前状态
public:
    Elevator();
    void setState(State* newState);  // 状态切换方法

    // 对外暴露的操作接口
    void open()  { state->open(this); }
    void close() { state->close(this); }
    void run()   { state->run(this); }
    void stop()  { state->stop(this); }

    ~Elevator() { delete state; }
};

//--------- 具体状态类实现 -----------
class StoppedState : public State {
public:
    void open(Elevator* elevator) override;
    void close(Elevator* elevator) override;
    void run(Elevator* elevator) override;
    void stop(Elevator* elevator) override;
};

class OpenedState : public State {
public:
    void open(Elevator* elevator) override;
    void close(Elevator* elevator) override;
    void run(Elevator* elevator) override;
    void stop(Elevator* elevator) override;
};

class ClosedState : public State {
public:
    void open(Elevator* elevator) override;
    void close(Elevator* elevator) override;
    void run(Elevator* elevator) override;
    void stop(Elevator* elevator) override;
};

class RunningState : public State {
public:
    void open(Elevator* elevator) override;
    void close(Elevator* elevator) override;
    void run(Elevator* elevator) override;
    void stop(Elevator* elevator) override;
};

//--------- 状态类方法实现 -----------
// StoppedState
void StoppedState::open(Elevator* elevator) {
    std::cout << "[Stopped] 打开电梯门" << std::endl;
    elevator->setState(new OpenedState());
}
void StoppedState::close(Elevator* elevator) {
    std::cout << "[Stopped] 电梯门已是关闭状态" << std::endl;
}
void StoppedState::run(Elevator* elevator) {
    std::cout << "[Stopped] 电梯开始运行" << std::endl;
    elevator->setState(new RunningState());
}
void StoppedState::stop(Elevator* elevator) {
    std::cout << "[Stopped] 电梯已经是停止状态" << std::endl;
}

// OpenedState
void OpenedState::open(Elevator* elevator) {
    std::cout << "[Opened] 电梯门已经是开启状态" << std::endl;
}
void OpenedState::close(Elevator* elevator) {
    std::cout << "[Opened] 关闭电梯门" << std::endl;
    elevator->setState(new ClosedState());
}
void OpenedState::run(Elevator* elevator) {
    std::cout << "[Opened] 错误：必须先关闭门才能运行！" << std::endl;
}
void OpenedState::stop(Elevator* elevator) {
    std::cout << "[Opened] 电梯已经是停止状态" << std::endl;
}

// ClosedState
void ClosedState::open(Elevator* elevator) {
    std::cout << "[Closed] 打开电梯门" << std::endl;
    elevator->setState(new OpenedState());
}
void ClosedState::close(Elevator* elevator) {
    std::cout << "[Closed] 电梯门已是关闭状态" << std::endl;
}
void ClosedState::run(Elevator* elevator) {
    std::cout << "[Closed] 电梯开始运行" << std::endl;
    elevator->setState(new RunningState());
}
void ClosedState::stop(Elevator* elevator) {
    std::cout << "[Closed] 电梯停止运行" << std::endl;
    elevator->setState(new StoppedState());
}

// RunningState
void RunningState::open(Elevator* elevator) {
    std::cout << "[Running] 错误：运行中不能开门！" << std::endl;
}
void RunningState::close(Elevator* elevator) {
    std::cout << "[Running] 电梯门已是关闭状态" << std::endl;
}
void RunningState::run(Elevator* elevator) {
    std::cout << "[Running] 电梯已经在运行中" << std::endl;
}
void RunningState::stop(Elevator* elevator) {
    std::cout << "[Running] 电梯停止运行" << std::endl;
    elevator->setState(new StoppedState());
}

//--------- 上下文类方法实现 -----------
Elevator::Elevator() : state(new StoppedState()) {}

void Elevator::setState(State* newState) {
    delete state;   // 释放旧状态
    state = newState;
}

//--------- 客户端测试代码 -----------
int main() {
    Elevator elevator;

    elevator.open();  // Stopped → Opened
    elevator.run();   // 失败：门未关
    elevator.close(); // Opened → Closed
    elevator.run();   // Closed → Running
    elevator.stop();  // Running → Stopped

    return 0;
}