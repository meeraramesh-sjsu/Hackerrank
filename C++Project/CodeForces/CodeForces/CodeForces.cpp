// CodeForces.cpp : Defines the entry point for the console application.

/*Problem: http://codeforces.com/problemset/problem/682/B

@author:Meera
email:meekar67@gmail.com
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class AlyonaAndMex
{
private:
	int *aux;
	void sort(int a[], int aux[], int lo, int hi);
	void sort();
	void merge(int a[], int aux[], int lo, int mid, int hi);
public:
	int maxMex();
	int n;
	int *a;
};

void AlyonaAndMex::sort(int a[], int aux[], int lo, int hi)
{
	if (hi <= lo) return;
	int mid = (lo + hi) / 2;
	sort(a, aux, lo, mid);
	sort(a, aux, mid + 1, hi);
	merge(a, aux, lo, mid, hi);
}
void AlyonaAndMex::sort()
{
	aux = new int[n];
	sort(a, aux, 0, n - 1);
}
void AlyonaAndMex::merge(int a[], int aux[], int lo, int mid, int hi)
{
	for (int k = lo; k <= hi; k++)
		aux[k] = a[k];
	int i = lo; int j = mid + 1;
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid) a[k] = aux[j++];
		else if (j > hi) a[k] = aux[i++];
		else if (aux[i] > aux[j]) a[k] = aux[j++];
		else a[k] = aux[i++];
	}
}
int AlyonaAndMex::maxMex()
{
	sort();
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= cur)
			cur++;
	}
	return cur;

}
int main()
{
	AlyonaAndMex alyon;
	int n;
	cin >> n;
	alyon.a= new int[n];
	alyon.n = n;
	for (int i = 0; i < n; i++)
	{
		cin >> alyon.a[i];
	}
	int result = alyon.maxMex();
	cout  << result;
    return 0;
}

