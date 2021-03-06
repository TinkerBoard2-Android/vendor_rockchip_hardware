/*
 * Copyright 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ROCKIT_HIDL_V1_0_UTILS_ROCKITPLAYERSERVICE_H
#define ROCKIT_HIDL_V1_0_UTILS_ROCKITPLAYERSERVICE_H

#include <rockchip/hardware/rockit/1.0/IRockitPlayer.h>
#include <rockchip/hardware/rockit/1.0/IRockitPlayerService.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

#include <utils/threads.h>
#include <utils/KeyedVector.h>

namespace rockchip {
namespace hardware {
namespace rockit {
namespace V1_0 {
namespace utils {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::IBinder;
using ::rockchip::hardware::rockit::V1_0::player_type;
using ::rockchip::hardware::rockit::V1_0::IRockitPlayer;
using ::rockchip::hardware::rockit::V1_0::Status;
using ::android::sp;
using ::android::wp;
using namespace android;

struct RockitPlayerService : public IRockitPlayerService {
    RockitPlayerService();

    Return<void>            createPlayer(createPlayer_cb _hidl_cb);
    Return<Status>          destroyPlayer(const sp<IRockitPlayer>& player);

protected:
    virtual ~RockitPlayerService();

private:
    void                    addClient(const sp<IRockitPlayer>& client);
    void                    removeClient(const sp<IRockitPlayer>& client);

    mutable Mutex                       mLock;
    SortedVector<sp<IRockitPlayer>>     mClients;
};



}  // namespace utils
}  // namespace V1_0
}  // namespace rockit
}  // namespace hardware
}  // namespace rockchip

#endif  // ROCKIT_HIDL_V1_0_UTILS_ROCKITPLAYERSERVICE_H