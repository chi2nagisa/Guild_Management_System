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
	int first_flag = 0; //��Ϊһ���˵�ѡ���־
	int second_flag = 1; // ��Ϊ�����˵�ѡ���־
	int third_flag = 1; //�����˵��뿪��־λ��0Ϊ�뿪
	int exit_flag = 1; //�뿪ѡ���־����1Ϊ�뿪
	string t_name; //���ڲ��ҵ�����
	//ϵͳ����
	system_start();
	g.load(FileName);
	loading();
	while (1)
	{
		first_flag = 0;
		second_flag = 1;
		first_list();
		cin >> first_flag; //һ���˵�ѡ��
		switch (first_flag)
		{
		case 1: 
		{
			while (1)
			{
				g.display();
				cout << "����0�˳�" << endl;
				cin >> second_flag;
				if (second_flag == 0)break;
			}
		}break;
		case 2:
		{
			while (1)
			{
				third_flag = 1; //�뿪��־��1
				second_list();
				cin >> second_flag;
				switch (second_flag)
				{
				case 1: //��ʿ���
				{
					while (third_flag)
					{
						g.addS();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 2: //��ʿ�˻�
				{
					while (third_flag)
					{
						g.delS();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 3: //ħ��ʦ���
				{
					while (third_flag)
					{
						g.addM();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 4: //ħ��ʦ�˻�
				{
					while (third_flag)
					{
						g.delM();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 5: //��Ա����
				{
					while (third_flag)
					{
						g.promotion();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 6: //�޸Ļ᳤��Ϣ
				{
					while (third_flag)
					{
						g.modiMA();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 7: //�޸Ľ�ʿ��Ϣ
				{
					while (third_flag)
					{
						g.modiS();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				case 8: //�޸�ħ��ʦ��Ϣ
				{
					while (third_flag)
					{
						g.modiM();
						cout << "����0������һ���˵�" << endl;
						cin >> third_flag;
					}
				}break;
				default:break;
				}
				if (second_flag == 9)break; //������һ���˵��ڵ�
			}

		}break;
		case 3: 
		{
			while (1)
			{
				search();
				cin >> t_name;
				g.search(t_name);
				cout << "\n��Ҫ����ʹ�ò�ѯ��������\n����0�˳���" << endl;
				cin >> second_flag;
				if (second_flag == 0)break; //�жϲ������ϼ��˵��ڵ�
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