#include "speechManager.h"


SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "********** 欢迎参加演讲比赛 **********" << endl;
	cout << "**********  1.开始演讲比赛  **********" << endl;
	cout << "**********  2.查看往届记录  **********" << endl;
	cout << "**********  3.清空比赛记录  **********" << endl;
	cout << "**********  0.退出比赛程序  **********" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->speaker.clear();
	this->index = 1;
	this->record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGIJKLM";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::speechDraw()
{
	cout << "第 << " << this->index << " >> 轮选手正在抽签" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "抽签顺序如下：" << endl;
	if (this->index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "-------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::startSpeech()
{
	this->speechDraw();
	this->speechContest();
	this->showScore();

	this->index++;
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->saveRecord();

	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechContest()
{
	cout << "-------------第" << this->index << "轮比赛正式开始------------" << endl;

	multimap<double, int, greater<double>> groupScore;

	int num = 0;
	vector<int> src;
	if (this->index == 1)
	{
		src = v1;
	}
	else
	{
		src = v2;
	}
	for (vector<int>::iterator it = src.begin(); it != src.end(); it++)
	{
		num++;
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->speaker[*it].score[this->index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "姓名：" << this->speaker[it->second].name
					<< "成绩：" << this->speaker[it->second].score[this->index - 1] << endl;
			}

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				if (count == 3) {
					break;
				}
				count++;

				if (this->index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					victory.push_back((*it).second);
				}
			}

			groupScore.clear();
		}
	}
	cout << "----第" << this->index << "轮比赛结束----" << endl;
}

void SpeechManager::showScore()
{
	cout << "-----第" << this->index << "轮晋级选手信息如下-----" << endl;
	vector<int> v;
	if (this->index == 1)
	{
		v = v2;
	}
	else
	{
		v = victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << "姓名：" << this->speaker[*it].name << "得分："
			<< this->speaker[*it].score[this->index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << "," << speaker[*it].score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已保存" << endl;
	this->isFileEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->isFileEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}

	this->isFileEmpty = false;
	string data;
	int index = 0;
	while (ifs>>data)
	{
		vector<string> v;
		int pos = 1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void SpeechManager::showRecord()
{
	if (this->isFileEmpty)
	{
		cout << "文件为空或者文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->record.size(); i++)
	{
		cout << "第" << i + 1 << "届 " << endl
			<< "冠军编号：" << this->record[i][0] << "得分：" << this->record[i][1] << " "
			<< "亚军编号：" << this->record[i][2] << "得分：" << this->record[i][3] << " "
			<< "季军编号：" << this->record[i][4] << "得分：" << this->record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "确认要清空？" << endl;
	cout << "1 确认" << endl;
	cout << "2 返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}