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

	// 第一轮选手编号
	vector<int> v1;
	// 第二轮选手编号
	vector<int> v2;
	// 前三名选手编号
	vector<int> victory;
	// 编号对应的选手
	map<int, Speaker> speaker;
	// 比赛轮数
	int index;
	bool isFileEmpty;
	map<int, vector<string>> record;
};