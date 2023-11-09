/*
Assignment No.: 7.Graph: Minimum Spanning Tree
***********************************************************************************
Problem Statement: Represent a graph of your college campus using adjacency list
/adjacency matrix. Nodes should
represent the various departments/institutes and links should represent the
distance between them.
Find minimum spanning tree
a) Using Kruskal’s algorithm.
b) Using Prim’s algorithm.
***********************************************************************************
*/
//a) Using Kruskal’s algorithm:

#include<iostream>
using namespace std;
class MST {
int a[20][20], n, k;
struct gr {
int v1;
int v2;
int wt;
}g[20];
public:
void accept();
void extract_edges();
void kruskal();
};

void MST::kruskal(){
gr temp,tree[20];
int i, j, father[20] = {0}, sum = 0, n1, n2, r1, r2;
for (i = 0; i < k; i++) {
for (j = 0; j < k - 1; j++) {
if (g[j].wt > g[j + 1].wt) {
temp = g[j + 1];
g[j + 1] = g[j];
g[j] = temp;
}
}
}
cout << "\tSource\tSink\tWeight\n";
for (i = 0; i < k; i++)
cout << "\t" << g[i].v1 << "\t" << g[i].v2 << "\t" << g[i].wt << "\n";
for (i = 0, j = 0; i < k && j < n - 1; i++) {
n1 = g[i].v1;
n2 = g[i].v2;
while (n1 > 0) {
r1 = n1;
n1 = father[n1];
}
while (n2 > 0) {
r2 = n2;
n2 = father[n2];
}
if (r1 != r2) {
tree[j].v1 = g[i].v1;
tree[j].v2 = g[i].v2;
tree[j++].wt = g[i].wt;
sum += g[i].wt;
father[r2] = r1;
}
}
cout << "\nEdges in MST:\n\tSource\tSink\tWeight\n";
for (i = 0; i < j; i++)
cout << "\t" << tree[i].v1 << "\t" << tree[i].v2 << "\t" << tree[i].wt <<
"\n";
cout << "Total cost of MST: " << sum << "\n";
}

void MST::accept() {
int i, j;
cout << "\nEnter the no. of vertices: ";
cin >> n;
cout << "Enter adjacency matrix:\n";
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
cin >> a[i][j];
}

void MST::extract_edges() {
int i, j;
for (i = 1, k = 0; i <= n; i++)
for (j = i + 1; j <= n; j++)
if (a[i][j] != 0) {
g[k].v1 = i;
g[k].v2 = j;
g[k++].wt = a[i][j];
}
cout << "\tSource\tSink\tWeight\n";
for (i = 0; i < k; i++)
cout << "\t" << g[i].v1 << "\t" << g[i].v2 << "\t" << g[i].wt << "\n";
}

int main() {
MST m;
int ch;
m.accept();
m.extract_edges();
m.kruskal();
return 0;
}
/* OUTPUT
Enter the no. of vertices: 6
Enter adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
Source Sink Weight

1 2 3
1 3 1
1 4 6
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
Source Sink Weight
1 3 1
4 6 2
1 2 3
2 5 3
3 6 4
2 3 5
3 4 5
1 4 6
3 5 6
5 6 6
Edges in MST:
Source Sink Weight
1 3 1
4 6 2
1 2 3
2 5 3
3 6 4
Total cost of MST: 13
*/
//b) Using Prim’s algorithm:
#include<iostream>
using namespace std;
class MST {
int a[20][20], n, k;
struct gr {
int v1;
int v2;
int wt;
}
g[20];
public:
void accept();
void extract_edges();
void prims();
};
void MST::accept() {
int i, j;
cout << "\nEnter the no. of vertices: ";
cin >> n;
cout << "Enter adjacency matrix:\n";
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
cin >> a[i][j];
}
void MST::extract_edges() {
int i, j;
for (i = 0, k = 0; i < n; i++)
for (j = i + 1; j < n; j++)
if (a[i][j] != 0) {
g[k].v1 = i;
g[k].v2 = j;
g[k++].wt = a[i][j];
}
cout << "Edges in the graph are:\n\tSource\tSink\tWeight\n";
for (i = 0; i < k; i++)
cout << "\t" << char(g[i].v1 + 65) << "\t" << char(g[i].v2 + 65) << "\t" <<
g[i].wt << "\n";
}
void MST::prims() {
int i, j, min_edge, visited[20] = {0}, sum = 0, min, flag;
visited[0] = 1;
for (i = 0; i < k; i++) {
min = 1000;
flag = 0;
for (j = 0; j < k; j++) {
if ((visited[g[j].v1] == 0 && visited[g[j].v2] == 1) ||
(visited[g[j].v1] == 1 && visited[
g[j].v2] == 0))
if (g[j].wt < min) {
min = g[j].wt;
min_edge = j;
flag = 1;
}
}
if (flag) {
cout << "\nEdge included "<<char(g[min_edge].v1+65)<<"--"<<char(g[min_edge].v2+65)<<" with weight "<<g[min_edge].wt;
visited[g[min_edge].v1]=1;
visited[g[min_edge].v2] = 1;
sum += g[min_edge].wt;
}
}
cout << "\nTotal cost of MST: " << sum << "\n";
}
int main() {
MST m;
m.accept();
m.extract_edges();
m.prims();
return 0;
}
/* OUTPUT
Enter the no. of vertices: 6
Enter adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
Edges in the graph are:

Source Sink Weight
A B 3
A C 1
A D 6
B C 5
B E 3
C D 5
C E 6
C F 4
D F 2
E F 6
Edge included A--C with weight1
Edge included A--B with weight3
Edge included B--E with weight3
Edge included C--F with weight4
Edge included D--F with weight2
Total cost of MST: 13
*/