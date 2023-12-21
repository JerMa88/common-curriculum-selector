#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <map>

#include "../data/list_CC_req.h"

struct Course {
    std::string className;
    std::map<std::string, CCReq> reqs;
    int reqCount;
};

#endif