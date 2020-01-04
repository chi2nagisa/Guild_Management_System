#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>
#include "ui.h"
#include "GMS.h"

using namespace std;

const string FileName = "Guild.csv";

int main()
{
	guild g;
	int first_flag = 0; //作为一级菜单选择标志
	int second_flag = 1; // 作为二级菜单选择标志
	int third_flag = 1; //三级菜单离开标志位，0为离开
	int exit_flag = 1; //离开选择标志，非1为离开
	string t_name; //用于查找的姓名
	//系统启动
	system_start();
	g.load(FileName);
	loading();
	while (1)
	{
		first_flag = 0;
		second_flag = 1;
		first_list();
		cin >> first_flag; //一级菜单选项
		switch (first_flag)
		{
		case 1: 
		{
			while (1)
			{
				g.display();
				cout << "输入0退出" << endl;
				cin >> second_flag;
				if (second_flag == 0)break;
			}
		}break;
		case 2:
		{
			while (1)
			{
				third_flag = 1; //离开标志置1
				second_list();
				cin >> second_flag;
				switch (second_flag)
				{
				case 1: //剑士入会
				{
					while (third_flag)
					{
						g.addS();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 2: //剑士退会
				{
					while (third_flag)
					{
						g.delS();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 3: //魔法师入会
				{
					while (third_flag)
					{
						g.addM();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 4: //魔法师退会
				{
					while (third_flag)
					{
						g.delM();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 5: //成员晋升
				{
					while (third_flag)
					{
						g.promotion();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 6: //修改会长信息
				{
					while (third_flag)
					{
						g.modiMA();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 7: //修改剑士信息
				{
					while (third_flag)
					{
						g.modiS();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				case 8: //修改魔法师信息
				{
					while (third_flag)
					{
						g.modiM();
						cout << "输入0返回上一级菜单" << endl;
						cin >> third_flag;
					}
				}break;
				default:break;
				}
				if (second_flag == 9)break; //返回上一级菜单节点
			}

		}break;
		case 3: 
		{
			while (1)
			{
				search();
				cin >> t_name;
				g.search(t_name);
				cout << "\n需要继续使用查询服务喵？\n输入0退出喵" << endl;
				cin >> second_flag;
				if (second_flag == 0)break; //判断并返回上级菜单节点
			}
			
		}; break;
		case 4:
		{
			exit(); 
			cin >> exit_flag;
		}break;
			
		default:wrong_slection(); break;
		}
		if (exit_flag != 1) break;
	}
	g.save(FileName);
	return 0;
}