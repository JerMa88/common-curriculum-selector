#include <iostream>

#include "./db2ds.h"

db2ds::db2ds() {}
db2ds::~db2ds() {}

void db2ds::addReq(CCReq req)
{
    userReqs.push_back(req);
}        // main will add in each individual req in a loop; function will add each req into userReqs
void db2ds::addAllCourses(Course course)
{
    for (CCReq Req: userReqs)
    {
        
    }
    courseMatrix.push_back(eachReq);

}// function will add each reqs and each course of each req into the matrix
void db2ds::DEV_printReqs()
{
    std::cout << "Printing all requirements...\n";
    for (CCReq Req: userReqs)
    {
        std::cout << Req << "\n";
    }
}
void db2ds::DEV_printCourses()
{
    std::cout << "Printing all courses...\n";
    for (DSList<Course> eachReqList: courseMatrix)
    {
        for (Course course: eachReqList)
        {
            std::cout << course << "\n";
        }
    }
}
DSList<DSList<Course>> db2ds::getCourseMatrix()
{
    return courseMatrix;
} // interceptor algorithm will use this to copy the matrix
