#include <iostream>
#include "list_CC_req.h"

CCReq stringToCCReq(const std::string& str) {
    static const std::map<std::string, CCReq> stringToEnum = {
        {"AW", CCReq::AW},
        {"CA", CCReq::CA},
        {"CAA", CCReq::CAA},
        {"CAC", CCReq::CAC},
        {"CE", CCReq::CE},
        {"CIE", CCReq::CIE},
        {"CR", CCReq::CR},
        {"ES", CCReq::ES},
        {"GPS", CCReq::GPS},
        {"HC", CCReq::HC},
        {"HD", CCReq::HD},
        {"LAI", CCReq::LAI},
        {"OC", CCReq::OC},
        {"PREI", CCReq::PREI},
        {"QA", CCReq::QA},
        {"QR", CCReq::QR},
        {"SBS", CCReq::SBS},
        {"SLC", CCReq::SLC},
        {"SLM", CCReq::SLM},
        {"SLS", CCReq::SLS},
        {"TAS", CCReq::TAS},
        {"W", CCReq::W},
        {"INVALID", CCReq::INVALID}
    };

    auto it = stringToEnum.find(str);
    if (it != stringToEnum.end()) {
        return it->second;
    }

    // Default value when the string doesn't match any enum value
    return CCReq::INVALID;
}

listCCReq::listCCReq()
{
    
}

void listCCReq::printCC()
{
    for (const auto &entry : cc_map)
    {
        std::cout << entry.first << " stands for " << entry.second << std::endl;
    }
}
