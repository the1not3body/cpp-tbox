#ifndef TBOX_TELNETD_TERMINAL_H_20220128
#define TBOX_TELNETD_TERMINAL_H_20220128

#include "interface.h"

namespace tbox::terminal {

class Terminal : public TerminalInteract,
                 public TerminalBuild {
  public:
    Terminal();
    ~Terminal();

  public:
    SessionToken newSession(Connection *wp_conn) override;
    bool deleteSession(const SessionToken &st) override;

    bool onBegin(const SessionToken &st) override;
    bool onRecvString(const SessionToken &st, const std::string &str) override;
    bool onRecvWindowSize(const SessionToken &st, uint16_t w, uint16_t h) override;
    bool onExit(const SessionToken &st) override;

  public:
    NodeToken create(const FuncInfo &info) override;
    NodeToken create(const DirInfo &info) override;
    NodeToken root() const override;
    NodeToken find(const std::string &path) const override;
    bool mount(const NodeToken &parent, const NodeToken &child) override;
    bool list(const NodeToken &token, std::vector<NodeInfo> &node_vec) const override;

  private:
    class Impl;
    Impl *impl_ = nullptr;
};

}

#endif //TBOX_TELNETD_TERMINAL_H_20220128
