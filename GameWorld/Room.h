#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include "..\Interaction\Item\item.h"
#include "..\Interaction\NPC\NPC.h"
#include "Tools.h"

struct Door { //replace with union maybe
    Coordinate doorLocation;
    bool vertical;
	bool locked;
    int roomKey1;
    int roomKey2;
};
class Room {

private:
	string description;
	string exitString();
    vector<int> itemsInRoom;
    vector<NPC> npcsInRoom;
    vector<Door> doorsInRoom;
	unordered_set<int> cells;
	void addDoor(Door door);
    int key;
	friend class Floor;
	bool hasUpLadder;
	bool hasDownLadder;
public:
    int numberOfItems();
	Room(unordered_set <int> cells,string description);
	string shortDescription();
    void addItem(int i);
    void removeItemFromRoom(int location);
	int getKey();
	bool cellInRoom(Coordinate c);
	unordered_set<int> getCells();
	vector<Door> &getDoors();
	operator int();
	bool operator<(Room r2);
    void addNPC(int);
    vector<NPC> &getNPCs();
	void giveLadder(bool up);
};

#endif