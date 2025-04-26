#include <iostream>
#include <string>

using namespace std;

class Room
{
public:
    int roomNumber;
    string guest;
    bool isBooked;

    void printRoomInfo(int roomNumber, string guest, bool isBooked)
    {
        cout << "Room: " << roomNumber << endl;
        cout << "Guest: " << (isBooked ? guest : "Available") << endl;
        cout << "Booked: " << (isBooked ? "Yes" : "No") << endl;
        cout << "------------------" << endl;
    }
    void bookRoom(int roomNumber, string guestName)
    {
        if (roomNumber == 101)
        {
            cout << "Room 101 is already booked." << endl;
        }
        else if (roomNumber == 102)
        {
            if (isBooked == false)
            {
                cout << "Room 102 is now booked for " << guestName << "." << endl;
                isBooked = true;
                guest = guestName;
            }else{
                cout << "Already Booked" << endl;
            }
            
            
        }
        
        
    }
};
int main()
{
    Room room1, room2;
    room1.printRoomInfo(101, "Ali", true);
    room2.printRoomInfo(102, "", false);
    room2.bookRoom(102, "Sara");
    room2.bookRoom(102, "Huziafa");
    return 0;
}