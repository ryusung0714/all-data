#include <iostream>
#include <CoreWindow.h>
#include "Class.h"
using namespace std;
//class GameEntry {
//public:
//	GameEntry(const string& n = "", int s = 0);//����Ʈ �Ű������� �Լ��� ������ ���� �κп��� ǥ���ص���
//	string getName() const;
//	int getScore() const;
//private://Ŭ���� ���ο����� ���ٰ���
//	string name;//�̸�
//	int score;//����
//};
//class Scores {
//public:
//	Scores(int maxEnt = 10);//������ ������ �ִ밹��
//	~Scores();
//	void add(const GameEntry& e);//���۷����� ��� �޸𸮰����Ҵ�x Ư�� Ŭ������ ������ �߰��Ͽ� ���
//	GameEntry remove(int i);//����� ������ ����
//	void ALL();//���� ���
//private:
//	int maxEntries;//�����ϴ� �ִ� ����
//	int numEntries;//����� ����
//	GameEntry* entries; //���� ��Ʈ�� �迭
//};
//GameEntry::GameEntry(const string& n, int s):name(n),score(s)//����̴ϼ� ������ ��� ��������� �Ҵ��̾ƴ� �ʱ�ȭ���� ��������
//{ }
//string GameEntry::getName()const//GammEntry�� Ŭ�������� name������ ���� ��ȯ�Ѵ�
//{
//	return name;
//}
//int GameEntry::getScore()const//GammEntry�� Ŭ�������� score������ ���� ��ȯ�Ѵ�
//{
//	return score;
//}
//Scores::Scores(int maxEnt)//Scores ������ ����
//{
//	maxEntries = maxEnt;
//	entries = new GameEntry[maxEntries];
//	numEntries = 0;
//}
//Scores::~Scores()//�Ҹ���
//{
//	delete[] entries;
//}
//void Scores::add(const GameEntry& e)
//{
//	int newScore = e.getScore();
//	if (numEntries == maxEntries)//numEntries�� ���� ����� �����̰� max�� �ִ� �����̴� �ΰ��� ������ ��á�ٴ� �ǹ��̴�
//	{
//		if (newScore <= entries[maxEntries - 1].getScore())
//		{
//			cout << "�ش� ������ 10��° �������� ���Ƽ� ǥ�õ��� �ʽ��ϴ�." << endl;
//			return;
//		}
//	}
//	else
//	{
//		numEntries++;
//	}
//	int i = numEntries - 2;// ���� ���� �˰���(������ ���� ������ ��´�)
//	while (i >= 0 && newScore > entries[i].getScore())
//	{
//		entries[i + 1] = entries[i];
//		i--;
//	}
//	entries[i + 1] = e;
//	cout << "�߰� �Ǽ˽��ϴ�" << endl;
//	for (int i = 0; i < numEntries; i++)
//	{
//		cout << i + 1 << ". �̸�:" << entries[i].getName() << " ����:" << entries[i].getScore() << endl;
//	}
//
//}
//void Scores::ALL()
//{
//	if (numEntries == 0)
//	{
//		cout << "������ �ϳ��� �����ϴ�" << endl;
//		return;
//	}
//	for (int i = 0; i < numEntries; i++)
//	{
//		cout << i + 1 << ". �̸�:" << entries[i].getName() << " ����:" << entries[i].getScore() << endl;
//	}
//}
//GameEntry Scores::remove(int i)
//{
//	GameEntry e = entries[i - 1];
//	if (i < 0 || i >= numEntries)
//	{
//		std::cout << "�ش� �������� ������ �����Ͱ� �����ϴ�." << endl;
//		return e;
//	}
//	for (int j = i + 1; j < numEntries; j++)
//	{
//		entries[j - 1] = entries[j];
//	}
//	numEntries--;
//	cout << "�����Ǿ����ϴ�." << endl;
//	return e;
//}
int main()
{
	Scores all;
	string name;
	int score,num,ranker;
	GameEntry* human;
	GameEntry Haman;
	do {
		cout << "1.�߰�" << endl;
		cout << "2.����" << endl;
		cout << "3.��ü ���" << endl;
		cout << "4.����" << endl;
		cout << "������ ���͵帱���?(�ش� ��ȣ�� �Է����ּ���)";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "�̸��� ������ �Է��ϼ���:";
			cin >> name >> score;
			human = new GameEntry{ name,score };
			all.add(*human);
			delete human;
			break;
		case 2:
			all.ALL();
			cout << "���° ������ �����Ͻðڽ��ϱ�?";
			cin >> ranker;
			Haman=all.remove(ranker);
			cout << Haman.getName() << "�����Ǿ����ϴ�" << endl;
			break;
		case 3:
			all.ALL();
			break;
		case 4:
			break;

		}
		system("pause");
		system("cls");
	} while (num!=4);

}