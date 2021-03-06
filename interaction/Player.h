#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <array>
#include <memory>
#include "Item\item.h"
#include "Item\Weapon.h"
#include "Item\Wearable.h"
#include "..\GameWorld\Tools.h"

#define STARTING_ATRRIBUTE_POINTS 4

using namespace std;

namespace QTGui {
    class InventoryWidget;
    class GameInstance;
}

class Player {
    private:
        friend class QTGui::GameInstance;
        friend class QTGui::InventoryWidget;
        friend class Human;
        vector<shared_ptr<Item>> inventory;
        unsigned int inventorySpace;
        shared_ptr<Weapon> activeWeapon;
        shared_ptr<Wearable> activeWearable1;
        shared_ptr<Wearable> activeWearable2;
        int luck, strength, charisma;
        void changeInventorySpace(int);
        void changeParams(std::array<int,4> params, bool equip);
    public:
        Player();
        Player(string playerToken);
        int getStrength();
        int getLuck();
        int getCharisma();
        bool equip(shared_ptr<Item> item, int slot);
        void unequip(int slot);
        void addItem(int key);
        Coordinate takeRandomItem();
        int takeItem(int i);
        bool canMove();
        template<typename T>
        static int byteHexStringToInt(T first,T second);
};
#endif /*PLAYER_H_*/
