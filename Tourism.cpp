#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include"Tourism.h"
#include"Graph.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
static CGraph m_Graph;
 void CreateGraph() {
	printf("==== ������������ͼ ====\n");
	char buffer[1024];
#ifdef DEBUG
	FILE* inVex = fopen("C:\\Users\\1\\source\\repos\\DataStructureExp2\\Vex.txt", "r");   // ��Vex�ĵ�
	FILE* inEdge = fopen("C:\\Users\1\\source\\repos\\DataStructureExp2Edge.txt", "r"); // ��Edge�ĵ�
#else

	FILE* inVex = fopen("Vex.txt", "r");   // ��Vex�ĵ�
	FILE* inEdge = fopen("Edge.txt", "r"); // ��Edge�ĵ�
#endif // DEBUG
	if (inVex == NULL || inEdge == NULL) {
		cerr << "�ļ���ʧ��" << endl;
		return ;
	}

	fgets(buffer, 20, inVex); // �����һ�ж�����
	int vexNum = atoi(buffer);
	printf("��Ŀ��������%d\n", vexNum);

	Vex vex;
	m_Graph.Init();
	printf("----- ���� -----\n");
	for (int i = 0; i < vexNum; i++) {
		fgets(buffer, 20, inVex); // ���붥����
		sscanf(buffer, "%d", &vex.num);
		fgets(vex.name, 20, inVex); // ���붥����
		fgets(vex.desc, 1024, inVex); // ���붥������
		m_Graph.InsertVex(vex); // ���붥��
		printf("%d-%s\n", vex.num, vex.name);
	}

	Edge edge;
	printf("----- �� -----\n");
	while (fgets(buffer, sizeof(buffer), inEdge) != NULL) { // �������Ϣ
		sscanf(buffer, "%d %d %d", &edge.vex1, &edge.vex2, &edge.weight); // ��������Ϣ
		m_Graph.InsertEdge(edge); // �����
		printf("<v%d,v%d> %d\n", edge.vex1, edge.vex2, edge.weight);
	}

	fclose(inVex); // �ر��ļ�
	fclose(inEdge);
	return ;
}
 void GetSpotInfo()
{
	cout << "==== ��ѯ������Ϣ ====" << endl;
	Vex vex;
	//���ÿ��������Ϣ�����
	for (int i = 0; i < m_Graph.GetVexnum(); i++)

	{
		vex = m_Graph.GetVex(i);
		cout << vex.num << "-" << vex.name << endl;
	}
	cout << "��������Ҫ��ѯ�ľ����ţ�";
	int nVex;
	cin >> nVex;
	vex = m_Graph.GetVex(nVex);
	cout << vex.name << endl;
	cout << vex.desc << endl;
	cout << "----- �ܱ߾��� -----" << endl;
	Edge edge[20];
	//����붥����صı�
	int edgenum = m_Graph.FindEdge(nVex, edge);
	for (int i = 0; i < edgenum; i++)
	{
		cout << char('A' + nVex) << "��->" << char('A' + edge[i].vex2) << "�� " << edge[i].weight << "m" << endl;
	}
}
 void TravelPath()
{
	cout << "==== ���ξ��㵼�� ====" << endl;
	Vex vex;
	//���ÿ��������Ϣ�����
	for (int i = 0; i < m_Graph.GetVexnum(); i++)
	{
		vex = m_Graph.GetVex(i);
		cout << vex.num << "-" << vex.name << endl;
	}
	cout << "��������ʼ���ţ�";
	int beginNum;
	cin >> beginNum;
	PathList pList = (PathList)malloc(sizeof(Path));
	cout << "����·��Ϊ��" << endl;
	m_Graph.DFSTraverse(beginNum, pList);
}
 void FindShortPath()
{
	cout << "==== �������·�� ====" << endl;
	Vex vex;
	//���ÿ��������Ϣ�����
	for (int i = 0; i < m_Graph.GetVexnum(); i++)
	{
		vex = m_Graph.GetVex(i);
		cout << vex.num << "-" << vex.name << endl;
	}
	int nVexStart, nVexEnd;
	cout << "���������ı�ţ�";
	cin >> nVexStart;
	cout << "�������յ�ı�ţ�";
	cin >> nVexEnd;
	Edge aPath[MAX_VERTEX_NUM];
	int shortPath = m_Graph.FindShortPath(nVexStart, nVexEnd, aPath);
	cout << "���·��Ϊ��";
	int i = 0;
	while (i < m_Graph.GetVexnum())
	{
		if (aPath[i].vex1 != aPath[i].vex2)
			cout << m_Graph.GetVex(aPath[i].vex1).name << "->";
		else
		{
			cout << m_Graph.GetVex(aPath[i - 1].vex2).name << endl;
			break;
		}
		i++;
	}
	cout << "��̾���Ϊ��" << shortPath << endl;
}
 void DesignPath()
{
	cout << "==== �����·���� ====" << endl;
	cout << "��������������֮�������·��" << endl;
	Edge aPath[MAX_VERTEX_NUM];
	int length = m_Graph.FindMinTree(aPath);
	for (int i = 0; (i < m_Graph.GetVexnum()) && (aPath[i].vex1 != aPath[i].vex2); i++)
	{
		cout << m_Graph.GetVex(aPath[i].vex1).name << " - " << m_Graph.GetVex(aPath[i].vex2).name << "   " << aPath[i].weight << "m" << endl;
	}
	cout << "�����·���ܳ���Ϊ��" << length << endl;
}