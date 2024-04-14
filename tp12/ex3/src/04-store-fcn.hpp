#pragma once

#define ANSWER_00 <functional>

#define ANSWER_10 std::function
#define ANSWER_11 bool
#define ANSWER_12 T&
#define ANSWER_13 T
#define ANSWER_14 void

#define ANSWER_20 [&value](const int& v) { return v < value; }
#define ANSWER_21 [](std::string& s) { s += " " + s; }
#define ANSWER_22 [c = 0u]() mutable { return c++; }