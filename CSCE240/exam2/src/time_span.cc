// Copyright 2020 Matthew Graham
#include <inc/time_span.h>

TimeSpan::TimeSpan() {
  hours_ = 0;
  minutes_ = 0;
  seconds_ = 0;
}

TimeSpan::TimeSpan(int hours, int minutes, int seconds) {
  hours_ = hours;
  minutes_ = minutes;
  seconds_ = seconds;
}

int TimeSpan::hours() const {
  return hours_;
}

int TimeSpan::minutes() const {
  return minutes_;
}

int TimeSpan::seconds() const {
  return seconds_;
}

const TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
  int hours = hours_ + rhs.hours_;
  int minutes = minutes_ + rhs.minutes_;
  int seconds = seconds_ + rhs.seconds_;

  if (minutes >= 60) {
    hours++;
    minutes -= 60;
  }
  if (seconds >= 60) {
    minutes++;
    seconds -= 60;
  }

  return TimeSpan(hours, minutes, seconds);
}

std::istream& TimeSpan::Insert(std::istream* in) {
  char delimit = ':';
  *in >> hours_ >> delimit >> minutes_ >> delimit >> seconds_;
  return *in;
}

std::ostream& TimeSpan::Extract(std::ostream* out) const {
  *out << hours_ << " : " << minutes_ << " : " << seconds_;
  return *out;
}

const TimeSpan operator+(int lhs, const TimeSpan& rhs) {
  return rhs.operator+(rhs);
}

std::istream& operator>>(std::istream& lhs, TimeSpan& rhs) {
  return rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs) {
  return rhs.Extract(&lhs);
}
