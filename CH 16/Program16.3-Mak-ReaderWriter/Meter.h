#ifndef METER_H_
#define METER_H_

#include <thread>
#include <shared_mutex>
#include <time.h>

using namespace std;
using namespace std::chrono;

class Meter
{
public:
    Meter()
        : setting(0), active_technicians_count(TECHNICIANS_COUNT)
    {
        srand(time(0));
        start_time = steady_clock::now();
    }

    void run();

private:
    const int MAX_SETTING_LEVEL         =  4;
    const int TECHNICIANS_COUNT         =  3;
    const int TECHNICIAN_TURNS          =  3;
    const int MIN_TECHNICIAN_SLEEP_TIME = 10;
    const int MAX_TECHNICIAN_SLEEP_TIME = 20;
    const int MAX_LOGGER_SLEEP_TIME     = 15;
    const int LOGGERS_COUNT             =  3;
    const int LOGGING_TIME              =  3;
    const int LOGGER_PRINT_MARGIN       = 25;

    int setting;
    int active_technicians_count;

    shared_mutex meter_mutex;
    mutex print_mutex;

    void set_meter(const int thread_id);
    void log_meter(const int thread_id);

    steady_clock::time_point start_time;

    int elapsed_seconds()
    {
        return duration_cast<seconds>(
                        steady_clock::now() - start_time).count();
    }
};

#endif /* METER_H_ */
