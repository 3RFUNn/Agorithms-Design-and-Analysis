#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

#define INF 99999

void printSolution(vector<vector<int>> dist, int V);

vector<vector<int>> floydWarshall(vector<vector<int>> graph,int V)
{
	vector<vector<int>> dist(V, vector<int>(V));
	int i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] >= INF)
				dist[i][j] = -1;
		}
	}

	return dist;
}

void printSolution(vector<vector<int>> dist, vector<int> red, vector<int> hospital,int V)
{
	int min = INF;
    for (int i = 0; i < V; i++)
    {
		if (red[i] == 0)
			continue;
		else if(red[i] == 1)
			for (int j = 0; j < V; j++)
			{
				if ((min > dist[i][j])&&(hospital[j]==1))
					min = dist[i][j];
			}
		cout << i+1 << " " << min;
		cout << endl;
    }
}
int main() {
	int number_of_city, number_of_roads;

	cin >> number_of_city;

	cin >> number_of_roads;
	vector<int> red_city(number_of_city), hospital_city(number_of_city);
	vector<vector<int>> graph(number_of_city,vector<int>(number_of_city));
	vector<vector<int>> dist(number_of_city, vector<int>(number_of_city));

	for (int i = 0; i < number_of_city; i++) {
		for (int j = 0; j < number_of_city; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	for (int i = 0; i < number_of_city; i++) {
		int first, second;

		cin >> first;
		red_city[i] = first;

		cin >> second;
		hospital_city[i] = second;
	}
	for (int i = 0; i < number_of_roads; i++) {
		int first, second, lenght;

		cin >> first;

		cin >> second;

		cin >> lenght;
		if ((first <= number_of_city) && (second <= number_of_city)&&(first >=1)&&(second >=1)) {
			graph[first-1][second-1] = lenght;
			graph[second-1][first-1] = lenght;
		}

	}


	dist = floydWarshall(graph,number_of_city);

	printSolution(dist,red_city,hospital_city, number_of_city);
	return 0;
}
