#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include<deque>
#include <functional>
#include <numeric>
#include <fstream>
#include <string>

class SpeechManager
{
public:
	SpeechManager();

	~SpeechManager();

	void showMenu();

	void exitSystem();

	void initSpeech();

	void createSpeaker();

	void speechDraw();

	void startSpeech();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();

	void showRecord();

	void clearRecord();

	// ��һ��ѡ�ֱ��
	vector<int> v1;
	// �ڶ���ѡ�ֱ��
	vector<int> v2;
	// ǰ����ѡ�ֱ��
	vector<int> victory;
	// ��Ŷ�Ӧ��ѡ��
	map<int, Speaker> speaker;
	// ��������
	int index;
	bool isFileEmpty;
	map<int, vector<string>> record;
};