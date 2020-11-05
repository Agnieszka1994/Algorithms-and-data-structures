#include <vector>
#include <string>
using namespace std;

struct StringMeeting {
	string start;
	string end;
};

struct Meeting {
	int start;
	int end;
};

vector<Meeting> updateCalendar(vector<StringMeeting>, StringMeeting);
vector<Meeting> mergeCalendars(vector<Meeting>, vector<Meeting>);
vector<Meeting> flattenCalendar(vector<Meeting>);
vector<StringMeeting> getMatchingSlots(vector<Meeting>, int);

int timeToMinutes(string);
string minutesToTime(int);

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
	StringMeeting dailyBounds1,
	vector<StringMeeting> calendar2,
	StringMeeting dailyBounds2,
	int meetingDuration) {
	vector<Meeting> updatedCalendar_1 = updateCalendar(calendar1, dailyBounds1);
	vector<Meeting> updatedCalendar_2 = updateCalendar(calendar2, dailyBounds2);
	vector<Meeting> mergedCalendar = mergeCalendars(updatedCalendar_1, updatedCalendar_2);
	vector<Meeting> flattenedCalendar = flattenCalendar(mergedCalendar);
	return getMatchingSlots(flattenedCalendar, meetingDuration);
}

vector<Meeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting bounds) {
	vector<StringMeeting> updatedCalendar;
	updatedCalendar.push_back({"0:00", bounds.start});
	updatedCalendar.insert(updatedCalendar.end(), calendar.begin(), calendar.end());
	updatedCalendar.push_back({bounds.end, "23:59" });
	vector<Meeting> calendarInMinutes;
	for (int i = 0; i < updatedCalendar.size(); i++) {
		calendarInMinutes.push_back({timeToMinutes(updatedCalendar[i].start), 
			timeToMinutes(updatedCalendar[i].end)});
	}
	return calendarInMinutes;
}

vector<Meeting> mergeCalendars(vector<Meeting> calendar_1, vector<Meeting> calendar_2) {
	vector<Meeting> mergedCalendar;
	int i = 0;
	int j = 0;
	while (i < calendar_1.size() && j < calendar_2.size()) {
		Meeting meeting_1 = calendar_1[i];
		Meeting meeting_2 = calendar_2[j];
		if (meeting_1.start < meeting_2.start) {
			mergedCalendar.push_back(meeting_1);
			i++;
		}
		else {
			mergedCalendar.push_back(meeting_2);
			j++;
		}
	}
	while (i < calendar_1.size()) {
		mergedCalendar.push_back(calendar_1[i++]);
	}
	while (j < calendar_2.size()) {
		mergedCalendar.push_back(calendar_2[j++]);
	}
	return mergedCalendar;
}


vector<Meeting> flattenCalendar(vector<Meeting> calendar) {
	vector<Meeting> flattened = { calendar[0] };
	for (int i = 1; i < calendar.size(); i++) {
		Meeting currentMeeting = calendar[i];
		Meeting prevMeeting = flattened[flattened.size() - 1];
		if (prevMeeting.end >= currentMeeting.start) {
			Meeting newPrevMeeting = { prevMeeting.start, max(prevMeeting.end, currentMeeting.end)};
			flattened[flattened.size() - 1] = newPrevMeeting;
		}
		else {
			flattened.push_back(currentMeeting);
		}
	}
	return flattened;
}

vector<StringMeeting> getMatchingSlots(vector<Meeting> calendar, int meetingDuration) {
	vector<Meeting> matchingSlots;
	for (int i = 1; i < calendar.size(); i++) {
		int start = calendar[i - 1].end;
		int end = calendar[i].start;
		int slotDuration = end - start;
		if (slotDuration >= meetingDuration) {
			matchingSlots.push_back({start, end});
		}
	}

	vector<StringMeeting> matchingSlotsStr;
	for (int i = 0; i < matchingSlots.size(); i++) {
		matchingSlotsStr.push_back({ minutesToTime(matchingSlots[i].start),
			minutesToTime(matchingSlots[i].end) });
	}
	return matchingSlotsStr;
}


int timeToMinutes(string time) {
	int pos = time.find(":");
	int hours = stoi(time.substr(0, pos));
	int minutes = stoi(time.substr(pos + 1, time.length()));
	return hours * 60 + minutes;
}

string minutesToTime(int minutes) {
	int hours = minutes / 60;
	int min = minutes % 60;
	string hoursStr = to_string(hours);
	string minutesStr = min < 10 ? "0" + to_string(min) : to_string(min);
	return hoursStr + ":" + minutesStr;
}