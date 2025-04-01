#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Graph.h"
#include"Tourism.h"
bool Switch(int co) {
	switch (co)
	{
	case 1:
		CreateGraph();
		break;
	case 2:
		GetSpotInfo();
		break;
	case 3:
		TravelPath();
		break;
	case 4:
		FindShortPath();
		break;
	case 5:
		DesignPath();
		break;
	case 0:
		exit(0);
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
	return true;
}
int main() {
	bool bRunning = true;
	while (bRunning)
	{
		cout << "====景区信信息管理系统====" << endl;
		cout<<"1.创建景区景点图"<<endl;
		cout<<"2.查询景点信息"<<endl;
		cout<<"3.旅游景点导航"<<endl;
		cout<<"4,搜索最短路径"<<endl;
		cout<<"5.铺设电路规划"<<endl;
		cout<<"0.退出"<<endl;
		cout<<"请输入选择：";
		int nSelect = 0;
		cin >> nSelect;
		bRunning =  Switch(nSelect);
	}
}