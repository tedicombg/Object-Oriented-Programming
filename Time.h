#pragma once

#include <iostream>
class Time
{
private:
    int hours;
    int minutes;
    void simplify()
    {
        if(minutes >= 60)
        {
            hours =+ minutes / 60;
            minutes = minutes % 60;
        }
    }
public:
    Time()
    {
        this -> hours = 0;
        this -> minutes = 0;
    }
    Time(int _hours, int _minutes)
    {
        this -> hours = _hours;
        this -> minutes = _minutes;
    }
    Time (Time const& r)
    {
        this -> hours = r.hours;
        this -> minutes = r.minutes;
    }
    void reset(int h = 0, int m = 0)            //мутатор за часове и минути
    {
        this -> hours = h;
        this -> minutes = m;
        simplify();
    }
    void addMin(int m)
    {
        minutes = minutes + m;
        simplify();
    }
    void addHours(int h)
    {
        hours =+ h;
    }
    operator int() const
    {
        return hours * 60 + minutes;
    }
    void print() const
    {
        std::cout << "hours: " << this -> hours << " ,minutes :" << this -> minutes << std::endl;
    }
    Time operator +(const Time& t) const
    {
        Time newTime;
        newTime.minutes = this -> minutes + t.minutes;
        newTime.hours = this -> hours + t.hours;
        newTime.simplify();
        return newTime;
    }
    Time operator -(const Time& t) const
    {
        Time newTime;
        int m1, m2;
        m1 = t.hours * 60 + t.minutes;
        m2 = this -> hours * 60 + this -> minutes;
        newTime.minutes = (m2 - m1) % 60;
        newTime.hours = (m2 - m1) / 60;
        return newTime;
    }
    Time operator *(int mult) const
    {
        Time newTime;
        int m = (hours * 60 + minutes) * mult;
        newTime.hours = m / 60;
        newTime.minutes = m % 60;
        return newTime;
    }

};
