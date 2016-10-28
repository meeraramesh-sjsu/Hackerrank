/*
@Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
@author: Meera Ramesh
@email: meekar67@gmail.com
*/
struct Node {
	int element;
	int i;
	int j;
	Node()
	{
		element = 0;
		i = 0;
		j = 0;
	}
};
class MinHeap
{
public:
	MinHeap(int size)
	{
		heap = new Node[size+1];
		N = 0;
	}
	void insert(Node element)
	{
		heap[++N] = element;
		swim(N);
	}
	void replaceMin(Node element)
	{
		heap[1] = element;
		sink(1);
	}
	Node *heap;
	Node minEle()
	{
		return heap[1];
	}
private:
	int N;
	void swim(int k)
	{
		while (k > 1)
		{
			if ((heap[k / 2].element > heap[k].element))
			{
				exch(k, k / 2);
				k = k / 2;
			}
			else break;
		}
	}
	void exch(int a, int b)
	{
		Node temp;
		temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;
	}
	void sink(int k)
	{
		while (2*k <= N)
		{
		    int j = 2*k;
			if (j  < N && heap[j + 1].element < heap[j].element)
				j = j + 1;
			if (heap[j].element < heap[k].element)
			{
				exch(j, k);
				k=j;
			}
			else break;
		}
	}
};
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		MinHeap min(n);
		Node  temp;
		vector<int> result;
		for (int i = 0; i < n; i++)
		{
			temp.element = matrix[i][0];
			temp.i = i;
			temp.j = 1;
		
			min.insert(temp);
			}
		for (int count = 0; count < n*n; count++)
		{
			Node minEle = min.minEle();
			result.push_back(minEle.element);
			if (minEle.j < n)
			{
				minEle.element = matrix[minEle.i][minEle.j];
				minEle.j++;
			}
			else
			{		
				minEle.element = INT_MAX;		
			}
			min.replaceMin(minEle);
		}
	
		return result[k - 1];
	}
};