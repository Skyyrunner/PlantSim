#include "Months.h"

namespace ALMANAC
  {
  using namespace std;
  //std::string getMonthName(const int MONTH)
    

  Month::Month()
    :MONTH(JANUARY), date(1), year(2013)
    {

    }

  Month::Month(const int& NEWMONTH, const int& day, const int& startYear)
    {
    year = year;
    if (NEWMONTH > 0 && NEWMONTH < 14)
      MONTH = NEWMONTH;
    else
      {
      MONTH = JANUARY;
      year++;
      }

    if (day > 0 && day < 31)
      {
      if (MONTH == FEBRUARY)
        {
        if (day < 29)
          date = day;
        }
      else
        date = day;
      }
    }

  ostream& operator<< (ostream& os, const Month& month)
    {
    os << getMonthName(month.getMonth()) << " " << month.getDate() << " " << month.getYear();
    return os;
    }

  void Month::advanceDay(const int& numDays)
    {
    int days = numDays;

    // Add days~
    for(;days > 0; days--)
      {
      date ++;
      // check for feb
     /* if (MONTH == FEBRUARY){
        if (date > 28)
          {
          MONTH++;
          date = 1;
          }}
      else*/
      
      if (MONTH != DECEMBER)
        { // First check for non-December cases.
        if (date > 30)
          {
          date = 1;
          MONTH++;
          }
        }
      else
        if (date > 30) // If it's both december and the date is over 30...
          {
          date = 1;
          MONTH = JANUARY;
          }
        }
      
    }

  void Month::setDate(const int& newDate)
    {
    if (newDate < 31 && newDate > 0)
        date = newDate;
    }

  void Month::setMonth(const int& NEWMONTH)
    {
    if (NEWMONTH >= 1 && NEWMONTH < 13)
      MONTH = NEWMONTH;
    }
  
  int Month::getMonth() const
    {
    return MONTH;
    }

  int Month::getDate() const
    {
    return date;
    }

  int Month::getYear() const
    {
    return year;
    }

  int Month::getNumberOfDaysInMonth() const
    {
 /*   if (MONTH == FEBRUARY)
      return 28;
    else*/
      return 30;
    }

  int Month::getDaysSinceYearStart() const
  {
      int days = 0;
      int months = MONTH;

      months -= 1;

      days = months * 30 + date;

      return days;
  }

  int operator-(const Month& left, const Month& right)
  {
      int yearDiff = left.year - right.year;
      int monthDiff = left.MONTH - right.MONTH;
      int dayDiff = left.date - right.date;
      
      return yearDiff * 360 + monthDiff * 30 + dayDiff;
  }
}

