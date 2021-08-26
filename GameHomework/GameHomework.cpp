// GameHomework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Player {
protected:
    std::string name;
    std::string characterClass;
    int level;
    int hp;
    int damagePower;

public:
    Player(std::string myName, std::string myClass, int myLevel, int myHP, int myDamagepower) {
        name = myName;
        characterClass = myClass;
        level = myLevel;
        hp = myHP;
        damagePower = myDamagepower;
    }

    void SetName(std::string myName) {
        name = myName;
    }
    void SetCharacterClass(std::string myClass) {
        characterClass = myClass;
    }

    void SetLevel(int myLevel) {
        level = myLevel;
    }

    void SetHP(int myHP) {
        hp = myHP;
    }

    void SetDamagePower(int myDamagePower) {
        damagePower = myDamagePower;
    }

    std::string GetName() {
        return name;
    }

    std::string GetClass() {
        return characterClass;
    }

    int GetLevel() {
        return level;
    }

    int GetHP() {
        return hp;
    }

    int GetDamagePower() {
        return damagePower;
    }

    void PrintPlayer() {
        std::cout << GetName() << " has class " << GetClass() << " and level " << GetLevel() <<", hp " << GetHP()<<" and can inflict "<< GetDamagePower() << " damage." << std::endl;
    }
};

class PlayerEnhancer {
public:
    void Enchance(Player& player) {
        std::cout <<player.GetName()<<" got enhanced!" << std::endl;

        player.SetHP(player.GetHP() + 10);
        player.SetDamagePower(player.GetDamagePower() + 25);
        player.SetLevel(player.GetLevel() + 1);
    }
};

static bool attack = 1;

class Battle {
public:
    void BattleA(Player& player1, Player& player2) {
        if (attack) {
            std::cout << player1.GetName() << " attacks!" << std::endl;
            player2.SetHP(player2.GetHP() - player1.GetDamagePower());
            attack = 0;
        }
        else {
            std::cout << player2.GetName() << " attacks!" << std::endl;
            player1.SetHP(player1.GetHP() - player2.GetDamagePower());
            attack = 1;
        }
    }
};

int main()
{
    Player Klaus("Klaus", "Warrior", 5, 100, 25);
    Player Elijah("Elijah", "Sorcerer", 10, 150, 20);

    Klaus.PrintPlayer();
    Elijah.PrintPlayer();
    std::cout << std::endl;

    PlayerEnhancer E;
    E.Enchance(Klaus);
    E.Enchance(Elijah);

    Klaus.PrintPlayer();
    Elijah.PrintPlayer();
    std::cout << std::endl;

    Battle b;
    b.BattleA(Klaus, Elijah);
    Klaus.PrintPlayer();
    Elijah.PrintPlayer();
    std::cout << std::endl;

    b.BattleA(Klaus, Elijah);
    Klaus.PrintPlayer();
    Elijah.PrintPlayer();
    std::cout << std::endl;

    return 0;
}
