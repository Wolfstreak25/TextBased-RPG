#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>
using namespace std;
class Character
{
  public:
  virtual bool Death() = 0;
  virtual int getHealth() = 0;
  virtual void getLevel(int lvl) = 0;
  virtual int setHealth() = 0;
  virtual int setHeal() = 0;
  virtual int bonusHeal() = 0;
  virtual int getMeleeDamage() = 0;
  virtual int setDamage() = 0;
  virtual int takeDamage(int dmg) = 0;
  virtual bool isWinner() = 0;
  virtual int HealDamage() = 0;
  virtual ~Character()
  {};
};

class player : public Character
{  
  private:
  int level;
  int count = 0;
  int random;
  int Basehealth = 100;
  int health = 100;
  int heal = 10;
  int mindamage = 10;
  int maxdamage = 15;
  int meleedamage = 15;
  int rangedamage;
  bool isAlive = true;
  bool isGameOver = false;
  public:

  bool Death()
  {
    return isAlive;
  }
  int getHealth()
  {
    return health;
  }
  void getLevel(int lvl)
  {
    level = lvl;
  }
  int setHealth()
  {
    Basehealth = Basehealth + 25 ;
    health = Basehealth;
    return health;
  }
  int setHeal()
  {
    heal = heal + 5 ;
    return heal;
  }
  int bonusHeal()
  {
    if (health < Basehealth)
      {
        health = health + 25 ;
        if(health>Basehealth)
        { 
          health=Basehealth;
        }
      }
    else
      cout<<"Player is still healthy\n";
    return health;
  }

  int getMeleeDamage()
  {
    random = rand() % 10;
    if(random == 2 && level >= 3)
    {
      cout<<"ability 1 : critical heat"<<endl;
      meleedamage = rand()%(maxdamage - mindamage) + mindamage + (rand() % 25 + 10);
    }
    else if(random == 4 && level >= 4)
    {
      cout<<"ability 2 : blocker"<<endl;
      meleedamage = 0;
      count += 1;
    }
    else if(random == 6 && level >= 5)
    {
      cout<<"ability 3 : Life steal "<<endl;
      
      meleedamage = rand()%(maxdamage - mindamage) + mindamage;
      cout<<"Player gave damage : "<<meleedamage<<endl;
      health = health + meleedamage;
      cout<<"Player Healed damage : "<<meleedamage<<endl;
    }
    else if(random == 8 && level >= 6)
    {
      cout<<"ability 4 : ranged attack "<<endl;
      meleedamage = 10;
      count += 1;
    }
    else
    {
      meleedamage = rand()%(maxdamage - mindamage) + mindamage;
    }
    return meleedamage;
  }
  int setDamage()
  {
      mindamage = mindamage + 5;
      maxdamage = maxdamage + 5;
    return meleedamage;
  }
  int takeDamage(int dmg)
  {
    if (count == 0)
    {
      health = health - dmg ;
      if (health <= 0)
      {
        cout<<"Player Died"<<endl;
        isAlive = false;
        isGameOver = true;
      }
      else
      {
        cout<<"Player health : "<<health<<endl;
      }
    }
    else
    {
      count -= 1;
    }
    return health ;
  }
  bool isWinner()
  {
    if (isAlive == true)
    {
      cout<<"Player won the fight "<<endl;
      return true;
      }
    else
    {
      cout<<"Player lost the fight \nGame Over"<<endl;
      return false;
      }
  }
  int HealDamage()
  {

    if (health < Basehealth)
      { 
        cout<<"Player healing"<<endl;
        health = health + heal; ;
        if(health>Basehealth)
        { 
          health=Basehealth;
        }
      }
    else
    {cout<<"Player is still healthy\n";}
    cout<<"Player health : "<<health<<endl;
    return health;
  }
};

class boss : public Character
{  
  private:
  int count = 0;
  int random;
  int Basehealth = 300;
  int health = 300;
  int heal = 35;
  int mindamage = 35;
  int maxdamage = 45;
  int meleedamage;
  int rangedamage = 15;
  bool isAlive = true;
  bool isGameOver = false;
  public:
  boss()
  {
    cout<<"\nPlayer reached the final door\n";
    cout<<"Knocked down the door\n";
    cout<<"Boss seating on the throne\n";
    cout<<"you did well reaching this far\n";
    cout<<"now feel the wrath of almighty\n";
  }
  bool Death()
  {
    return isAlive;
  }
  void getLevel(int lvl)
  {}
  int getHealth()
  {
    return health;
  }
  int setHealth()
  {
    return health;
  }
  int setHeal()
  {
    return heal;
  }
  int bonusHeal()
  {
    return health;
  }

