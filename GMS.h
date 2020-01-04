#pragma once


using namespace std;

inline uint MAXS() // 最大剑士数量
{
	return 100;
}
inline uint MAXM() //最大魔法师数量
{
	return 100;
}
uint stringToNum(const string& str) //将字符串转换为uint
{
	istringstream iss(str);
	uint num;
	iss >> num;
	return num;
}

class adventure
{
public:
	adventure();
	adventure(string newName, uint newAge, uint newLevel, uint HP);
	virtual ~adventure();
	virtual string getName();
	virtual uint getAge();
	virtual uint getLevel();
	virtual uint getHP();
	virtual void modi() = 0; // 纯虚函数
	virtual void printAtt() = 0; // 纯虚函数
	virtual void printAtt(string s) = 0; // 以列方向输出信息

protected:
	string Name;
	uint Age;
	uint Level;
	uint HP;
};

adventure::adventure()
{
	//cout << "" << endl;
}
adventure::adventure(string newName, uint newAge, uint newLevel, uint newHP)
{
	Name = newName;
	Age = newAge;
	Level = newLevel;
	HP = newHP;
}
adventure::~adventure()
{

}
string adventure::getName()
{
	return Name;
}
uint adventure::getAge()
{
	return Age;
}
uint adventure::getLevel()
{
	return Level;
}
uint adventure::getHP()
{
	return HP;
}

class saber :virtual public adventure
{
public:
	saber();
	saber(string newName, uint newAge, uint newLevel, uint newHP, uint newATK);
	saber(saber &s); //拷贝构造函数
	~saber();
	uint getATK(); //获取攻击力
	void modi(); //用于普通修改
	void modi(string newName, uint newAge, uint newLevel, uint newHP, uint newATK); //用于新建后的输入
	void printAtt();
	void printAtt(string s); //以行的形式显示

protected:
	uint ATK;
};

saber::saber()
{
	;
}
saber::saber(string newName, uint newAge, uint newLevel, uint newHP, uint newATK)
	:adventure(newName, newAge, newLevel, newHP)
{
	ATK = newATK;
}
saber::saber(saber &s)
	: adventure(s.Name, s.Age, s.Level, s.HP)
{
	ATK = s.ATK;
}
saber::~saber()
{

}
uint saber::getATK()
{
	return ATK;
}
void saber::modi()
{
	string temp_n;
	uint temp_i, temp_select;
	temp_select = dis_prolist(0);
	property p = p_list[temp_select - 1];
	cout << "请输入阁下要修改的内容" << endl;
	switch (p)
	{
	case name:cin >> temp_n; Name = temp_n;
		break;
	case age:cin >> temp_i; Age = temp_i;
		break;
	case level:cin >> temp_i; Level = temp_i;
		break;
	case hp:cin >> temp_i; HP = temp_i;
		break;
	case atk:cin >> temp_i; ATK = temp_i;
		break;
	default:cout << "关键字错误" << endl;
		break;
	}
}
void saber::modi(string newName, uint newAge, uint newLevel, uint newHP, uint newATK)
{
	Name = newName;
	Age = newAge;
	Level = newLevel;
	HP = newHP;
	ATK = newATK;
}
void saber::printAtt()
{
	cout << "姓名：" << Name << endl;
	cout << "年龄：" << Age << endl;
	cout << "等级：" << Level << endl;
	cout << "HP：" << HP << endl;
	cout << "ATK：" << ATK << endl;
}
void saber::printAtt(string s)
{
	cout << Name << "\tsaber\t" << Age << "\t" << Level << "\t" << HP << "\t" << ATK << endl;
}

class magician :virtual public adventure
{
public:
	magician();
	magician(string newName, uint newAge, uint newLevel, uint newHP, uint newMGA);
	magician(magician &m);
	//magician(saber &s);
	~magician();
	uint getMGA();
	void modi();
	void modi(string newName, uint newAge, uint newLevel, uint newHP, uint newMGA);
	void printAtt();
	void printAtt(string s); //以行的形式显示

protected:
	uint MGA;
};

