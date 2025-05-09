#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

class charactor
{
    public:
        int base_strength = 0;
        int base_speed = 0;
        int base_defense = 0;
        int base_health = 0;

        int strengthPnt = 0;
        int healthPnt = 0;
        int speedPnt = 0;
        int defensePnt = 0;

        int get_finalHealth()
        {
            return base_health + healthPnt;
        }
        int get_finalStrength()
        {
            return base_strength + strengthPnt;
        }
        int get_finalDefense()
        {
            return base_defense + defensePnt;
        }
        int get_finalSpeed()
        {
            return base_speed + speedPnt;
        }

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

        //Damage calculation for battle menu
        void reduce_Health(int damage)
        {
            base_health = max(0, get_FinalHealth() - damage);
        }
        
        //For calculation of stats after point assignment
        int get_FinalStrength()
        {
            return base_strength + strengthPnt;
        }
        int get_FinalSpeed()
        {
            return base_speed + speedPnt;
        }
        int get_FinalHealth()
        {
            return base_health + healthPnt;
        }
        int get_FinalDefense()
        {
            return base_defense + defensePnt;
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
                base_strength = 12;
                base_speed = 6;
                base_health = 100;
                base_defense = 10;
                base_level = 0;
            }
            else if (player_Class == 2)
            {
                class_Name = "Archer";
                item_InHand = "Worn out bow";
                base_strength = 9;
                base_speed = 12;
                base_health = 80;
                base_defense = 4;
                base_level = 0;
            }
            else if (player_Class == 3)
            {
                class_Name = "Healer";
                item_InHand = "Tattered robes";
                base_strength = 7;
                base_speed = 9;
                base_health = 70;
                base_defense = 3;
                base_level = 0;
            }
            else if (player_Class == 4)
            {
                class_Name = "Thief";
                item_InHand = "Empty handed";
                base_strength = 9;
                base_speed = 13;
                base_health = 75;
                base_defense = 4;
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

            enemy() : charactor(0, 0, 0, 0), ID(0), enemy_name("Unknown") {}

            enemy(string n, int id, int st, int sp, int de, int he) :
                charactor(st, sp, de, he), enemy_name(n), ID(id) {}

            //Health reduction function
            void reduce_Health(int damage)
            {
                base_health = max(0, get_finalHealth() - damage);
            }
        
            void level_condition(player& p)
            {
                if (p.enemies_defeated == 3)
                {
                    p.level_up();
                    p.enemies_defeated = 0;
                }
            }

            void battle_begin(player&p, vector<enemy>&enemy_list)
            {

            }

            void battle_menu(player&p, vector<enemy>&enemy_list)
            {
                int battle_choice;

                //Random enemy ID selection
                int rand_ID = rand() % enemy_list.size();
                enemy& selected_enemy = enemy_list[rand_ID];

                cout << endl;
                cout << "You have encountered an enemy! What do you want to do?" << endl;

                while (p.get_FinalHealth() != 0 && selected_enemy.get_finalHealth() != 0)
                {

                    cout << endl;
                    cout << "Enemy Name: " << selected_enemy.enemy_name << endl;
                    cout << "Enemy Health: " << selected_enemy.get_finalHealth() << endl;;
                    cout << endl;
                    cout << "Player Name: " << p.player_Name << endl;
                    cout << "Player Health: " << p.get_FinalHealth() << endl;;
                    cout << endl;
                    cout << "1 - Attack" << endl;
                    cout << "2 - View enemy stats" << endl;
                    cout << "3 - Drink health potion" << endl;
                    cout << "4 - Run" << endl;
                    cout << "Enter your choice 1 2 3 4: ";
                    cin >> battle_choice;
                    cout << endl;

                    if (battle_choice == 1)
                    {
                        bool player_turn = p.get_FinalSpeed() >= selected_enemy.get_finalSpeed();

                        int damage_ToEnemy = max(0, (p.get_FinalStrength() - selected_enemy.get_finalDefense()));
                        int damage_ToPlayer = max(0, (selected_enemy.get_finalStrength() - p.get_FinalDefense()));

                        if (player_turn)
                        {
                            //Critical hit chance ofr player turn
                            int crit_chance = rand() % 100;
                            if (crit_chance < 25)
                            {
                                cout << endl;
                                cout << "Critical hit! Damage doubled" << endl;
                                damage_ToEnemy = max(0, (2 * (p.get_FinalStrength() - selected_enemy.get_finalDefense())));
                            }
                            selected_enemy.reduce_Health(damage_ToEnemy);
                            p.reduce_Health(damage_ToPlayer);
                            cout << "Player moves first!" << endl;
                            cout << "Damage by player: " << damage_ToEnemy << endl;
                            cout << "Damage by enemy: " << damage_ToPlayer << endl;
                        }
                        else
                        {
                            //Critical hit chance for enemy turn
                            int crit_chance = rand() % 100;
                            if (crit_chance < 25)
                            {
                                cout << endl;
                                cout << "Critical hit! Damage doubled" << endl;
                                damage_ToEnemy = max(0, (2*(p.get_FinalStrength() - selected_enemy.get_finalDefense())));
                            }
                            p.reduce_Health(damage_ToPlayer);
                            selected_enemy.reduce_Health(damage_ToEnemy);
                            cout << "Enemy moves first!" << endl;
                            cout << "Damage by enemy: " << damage_ToPlayer << endl;
                            cout << "Damage by player: " << damage_ToEnemy << endl;
                        }
                    }
                    else if (battle_choice == 2)
                    {
                        cout << endl;
                        cout << "- - - - - - Enemy Stats - - - - - -" << endl;
                        cout << "Enemy Name: " << selected_enemy.enemy_name << endl;
                        cout << "Health left: " << selected_enemy.get_finalHealth() << endl;
                        cout << "Strength: " << selected_enemy.get_finalStrength() << endl;
                        cout << "Defense: " << selected_enemy.get_finalDefense() << endl;
                        cout << "Speed: " << selected_enemy.get_finalSpeed() << endl;
                        cout << endl;
                    }
                    else if (battle_choice == 4)
                    {
                        cout << endl;
                        cout << "You decided to run away!" << endl;
                        break;
                    }
                }

                if (p.get_FinalHealth() != 0 && battle_choice == 1)
                {
                    cout << endl;
                    cout << "You have defeated " << selected_enemy.enemy_name << "!";
                    p.enemies_defeated++;
                }
                else if (selected_enemy.get_finalHealth() != 0 && battle_choice == 1)
                {
                    cout << endl;
                    cout << "You were defeated by " << selected_enemy.enemy_name << "!";
                }
             }
};

class item
{
    public:
        string item_name;
        int bonus_strength;
        int bonus_speed;
        int bonus_defense;
        int bonus_health;
        int item_price;
        string potion_name;
        int health_regen;
        int strength_regen;
        int defense_regen;
        int speed_regen;
        int potion_price;

