#ifndef TBOX_ACTION_ACTION_H_20221001
#define TBOX_ACTION_ACTION_H_20221001

#include <string>
#include <functional>

#include <tbox/base/defines.h>
#include <tbox/base/json_fwd.h>
#include <tbox/event/forward.h>

namespace tbox {
namespace action {

//! 动作类
class Action {
  public:
    explicit Action(event::Loop &loop);
    virtual ~Action();

    NONCOPYABLE(Action);
    IMMOVABLE(Action);

  public:
    //! 状态
    enum class State {
      kIdle,      //!< 未启动状态
      kRunning,   //!< 正在运行状态
      kPause,     //!< 暂停状态
      kFinished,  //!< 结束状态，自主通过 finish() 结束
      kStoped     //!< 停止状态，外部通过 stop() 结束
    };

    //! 结果
    enum class Result {
      kUnsure,    //!< 未知
      kSuccess,   //!< 成功
      kFail,      //!< 失败
    };

    virtual std::string type() const = 0;

    inline State state() const { return state_; }
    inline Result result() const { return result_; }

    inline void set_name(const std::string &name) { name_ = name; }
    inline std::string name() const { return name_; }

    //!< 设置结束回调
    using FinishCallback = std::function<void(bool is_succ)>;
    inline void setFinishCallback(const FinishCallback &cb) { finish_cb_ = cb; }

    virtual void toJson(Json &js) const;

    bool start();   //!< 开始
    bool pause();   //!< 暂停
    bool resume();  //!< 恢复
    bool stop();    //!< 停止
    void reset();   //!< 重置，将所有的状态恢复到刚构建状态

  protected:
    bool finish(bool is_succ);

    virtual bool onStart() { return true; }
    virtual bool onPause() { return true; }
    virtual bool onResume() { return true; }
    virtual bool onStop() { return true; }
    virtual void onReset() { }
    virtual void onFinished(bool is_succ) { }

  protected:
    event::Loop &loop_;

  private:
    std::string name_;
    FinishCallback finish_cb_;

    State state_ = State::kIdle;      //!< 状态
    Result result_ = Result::kUnsure; //!< 运行结果
};

//! 枚举转字串
std::string ToString(Action::State state);
std::string ToString(Action::Result result);

}
}

#endif //TBOX_ACTION_ACTION_H_20221001