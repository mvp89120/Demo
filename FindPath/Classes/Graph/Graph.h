#pragma once
#include <vector>
// map�ǰ���operator<�Ƚ��ж�Ԫ���Ƿ���ͬ���Լ��Ƚ�Ԫ�صĴ�С��Ȼ��ѡ����ʵ�λ�ò��뵽���С�
// unordered_map�Ǽ���Ԫ�ص�Hashֵ������Hashֵ�ж�Ԫ���Ƿ���ͬ��
#include <unordered_map>
using namespace std;

class Edge;
class Vertex;
class Graph;
class GraphPathfinding;

/*
    ͼ����
*/

class Vertex
{
	friend class Graph;
	friend class GraphPathfinding;
	friend class Dijkstra;

public:
	Vertex(const string& Name)
	{
		m_strId = Name;
		m_Cost = 0;
		m_pGraph = 0;
	}

	~Vertex(){}

public:
	// ��������
	unordered_map<string, void*> UserData;

public:
	const unordered_map<string, Edge*> & GetEdgesOut() const
	{
		return m_EdgesOut;
	}

	const unordered_map<string, Edge*> & GetEdgesIn() const
	{
		return m_EdgesIn;
	}

	const string & GetId() const
	{
		return m_strId;
	}

	const string & GetText() const
	{
		return m_Text;
	}

	void SetText(const string & Text)
	{
		m_Text = Text;
	}

	Graph * GetGraph()
	{
		return m_pGraph;
	}

public:
	// AStarѰ·�㷨��Ҫ������
	struct Pathfinding
	{
		// �����ǰ������
		Vertex *pParent;
		// ·�����۹���  
		int Cost;
		// ��ʶ��
		int Flag;
		// ����ʽ�����ļ��������ֵ
		int Heuristic;

		Pathfinding()
		{
			pParent = 0;
			Cost = 0;
			Flag = 0;
			Heuristic = 0;
		}
	}PathfindingData;

protected:
	// ���ȼ���
	unordered_map<string, Edge*> m_EdgesOut;

	// ��ȼ���
	unordered_map<string, Edge*> m_EdgesIn;

	// �ڵ��ʾ���ַ���
	string m_Text;

	// �ڵ��ID
	string m_strId;

	// ����Ѱ·�㷨��·�����۹���
	int m_Cost;

	// ������ͼ
	Graph *m_pGraph;
};

/*
	ͼ����ı�
	�����
*/
class Edge
{
	friend class Graph;

public:
	Edge()
	{
		m_Weight = 0;
		m_pStartVertex = m_pEndVertex = 0;
	}

	Edge(Vertex* pStartVertex, Vertex* pEndVertex, int Weight = 0)
	{
		m_Weight = Weight;

		m_pStartVertex = pStartVertex;
		m_pEndVertex = pEndVertex;
	}

public:
	int GetWeight() const 
	{ 
		return m_Weight; 
	}

	void SetWeight(int var)
	{
		m_Weight = var;
	}

	Vertex* GetStartVertex() const 
	{ 
		return m_pStartVertex; 
	}

	Vertex* GetEndVertex() const 
	{ 
		return m_pEndVertex; 
	}

protected:
	// �ߵ�Ȩֵ
	int m_Weight;

	// ���Ķ���
	Vertex *m_pStartVertex;

	// �յ�Ķ���
	Vertex *m_pEndVertex;
};

/*
    ͼ.
    ͼ�Ḻ���ͷŶ���ͱߵ��ڴ�
*/
class Graph
{
public:
	Graph();
	~Graph();

public:
	// ����һ������
	void AddVertex(Vertex* pV);

	// ɾ��һ������
	void DeleleVertex(const string& VertexName);

	// ����һ���ߡ����ر߶���
	Edge* AddEdge(const string& Vertex1Name, const string& Vertex2Name, int Weight = 0);

	// ɾ��һ����
	void DeleteEdge(const string& StartVertexName, const string& EndVertexName);

public:
	const unordered_map<string, Vertex *> & GetVertes() const
	{
		return m_Vertexes;
	}

protected:
	// ����ļ���
	unordered_map<string, Vertex*> m_Vertexes;

	// �ߵļ��ϡ�Key�ĸ�ʽ������1name->����2name"
	unordered_map<string, Edge*> m_Edges;

protected:
	#define GetEdgeKey( pV1 , pV2 )(  pV1->m_strId + "->" + pV2->m_strId );
};