#pragma once
#define MAX_VERTEX_NUM 20
struct Vex
{
	int num;
	char name[20];
	char desc[1024];
};
struct Edge
{
	int vex1;
	int vex2;
	int weight;	
};
typedef struct Path
{
	int vexs[20];
	Path* next = nullptr;
} *PathList;
class CGraph
{
private:
	int m_aAdjMatrix[20][20];
	Vex m_aVexs[20];
	int m_nVexNum;
public:
	void  Init();
	int InsertVex(Vex sVex);
	int InsertEdge(Edge sEdge);
	Vex GetVex(int nVex);
	int FindEdge(int nVex, Edge aEdge[]);
	int GetVexnum();	
	void DFS(int nVex, bool bVisted[], int& nIndex, PathList& pList);
	void DFSTraverse(int nVex, PathList& pList);
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);
	int FindMinTree(Edge aPath[]);
};