magician::magician()
{
	;
}
magician::magician(string newName, uint newAge, uint newLevel, uint newHP, uint newMGA)
	:adventure(newName, newAge, newLevel, newHP)
{
	MGA = newMGA;
}
magician::magician(magician &m)
	: adventure(m.Name, m.Age, m.Level, m.HP)
{
	MGA = m.MGA;
}
magician::~magician()
{
	;
}
uint magician::getMGA()
{
	return MGA;
}
void magician::modi()
{
	string temp_n;
	uint temp_i, temp_select;
	temp_select = dis_prolist(1);
	property p = p_list[temp_select - 1];
	cout << "请输入要修改的内容" << endl;
	switch (p)
	{
	case name:cin >> temp_n; Name = temp_n;
		break;
	case age:cin >> temp_i; Age = temp_i;
		break;
	case level:cin >> temp_i; Level = temp_i;
		break;
	case hp:cin >> temp_i; HP = temp_i;
		break;
	case mga:cin >> temp_i; MGA = temp_i;
		break;
	default:cout << "关键字错误" << endl;
		break;
	}
}
void magician::modi(string newName, uint newAge, uint newLevel, uint newHP, uint newMGA)
{
	Name = newName;
	Age = newAge;
	Level = newLevel;
	HP = newHP;
	MGA = newMGA;
}
void magician::printAtt()
{
	cout << "姓名：" << Name << endl;
	cout << "年龄：" << Age << endl;
	cout << "等级：" << Level << endl;
	cout << "HP：" << HP << endl;
	cout << "MGA：" << MGA << endl;
}
void magician::printAtt(string s)
{
	cout << Name << "\tmage\t" << Age << "\t" << Level << "\t" << HP << "\t\t" << MGA << endl;
}

class master : public saber, public magician
{
public:
	master();
	master(string newName, uint newAge, uint newlevel, uint newHP, uint newATK, uint newMGA);
	master(saber &s); //拷贝构造函数
	master(magician &m); //拷贝构造函数
	~master();
	void modi();
	void modi(string newName, uint newAge, uint newLevel, uint newHP, uint newATK, uint newMGA);
	void printAtt();
	void printAtt(string s);
};

master::master()
{
	Name = "0";
	Age = 0;
	Level = 0;
	HP = 0;
	ATK = 0;
	MGA = 0;
}
master::master(string newName, uint newAge, uint newLevel, uint newHP, uint newATK, uint newMGA)
	:adventure(newName, newAge, newLevel, newHP), saber(newName, newAge, newLevel, newHP, newATK), magician(newName, newAge, newLevel, newHP, newMGA)
{
	;
}
master::master(saber &s)
{
	Name = s.getName();
	Age = s.getAge();
	Level = s.getLevel();
	HP = s.getHP();
	ATK = s.getATK();
	MGA = 50; //初始化为50
}
master::master(magician &m)
{
	Name = m.getName();
	Age = m.getAge();
	Level = m.getLevel();
	HP = m.getHP();
	ATK = 50; //初始化为50
	MGA = m.getMGA();
}
master::~master()
{

}
void master::modi()
{
	string temp_n;
	uint temp_i, temp_select;
	temp_select = dis_prolist(2);
	property p = p_list[temp_select - 1];
	cout << "请输入阁下要修改的内容" << endl;
	switch (p)
	{
	case name:cin >> temp_n; Name = temp_n;
		break;
	case age:cin >> temp_i; Age = temp_i;
		break;
	case level:cin >> temp_i; Level = temp_i;
		break;
	case hp:cin >> temp_i; HP = temp_i;
		break;
	case atk:cin >> temp_i; ATK = temp_i;
		break;
	case mga:cin >> temp_i; MGA = temp_i;
		break;
	default:cout << "关键字错误" << endl;
		break;
	}
}
void master::modi(string newName, uint newAge, uint newLevel, uint newHP, uint newATK, uint newMGA)
{
	Name = newName;
	Age = newAge;
	Level = newLevel;
	HP = newHP;
	ATK = newATK;
	MGA = newMGA;
}
void master::printAtt()
{
	cout << "姓名：" << Name << endl;
	cout << "年龄：" << Age << endl;
	cout << "等级：" << Level << endl;
	cout << "HP：" << HP << endl;
	cout << "ATK：" << ATK << endl;
	cout << "MGA：" << MGA << endl;
}
void master::printAtt(string s)
{
	cout << Name << "\tmaster\t" << Age << "\t" << Level << "\t" << HP << "\t" << ATK << "\t" << MGA << endl;
}

