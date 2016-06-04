// timp5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Tree{
	int k;
	int *p1;
	int *p2;
public:
	Tree() : p1(0), p2(0), k(0){}
	~Tree(){
		if (p1) delete[] p1;
		if (p2) delete[] p2;
	}
	void add(int x)
	{
		int z = 0;
		if (p1 == 0){
			if (p2 == 0)
			{ 
			  k++; 
			  p1 = new int[1]; 
			  p1[0] = x; 
			  goto exit1; 
			}
			for (int i = 0; i < k - 1; i++){
				if (x < p2[i]) 
				{ 
					z = i;  
					goto hh; 
				}
				if ((2 * i + 1) <= k - 1) 
				{ 
					if (x < p2[2 * i + 1]) { z = (2 * i + 1); 
					goto hh; } 
				}
				if ((2 * i + 2) <= k - 1) 
				{ 
					if (x < p2[2 * i + 2]) 
					{ 
					   z = (2 * i + 2); 
					   goto hh; 
					} 
				}
			}
			if (!z){
				k++;
				p1 = new int[k];
				for (int i = 0; i < k - 1; i++) 
					p1[i] = p2[i];
				p1[k - 1] = x; goto exit1;
			}
		hh: k++;
			p1 = new int[k];
			for (int i = 0; i < z; i++) 
				p1[i] = p2[i];
			p1[z] = x;
			for (int i = (z + 1); i < k; i++) 
				p1[i] = p2[i - 1];
		exit1: if (p2 != 0) 
		{ delete[] p2; p2 = 0; return; }
			return;
		}
		else{
			if (p2 == 0)
			{
				for (int i = 0; i < k; i++)
				{
					if (x < p1[i]) 
					{ 
						k++; p2 = new int[k]; 
						p2[0] = x; 
						for (int i = 1; i < k; i++) 
							p2[i] = p1[i - 1]; 
						goto exit2; 
					}
					if ((2 * i + 1) <= k - 1) 
					{ if (x < p1[2 * i + 1]) 
					 { 
						z = (2 * i + 1); goto dd; 
					 } 
					}
					if ((2 * i + 2) <= k - 1) 
					{ 
						if (x < p1[2 * i + 2]) 
						 { 
							z = (2 * i + 2); 
						    goto dd; 
						 } 
					}
				}
				if (!z)
				{
					k++;
					p2 = new int[k];
					for (int i = 0; i < k - 1; i++) 
						p2[i] = p1[i];
					p2[k - 1] = x;
					goto exit2;
				}
			dd: k++;
				p2 = new int[k];
				for (int i = 0; i < z; i++) 
					p2[i] = p1[i];
				p2[z] = x;
				for (int i = (z + 1); i < k; i++) 
					p2[i] = p1[i - 1];
			exit2: if (p1 != 0) 
			{ 
					   delete[] p1; 
					   p1 = 0; 
					   return; 
			}
			}
			return;
		}
	}
	void get(){
		if (p1) cout << p1[0] << endl;
		if (p2) cout << p2[0] << endl;
	}
	void del(){
		k--;
		if (p1){
			p2 = new int[k];
			for (int i = 0; i < k; i++) 
				p2[i] = p1[i + 1];
			delete[] p1; 
			p1 = 0; 
			return;
		}
		if (p2){
			p1 = new int[k];
			for (int i = 0; i < k; i++) 
				p1[i] = p2[i + 1];
			delete[] p2; 
			p2 = 0;
		}
	}
};

void main(){
	Tree T;  int n; string s;
	cin >> n;
	while (n){
		getline(cin, s);
		if (!s.find("add")){
			n--;
			s.erase(0, 4);
			int x = atoi(s.c_str());
			T.add(x);
		}
		if (s == "del"){
			n--;
			T.del();
		}
		if (s == "get"){
			n--;
			T.get();
		}
	}
	system("pause");
}
