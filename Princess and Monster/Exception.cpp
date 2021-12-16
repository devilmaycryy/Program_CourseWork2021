#include "Exception.h"

Exception::Exception(int err)
{
    error_number = err;
}
Text Exception::show()
{
    string message;

    Text MessageText;
  
    switch (error_number)
    {
    case 1:
        message = "Error opening image file";
        break;
    case 2:
        message = "Error loading input file";
        break;
    case 3:
        message = "Out of range of game field "; //z
        break;
    case 4:
        message = "Incorrect character input"; //z?
        break;
    case 5:
        message = "Unknown result"; //z?
        break;
    case 6:
        message = "Incorrect input time";
        break;
    case 7:
        message = "Time is expired";
        break;
    case 8:
        message = "The princess and the monster are in the same place!!!"; //z
        break;
    case 9:
        message = "The princess can go beyond the playing field!!!"; //z
        break;
    case 10:
        message = "The monster can go beyond the playing field!!!"; //z
        break;
    }

    MessageText.setString(message);
    return MessageText;
    
}