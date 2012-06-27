#include "DateTime.hpp"
#include "Stopwatch.hpp"
#include "NativeTimers.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    cout << "size: " << sizeof(DateTime) << endl;

    DateTime a = DateTime::LocalTime();
    DateTime b = a.DateOnly();

    TimeSpan gap = a - b;

    cout << gap << endl;

    a += TimeSpan::FromMinutes(5);

    int day = a.DayOfWeek();
    cout << DateTime::DayToString(day) << endl;
    cout << "5 minutes from now: " << a << endl;
    cout << "today with date only: " << a.DateOnly() << endl;
    cout << "standard UTC time: " << DateTime::UtcTime() << endl;
    cout << "native UTC time: " << GetNativeTime() << endl;

    a.Set(2012, 12, 31);
    cout << "Dec 31, yes? " << a << endl;
    cout << a.Ticks() << endl;

    ResetTimer();
    Stopwatch stopwatch;
    stopwatch.Start();
    TimeSpan sleepTime = TimeSpan::FromSeconds(1)
        + TimeSpan::FromMilliseconds(500);
    Sleep(sleepTime);
    cout << stopwatch.Elapsed() << endl;

    return 0;
}
