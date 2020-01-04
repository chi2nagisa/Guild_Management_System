#pragma once
using namespace std;

typedef unsigned int uint;

string pro_list[] = { "姓名","年龄","等级","HP","ATK","MGA" };
enum property { name = 0, age, level, hp, atk, mga };
property p_list[] = {name, age, level, hp, atk, mga};

struct pro
{
	string p_name;
	uint p_age;
	uint p_level;
	uint p_hp;
	uint p_atk;
	uint p_mga;
};

pro pro_in(uint i)
{
	pro temp;
	cout << "请输入姓名" << endl;
	cin >> temp.p_name;
	cout << "请输入年龄" << endl;
	cin >> temp.p_age;
	cout << "请输入等级" << endl;
	cin >> temp.p_level;
	cout << "请输入生命值" << endl;
	cin >> temp.p_hp;
	switch (i)
	{
	case 0: //Saber
	{
		cout << "请输入物理攻击值" << endl;
		cin >> temp.p_atk;
	}break;
	case 1: //Magician
	{
		cout << "请输入魔法攻击值" << endl;
		cin >> temp.p_mga;
	}break;
	case 2: //Master
	{
		cout << "请输入物理攻击值" << endl;
		cin >> temp.p_atk;
		cout << "请输入魔法攻击值" << endl;
		cin >> temp.p_mga;
	}break;
	default:
		break;
	}
	return temp;
}

uint dis_prolist(int id) //用于显示属性选择界面
{
	uint temp_select=65535;
	uint ctrl;
	switch (id)
	{
	case 0:ctrl = 4; 
		break; //0为剑士的列表
	case 1:ctrl = 5; 
		break; //1为魔法师的列表
	case 2:ctrl = 5;
		break; //2为会长的列表
	default:
		break;
	}
	system("cls");
	cout << "请选择需要修改的项目" << endl;
	for (uint i = 0; i <= ctrl; i++)
	{
		if (id == 1 && i == 4)continue;
		cout << i + 1 << "： " << pro_list[i] << endl;
	}
	cin >> temp_select;
	while ((temp_select > ctrl + 1) && (temp_select != 0)) // 防止输入错误
	{
		cout << "输入不正确，请重新输入！" << endl;
		cin >> temp_select;
	}
	return temp_select;
}

void pro_title() //用于显示成员信息时的表头
{
	cout << "姓名\t职业\t年龄\t等级\t生命值\tATK\tMGA\n";
}

void system_start()
{
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                  *** ###                                                            *" << endl;
	cout << "*                                                 *** ###                                                             *" << endl;
	cout << "*                                                *** ###         正在唤醒系统                                         *" << endl;
	cout << "*                                                 *** ###                                                             *" << endl;
	cout << "*                                                  *** ###                                                            *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	Sleep(2000);
}

void first_list()
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                              欢迎使用公会成员管理系统                                               *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                   DAY DREAM CAFE                                                    *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                           1 显示公会信息                                                            *" << endl;
	cout << "*                                           2 公会管理                                                                *" << endl;
	cout << "*                                           3 信息查询                                                                *" << endl;
	cout << "*                                           4 退出系统（划掉）                                                        *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << endl << "请选择您想要使用的功能：（只能1-3嗷~~）" << endl;
}

void second_list() //公会管理二级菜单
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                      公会管理                                                       *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                   DAY DREAM CAFE                                                    *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                           1 剑士入会                                                                *" << endl;
	cout << "*                                           2 剑士退会                                                                *" << endl;
	cout << "*                                           3 魔法师入会                                                              *" << endl;
	cout << "*                                           4 魔法师退会                                                              *" << endl;
	cout << "*                                           5 成员晋升                                                                *" << endl;
	cout << "*                                           6 修改会长信息                                                            *" << endl;
	cout << "*                                           7 修改剑士信息                                                            *" << endl;
	cout << "*                                           8 修改魔法师信息                                                          *" << endl;
	cout << "*                                           9 返回上一级                                                              *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << endl << "请选择您想要使用的功能" << endl;
}

void search()
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                      公会管理                                                       *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                   DAY DREAM CAFE                                                    *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                             请输入想要查找的人员的【姓名】                                          *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
}

void wrong_slection() //错误选项显示页面
{
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                              僵尸吃掉了你的脑子                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	Sleep(1000);
}

void exit() //系统退出显示页面
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                             真的要走了吗嘤嘤嘤                                                      *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                             输入“0”还能回去哦~                                                    *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	Sleep(1000);
}

void loading()
{
	for (int i = 0; i < 11; i++)
	{
		system("cls");
		cout << "理智模块正在启动：" << endl<<(double)i/10*100<<"% [";
		for (int j = 0; j < i; j++)
		{
			cout << "*****";
		}
		for (int k = 10 - i; k > 0; k--)
		{
			cout << "     ";
		}
		cout << "]" << endl;
		Sleep(100);
	}
	for (int i = 11; i < 51; i++)
	{
		system("cls");
		cout << "警告，理智模块已超载：" << endl << (double)i / 10 * 100 << "% [";
		for (int j = 0; j < i; j++)
		{
			cout << "**********";
		}
		for (int k = 50 - i; k > 0; k--)
		{
			cout << "     ";
		}
		cout << "" << endl;
		Sleep((101-i)/2);
	}
	for (int i = 51; i < 101; i+=5)
	{
		system("cls");
		cout << "警告，理智模块已超载：" << endl << (double)i / 10 * 100 << "% [";
		for (int j = 0; j < i; j++)
		{
			cout << "**********";
		}
		for (int k = 100 - i; k > 0; k--)
		{
			cout << "     ";
		}
		cout << "" << endl;
		Sleep((101 - i) / 4);
	}
	system("cls");
	for (int i = 0; i < 1000; i++)
	{
		cout << "Doom!!!!!!Boom!!!!!Dommm!!!!!" << endl;
	}
}