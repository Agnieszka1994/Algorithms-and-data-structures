#include "pch.h"
#include "CalendarMatching.cpp"

bool compareCalendars(vector<StringMeeting> calendar1,
    vector<StringMeeting> calendar2) {
    if (calendar1.size() != calendar2.size()) {
        return false;
    }
    for (int i = 0; i < calendar1.size(); i++) {
        if (calendar1[i].start != calendar2[i].start ||
            calendar1[i].end != calendar2[i].end)
            return false;
    }
    return true;
}

TEST(SampleTestCase1, SampleTest) {
    vector<StringMeeting> calendar1 = {
                {"9:00", "10:30"}, {"12:00", "13:00"}, {"16:00", "18:00"} };
    StringMeeting dailyBounds1 = { "9:00", "20:00" };
    vector<StringMeeting> calendar2 = { {"10:00", "11:30"},
                                       {"12:30", "14:30"},
                                       {"14:30", "15:00"},
                                       {"16:00", "17:00"} };
    StringMeeting dailyBounds2 = { "10:00", "18:30" };
    int meetingDuration = 30;
    vector<StringMeeting> expected = {
        {"11:30", "12:00"}, {"15:00", "16:00"}, {"18:00", "18:30"} };
    vector<StringMeeting> actual = calendarMatching(
        calendar1, dailyBounds1, calendar2, dailyBounds2, meetingDuration);
    assert(compareCalendars(expected, actual));
};