  int getMeleeDamage()
  {
    random = rand() % 10 + 1;
    if(random == 1)
    {
      cout<<"ability 1 : critical heat"<<endl;
      meleedamage = rand()%(maxdamage - mindamage) + mindamage + (rand() % 25 + 10);
    }
    else if(random == 2)
    {
      cout<<"ability 2 : blocker"<<endl;
      meleedamage = 0;
      count += 1;
    }
    else if(random == 3)
    {
      cout<<"ability 3 : Life steal "<<endl;
      
      meleedamage = rand()%(maxdamage - mindamage) + mindamage;
      cout<<"Boss gave damage : "<<meleedamage<<endl;
      health = health + meleedamage;
      cout<<"boss Healed damage : "<<meleedamage<<endl;
    }
    else if(random == 4)
    {
      cout<<"ability 4 : ranged attack "<<endl;
      meleedamage = 10;
      count += 1;
    }
    else if(random > 4 && random < 8)
    {
      meleedamage = rand()%(maxdamage - mindamage) + mindamage;
    }
    else
    {
      count +=1;
    }
    return meleedamage;
  }
  int setDamage()
  {
      mindamage = mindamage + 5;
      maxdamage = maxdamage + 5;
    return meleedamage;
  }

  int takeDamage(int dmg)
  {
    if (count == 0)
    {
      cout<<"Player attacked"<<endl;
      health = health - dmg ;
      if (health <= 0)
      {
        cout<<"Boss Died"<<endl;
        isAlive = false;
        isGameOver = true;
      }
      else
      {
        cout<<"boss health : "<<health<<endl;
      }
    }
    else
    {
      count -= 1;
      cout<<"boss defending"<<endl;
    }
    return health ;
  }
  bool isWinner()
  {
    if (isAlive == true)
    {
      cout<<"boss won the fight "<<endl;
      return true;
      }
    else
    {
      cout<<"boss lost the fight \nGame Over"<<endl;
      return false;
      }
  }
    int HealDamage()
  {

    if (health < Basehealth)
      { 
        cout<<"Boss healing"<<endl;
        health = health + heal; ;
        if(health>Basehealth)
        { 
          health=Basehealth;
        }
      }
    cout<<"Boss health : "<<health<<endl;
    return health;
  }
};

class fistenemy : public Character
{
  private:
  int count = 0;
  int random;
  int Basehealth = 300;
  int health = 100;
  int heal = 10;
  int meleedamage = 15;
  int mindamage = 10;
  int maxdamage = 15;
  int rangedamage = 10;
  bool isAlive = true;
  bool isGameOver = false;

  public:
  fistenemy()
  {
    cout<<"\nhey you, don't move.\nGet lost from here intruder\n\n";
  }

  int getHealth()
  {
    return health;
  }

  int getMeleeDamage()
  {   
    random = rand() % 10;
    if (random > 5 && random < 8)
    {
      cout<<"Enemy taken deffencive stance"<<endl;
      count += 1;
      meleedamage = 0;
    }
    else
    {
      cout<<"Enemy attacked"<<endl;
      meleedamage = rand()%(maxdamage - mindamage) + mindamage;
    }
    return meleedamage;
  }

  int takeDamage(int dmg)
  {
    if (count == 0)
    {
      cout<<"Player attacked"<<endl;
      health = health - dmg ;
      if (health <= 0)
      {
        cout<<"Enemy  Died"<<endl;
        isAlive = false;
      }
      else
      {
        cout<<"enemy health : "<<health<<endl;
      }
    }
    else
    {
      count -= 1;
      cout<<"Player attacked"<<endl;
      cout<<"Enemy defending\nreduced damage received\n";
      health = health - (int)( dmg * 0.45) ;
      
    }
    return health ;
  }
  bool Death()
  {
    return 0;
  }
  void getLevel(int lvl)
  {
  }
  int setHealth()
  {
    return 0;
  }
  int setHeal()
  {
    return 0;
  }
  int bonusHeal()
  {
    return 0;
  }
  int setDamage()
  {
    return 0;
  }
  bool isWinner()
  {
    return 0;
  }
  int HealDamage()
  {

    if (health < Basehealth)
      { 
        cout<<"Boss healing"<<endl;
        health = health + heal; ;
        if(health>Basehealth)
        { 
          health=Basehealth;
        }
      }
    cout<<"Boss health : "<<health<<endl;
    return health;
  }
};

class GamePlay
{
  private:
  Character *Player = new player();
  int level = 1;
  char choice;
  
