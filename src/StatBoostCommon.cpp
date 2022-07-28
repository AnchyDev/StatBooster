#include "StatBoostCommon.h"

template<typename T>
uint32 StatBoostCommon::MeasureExecution(T&& func)
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    func();
    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    return ms_int.count();
}
