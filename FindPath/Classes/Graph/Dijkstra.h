#pragma once
#include "GraphPathfinding.h"

/*
 *	�Ͻ�˹������Դ���·���㷨
*/
class Dijkstra : public GraphPathfinding
{
public:
	Dijkstra();
	~Dijkstra();

public:
	void Execute(const Graph& Graph, const string& VetexId) override;

private:
	// �����С·����ֵ�Ķ���
	Vertex* ExtractMin(vector< Vertex* >& Q);

	// �ɳ�
	void Relax(Vertex* v1, Vertex* v2, int Weight);

public:
	Result& GetResult() { return m_Ret; }

private:
	Result m_Ret;
};