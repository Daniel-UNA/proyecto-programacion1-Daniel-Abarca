#include "schedule.h"



Schedule::Schedule() {
    time_t now = time(0);
    date = *localtime(&now);

    startTime = {};
    startTime.tm_hour = 0;
    startTime.tm_min = 0;
    startTime.tm_sec = 0;

    endTime = {};
    endTime.tm_hour = 0;
    endTime.tm_min = 0;
    endTime.tm_sec = 0;

}

Schedule::Schedule(const tm &inputDate, const tm &inputStartTime, const tm &inputEndDate) :
                    date(inputDate), startTime(inputStartTime), endTime(inputEndDate) {}

tm Schedule::getDate() const { return date; }

tm Schedule::getStartTime() const { return startTime; }

tm Schedule::getEndTime() const { return endTime; }

void Schedule::setDate(const tm &inputDate){
    date = inputDate;
}

void Schedule::setStartTime(const tm &inputStartTime) {
    startTime = inputStartTime;
}

void Schedule::setEndTime(const tm &inputEndDate) {
    endTime = inputEndDate;
}

Schedule::~Schedule() {
    //No more Schedule
}
