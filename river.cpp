#include "river.h"
#include <algorithm> // you are allowed to use std::sort from this library
#include <iostream>
#include <climits> //for INT_MAX
using namespace std;

/* Members:
	Leanorine Lorenzana-Garcia U70358223
	Zachary Tan U71790150

   Sources:
	Dijkstra's Algorithm - https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
*/

void dfs(int start, river const&r, bool visited[], int t, vector<int> &allStarts) {
	//depth first search backwards and if it reaches an end push to vector
	bool isStart = true; 
	visited[start] = true;
	for(int i = t; i >= 0; i--) {
		if(r[i][start] == 1 && (!visited[i])) { //if not starting point
			dfs(i, r, visited, t, allStarts);
			isStart = false;
		}
	}
	if(isStart) //if starting point push back
		allStarts.push_back(start);
}	

// part (a)
std::vector<int> start(river const&r, int t) {
	bool visited[r[0].size()] = {false}; 
	vector<int> allStarts; 
	dfs(t, r, visited, t, allStarts); 
	sort(allStarts.begin(), allStarts.end()); //sort in ascending order
	return {allStarts};
}

int minDis(int distance[], bool sptSet[], int vertices) {
	//get the index of the minimum distance
	int min = INT_MAX;
	int index;
	for(int i = 0; i < vertices; i++) {
		if(!sptSet[i] && distance[i] <= min) {
			min = distance[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(river const&r, int start, int vertices, int distance[]) {
	//get shortest distance
	//distance of each edge in this case is 1
	
	bool sptSet[vertices] = {false};
	int myMin;
	
	for(int i = 0; i < vertices; i++)
		distance[i] = INT_MAX;
	distance[start] = 0;
	
	for(int i = 0; i < vertices - 1; i++) {
		myMin = minDis(distance, sptSet, vertices);
		sptSet[myMin] = true;
		
		for(int j = 0; j < vertices; j++) {
			if(!sptSet[j] && r[myMin][j] == 1 && distance[myMin] != INT_MAX && distance[myMin] + r[myMin][j] < distance[j])
				distance[j] = distance[myMin] + r[myMin][j];
		}
	}
}

// part (b)
std::vector<int> meet(river const&r, int ryan, int mira) {
	int vertices = r[0].size(), shortest = INT_MAX;
	int r_distance[vertices];
	int m_distance[vertices];
	vector<int> epm;
	
	dijkstra(r, ryan, vertices, r_distance);
	dijkstra(r, mira, vertices, m_distance);
	
	for(int i = 0; i < vertices; i++) {
		if((r_distance[i] == 0 && m_distance[i] != INT_MAX) || (m_distance[i] == 0 && r_distance[i] != INT_MAX)) {
			//checks if either ryan or mira could wait
			//if so, return vertex of person waiting
			epm.push_back(i);
			break;
		} else if(r_distance[i] != INT_MAX && m_distance[i] != INT_MAX) {
			//if vertex is reachable by both ryan and mira
			if(r_distance[i] + m_distance[i] < shortest) { //if distance is shortest for both ryan and mira
				shortest = r_distance[i] + m_distance[i]; //change shortest
				if(epm.size() == 1) {
					epm[0] = i;
				} else {
					epm.push_back(i);
				}
			}
		}
	}	
	return {epm};
}