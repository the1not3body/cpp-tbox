#ifndef TBOX_EVENT_LIBEVENT_SINGAL_EVENT_H_20170715
#define TBOX_EVENT_LIBEVENT_SINGAL_EVENT_H_20170715

#include "../../signal_event.h"
#include <event2/event_struct.h>

namespace tbox {
namespace event {

class LibeventLoop;

class LibeventSignalEvent : public SignalEvent {
  public:
    explicit LibeventSignalEvent(LibeventLoop *wp_loop);
    virtual ~LibeventSignalEvent();

  public:
    virtual bool initialize(int signum, Mode mode);
    virtual void setCallback(const CallbackFunc &cb);

    virtual bool isEnabled() const;
    virtual bool enable();
    virtual bool disable();

    virtual Loop* getLoop() const;

  protected:
    static void OnEventCallback(int, short, void *args);
    void onEvent();

  private:
    LibeventLoop *wp_loop_;

    struct event event_;
    bool is_inited_;
    CallbackFunc cb_;
    int cb_level_;
};

}
}

#endif //TBOX_EVENT_LIBEVENT_SINGAL_EVENT_H_20170715