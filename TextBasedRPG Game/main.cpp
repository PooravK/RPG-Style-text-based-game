#include <iostream>
#include <string>
#include <vector>
using namespace std;

class charactor
{
    public:
        int base_strength;
        int base_speed;
        int base_defense;
        int base_health;

        int strengthPnt = 0;
        int healthPnt = 0;
        int speedPnt = 0;
        int defensePnt = 0;

        //COnstructor to initialize stats for enemy class
        charactor(int st, int sp, int de, int he) : 
            base_strength(st), base_defense(de), base_speed(sp), base_health(he) {}
};

class player : public charactor
{
    public:
        //To default the charactor constructor
        player() : charactor(0, 0, 0, 0) {}

        //Player name, class and inventory
        string player_Name;
        int player_Class;
        string class_Name;
        string item_InHand;

        //Initial stats of the player
        /*int strengthPnt = 0;
        int healthPnt = 0;
        int speedPnt = 0;
        int defensePnt = 0;

        //Base stats of the player
        int base_strength;
        int base_speed;
        int base_defense;
        int base_health;*/

        //Levelling  up system
        int floor_level;
        int player_level = 0;
        int enemies_defeated = 0;
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
            strengthPnt = 0;
            healthPnt = 0;
            speedPnt = 0;
            defensePnt = 0;
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
            int condn = 0;
            while (condn == 0)
            {
                cout << "Choose a desired class: ";
                cin >> player_Class;
                if (player_Class == 1 || player_Class == 2 || player_Class == 3 || player_Class == 4)
                {
                    condn = 1;
                }
                else
                {
                    cout << "Invalid input. Please enter from 1 to 4" << endl;
                }
            }

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
        int level_up()
        {
            player_level = player_level + 1;
            cout << endl;
            cout << "Congratulations, You have levelled up! You can now add 3 points to any of your base stats: " << endl;
            int statChosen;

            for (int i = 0; i < 3; i++)
            {
                int condn_level = 0;
                strengthPnt = 0;
                healthPnt = 0;
                speedPnt = 0;
                defensePnt = 0;
                show_Stats();

                while (condn_level == 0)
                {
                    cout << endl;
                    cout << "Where do you want to get stronger?" << endl;
                    cout << "1 - Health" << endl;
                    cout << "2 - Strength" << endl;
                    cout << "3 - Defense" << endl;
                    cout << "4 - Speed" << endl;
                    cout << endl;
                    cout << "Enter from 1 2 3 4 - ";
                    cin >> statChosen;
                    if (statChosen == 1 || statChosen == 2 || statChosen == 3 || statChosen == 4)
                    {
                        condn_level = 1;
                    }
                    else
                    {
                        cout << "Invalid input. " << endl;
                        condn_level = 0;
                    }
                }
                if (statChosen == 1)
                {
                    healthPnt++;
                    get_FinalHealth();
                }
                else if (statChosen == 2)
                {
                    strengthPnt++;
                    get_FinalStrength();
                }
                else if (statChosen == 3)
                {
                    defensePnt++;
                    get_FinalDefense();
                }
                else
                {
                    speedPnt++;
                    get_FinalSpeed();
                }
            }
            show_Stats();
        }
};

class enemy : public charactor
{
        public:
            int ID;
            string enemy_name;

            enemy(string n, int id, int st, int sp, int de, int he) :
                charactor(st, sp, de, he), enemy_name(n), ID(id) {}
        
            void level_condition(player& p)
            {
                if (p.enemies_defeated == 3)
                {
                    p.level_up();
                    p.enemies_defeated = 0;
                }
            }
};

int main()
{
    player pl;
    //Creating a vector array to store all enemy IDs and their stats
    vector <enemy> enemy_list = 
    {
        enemy("Slime", 0, 5, 4, 7, 100),
        enemy("Goblin", 1, 8, 11, 4, 50),
        enemy("Skeleton", 2, 7, 7, 6, 70),
        enemy("Bat", 3, 4, 13, 3, 40),
        enemy("Wolf", 4, 8, 10, 4, 90),
        enemy("Zombie", 5, 9, 3, 10, 130),
        enemy("Bandit", 6, 11, 8, 7, 100),
        enemy("Witch", 7, 12, 8, 4, 70),
        enemy("Rock Golem", 8, 9, 3, 14, 140),
        enemy("Fire Imp", 9, 11, 10, 3, 90),
        enemy("Ice spirit", 10, 9, 8, 6, 60),
        enemy("Shadowling", 11, 8, 14, 2, 40),
        enemy("Mimic", 12, 12, 8, 10, 100),
        enemy("Scarecrow", 13, 9, 5, 7, 100),
        enemy("Troll", 14, 15, 4, 9, 150),
        enemy("Harpy", 15, 8, 11, 4, 80),
        enemy("Dark Knight", 16, 16, 9, 4, 130),
        enemy("Cultist", 17, 5, 7, 3, 60),
        enemy("Plague Rat", 18, 8, 11, 4, 60),
        enemy("Mirror Image", 19, 6, 8, 2, 50),
    };

    pl.player_Info();
    pl.choose_Class();
    //p.show_Stats();

    pl.level_up();   
    return 0;
}