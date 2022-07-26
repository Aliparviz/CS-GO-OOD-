//بسم الله الرحمن الرحیم
#include<iostream>
#include <vector>
#include<string>
#define knife_power 35
#define knife_award 500
#define knife_price 0
#define pistol_price 400
#define pistol_power 20
#define pistol_award 200
#define heavy_price 3000
#define heavy_power 45
#define heavy_award 100
#define max_money 10000
#define winner_prize 2700
#define loser_prize 2400
using namespace std;
class Weapon
{
private:
	string name;
	int power;
	int award;
	int price;
public:
	int getpower() { return power; }
	int getaward() { return award; }
	int getprice() { return price; }
	string getname() { return name; }
	Weapon(string wep_name)
	{
		if (wep_name == "knife")
		{
			power = knife_power;
			award = knife_award;
			price = knife_price;
			name = wep_name;
		}
		else if (wep_name == "pistol")
		{
			power = pistol_power;
			award = pistol_award;
			price = pistol_price;
			name = wep_name;
		}
		else if (wep_name == "heavy")
		{
			power = heavy_power;
			award = heavy_award;
			price = heavy_price;
			name = wep_name;
		}
	}
};
class Terrorist
{
private:
	bool is_alive;
	int check_afk;
	int money;
	int health;
	int kills_counter;
	int deaths_counter;
	string username;
	vector<Weapon>weapons;
public:
	Terrorist(string name, int afk = 0, int coin = 1000, int healf = 100, bool check_live = true, int kill = 0, int death = 0)
	{
		username = name;
		check_afk = afk;
		money = coin;
		health = healf;
		is_alive = check_live;
		kills_counter = kill;
		deaths_counter = death;
		weapons.push_back(Weapon("knife"));
	}
	void put_afk()
	{
		check_afk = 1;
	}
	void put_atk()
	{
		check_afk = 0;
	}
	void add_weapon(Weapon new_wep)
	{
		weapons.push_back(new_wep);
	}
	void reset_money(int wep_money)
	{
		money -= wep_money;
		if (money < 0)
		{
			money = 0;
		}
	}
	int getmoney() { return money; }
	int gethealth() { return health; }
	int getafk() { return check_afk; }
	int getkills() { return kills_counter; }
	int getdeaths() { return deaths_counter; }
	bool getalive() { return is_alive; }
	string getname() { return username; }
	void add_one_to_kills_counter()
	{
		kills_counter++;
	}
	void add_one_to_deaths_counter()
	{
		deaths_counter++;
	}
	void decrease_health(int weapon_power)
	{
		health -= weapon_power;
		if (health <= 0)
		{
			health = 0;
			is_alive = false;
		}
	}
	void add_prize(int prize)
	{
		money += prize;
		if (money > max_money)
		{
			money = max_money;
		}
	}
	void reset_alive() { is_alive = true; }
	void remove_weapons()
	{
		weapons.erase(weapons.begin() + 1, weapons.end());
	}
	vector<Weapon>getweapons() { return weapons; }

};
class Counter_Terrorist
{
private:
	bool is_alive;
	int check_afk;
	int money;
	int health;
	int kills_counter;
	int deaths_counter;
	string username;
	vector<Weapon>weapons;
public:
	Counter_Terrorist(string name, int afk = 0, int coin = 1000, int healf = 100, bool check_live = true, int kill = 0, int death = 0)
	{
		username = name;
		check_afk = afk;
		money = coin;
		health = healf;
		is_alive = check_live;
		kills_counter = kill;
		deaths_counter = death;
		weapons.push_back(Weapon("knife"));
	}
	void put_afk()
	{
		check_afk = 1;
	}
	void put_atk()
	{
		check_afk = 0;
	}
	void add_weapon(Weapon new_wep)
	{
		weapons.push_back(new_wep);
	}
	void reset_money(int wep_money)
	{
		money -= wep_money;
		if (money < 0)
		{
			money = 0;
		}
	}
	int getmoney() { return money; }
	int gethealth() { return health; }
	int getkills() { return kills_counter; }
	int getdeaths() { return deaths_counter; }
	int getafk() { return check_afk; }
	bool getalive() { return is_alive; }
	string getname() { return username; }
	void add_one_to_kills_counter()
	{
		kills_counter++;
	}
	void add_one_to_deaths_counter()
	{
		deaths_counter++;
	}
	void decrease_health(int weapon_power)
	{
		health -= weapon_power;
		if (health <= 0)
		{
			health = 0;
			is_alive = false;
		}
	}
	void add_prize(int prize)
	{
		money += prize;
		if (money > max_money)
		{
			money = max_money;
		}
	}
	void reset_alive() { is_alive = true; }
	void remove_weapons()
	{
		weapons.erase(weapons.begin() + 1, weapons.end());
	}
	vector<Weapon>getweapons() { return weapons; }
};
void start_game(int &check_start)
{
	check_start = 1;
	cout << "fight!" << endl;
}
void add_terrorist(vector<Terrorist>&terrorists, string name)
{
	Terrorist terrorist(name);
	terrorists.push_back(terrorist);
	cout << "ok" << endl;
}
void add_counter_terrorist(vector<Counter_Terrorist>&counter_terrorists, string name)
{
	Counter_Terrorist ct(name);
	counter_terrorists.push_back(ct);
	cout << "ok" << endl;
}
void add_user(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, int check_start)
{
	string name, team;
	cin >> name >> team;
	if (check_start == 1)
	{
		cout << "you can't add member after starting round" << endl;
		return;
	}
	if (team == "terrorist")
	{
		add_terrorist(terrorists, name);
	}
	if (team == "counter-terrorist")
	{
		add_counter_terrorist(counter_terrorists, name);
	}
}
void show_money(vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists)
{
	string name;
	cin >> name;
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == name)
		{
			cout << terrorists[i].getmoney() << endl;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == name)
		{
			cout << counter_terrorists[i].getmoney() << endl;
		}
	}
}
void show_health(vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists)
{
	string name;
	cin >> name;
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == name)
		{
			cout << terrorists[i].gethealth() << endl;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == name)
		{
			cout << counter_terrorists[i].gethealth() << endl;
		}
	}
}
void put_atk(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	string name;
	cin >> name;
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == name)
		{
			terrorists[i].put_atk();
			cout << "ok" << endl;
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == name)
		{
			counter_terrorists[i].put_atk();
			cout << "ok" << endl;
		}
	}
}
void put_afk(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	string name;
	cin >> name;
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == name)
		{
			terrorists[i].put_afk();
			cout << "ok" << endl;
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == name)
		{
			counter_terrorists[i].put_afk();
			cout << "ok" << endl;
		}
	}
}
vector<Weapon>standard_weapons()
{
	vector<Weapon>standard_weapons;
	standard_weapons.push_back(Weapon("knife"));
	standard_weapons.push_back(Weapon("pistol"));
	standard_weapons.push_back(Weapon("heavy"));
	return standard_weapons;
}
bool check_available_user(string user, vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == user && terrorists[i].getafk() == 0)
		{
			return true;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == user && counter_terrorists[i].getafk() == 0)
		{
			return true;
		}
	}
	return false;
}
bool check_available_users(string attacker, string attacked, vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists)
{
	if (check_available_user(attacker, terrorists, counter_terrorists) == true && check_available_user(attacked, terrorists, counter_terrorists) == true)
	{
		return true;
	}
	return false;
}
bool check_user_alive(string user, vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == user)
		{
			if (terrorists[i].getalive() == false)
			{
				return false;
			}
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == user)
		{
			if (counter_terrorists[i].getalive() == false)
			{
				return false;
			}
		}
	}
	return true;
}
bool check_having_rifle_terror(string attacker, string weapon, vector<Terrorist>terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacker)
		{
			for (int j = 0; j < terrorists[i].getweapons().size(); j++)
			{
				if (terrorists[i].getweapons()[j].getname() == weapon)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool check_having_rifle_counter(string attacker, string weapon, vector<Counter_Terrorist>counter_terrorists)
{
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacker)
		{
			for (int j = 0; j < counter_terrorists[i].getweapons().size(); j++)
			{
				if (counter_terrorists[i].getweapons()[j].getname() == weapon)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool check_having_rifle(string attacker, string weapon, vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	if (check_having_rifle_counter(attacker, weapon, counter_terrorists) == true ||
		check_having_rifle_terror(attacker, weapon, terrorists) == true)
	{
		return true;
	}
	return false;
}
bool check_counter_teammate(string attacker, string attacked, vector<Counter_Terrorist>counter_terrorists)
{
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacker)
		{
			for (int j = 0; j < counter_terrorists.size(); j++)
			{
				if (counter_terrorists[j].getname() == attacked)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool check_terror_teamate(string attacker, string attacked, vector<Terrorist>terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacker)
		{
			for (int j = 0; j < terrorists.size(); j++)
			{
				if (terrorists[j].getname() == attacked)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool check_teammate(vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists, string attacker, string attacked)
{
	if (check_counter_teammate(attacker, attacked, counter_terrorists) == true ||
		check_terror_teamate(attacker, attacked, terrorists) == true)
	{
		return true;
	}
	return false;
}
void add_one_to_kills(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, string attacker)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacker)
		{
			terrorists[i].add_one_to_kills_counter();
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacker)
		{
			counter_terrorists[i].add_one_to_kills_counter();
			return;
		}
	}
}
void add_one_to_deaths(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, string attacked)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacked)
		{
			terrorists[i].add_one_to_deaths_counter();
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacked)
		{
			counter_terrorists[i].add_one_to_deaths_counter();
			return;
		}
	}
}
int find_weapon_power(vector<Weapon>weapons_list, string weapon)
{
	for (int i = 0; i < weapons_list.size(); i++)
	{
		if (weapons_list[i].getname() == weapon)
		{
			return weapons_list[i].getpower();
		}
	}
}
void decrease_attacked_health(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, string attacked, string weapon)
{
	int weapon_power = find_weapon_power(standard_weapons(), weapon);

	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacked)
		{
			terrorists[i].decrease_health(weapon_power);
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacked)
		{
			counter_terrorists[i].decrease_health(weapon_power);
			return;
		}
	}

}
int find_weapon_award(vector<Weapon>weapons_list, string weapon)
{
	for (int i = 0; i < weapons_list.size(); i++)
	{
		if (weapons_list[i].getname() == weapon)
		{
			return weapons_list[i].getaward();
		}
	}
}
void add_award_to_attacker(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, string attacker, string weapon)
{
	int weapon_award = find_weapon_award(standard_weapons(), weapon);
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacker)
		{
			terrorists[i].add_prize(weapon_award);
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacker)
		{
			counter_terrorists[i].add_prize(weapon_award);
			return;
		}
	}
}
bool is_attacked_alive(vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists, string attacked)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacked)
		{
			if (terrorists[i].getalive() == true)
			{
				return true;
			}
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacked)
		{
			if (counter_terrorists[i].getalive() == true)
			{
				return true;
			}
		}
	}
	return false;
}
void remove_attacked_weapons(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, string attacked)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == attacked)
		{
			terrorists[i].remove_weapons();
			return;
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == attacked)
		{
			counter_terrorists[i].remove_weapons();
			return;
		}
	}
}
void shoot(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, int check_start)
{
	string attacker, attacked, weapon;
	cin >> attacker >> attacked >> weapon;
	if (check_start == 0)
	{
		cout << "the game hasn't started yet" << endl;
		return;
	}
	if (check_available_users(attacker, attacked, terrorists, counter_terrorists) == false)
	{
		cout << "user not available" << endl;
		return;
	}
	if (check_user_alive(attacker, terrorists, counter_terrorists) == false)
	{
		cout << "attacker is dead" << endl;
		return;
	}
	if (check_user_alive(attacked, terrorists, counter_terrorists) == false)
	{
		cout << "attacked is dead" << endl;
		return;
	}
	if (check_having_rifle(attacker, weapon, terrorists, counter_terrorists) == false)
	{
		cout << "attacker doesn't have this gun" << endl;
		return;
	}
	if (check_teammate(terrorists, counter_terrorists, attacker, attacked) == true)
	{
		cout << "you can't shoot this player" << endl;
		return;
	}
	else
	{
		decrease_attacked_health(terrorists, counter_terrorists, attacked, weapon);
		if (is_attacked_alive(terrorists, counter_terrorists, attacked) == false)
		{
			add_one_to_kills(terrorists, counter_terrorists, attacker);
			add_one_to_deaths(terrorists, counter_terrorists, attacked);
			add_award_to_attacker(terrorists, counter_terrorists, attacker, weapon);
			remove_attacked_weapons(terrorists, counter_terrorists, attacked);
		}
		cout << "nice shot" << endl;
	}
}
void buy_weapon(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, int check_start)
{
	string name, weapon_name;
	cin >> name >> weapon_name;
	if (weapon_name != "heavy" && weapon_name != "pistol"&& weapon_name != "knife")
	{
		cout << "weapon not available" << endl;
		return;
	}
	if (check_start == 1)
	{
		cout << "you can't buy weapons anymore" << endl;
		return;
	}
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getname() == name)
		{
			for (int j = 0; j < terrorists[i].getweapons().size(); j++)
			{
				if (terrorists[i].getweapons()[j].getname() == weapon_name)
				{
					cout << "you already have this weapon" << endl;
					return;
				}
			}
			for (int k = 0; k < standard_weapons().size(); k++)
			{
				if (standard_weapons()[k].getname() == weapon_name)
				{
					if (terrorists[i].getmoney() - standard_weapons()[k].getprice() < 0)
					{
						cout << "insufficient money" << endl;
						return;
					}
					if (terrorists[i].getmoney() - standard_weapons()[k].getprice() >= 0)
					{
						terrorists[i].reset_money(standard_weapons()[k].getprice());
						cout << "weapon bought successfully" << endl;
						terrorists[i].add_weapon(standard_weapons()[k]);
						return;
					}
				}
			}
		}
		if (terrorists[i].getafk() == 1)
		{
			cout << "user not available" << endl;
			return;
		}
	}

	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getname() == name)
		{
			for (int j = 0; j < counter_terrorists[i].getweapons().size(); j++)
			{
				if (counter_terrorists[i].getweapons()[j].getname() == weapon_name)
				{
					cout << "you already have this weapon" << endl;
					return;
				}
			}
			for (int k = 0; k < standard_weapons().size(); k++)
			{
				if (standard_weapons()[k].getname() == weapon_name)
				{
					if (counter_terrorists[i].getmoney() - standard_weapons()[k].getprice() < 0)
					{
						cout << "insufficient money" << endl;
						return;
					}
					if (counter_terrorists[i].getmoney() - standard_weapons()[k].getprice() >= 0)
					{
						counter_terrorists[i].reset_money(standard_weapons()[k].getprice());
						cout << "weapon bought successfully" << endl;
						counter_terrorists[i].add_weapon(standard_weapons()[k]);
						return;
					}
				}
			}
		}
		if (counter_terrorists[i].getafk() == 1)
		{
			cout << "user not available" << endl;
			return;
		}
	}
	cout << "user not available" << endl;
	return;
}
void show_counter_board(vector<Counter_Terrorist>counter_terrorists)
{
	cout << "counter-terrorist players:" << endl;
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		cout << counter_terrorists[i].getname() << " " << counter_terrorists[i].getkills() << " " << counter_terrorists[i].getdeaths() << endl;
	}
}
void show_terror_board(vector<Terrorist>terrorists)
{
	cout << "terrorist players:" << endl;
	for (int i = 0; i < terrorists.size(); i++)
	{
		cout << terrorists[i].getname() << " " << terrorists[i].getkills() << " " << terrorists[i].getdeaths() << endl;
	}
}
void show_board(vector<Terrorist>terrorists, vector<Counter_Terrorist>counter_terrorists)
{
	show_counter_board(counter_terrorists);
	show_terror_board(terrorists);
}
void sort_terrorists(vector<Terrorist>&terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		for (int j = 0; j < terrorists.size(); j++)
		{
			if (terrorists[i].getkills() > terrorists[j].getkills())
			{
				Terrorist flag = terrorists[i];
				terrorists[i] = terrorists[j];
				terrorists[j] = flag;
			}
			else if (terrorists[i].getkills() == terrorists[j].getkills())
			{
				if (terrorists[i].getdeaths() < terrorists[j].getdeaths())
				{
					Terrorist flag = terrorists[i];
					terrorists[i] = terrorists[j];
					terrorists[j] = flag;
				}
				else if (terrorists[i].getdeaths() == terrorists[j].getdeaths())
				{
					if (terrorists[i].getname() < terrorists[j].getname())
					{
						Terrorist flag = terrorists[i];
						terrorists[i] = terrorists[j];
						terrorists[j] = flag;
					}
				}
			}
		}
	}
}
void sort_counter_terrorists(vector<Counter_Terrorist>&counter_terrorists)
{
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		for (int j = 0; j < counter_terrorists.size(); j++)
		{
			if (counter_terrorists[i].getkills() > counter_terrorists[j].getkills())
			{
				Counter_Terrorist flag = counter_terrorists[i];
				counter_terrorists[i] = counter_terrorists[j];
				counter_terrorists[j] = flag;
			}
			else if (counter_terrorists[i].getkills() == counter_terrorists[j].getkills())
			{
				if (counter_terrorists[i].getdeaths() < counter_terrorists[j].getdeaths())
				{
					Counter_Terrorist flag = counter_terrorists[i];
					counter_terrorists[i] = counter_terrorists[j];
					counter_terrorists[j] = flag;
				}
				else if (counter_terrorists[i].getdeaths() == counter_terrorists[j].getdeaths())
				{
					if (counter_terrorists[i].getname() < counter_terrorists[j].getname())
					{
						Counter_Terrorist flag = counter_terrorists[i];
						counter_terrorists[i] = counter_terrorists[j];
						counter_terrorists[j] = flag;
					}
				}
			}
		}
	}
}
void sort_board(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	sort_terrorists(terrorists);
	sort_counter_terrorists(counter_terrorists);
}
void get_commands(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, int&check_start)
{
	string line;
	cin >> line;
	if (line == "start")
	{
		start_game(check_start);
	}
	else if (line == "add-user")
	{
		add_user(terrorists, counter_terrorists, check_start);
	}
	else if (line == "get-money")
	{
		show_money(terrorists, counter_terrorists);
	}
	else if (line == "get-health")
	{
		show_health(terrorists, counter_terrorists);
	}
	else if (line == "go-afk")
	{
		put_afk(terrorists, counter_terrorists);
	}
	else if (line == "go-atk")
	{
		put_atk(terrorists, counter_terrorists);
	}
	else if (line == "shoot")
	{
		shoot(terrorists, counter_terrorists, check_start);
	}
	else if (line == "buy")
	{
		buy_weapon(terrorists, counter_terrorists, check_start);
	}
	else if (line == "score-board")
	{
		sort_board(terrorists, counter_terrorists);
		show_board(terrorists, counter_terrorists);
	}
}
void get_inputs(int& num_of_rounds, int& num_of_commands, string& command, vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists, int check_start)
{
	while (cin >> command)
	{
		if (command == "add-user")
		{
			add_user(terrorists, counter_terrorists, check_start);
		}
		else if (command == "buy")
		{
			buy_weapon(terrorists, counter_terrorists, check_start);
		}
		else if (command == "score-board")
		{
			sort_board(terrorists, counter_terrorists);
			show_board(terrorists, counter_terrorists);
		}
		else if (command == "go-afk")
		{
			put_afk(terrorists, counter_terrorists);
		}
		else if (command == "go-atk")
		{
			put_atk(terrorists, counter_terrorists);
		}
		else if (command == "round")
		{
			cin >> num_of_commands;
			return;
		}
	}
}
void print_round_result(bool& check_terror_alive, bool& check_counter_alive, vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		if (terrorists[i].getalive() == true)
		{
			if (terrorists[i].getafk() == 0)
			{
				check_terror_alive = true;
				break;
			}
		}
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		if (counter_terrorists[i].getalive() == true)
		{
			if (counter_terrorists[i].getafk() == 0)
			{
				check_counter_alive = true;
				break;
			}
		}
	}
	if ((check_counter_alive == true && check_terror_alive == false) ||
		(check_counter_alive == true && check_terror_alive == true))
	{
		cout << "counter-terrorist won" << endl;
		return;
	}
	if (check_counter_alive == false &&
		check_terror_alive == true)
	{
		cout << "terrorist won" << endl;
		return;
	}
}
void add_prizes(bool check_terror_alive, bool check_counter_alive, vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	if ((check_counter_alive == true && check_terror_alive == false) ||
		(check_counter_alive == true && check_terror_alive == true))
		//it means that counter-terrorists won the game
	{
		for (int i = 0; i < terrorists.size(); i++)
		{
			terrorists[i].add_prize(loser_prize);
		}
		for (int i = 0; i < counter_terrorists.size(); i++)
		{
			counter_terrorists[i].add_prize(winner_prize);
		}
		return;
	}
	if (check_counter_alive == false &&
		check_terror_alive == true)
		//it means that terrorists won the game
	{
		for (int i = 0; i < terrorists.size(); i++)
		{
			terrorists[i].add_prize(winner_prize);
		}
		for (int i = 0; i < counter_terrorists.size(); i++)
		{
			counter_terrorists[i].add_prize(loser_prize);
		}
		return;
	}
}
void reset_alives(vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	for (int i = 0; i < terrorists.size(); i++)
	{
		terrorists[i].reset_alive();
	}
	for (int i = 0; i < counter_terrorists.size(); i++)
	{
		counter_terrorists[i].reset_alive();
	}
}
void manage_rounds(int& num_of_rounds, int& num_of_commands, int check_start
	, vector<Terrorist>&terrorists, vector<Counter_Terrorist>&counter_terrorists)
{
	bool check_terror_alive = false;
	bool check_counter_alive = false;
	string round;
	while (true)
	{
		for (int j = 0; j < num_of_commands; j++)
		{
			get_commands(terrorists, counter_terrorists, check_start);
		}
		print_round_result(check_terror_alive, check_counter_alive, terrorists, counter_terrorists);
		add_prizes(check_terror_alive, check_counter_alive, terrorists, counter_terrorists);
		reset_alives(terrorists, counter_terrorists);
		check_start = 0;
		cin >> round >> num_of_commands;
	}
}
int main()
{
	vector<Terrorist>terrorists;
	vector<Counter_Terrorist>counter_terrorists;
	int num_of_rounds, num_of_commands, check_start = 0;
	string command;
	cin >> num_of_rounds;
	get_inputs(num_of_rounds, num_of_commands, command, terrorists, counter_terrorists, check_start);

	manage_rounds(num_of_rounds, num_of_commands, check_start, terrorists, counter_terrorists);

	return 0;
}