  public:
  GamePlay()
  {
    cout<<"Long long ago\n";
    cout<<"In far land of Oeisis\n";
    cout<<"description of current situation\n";
    cout<<"tragedy involving fate\n";
    cout<<"Nemessis intro\n\n";
    GameMechanics();
  }
  
  void GameMechanics()
  {   cout<<"Press any key to continue\n";
      cin>>choice;
      system("clear");
      PlayerInfo();
      cout<<"Press any key to continue\n";
      cin>>choice;
      system("clear");
    for (int i = 1; i <= 5; i++)
    {
      AbilityUnlock(level);
      cout<<"Press any key to continue\n";
      cin>>choice;
      system("clear");
      cout<<"Floor : "<<i<<endl;
      Player->getLevel(i);
      cout<<" Player spotted "<<i<<" Enemies"<<endl;
      cout<<" Get ready for battle\n"<<endl;
      for (int j = 1; j <= i; j++)
        {
  
          level1();
          if(Player->isWinner() == true)
          {
            Player->bonusHeal();
          }
          else
            break;
          }
      cout<<"Press any key to continue\n";
      cin>>choice;
      system("clear");
      if(Player->getHealth() >= 0 )
      {cout<<"Player received buffs\n";
        Player->setHealth();
        Player->setDamage();
        Player->setHeal();
      }
      else
      {
        break;
        }
      cout<<"Passed level "<<i<<endl;
      level += 1;
      cout<<"Press any key to continue to Level :"<<level<<endl;
      cin>>choice;
      system("clear");
      
    }
    if(Player->getHealth() >= 0 )
    {
      cout<<"All levels cleared, time to meet the boss\n";
      level1();
    }
    delete Player;
  }
  void gameloop(Character *Enemy)
  {   
    do
    {
      cout<<"Choose action\nA. Attack\nH. Heal\n";
        here:
      cin >> choice;
      system ("clear");
      switch (choice) {
      case 'a':
        Enemy->takeDamage(Player->getMeleeDamage());
        break;
      case 'A':
        Enemy->takeDamage(Player->getMeleeDamage());
        break;
      case 'H':
        Player->HealDamage();
        break;
      case 'h':
        Player->HealDamage();
        break;
      default:
        cout << "Invalid Choice \n";
        goto here;
    };
      if(Enemy->getHealth() >= 0)
      {
        Player->takeDamage(Enemy->getMeleeDamage());
      }
      
      }while(Player->getHealth() >= 0 && Enemy->getHealth() >= 0);
  }
  void level1()
  {
    switch(level)
    {
      default:
        {Character *Enemy = new fistenemy;
          gameloop(Enemy);
          delete Enemy;
        break;}
      case 6:
        {Character *Enemy = new boss;
          gameloop(Enemy);
          delete Enemy;
        break;}
    } 
  }

  void AbilityUnlock(int i)
  {
    switch(i)
        {
          case 2 :
            {
              cout<<"Player got a mp of foor from the dead enemy.\nit says the den has 6 floors\n the boss is on the last floor\nevery floor has the same amount of enemy guards as the number of floor\n";
            }
          break;
          case 3 :
            {
              cout<<"hero picked a sword from the dead soldier\n damage increased\nnew ability unlocked\nGive critical damage to enemy\n";
            }
            break;
          case 4 :
          {
            cout<<"hero picked a shield from the dead soldier\n defence increased\nnew ability unlocked\nblock critical hits\n";
            }
          break;
          case 5 :
          {
            cout<<"that's one well crafted armour\nbut it didn't protect you from me\nnow that you don't need it, let me have it\n player looted armour from the dead soldier\n defence increased\nnew ability unlocked\nlife steal(when active player does damage and receive no damage for 1 turm)\n";
            }break;
          case 6 :
          {
            cout<<"that archer was a nuicense\nhe thought keeping distance would help him\nidiot, it's a fine bow suitable for a warrior\n player looted bow from the dead soldier\nnew ability unlocked\nLong range attack (attack enemy while keeping distance)\n";
            }
            break;
          default:
            {
              cout<<"Player enters battlefield with nothing but courage and bare hands\nKnocking on the door of eveil\n";
            }
          
        };
  }
  void PlayerInfo()
  {
    cout<<"\nsome cool intro to player\n";
    cout<<"fearsome name\n";
    cout<<"The man standing on the door of the evil, Chhagan\n";
    cout<<"Player objectives\n\n";
  }
  ~GamePlay()
  {
    delete Player;
  }
};

int main()
{
  GamePlay Gameplay;  
}
