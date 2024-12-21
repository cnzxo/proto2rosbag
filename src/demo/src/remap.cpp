#include "remap.h"

void RemapFunc(const proto::User &src, demo::User &dst) {
    dst.name = src.name();
    dst.age = src.age();
}

void RemapFunc(const proto::Data &src, demo::Data &dst) {
    dst.data = src.data();
}
