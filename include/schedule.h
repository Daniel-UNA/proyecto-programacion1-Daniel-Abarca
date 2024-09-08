#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <ctime>

class Schedule {
private:
    struct tm date;
    struct tm startTime;
    struct tm endTime;

public:
    Schedule();
    Schedule(const struct tm& inputDate, const struct tm& inputStartTime, const struct tm& inputEndDate);

    struct tm getDate() const;
    struct tm getStartTime() const;
    struct tm getEndTime() const;

    void setDate(const struct tm& inputDate);
    void setStartTime(const struct tm& inputStartTime);
    void setEndTime(const struct tm& inputEndDate);

    ~Schedule();

};

#endif