#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

class door
{
public:
    ~door() {}
    virtual void enter_door() = 0;
};

class room
{
public:
    ~room();
    virtual void check_room() = 0;
};

class userDoor : public door
{
public:
    ~userDoor() {}
    void enter_door()
    {
        cout << "Enter door..." << endl;
    }
};

class userRoom : public room
{
public:
    ~userRoom() {}
    void check_room()
    {
        int i = rand() % 10;
        switch (i)
        {
        case 1:
            cout << "You found exit.";
            break;
        default:
            cout << "There is no exit. " << endl;
            break;
        }



    }
};

class LabyrintFactory
{
public:
    virtual userDoor* createDoor() = 0;
    virtual userRoom* createRoom() = 0;
};

class userLabyrintFactory : public LabyrintFactory
{
public:

    static  userLabyrintFactory* GetInstance()
    {
        static  userLabyrintFactory* instance = new  userLabyrintFactory();
        return instance;
    }

    userRoom* createRoom()
    {
        return new userRoom;
    }
    userDoor* createDoor()
    {
        return new userDoor;
    }
};

class userInterface
{
public:
    ~userInterface() {}
    void menu()
    {
        cout << "You stay in room, there is 4 door. Find exit." << endl;
        while (1 == 1)
        {

            int c; cin >> c;
            switch (c)
            {
            case 1:
                for (int i = 0; i < ud.size(); i++) ud[i]->enter_door();
                break;
            case 2:
                for (int i = 0; i < ur.size(); i++) ur[i]->check_room();
                break;
            }
        }
    }

    vector<door*> ud;
    vector<room*> ur;
};

class interface
{
public:
    userInterface* createInterface(LabyrintFactory& factory)
    {
        userInterface* i = new userInterface;
        i->ur.push_back(factory.createRoom());
        i->ud.push_back(factory.createDoor());
        return i;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
  //  interface interface;
   // userLabyrintFactory ufactory;

    //userInterface* u = interface.createInterface(ufactory);
   // u->menu();

    door* d = userLabyrintFactory::GetInstance()->createDoor();
    room* r = userLabyrintFactory::GetInstance()->createRoom();
    d->enter_door();
    r->check_room();
    return 0;
}
