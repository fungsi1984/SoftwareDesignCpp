#include <iostream>
#include <iomanip>
#include <string>
#include "EventMaker.h"
#include "BaseballReporter.h"
#include "GraphReport.h"

using namespace std;

void GraphReport::update(const string name, const int outs)
{
    Event *event = reporter->get_current_event();
    int    hit   = event->get_hit();

    switch (hit)
    {
        case 1: singles++; break;
        case 2: doubles++; break;
        case 3: triples++; break;
        case 4: homers++;  break;

        default: break;
    }

    if (outs == 27) print_report();
}

void GraphReport::print_report()
{
    cout << endl << endl;
    cout << "GAME HITS GRAPH" << endl;
    cout << endl;

    cout << setw(2) << singles << " singles" << endl;
    cout << setw(2) << doubles << " doubles" << endl;
    cout << setw(2) << triples << " triples" << endl;
    cout << setw(2) << homers  << " homers"  << endl;
    cout << endl;

    cout << "         ....5...10...15...20...25...30" << endl;
    cout << "Singles: "; print_bar('S', singles);
    cout << "Doubles: "; print_bar('D', doubles);
    cout << "Triples: "; print_bar('T', triples);
    cout << " Homers: "; print_bar('H', homers);
}

void GraphReport::print_bar(const char ch, const int count)
{
    for (int i = count; i > 0; i--) cout << ch;
    cout << endl;
}