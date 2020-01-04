#pragma once
using namespace std;

typedef unsigned int uint;

string pro_list[] = { "����","����","�ȼ�","HP","ATK","MGA" };
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
	cout << "����������" << endl;
	cin >> temp.p_name;
	cout << "����������" << endl;
	cin >> temp.p_age;
	cout << "������ȼ�" << endl;
	cin >> temp.p_level;
	cout << "����������ֵ" << endl;
	cin >> temp.p_hp;
	switch (i)
	{
	case 0: //Saber
	{
		cout << "������������ֵ" << endl;
		cin >> temp.p_atk;
	}break;
	case 1: //Magician
	{
		cout << "������ħ������ֵ" << endl;
		cin >> temp.p_mga;
	}break;
	case 2: //Master
	{
		cout << "������������ֵ" << endl;
		cin >> temp.p_atk;
		cout << "������ħ������ֵ" << endl;
		cin >> temp.p_mga;
	}break;
	default:
		break;
	}
	return temp;
}

uint dis_prolist(int id) //������ʾ����ѡ�����
{
	uint temp_select=65535;
	uint ctrl;
	switch (id)
	{
	case 0:ctrl = 4; 
		break; //0Ϊ��ʿ���б�
	case 1:ctrl = 5; 
		break; //1Ϊħ��ʦ���б�
	case 2:ctrl = 5;
		break; //2Ϊ�᳤���б�
	default:
		break;
	}
	system("cls");
	cout << "��ѡ����Ҫ�޸ĵ���Ŀ" << endl;
	for (uint i = 0; i <= ctrl; i++)
	{
		if (id == 1 && i == 4)continue;
		cout << i + 1 << "�� " << pro_list[i] << endl;
	}
	cin >> temp_select;
	while ((temp_select > ctrl + 1) && (temp_select != 0)) // ��ֹ�������
	{
		cout << "���벻��ȷ�����������룡" << endl;
		cin >> temp_select;
	}
	return temp_select;
}

void pro_title() //������ʾ��Ա��Ϣʱ�ı�ͷ
{
	cout << "����\tְҵ\t����\t�ȼ�\t����ֵ\tATK\tMGA\n";
}

void system_start()
{
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                  *** ###                                                            *" << endl;
	cout << "*                                                 *** ###                                                             *" << endl;
	cout << "*                                                *** ###         ���ڻ���ϵͳ                                         *" << endl;
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
	cout << "*                                              ��ӭʹ�ù����Ա����ϵͳ                                               *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                   DAY DREAM CAFE                                                    *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                           1 ��ʾ������Ϣ                                                            *" << endl;
	cout << "*                                           2 �������                                                                *" << endl;
	cout << "*                                           3 ��Ϣ��ѯ                                                                *" << endl;
	cout << "*                                           4 �˳�ϵͳ��������                                                        *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << endl << "��ѡ������Ҫʹ�õĹ��ܣ���ֻ��1-3�~~��" << endl;
}

void second_list() //�����������˵�
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                      �������                                                       *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                   DAY DREAM CAFE                                                    *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                           1 ��ʿ���                                                                *" << endl;
	cout << "*                                           2 ��ʿ�˻�                                                                *" << endl;
	cout << "*                                           3 ħ��ʦ���                                                              *" << endl;
	cout << "*                                           4 ħ��ʦ�˻�                                                              *" << endl;
	cout << "*                                           5 ��Ա����                                                                *" << endl;
	cout << "*                                           6 �޸Ļ᳤��Ϣ                                                            *" << endl;
	cout << "*                                           7 �޸Ľ�ʿ��Ϣ                                                            *" << endl;
	cout << "*                                           8 �޸�ħ��ʦ��Ϣ                                                          *" << endl;
	cout << "*                                           9 ������һ��                                                              *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << endl << "��ѡ������Ҫʹ�õĹ���" << endl;
}

void search()
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                      �������                                                       *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                   DAY DREAM CAFE                                                    *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                             ��������Ҫ���ҵ���Ա�ġ�������                                          *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
}

void wrong_slection() //����ѡ����ʾҳ��
{
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                              ��ʬ�Ե����������                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	Sleep(1000);
}

void exit() //ϵͳ�˳���ʾҳ��
{
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                             ���Ҫ������������                                                      *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                             ���롰0�����ܻ�ȥŶ~                                                    *" << endl;
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
		cout << "����ģ������������" << endl<<(double)i/10*100<<"% [";
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
		cout << "���棬����ģ���ѳ��أ�" << endl << (double)i / 10 * 100 << "% [";
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
		cout << "���棬����ģ���ѳ��أ�" << endl << (double)i / 10 * 100 << "% [";
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