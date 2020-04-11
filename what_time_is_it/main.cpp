#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <stdint.h>

#define TEAM "Wolfpack"
#define PROBLEM 1

#define CENTI_SEC_IN_MIN (100 * 60)
#define CENTI_SEC_IN_HALF_DAY (100 * 60 * 60 * 12)
#define CENTI_SEC_IN_HR (100 * 60 * 60 )
#define CENTI_SEC_IN_DAY (100 * 60 * 60 * 24)
#define CENTI_SEC (m_time/10)
//#define DBL_CMP_PREC (0.0003)
#define DBL_CMP_PREC (0.025)
#define DBL_CMP_LOOSE (0.025)

using namespace std;

/* 
 * Problem write a program that outputs the time in the format
 * HH:MM:SS.SS for all times of the day that the hour, minute and second hand 
 * are coincident. That is they all point in the same direction and are 
 * perfectly aligned.
 */

class Time
{
    private:
    //time in miliseconds sec/1000
    uint64_t m_time;

    /*******************
     * Private methods *
     ******************/
    inline bool cmp_dbl(double a, double b, double prec)
    {
        return fabs(a - b) < prec;
    }

    inline double get_sec_deg(uint32_t centi_sec)
    {
        return ((double)(centi_sec % CENTI_SEC_IN_MIN) / 100.0) *
               (360.0 / 60.0); 
    }

    inline double get_sec_rad(uint32_t centi_sec)
    {
        return ((double)(centi_sec % CENTI_SEC_IN_MIN) / 100.0) * 
               ((360.0 / 60.0) * (M_PI / 180.0));
    }

    inline double get_min_deg(uint32_t centi_sec)
    {
        return ((double)(centi_sec % CENTI_SEC_IN_HR) / 6000.0) *
               (360.0 / 60.0);
    }

    inline double get_min_rad(uint32_t centi_sec)
    {
        return ((double)(centi_sec % CENTI_SEC_IN_HR) / 6000.0) *
               (((360.0) / 60.0) * (M_PI / 180.0));
    }

    inline double get_hr_deg(uint32_t centi_sec)
    {
        return ((double)(centi_sec % CENTI_SEC_IN_HALF_DAY) / 360000.0) *
               (360.0 / 60.0);
    }

    inline double get_hr_rad(uint32_t centi_sec)
    {
        return ((double)(centi_sec % CENTI_SEC_IN_HALF_DAY) / 360000.0) *
               ((360.0 / 12.0) * (M_PI / 180.0));
    }

    inline uint32_t get_clk_hr()
    {
        double hr = (((m_time / 1000) / 60) / 60) % 12;
        return (hr == 0) ? 12 : hr;
    }

    inline uint32_t get_clk_min()
    {
        return ((m_time / 1000) /60) % 60;
    }

    inline uint32_t get_clk_sec()
    {
        return (m_time / 1000) % 60;
    }

    inline double get_clk_sec_high_prec()
    {
        return (double)(m_time % 60000 ) / (double)1000;
    }

    inline uint32_t get_tot_centi_sec()
    {
        return (m_time / 10);
    }

    public:
    /****************
     * Constructors *
     ***************/
    Time() : m_time(0)
    {
    }

    Time(uint64_t time): m_time(time)
    {
    }

    bool CoincidentHrMin()
    {
        double hr = get_hr_deg(CENTI_SEC);
        double min = get_min_deg(CENTI_SEC);

        return cmp_dbl(hr, min, DBL_CMP_PREC);
    }

    bool CoincidentHrMinSec()
    {
        double sec = get_sec_deg(CENTI_SEC);
        double min = get_min_deg(CENTI_SEC);
        double hr = get_hr_deg(CENTI_SEC);
        
        return (cmp_dbl(sec, min, DBL_CMP_LOOSE) &&
                cmp_dbl(min, hr, DBL_CMP_LOOSE));
    }

    string GetHandPosDeg()
    {
        stringstream ss;

        ss << "Hour: " << get_hr_deg(CENTI_SEC) << " deg" << endl;
        ss << "Minute: " << get_min_deg(CENTI_SEC) << " deg" << endl;
        ss << "Second: " << get_sec_deg(CENTI_SEC) << " deg" << endl;

        return ss.str();
    }

    string GetHandPosRad()
    {
        stringstream ss;

        ss << "Hour: " << get_hr_rad(CENTI_SEC) << " rad" << endl;
        ss << "Minute: " << get_min_rad(CENTI_SEC) << " rad" << endl;
        ss << "Second: " << get_sec_rad(CENTI_SEC) << " rad" << endl;

        return ss.str();
    }

    string GetTimeStr()
    {
        stringstream ss;

        ss << setw(2) << get_clk_hr() << ":";
        ss << setfill('0') << setw(2) << get_clk_min() << ":";
        ss << setfill('0') << setw(2) << fixed << setprecision(2) << get_clk_sec_high_prec();

        return ss.str();
    }

    uint64_t GetTime() { return m_time; }

    void Tick() { m_time += 10; }
};

void solve_problem(ofstream& outf)
{
    cout << "Times when the hands of a clock are coincident" << endl;

    Time T(0);
    Time T1(0);
    Time T2(43200000);
    Time T3(3900000);
    Time T4(25755000);

    cout << "Time: " << T1.GetTimeStr() << endl << T1.GetHandPosDeg() << endl;
    cout << "Time: " << T2.GetTimeStr() << endl << T2.GetHandPosDeg() << endl;
    cout << "Time: " << T3.GetTimeStr() << endl << T3.GetHandPosDeg() << endl;
    cout << "Time: " << T4.GetTimeStr() << endl << T4.GetHandPosDeg() << endl;

    do
    {
        /*if (T.CoincidentHrMinSec()) //the problem doesn't call for the second hand
        {
            cout << "Hr, min, sec hands are coincident at " << T.GetTimeStr() << endl;
            //outf << T.GetTimeStr() << endl;
        }*/
        if (T.CoincidentHrMin())
        {
            cout << "Hr, min hands are coincident at " << T.GetTimeStr() << endl;
            outf << T.GetTimeStr() << endl;
        }

        T.Tick();
    }
    while(T.GetTime() < CENTI_SEC_IN_HALF_DAY);
}

int main(int argc, char** argv)
{
    char in_fname[255] = { 0 };
    char out_fname[255] = { 0 };
    ifstream inf;
    ofstream outf;
    int status = 0;
    sprintf(in_fname, "prob%d.dat", PROBLEM);
    sprintf(out_fname, "prob%d.out", PROBLEM);

    inf.open(in_fname);
    if (inf)
    {
        outf.open(out_fname);
        if (outf)
        {
            solve_problem(outf);
        }
        else
        {
            cout << "could not open output file " << out_fname << endl;
            status = -2;
        }
    }
    else
    {
        cout << "could not open input file " << in_fname << endl;
        status = -1;
    }

    inf.close();
    outf.close();

    return status;
}
