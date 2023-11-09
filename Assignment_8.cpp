/*
Assignment No.: 8.Graph:Shortest Path Algorithm
***********************************************************************************
Problem Statement: Represent a graph of city using adjacency matrix /adjacency
list. Nodes should represent the various landmarks and links should represent the
distance between them. Find the shortest path using
Dijkstra's algorithm from single source to all destination.
***********************************************************************************
*/
#include<iostream>
#include<math.h>
#define max 10
using namespace std;
class graph {
int g[max][max];
int n;
public:
graph() {}
void getgraph() {
cout << "\nEnter No. Of Vertices In Graph:";
cin >> n;
cout << "Enter the weight of edge:\n";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
cout << "[" << i << "][" << j << "]=";
cin >> g[i][j];
}
}
}
void displayg() {
cout << "\nAdjancy Matrix Is:\n";
for (int i = 0; i < n; i++) {
cout << "[";
for (int j = 0; j < n; j++) {
cout << g[i][j] << " ";
}
cout << "]\n";
}
}
void dijkstra() {
int cost[max][max];
int v[max] = {0};
int dist[max], sn = 0, nn;
int pred[max];
int mind;
int i, j;
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
if (g[i][j] == 0) {
cost[i][j] = INFINITY;
}
else {

cost[i][j] = g[i][j];
}
}
}
cout << "\nCost Matrix Is:\n";
for (i = 0; i < n; i++) {
cout << "[";
for (int j = 0; j < n; j++) {
cout << cost[i][j] << " ";
}
cout << "]\n";
}
/*
cout << "\nlist of visited nodes is:\n";
for (i = 0; i < n; i++) {
cout << i << "=" << v[i] << "\n";
}*/
for (i = 0; i < n; i++) {
dist[i] = cost[sn][i];
pred[i] = sn;
v[i] = 0;
}
dist[sn] = 0;
v[sn] = 1;
int cnt = 1;
while (cnt <= n - 1) {
mind = INFINITY;
for (i = 0; i < n; i++) {
if (dist[i] <= mind && !v[i]) {
mind = dist[i];
nn = i;
}
}
v[nn] = 1;
for (i = 0; i < n; i++) {
if (!v[i]) {
if (mind + cost[nn][i] < dist[i]) {
dist[i] = mind + cost[nn][i];
pred[i] = nn;
}
}
}
cnt++;
}
for (i = 0; i < n; i++) {
if (i != sn) {
cout << "\n Distance Of Node" << i << "=" << dist[i];
cout << "\n Path=" << i;
j = i;
do {
j = pred[j];
cout << "<-" << j;
} while (j != sn);
}
}
}
};
int main() {
graph g;

g.getgraph();
g.displayg();
g.dijkstra();
return 0;
}
/* Output
Enter No. Of Vertices In Graph:5
Enter the weight of edge:
[0][0]=0
[0][1]=3
[0][2]=1
[0][3]=6
[0][4]=8
[1][0]=5
[1][1]=0
[1][2]=11
[1][3]=4
[1][4]=9
[2][0]=8
[2][1]=4
[2][2]=0
[2][3]=3
[2][4]=9
[3][0]=10
[3][1]=3
[3][2]=7
[3][3]=0
[3][4]=5
[4][0]=8
[4][1]=3
[4][2]=3
[4][3]=8
[4][4]=0
Adjancy Matrix Is:
[0 3 1 6 8 ]
[5 0 11 4 9 ]
[8 4 0 3 9 ]
[10 3 7 0 5 ]
[8 3 3 8 0 ]
Cost Matrix Is:
[2147483647 3 1 6 8 ]
[5 2147483647 11 4 9 ]
[8 4 2147483647 3 9 ]
[10 3 7 2147483647 5 ]
[8 3 3 8 2147483647 ]
Distance Of Node1=3
Path=1<-0
Distance Of Node2=1
Path=2<-0
Distance Of Node3=4
Path=3<-2<-0
Distance Of Node4=8
Path=4<-0
*/