/*
 *     .============.
 *    //  M A K E  / \
 *   //  C++ DEV  /   \
 *  //  E A S Y  /  \/ \
 * ++ ----------.  \/\  .
 *  \\     \     \ /\  /
 *   \\     \     \   /
 *    \\     \     \ /
 *     -============'
 *
 * Copyright (c) 2023 Hevake and contributors, all rights reserved.
 *
 * This file is part of cpp-tbox (https://github.com/cpp-main/cpp-tbox)
 * Use of this source code is governed by MIT license that can be found
 * in the LICENSE file in the root of the source tree. All contributing
 * project authors may be found in the CONTRIBUTORS.md file in the root
 * of the source tree.
 */
#ifndef TBOX_JSONRPC_HEADER_PROTO_H_20230812
#define TBOX_JSONRPC_HEADER_PROTO_H_20230812

#include "proto.h"

namespace tbox {
namespace jsonrpc {

class HeaderProto : public Proto {
  public:
    virtual ssize_t onRecvData(const void *data_ptr, size_t data_size) override;

  protected:
    virtual void sendJson(const Json &js) override;
};

}
}

#endif //TBOX_JSONRPC_HEADER_PROTO_H_20230812