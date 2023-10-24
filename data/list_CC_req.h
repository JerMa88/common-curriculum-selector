#include <map>
#include <string>
enum class CCReq
{
    AW,
    CA,
    CAA,
    CAC,
    CE,
    CIE,
    CR,
    ES,
    GPS,
    HC,
    HD,
    LAI,
    OC,
    PREI,
    QA,
    QR,
    SBS,
    SLC,
    SLM,
    SLS,
    TAS,
    W,
    INVALID
};
CCReq stringToCCReq(const std::string& str);

class listCCReq
{
private:
    const std::map<std::string, std::string> cc_map = {
        {"AW", "Foundations: Academic Writing"},
        {"CA", "Breadth: Creativity and Aesthetics"},
        {"CAA", "Breadth: C&A: Analysis"},
        {"CAC", "Breadth: C&A: Creation"},
        {"CE", "P and E: Community Engagement"},
        {"CIE", "P and E: Civics and Indiv Ethics"},
        {"CR", "Foundations: Critical Reasoning"},
        {"ES", "Breadth: Exploring Science"},
        {"GPS", "P and E: Global Perspectives"},
        {"HC", "Breadth: Historical Contexts"},
        {"HD", "P and E: Human Diversity"},
        {"LAI", "Breadth: Lit Analysis and Interp"},
        {"OC", "P and E: Oral Communication"},
        {"PREI", "Breadth: Phil, Reli & Ethic Inqry"},
        {"QA", "P and E: Quantitative Applications"},
        {"QR", "Foundations: Quantitative Reasoning"},
        {"SBS", "Breadth: Social and Behavioral Sci"},
        {"SLC", "Foundations: Second Language Classical"},
        {"SLM", "Foundations: Second Language Modern"},
        {"SLS", "Foundations: Second Language Sign"},
        {"TAS", "Breadth: Tech Advances and Society"},
        {"W", "P and E: Writing"}};

public:
    listCCReq();
    void printCC();
};