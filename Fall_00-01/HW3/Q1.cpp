#include <bits/stdc++.h>
using namespace std;
class DisjointSet { //to represent disjoint set
    unordered_map<int, int> parent;
public:
    unordered_map<int, int> sizes;
    void makeSet(vector<int> wholeset){
   //perform makeset operation
        for(int i = 0; i < wholeset.size(); i++){
            parent[wholeset[i]] = wholeset[i];
            sizes[i] = 1;
        }
    }
    int Find(int l) { // Find the root of the set in which element l belongs
        if (parent[l] == l) // if l is root
            return l;
        return Find(parent[l]); // recurs for parent till we find root
    }
    void Union(int c1, int c2) { // perform Union of two subsets m and n
        int p1 = Find(c1);
        int p2 = Find(c2);
        if(p1 == p2)
            return;
        if(p1 < p2)
            parent[p2] = p1;
        else
            parent[p1] = p2;
        int tmp = sizes[p1] + sizes[p2];
        sizes[p1] = tmp;
        sizes[p2] = tmp;
    }
    int findSize(int c){
        int p = Find(c);
        return sizes[p];
    }
};
void print(vector<int> universe, DisjointSet dis) {
    for(int i = 0; i < universe.size(); i++){
        cout << universe[i] << " : " << dis.Find(universe[i]) << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int arr1[n];
    int arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    vector<int> whole;
    for(int i = 0; i < 501; i++){
        //whole.push_back(arr1[i]);
        //whole.push_back(arr2[i]);
        whole.push_back(i);
    }
    DisjointSet obj;
    obj.makeSet(whole);

    int options[n];
    for(int i = 0; i < n; i++){
        options[i] = 1;
    }


    int counter = 0;
    for(int i = 0; i < n; i++){
        if(obj.Find(arr1[i]) != obj.Find(arr2[i])){
            options[i] *= obj.findSize(arr1[i]) * obj.findSize(arr2[i]) * 2;
            obj.Union(arr1[i], arr2[i]);
            counter++;
        }
    }
    cout << counter << endl;
    for(int i = 0; i < n; i++){
        if(options[i] != 1){
            cout << options[i] << endl;
        }
    }
}
