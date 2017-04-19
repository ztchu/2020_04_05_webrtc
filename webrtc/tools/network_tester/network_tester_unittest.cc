/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#ifdef WEBRTC_NETWORK_TESTER_TEST_ENABLED

#include "webrtc/tools/network_tester/test_controller.h"

#include "webrtc/base/gunit.h"
#include "webrtc/test/gtest.h"
#include "webrtc/test/testsupport/fileutils.h"

namespace webrtc {

TEST(NetworkTesterTest, ServerClient) {
  TestController client(
      0, 0, webrtc::test::ResourcePath("network_tester/client_config", "dat"));
  TestController server(
      9090, 9090,
      webrtc::test::ResourcePath("network_tester/server_config", "dat"));
  client.SendConnectTo("127.0.0.1", 9090);
  EXPECT_TRUE_WAIT(server.IsTestDone() && client.IsTestDone(), 2000);
}

}  // namespace webrtc

#endif  // WEBRTC_NETWORK_TESTER_TEST_ENABLED
