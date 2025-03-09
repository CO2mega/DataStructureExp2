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
	printf("==== 创建景区景点图 ====\n");
	char buffer[1024];
#ifdef DEBUG
	FILE* inVex = fopen("C:\\Users\\1\\source\\repos\\DataStructureExp2\\Vex.txt", "r");   // 打开Vex文档
	FILE* inEdge = fopen("C:\\Users\1\\source\\repos\\DataStructureExp2Edge.txt", "r"); // 打开Edge文档
#else

	FILE* inVex = fopen("Vex.txt", "r");   // 打开Vex文档
	FILE* inEdge = fopen("Edge.txt", "r"); // 打开Edge文档
#endif // DEBUG
	if (inVex == NULL || inEdge == NULL) {
		cerr << "文件打开失败" << endl;
		return ;
	}

	fgets(buffer, 20, inVex); // 读入第一行顶点数
	int vexNum = atoi(buffer);
	printf("项目顶点数：%d\n", vexNum);

	Vex vex;
	m_Graph.Init();
	printf("----- 顶点 -----\n");
	for (int i = 0; i < vexNum; i++) {
		fgets(buffer, 20, inVex); // 读入顶点编号
		sscanf(buffer, "%d", &vex.num);
		fgets(vex.name, 20, inVex); // 读入顶点名
		fgets(vex.desc, 1024, inVex); // 读入顶点描述
		m_Graph.InsertVex(vex); // 插入顶点
		printf("%d-%s\n", vex.num, vex.name);
	}

	Edge edge;
	printf("----- 边 -----\n");
	while (fgets(buffer, sizeof(buffer), inEdge) != NULL) { // 读入边信息
		sscanf(buffer, "%d %d %d", &edge.vex1, &edge.vex2, &edge.weight); // 解析边信息
		m_Graph.InsertEdge(edge); // 插入边
		printf("<v%d,v%d> %d\n", edge.vex1, edge.vex2, edge.weight);
	}

	fclose(inVex); // 关闭文件
	fclose(inEdge);
	return ;
}
 void GetSpotInfo()
{
	cout << "==== 查询景点信息 ====" << endl;
	Vex vex;
	//获得每个顶点信息并输出
	for (int i = 0; i < m_Graph.GetVexnum(); i++)

	{
		vex = m_Graph.GetVex(i);
		cout << vex.num << "-" << vex.name << endl;
	}
	cout << "请输入想要查询的景点编号：";
	int nVex;
	cin >> nVex;
	vex = m_Graph.GetVex(nVex);
	cout << vex.name << endl;
	cout << vex.desc << endl;
	cout << "----- 周边景区 -----" << endl;
	Edge edge[20];
	//获得与顶点相关的边
	int edgenum = m_Graph.FindEdge(nVex, edge);
	for (int i = 0; i < edgenum; i++)
	{
		cout << char('A' + nVex) << "区->" << char('A' + edge[i].vex2) << "区 " << edge[i].weight << "m" << endl;
	}
}
 void TravelPath()
{
	cout << "==== 旅游景点导航 ====" << endl;
	Vex vex;
	//获得每个顶点信息并输出
	for (int i = 0; i < m_Graph.GetVexnum(); i++)
	{
		vex = m_Graph.GetVex(i);
		cout << vex.num << "-" << vex.name << endl;
	}
	cout << "请输入起始点编号：";
	int beginNum;
	cin >> beginNum;
	PathList pList = (PathList)malloc(sizeof(Path));
	cout << "导游路线为：" << endl;
	m_Graph.DFSTraverse(beginNum, pList);
}
 void FindShortPath()
{
	cout << "==== 搜索最短路径 ====" << endl;
	Vex vex;
	//获得每个顶点信息并输出
	for (int i = 0; i < m_Graph.GetVexnum(); i++)
	{
		vex = m_Graph.GetVex(i);
		cout << vex.num << "-" << vex.name << endl;
	}
	int nVexStart, nVexEnd;
	cout << "请输入起点的编号：";
	cin >> nVexStart;
	cout << "请输入终点的编号：";
	cin >> nVexEnd;
	Edge aPath[MAX_VERTEX_NUM];
	int shortPath = m_Graph.FindShortPath(nVexStart, nVexEnd, aPath);
	cout << "最短路线为：";
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
	cout << "最短距离为：" << shortPath << endl;
}
 void DesignPath()
{
	cout << "==== 铺设电路规则 ====" << endl;
	cout << "在以下两个景点之间铺设电路：" << endl;
	Edge aPath[MAX_VERTEX_NUM];
	int length = m_Graph.FindMinTree(aPath);
	for (int i = 0; (i < m_Graph.GetVexnum()) && (aPath[i].vex1 != aPath[i].vex2); i++)
	{
		cout << m_Graph.GetVex(aPath[i].vex1).name << " - " << m_Graph.GetVex(aPath[i].vex2).name << "   " << aPath[i].weight << "m" << endl;
	}
	cout << "铺设电路的总长度为：" << length << endl;
}