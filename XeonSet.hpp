#include <string_view>
#include <map>

using std::string_view;
using std::map;

/// @brief An operator evaluates an expression and returns a result, whether it be boolean or arithmetic expressions
map<string_view, int> operators{

    /* Start Rational Operators */

    {"!",       0},
    {"not",     1},
    {">",       2},
    {"gt",      3},
    {"<",       4},
    {"lt",      5},
    {">=",      6},
    {"gte",     7},
    {"<=",      8},
    {"lte",     9},
    {"==",      10},
    {"eql",     11},
    {"!=",      12}, //or not eql

    /* End Rational Operators */

    /* Start Logical Operators */ 

    {"&&",      13},
    {"and",     14},
    {"||",      15},
    {"or",      16},

    /* End Logical Operators */ 

    /* Start Arthimetic Operators */

    {"+",       17},
    {"-",       18},
    {"*",       19},
    {"/",       20},
    {"%",       21},
    {"mod",     22},

    /* End Arthimetic Operators */

    /* Start Unary Operators */

    {"++",      23},
    {"--",      24},

    /* End Unary Operators */

    /* Start Bitwise Operators */

    {"&",       25},
    {"|",       26},
    {"<<",      27},
    {">>",      28},
    {"~",       29},
    {"^",       30},

    /* End Bitwise Operators */

    /* Start Assignment Operators */

    {"=",       31},
    {"=>",      32},
    {"+>",      33},
    {"->",      34},
    {"+=",      35},
    {"-=",      36},
    {"/=",      37},
    {"*=",      38},
    {"%=",      39}

    /* End Assignment Operators */
};