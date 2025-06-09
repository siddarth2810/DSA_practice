#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class Meeting
{
private:
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};

ostream& operator<<(ostream& os, const Meeting& meeting)
{
    return os << "{ startTime: " << to_string(meeting.getStartTime())
              << ", endTime: " << to_string(meeting.getEndTime()) << " }";
}

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    if (meetings.empty()) return {}; 

    vector<Meeting> sortedMeetings = meetings;

    sort(sortedMeetings.begin(), sortedMeetings.end(), [](const Meeting& a, const Meeting& b) {
        return a.getStartTime() < b.getStartTime();
    });

    vector<Meeting> mergedMeetings;
    mergedMeetings.push_back(sortedMeetings[0]);

    for (size_t i = 1; i < sortedMeetings.size(); ++i) {
        Meeting& lastMerged = mergedMeetings.back();
        const Meeting& current = sortedMeetings[i];

        if (current.getStartTime() <= lastMerged.getEndTime()) {
            lastMerged.setEndTime(max(lastMerged.getEndTime(), current.getEndTime()));
        }
        else {
            mergedMeetings.push_back(current);
        }
    }

    return mergedMeetings;
}




















// tests

const lest::test tests[] = {
    {CASE("meetings overlap") {
        const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(2, 4)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 4)};
        EXPECT(actual == expected);
    }},

    {CASE("meetings touch") {
        const auto meetings = vector<Meeting> {Meeting(5, 6), Meeting(6, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(5, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("meeting contains other meeting") {
        const auto meetings = vector<Meeting> {Meeting(1, 8), Meeting(2, 5)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("meetings stay separate") {
        const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("multiple merged meetings") {
        const auto meetings = vector<Meeting> {Meeting(1, 4), Meeting(2, 5), Meeting(5, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("meetings not sorted") {
        const auto meetings = vector<Meeting> {Meeting(5, 8), Meeting(1, 4), Meeting(6, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 4), Meeting(5, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("one long meeting contains smaller meetings") {
        const auto meetings = vector<Meeting> {Meeting(1, 10), Meeting(2, 5), Meeting(6, 8),
            Meeting(9, 10), Meeting(10, 12)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 12)};
        EXPECT(actual == expected);
    }},

    {CASE("sample input") {
        const auto meetings = vector<Meeting> {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8),
            Meeting(10, 12), Meeting(9, 10)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)};
        EXPECT(actual == expected);
    }},
};
int main(int argc, char** argv)
{
   return lest::run(tests, argc, argv);
}
