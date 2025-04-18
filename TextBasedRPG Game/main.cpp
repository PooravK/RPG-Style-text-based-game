#include <iostream>
#include <string>
using namespace std;

class player
{
    public:
        //Player name, class and inventory
        string player_Name;
        int player_Class;
        string class_Name;
        string item_InHand;

        //Initial stats of the player
        int strengthPnt = 0;
        int healthPnt = 0;
        int speedPnt = 0;
        int defensePnt = 0;

        //Base stats of the player
        int base_strength;
        int base_speed;
        int base_defense;
        int base_health;
        int base_level;
        
        //For calculation of stats after point assignment
        int get_FinalStrength()
        {
            base_strength = base_strength + strengthPnt;
            return base_strength;
        }
        int get_FinalSpeed()
        {
            base_speed = base_speed + speedPnt;
            return base_speed;
        }
        int get_FinalHealth()
        {
            base_health = base_health + healthPnt;
            return base_health;
        }
        int get_FinalDefense()
        {
            base_defense = base_defense + defensePnt;
            return base_defense;
        }
        //To input player name:
        void player_Info()
        {
            cout << endl;
            cout << "- - - - - - Enter your name - - - - - -" << endl;
            cout << "Name = ";
            getline(cin >> ws, player_Name); //Used to take input of player name without the error of whitespace (ws) in between
            cout << endl;
        }

        //To Show stats and level of the player:
        void show_Stats()
        {
            cout << endl;
            cout << "- - - - - - STAT WINDOW - - - - - -" << endl;
            cout << "Player name: " << player_Name << endl;
            cout << "Player class: " << class_Name << endl;
            cout << "Current equipment: " << item_InHand << endl;
            cout << "Health: " << get_FinalHealth() << endl;
            cout << "Strength: " << get_FinalStrength() << endl;
            cout << "Defense: " << get_FinalDefense() << endl;
            cout << "Speed: " << get_FinalSpeed() << endl;
            cout << endl;
        }
        //Class choosing menu:
        void choose_Class()
        {
            cout << endl;
            cout << "- - - - - - Choose a class - - - - - -" << endl;
            cout << "1 - Warrior" << endl;
            cout << "2 - Archer" << endl;
            cout << "3 - Healer" << endl;
            cout << "4 - Thief" << endl;
            cout << endl;
            cout << "Enter the class you want (1 2 3 4) - ";
            cin >> player_Class;
            cout << endl;

            if (player_Class == 1)
            {
                class_Name = "Warrior";
                item_InHand = "Broken sword";
                base_strength = 8;
                base_speed = 0;
                base_health = 20;
                base_defense = 5;
                base_level = 0;
            }
            else if (player_Class == 2)
            {
                class_Name = "Archer";
                item_InHand = "Worn out bow";
                base_strength = 1;
                base_speed = 8;
                base_health = 20;
                base_defense = 0;
                base_level = 0;
            }
            else if (player_Class == 3)
            {
                class_Name = "Healer";
                item_InHand = "Tattered robes";
                base_strength = 1;
                base_speed = 0;
                base_health = 40;
                base_defense = 0;
                base_level = 0;
            }
            else if (player_Class == 4)
            {
                class_Name = "Thief";
                item_InHand = "Empty handed";
                base_strength = 1;
                base_speed = 20;
                base_health = 20;
                base_defense = 0;
                base_level = 0;
            }
        }
};

int main()
{
    player p;
    p.player_Info();
    p.choose_Class();
    p.show_Stats();
    return 0;
}