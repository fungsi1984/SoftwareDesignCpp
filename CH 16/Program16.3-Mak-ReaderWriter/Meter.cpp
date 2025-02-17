#include "Meter.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <shared_mutex>

using namespace std;

void Meter::run()
{
    thread technicians[TECHNICIANS_COUNT];
    thread loggers[LOGGERS_COUNT];

    for (int i = 0; i < TECHNICIANS_COUNT; i++)
    {
        technicians[i] = thread(&Meter::set_meter, this, i + 1);
    }

    for (int i = 0; i < LOGGERS_COUNT; i++)
    {
        loggers[i] = thread(&Meter::log_meter, this, i + 1);
    }

    for (int i = 0; i < TECHNICIANS_COUNT; i++)
    {
        technicians[i].join();
    }

    for (int i = 0; i < LOGGERS_COUNT; i++)
    {
        loggers[i].join();
    }
}

void Meter::set_meter(const int thread_id)
{
    for (int turn = 1; turn <= TECHNICIAN_TURNS; turn++)
    {
        {
            unique_lock<shared_mutex> writing_lock(meter_mutex);
            {
                printf("TECH #%d @%02d:", thread_id,
                                          elapsed_seconds());

                    int level = rand()%MAX_SETTING_LEVEL + 1;
                    setting = level;

                    for (int n = 1; n <= level; n++)
                    {
                        this_thread::sleep_for(chrono::seconds(1));

                        printf("%2d", n);
                        cout.flush();
                    }
                    cout << endl;

                if (turn == TECHNICIAN_TURNS)
                {
                    printf("TECH #%d @%02d: done!\n",
                           thread_id, elapsed_seconds());

                    active_technicians_count--;
                }
            }
        }

        if (turn < TECHNICIAN_TURNS)
        {
            int sleep_time =
                    rand()%(  MAX_TECHNICIAN_SLEEP_TIME
                            - MIN_TECHNICIAN_SLEEP_TIME + 1)
                    + MIN_TECHNICIAN_SLEEP_TIME;
            this_thread::sleep_for(chrono::seconds(sleep_time));
        }
    }
}

void Meter::log_meter(const int thread_id)
{
    while (true)
    {
        int setting_read;
        int time_started;

        {
            shared_lock<shared_mutex> reading_lock(meter_mutex);
            {
                setting_read = setting;
                time_started = elapsed_seconds();

                this_thread::sleep_for(
                                    chrono::seconds(LOGGING_TIME));

                {
                    lock_guard<mutex> printing_lock(print_mutex);
                    {
                        printf("%*sLOGGER #%d @%02d: logging %d\n",
                               LOGGER_PRINT_MARGIN, " ",
                               thread_id, time_started,
                               setting_read);
                    }
                }

                if (active_technicians_count == 0) break;
            }
        }

        this_thread::sleep_for(
            chrono::seconds(rand()%MAX_LOGGER_SLEEP_TIME + 1));
    }
}
