#include <iostream>

#include "../datastructure/course.h"
#include "../datastructure/list.h"

class db2ds
{
private:
    DSList<DSList<Course> > courseMatrix;
    DSList<CCReq> userReqs;

public:
    db2ds();
    ~db2ds();

    void addReq(CCReq req); // main will add in each individual req in a loop; function will add each req into userReqs
    void addAllCourses(Course course); // function will add each reqs and each course of each req into the matrix
    void DEV_printReqs();
    void DEV_printCourses();
    DSList<DSList<Course> > getCourseMatrix(); // interceptor algorithm will use this to copy the matrix
};