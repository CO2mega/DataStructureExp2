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
		cout << "�����������������" << endl;
		break;
	}
	return true;
}
int main() {
	bool bRunning = true;
	while (bRunning)
	{
		cout << "====��������Ϣ����ϵͳ====" << endl;
		cout<<"1.������������ͼ"<<endl;
		cout<<"2.��ѯ������Ϣ"<<endl;
		cout<<"3.���ξ��㵼��"<<endl;
		cout<<"4,�������·��"<<endl;
		cout<<"5.�����·�滮"<<endl;
		cout<<"0.�˳�"<<endl;
		cout<<"������ѡ��";
		int nSelect = 0;
		cin >> nSelect;
		bRunning =  Switch(nSelect);
	}
}