class guild
{
public:
	guild();
	~guild();
	void addMA();
	void addMA(string newName, uint newAge, uint newLevel, uint newHP, uint newATK, uint newMGA);
	void addS();
	void addS(string newName, uint newAge, uint newLevel, uint newHP, uint newATK);
	void addM();
	void addM(string newName, uint newAge, uint newLevel, uint newHP, uint newMGA);
	void modiMA();
	void modiS();
	void modiM();
	void delS();
	void delS(string s_name);
	void delM();
	void delM(string m_name);
	void promotion(); // 将某一个队员升职为会长
	void searchS(string t_name);
	void searchM(string t_name);
	void search(string t_name); //对除会长外的人员进行搜索
	void load(string FileName);
	void save(string FileName);
	void displayMa();
	void displayS();
	void displayM();
	void display();

protected:
	uint s_num = 0;
	uint m_num = 0;
	master ma;
	saber s[100];
	magician m[100];
};

guild::guild()
{

}
guild::~guild()
{

}
void guild::addMA()
{
	pro temp;
	if (ma.getName() != "0")
	{
		temp = pro_in(2);
		ma.modi(temp.p_name, temp.p_age, temp.p_level, temp.p_hp, temp.p_atk, temp.p_mga);
	}
	else cout << "已存在会长，添加失败！" << endl;
}
void guild::addMA(string newName, uint newAge, uint newLevel, uint newHP, uint newATK, uint newMGA)
{
	if (ma.getName() == "0")
	{
		ma.modi(newName, newAge, newLevel, newHP, newATK, newMGA);
	}
	else cout << "已存在会长，添加失败！" << endl;
}
void guild::addS()
{
	cout << "正在添加剑士" << endl;
	if (s_num < MAXS())
	{
		pro temp;
		temp = pro_in(0);
		s[s_num].modi(temp.p_name, temp.p_age, temp.p_level, temp.p_hp, temp.p_atk);
		s_num++;
	}
	else cout << "人数已满，无法添加！" << endl;
}
void guild::addS(string newName, uint newAge, uint newLevel, uint newHP, uint newATK)
{
	if (s_num < MAXS())
	{
		s[s_num].modi(newName, newAge, newLevel, newHP, newATK);
		s_num++;
	}
	else cout << "人数已满，无法添加！" << endl;
}
void guild::addM()
{
	cout << "正在添加魔法师" << endl;
	if (m_num < MAXM())
	{
		pro temp;
		temp = pro_in(1);
		m[m_num].modi(temp.p_name, temp.p_age, temp.p_level, temp.p_hp, temp.p_mga);
		m_num++;
	}
	else cout << "人数已满，无法添加" << endl;
}
void guild::addM(string newName, uint newAge, uint newLevel, uint newHP, uint newMGA)
{
	if (m_num < MAXM())
	{
		m[m_num].modi(newName, newAge, newLevel, newHP, newMGA);
		m_num++;
	}
	else cout << "人数已满，无法添加！" << endl;
}
void guild::modiMA()
{
	pro temp;
	cout << "正在修改会长信息" << endl;
	cout << "请输入年龄" << endl;
	cin >> temp.p_age;
	cout << "请输入等级" << endl;
	cin >> temp.p_level;
	cout << "请输入生命值" << endl;
	cin >> temp.p_hp;
	cout << "请输入物理攻击值" << endl;
	cin >> temp.p_atk;
	cout << "请输入魔法攻击值" << endl;
	cin >> temp.p_mga;
	ma.modi(ma.getName(), temp.p_age, temp.p_level, temp.p_hp, temp.p_atk, temp.p_mga);
	cout << "修改成功" << endl;
}
void guild::modiS()
{
	pro temp;
	uint order = 0;
	int search_flag = 0;
	cout << "正在修改剑士信息" << endl;
	pro_title();
	displayS();
	cout << "请输入要修改属性的剑士姓名" << endl;
	cin >> temp.p_name;
	for (order = 0; order < s_num; order++)
	{
		if (temp.p_name == s[order].getName())
		{
			search_flag = 1;
			break;
		}
	}
	if (search_flag)
	{
		cout << "\n已找到名称: " << temp.p_name << " 的剑士，正在进行修改" << endl;
		cout << "请输入年龄" << endl;
		cin >> temp.p_age;
		cout << "请输入等级" << endl;
		cin >> temp.p_level;
		cout << "请输入生命值" << endl;
		cin >> temp.p_hp;
		cout << "请输入物理攻击值" << endl;
		cin >> temp.p_atk;
		s[order].modi(s[order].getName(), temp.p_age, temp.p_level, temp.p_hp, temp.p_atk);
	}
	else cout << "剑士不存在，修改失败！" << endl;
}
void guild::modiM()
{
	pro temp;
	uint order = 0;
	int search_flag = 0;
	cout << "正在修改魔法师信息" << endl;
	pro_title();
	displayM();
	cout << "请输入要修改属性的魔法师姓名" << endl;
	cin >> temp.p_name;
	for (order = 0; order < m_num; order++)
	{
		if (temp.p_name == m[order].getName())
		{
			search_flag = 1;
			break;
		}
	}
	if (search_flag)
	{
		cout << "\n已找到名称: " << temp.p_name << " 的魔法师，正在进行修改" << endl;
		cout << "请输入年龄" << endl;
		cin >> temp.p_age;
		cout << "请输入等级" << endl;
		cin >> temp.p_level;
		cout << "请输入生命值" << endl;
		cin >> temp.p_hp;
		cout << "请输入魔法攻击值" << endl;
		cin >> temp.p_mga;
		m[order].modi(m[order].getName(), temp.p_age, temp.p_level, temp.p_hp, temp.p_mga);
	}
	else cout << "魔法师不存在，修改失败！" << endl;
}
void guild::delS()
{
	string s_name; //用于获取待移出公会的剑士姓名
	int del_flag = 0; //删除标志位，如果删除成功为1，否则为0
	if (s_num > 0)
	{
		pro_title();
		displayS();
		cout << "请输入需要离开公会的剑士的姓名" << endl;
		cin >> s_name;
		for (uint i = 0; i < s_num; i++)
		{
			if (s_name == s[i].getName())
			{
				if (i < s_num - 1)
				{
					for (uint j = i; j < s_num - 1; j++)
					{
						s[j].modi(s[j + 1].getName(), s[j + 1].getAge(), s[j + 1].getLevel(), s[j + 1].getHP(), s[j + 1].getATK());
						del_flag = 1;
					}
				}
				else
				{
					del_flag = 1;
				}
			}
		}
		if (del_flag == 1)
		{
			s[s_num - 1].modi("0", 0, 0, 0, 0); //写入零抹除数据
			s_num--;
		}
		else
		{
			cout << "查无此人，移出失败" << endl;
		}
	}
	else
	{
		cout << "人数不足，删除失败！" << endl;
	}
}
void guild::delS(string s_name)
{
	int del_flag = 0; //删除标志位，如果删除成功为1，否则为0
	if (s_num > 0)
	{
		for (uint i = 0; i < s_num; i++)
		{
			if (s_name == s[i].getName())
			{
				if (i < s_num - 1)
				{
					for (uint j = i; j < s_num - 1; j++)
					{
						s[j].modi(s[j + 1].getName(), s[j + 1].getAge(), s[j + 1].getLevel(), s[j + 1].getHP(), s[j + 1].getATK());
						del_flag = 1;
					}
				}
				else
				{
					del_flag = 1;
				}
			}
		}
		if (del_flag == 1)
		{
			s[s_num - 1].modi("0", 0, 0, 0, 0); //写入零抹除数据
			s_num--;
		}
		else
		{
			cout << "查无此人，移出失败" << endl;
		}
	}
	else
	{
		cout << "人数不足，删除失败！" << endl;
	}
}
void guild::delM()
{
	string m_name; //用于获取待移出公会的魔法师姓名
	int del_flag = 0; //删除标志位，如果删除成功为1，否则为0
	if (m_num > 0)
	{
		pro_title();
		displayM();
		cout << "请输入需要离开公会的魔法师的姓名" << endl;
		cin >> m_name;
		for (uint i = 0; i < m_num; i++)
		{
			if (m_name == m[i].getName())
			{
				if (i < m_num - 1)
				{
					for (uint j = i; j < s_num - 1; j++)
					{
						m[j].modi(m[j + 1].getName(), m[j + 1].getAge(), m[j + 1].getLevel(), m[j + 1].getHP(), m[j + 1].getMGA());
						del_flag = 1;
					}
				}
				else
				{
					del_flag = 1;
				}
			}
		}
		if (del_flag == 1)
		{
			m[s_num - 1].modi("0", 0, 0, 0, 0); //写入零抹除数据
			m_num--;
		}
		else
		{
			cout << "查无此人，移出失败" << endl;
		}
	}
	else
	{
		cout << "人数不足，删除失败！" << endl;
	}
}
void guild::delM(string m_name)
{
	int del_flag = 0; //删除标志位，如果删除成功为1，否则为0
	if (m_num > 0)
	{
		for (uint i = 0; i < m_num; i++)
		{
			if (m_name == m[i].getName())
			{
				if (i < m_num - 1)
				{
					for (uint j = i; j < s_num - 1; j++)
					{
						m[j].modi(m[j + 1].getName(), m[j + 1].getAge(), m[j + 1].getLevel(), m[j + 1].getHP(), m[j + 1].getMGA());
						del_flag = 1;
					}
				}
				else
				{
					del_flag = 1;
				}
			}
		}
		if (del_flag == 1)
		{
			m[s_num - 1].modi("0", 0, 0, 0, 0); //写入零抹除数据
			m_num--;
		}
		else
		{
			cout << "查无此人，移出失败" << endl;
		}
	}
	else
	{
		cout << "人数不足，删除失败！" << endl;
	}
}
void guild::promotion()
{
	int search_flag = 0;
	string temp;
	cout << "请输入想要升职的队员姓名" << endl;
	cin >> temp;
	for (uint i = 0; i < s_num; i++)
	{
		if (temp == s[i].getName())
		{
			master ma_temp(s[i]);
			ma = ma_temp;
			delS(temp);
			search_flag = 1;
			break;
		}
	}
	for (uint i = 0; i < m_num; i++)
	{
		if (temp == m[i].getName())
		{
			master ma_temp(m[i]);
			ma = ma_temp;
			delM(temp);
			search_flag = 1;
			break;
		}
	}
	if (search_flag)cout << "恭喜 " << temp << " 荣升会长\n老会长光荣退休！" << endl;
	else cout << "无法找到待提拔人员" << endl;
}
void guild::searchS(string t_name)
{
	int search_flag = 0;
	for (uint i = 0; i < s_num; i++)
	{
		if (s[i].getName() == t_name)
		{
			cout << "已找到 " << t_name << " 的信息" << endl;
			pro_title();
			s[i].printAtt("row");
			search_flag = 1;
			break;
		}
	}
	if (search_flag == 0)
	{
		cout << "查无此人" << endl;
	}
}
void guild::searchM(string t_name)
{
	int search_flag = 0;
	for (uint i = 0; i < m_num; i++)
	{
		if (m[i].getName() == t_name)
		{
			cout << "已找到 " << t_name << " 的信息" << endl;
			pro_title();
			m[i].printAtt("row");
			search_flag = 1;
		}
	}
	if (search_flag == 0)
	{
		cout << "查无此人" << endl;
	}
}
void guild::search(string t_name)
{
	int search_flag = 0;
	for (uint i = 0; i < s_num; i++)
	{
		if (s[i].getName() == t_name)
		{
			cout << "已找到 " << t_name << " 的信息" << endl;
			pro_title();
			s[i].printAtt("row");
			search_flag = 1;
			break;
		}
	}
	for (uint i = 0; i < m_num; i++)
	{
		if (m[i].getName() == t_name)
		{
			cout << "已找到 " << t_name << " 的信息" << endl;
			pro_title();
			m[i].printAtt("row");
			search_flag = 1;
		}
	}
	if (search_flag == 0)
	{
		cout << "查无此人" << endl;
	}
}
void guild::load(string csvFileName)
{
	fstream File;
	File.open(csvFileName, ios::in);
	string Line;
	while (getline(File, Line))
	{
		stringstream ss(Line);
		string str;
		pro temp;
		string career;
		uint i = 0;
		uint max = 7;
		while (getline(ss, str, ',')) //以逗号分隔获取单个字符串
		{
			if (i >= max)break;
			switch (i)
			{
			case 0:temp.p_name = str; break;
			case 1:career = str; break;
			case 2:temp.p_age = stringToNum(str); break;
			case 3:temp.p_level = stringToNum(str); break;
			case 4:temp.p_hp = stringToNum(str); break;
			case 5:
			{
				if (career == "mage")break;
				else temp.p_atk = stringToNum(str); break;
			}
			case 6: temp.p_mga = stringToNum(str); break;
			default:break;
			}
			if (career == "saber") max = 6;
			else max = 7;
			i++;
		}
		if (career == "saber")addS(temp.p_name, temp.p_age, temp.p_level, temp.p_hp, temp.p_atk);
		else if (career == "mage")addM(temp.p_name, temp.p_age, temp.p_level, temp.p_hp, temp.p_mga);
		else addMA(temp.p_name, temp.p_age, temp.p_level, temp.p_hp, temp.p_atk, temp.p_mga);
	}
}
void guild::save(string csvFileName)
{
	fstream File;
	File.open(csvFileName, ios::out);
	File << ma.getName() << ",master," << ma.getAge() << "," << ma.getLevel() << "," << ma.getHP() << "," << ma.getATK() << "," << ma.getMGA() << endl;
	for (uint i = 0; i < s_num; i++)
	{
		File << s[i].getName() << ",saber," << s[i].getAge() << "," << s[i].getLevel() << "," << s[i].getHP() << "," << s[i].getATK() << endl;
	}
	for (uint j = 0; j < m_num; j++)
	{
		File << m[j].getName() << ",mage," << m[j].getAge() << "," << m[j].getLevel() << "," << m[j].getHP() << ",," << m[j].getMGA() << endl;
	}
}
void guild::displayMa()
{
	system("cls");
	pro_title();
	ma.printAtt("row");
}
void guild::displayS()
{
	system("cls");
	pro_title();
	for (uint i = 0; i < s_num; i++)
	{
		s[i].printAtt("row");
	}
}
void guild::displayM()
{
	system("cls");
	pro_title();
	for (uint i = 0; i < m_num; i++)
	{
		m[i].printAtt("row");
	}
}
void guild::display()
{
	system("cls");
	if (ma.getName() == "0")
	{
		cout << "会长位置虚位以待！" << endl;
	}
	else { cout << "会长为：" << ma.getName() << endl; }
	cout << "公会中有" << s_num << "名剑士" << endl;
	cout << "公会中有" << m_num << "名魔法师" << endl;
	pro_title();
	if (ma.getName() != "0")
	{
		ma.printAtt("row");
	}
	for (uint i = 0; i < s_num; i++)
	{
		s[i].printAtt("row");
	}
	for (uint i = 0; i < m_num; i++)
	{
		m[i].printAtt("row");
	}
}