        item (string n, int bstr, int bspe, int bdef, int bhea, int price) :
            item_name(n), bonus_strength(bstr), bonus_speed(bspe), bonus_defense(bdef), bonus_health(bhea), item_price(price){}
        
        item(string n1, int heregen, int stregen, int deregen, int spregen, int p_price) :
            potion_name(n1), health_regen(heregen), strength_regen(stregen), speed_regen(spregen), defense_regen(deregen), potion_price(p_price){}
};

int main()
{
    player pl;
    enemy en;
    //Seeding the generator
    srand(static_cast<unsigned>(time(0)));
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

    vector <item> item_list = 
    {
        item("Rusty Dagger", 2, 1, 0, 0, 100),
        item("Iron Sword", 4, 0, 0, 0, 100),
        item("Twin Blades", 3, 3, 0, 0, 100),
        item("Spiked club", 6, -1, 0, 0, 100),
        item("Knight's longsword", 7, 0, 0, 0, 100),
        item("Flame blade", 5, 2, 0, 0, 100),
        item("Doom hammer", 10, -2, 0, 0, 100),
        item("Runesteel Katana", 9, 4, 0, 0, 100),
        item("Bloodfang axe", 13, -3, 0, 0, 100),
        item("Celestial Blade (LEGENDARY)", 15, 5, -3, 0, 100),
        item("Leather Vest", 0, 0, 2, 0, 100),
        item("Chainmail Armor", 0, 0, 5, 0, 100),
        item("Stonehide Plate", 0, -1, 8, 0, 100),
        item("Mage Cloak", 0, 3, 3, 0, 100),
        item("Dragonbone Armor", 0, -2, 12, 5, 100),
        item("Void aeiges (LEGENDARY)", -2, -3, 16, 10, 100),
    };

    vector <item> potion_list = 
    {
        item("Minor health potion", 20, 0, 0, 0, 100),
    };

    pl.player_Info();
    pl.choose_Class();
    //p.show_Stats();

    //pl.level_up();
    en.battle_menu(pl, enemy_list);
    return 0;
}