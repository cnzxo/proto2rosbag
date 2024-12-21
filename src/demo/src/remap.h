#include <iostream>

#include "demo/User.h"
#include "demo/Data.h"
#include "User.pb.h"
#include "Data.pb.h"

void RemapFunc(const proto::User &src, demo::User &dst);
void RemapFunc(const proto::Data &src, demo::Data &dst);

template <typename Tsrc, typename Tdst>
void RemapFunc(const Tsrc &src, Tdst &dst) {
    RemapFunc(src, dst);
}
