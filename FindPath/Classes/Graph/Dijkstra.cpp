#include "Dijkstra.h"
#include <queue>

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}

void Dijkstra::Execute(const Graph& Graph, const string& VetexId)
{
	m_Ret.PathTree.clear();

	const auto & Vertexes = Graph.GetVertes();
	Vertex *pGvStart = Vertexes.find(VetexId)->second;
	vector<Vertex*> Q;

	// ��ʼ��
	for (auto &it : Vertexes)
	{
		it.second->m_Cost = 0x0FFFFFFF;
		Q.push_back(it.second);
	}
	m_Ret.PathTree[pGvStart] = 0;  //  ��ʼ�����ǰ������Ϊ��
	pGvStart->m_Cost = 0;

	for (; Q.size() > 0;)
	{
		// ѡ����С·�����ƵĶ���
		auto v = ExtractMin(Q);

		// �����еĳ��߽��С��ɳڡ�
		const auto &EO = v->GetEdgesOut();
		for (auto &it : EO)
		{
			Edge *pEdge = it.second;
			Relax(v, pEdge->GetEndVertex(), pEdge->GetWeight());
		}
	}
}

Vertex* Dijkstra::ExtractMin(vector<Vertex*> &Q)
{
	Vertex* Ret = 0;

	Ret = Q[0];
	int pos = 0;
	for (int i = 1, size = Q.size(); i < size; ++i)
	{
		if (Ret->m_Cost > Q[i]->m_Cost)
		{
			Ret = Q[i];
			pos = i;
		}
	}

	Q.erase(Q.begin() + pos);

	return Ret;
}

void Dijkstra::Relax(Vertex* v1, Vertex* v2, int Weight)
{
	int n = v1->m_Cost + Weight;
	if (n < v2->m_Cost)
	{
		v2->m_Cost = n;
		m_Ret.PathTree[v2] = v1;
	}
}