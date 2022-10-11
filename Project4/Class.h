#pragma once
#include<iostream>
using namespace std;
class GameEntry {
public:
	GameEntry(const string& n = "", int s = 0);//디폴트 매개변수는 함수및 생성자 선언 부분에만 표시해도됨
	string getName() const;
	int getScore() const;
private://클래스 내부에서만 접근가능
	string name;//이름
	int score;//점수
};
class Scores {
public:
	Scores(int maxEnt = 10);//저장할 점수의 최대갯수
	~Scores();
	void add(const GameEntry& e);//레퍼런스를 사용 메모리공간할당x 특정 클래스에 별명을 추가하여 사용
	GameEntry remove(int i);//저장된 점수를 제거
	void ALL();//정보 출력
private:
	int maxEntries;//저장하는 최대 갯수
	int numEntries;//저장된 갯수
	GameEntry* entries; //게임 엔트리 배열
};
GameEntry::GameEntry(const string& n, int s) :name(n), score(s)//멤버이니셜 라이져 사용 멤버변수에 할당이아닌 초기화값을 지정해줌
{ }
string GameEntry::getName()const//GammEntry의 클래스에서 name변수의 값을 반환한다
{
	return name;
}
int GameEntry::getScore()const//GammEntry의 클래스에서 score변수의 값을 반환한다
{
	return score;
}
Scores::Scores(int maxEnt)//Scores 생성자 정의
{
	maxEntries = maxEnt;
	entries = new GameEntry[maxEntries];
	numEntries = 0;
}
Scores::~Scores()//소멸자
{
	delete[] entries;
}
void Scores::add(const GameEntry& e)
{
	int newScore = e.getScore();
	if (numEntries == maxEntries)//numEntries가 현재 저장된 갯수이고 max는 최대 갯수이다 두개가 같으면 꽉찼다는 의미이다
	{
		if (newScore <= entries[maxEntries - 1].getScore())
		{
			cout << "해당 점수는 10번째 점수보다 낮아서 표시되지 않습니다." << endl;
			return;
		}
	}
	else
	{
		numEntries++;
	}
	int i = numEntries - 2;// 삽입 정렬 알고리즘(기준전 값을 기준을 잡는다)
	while (i >= 0 && newScore > entries[i].getScore())
	{
		entries[i + 1] = entries[i];
		i--;
	}
	entries[i + 1] = e;
	cout << "추가 되셧습니다" << endl;
	for (int i = 0; i < numEntries; i++)
	{
		cout << i + 1 << ". 이름:" << entries[i].getName() << " 점수:" << entries[i].getScore() << endl;
	}

}
void Scores::ALL()
{
	if (numEntries == 0)
	{
		cout << "정보가 하나도 없습니다" << endl;
		return;
	}
	for (int i = 0; i < numEntries; i++)
	{
		cout << i + 1 << ". 이름:" << entries[i].getName() << " 점수:" << entries[i].getScore() << endl;
	}
}
GameEntry Scores::remove(int i)
{
	GameEntry e = entries[i - 1];
	if (i < 0 || i >= numEntries)
	{
		std::cout << "해당 범위에는 삭제할 데이터가 없습니다." << endl;
		return e;
	}
	for (int j = i + 1; j < numEntries; j++)
	{
		entries[j - 1] = entries[j];
	}
	numEntries--;
	cout << "삭제되었습니다." << endl;
	return e;
}