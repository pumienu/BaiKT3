#include <bits/stdc++.h>
using namespace std;
class QMAX{
private:
    vector <int> a;
public:
    QMAX(int n): a(n, 0){}
    void update(int u, int v, int k){
        a[u-1] += k;
        if (v <= a.size()) a[v] -= k;
    }
    void update2(){
        for(int i = 1; i < a.size(); i++)
            a[i] += a[i-1];
    }
    int maxValue(int u, int v){
        int max_value = a[u-1];
        for(int i = u; i < v; i++){
            max_value = max(max_value, a[i]);
        }
        return max_value;
    }
};
int main(){
    int n, m, u, v, k, p;
    cin>>n>>m;
    QMAX arr(n);
    for(int i = 0; i < m; i++){
        cin>>u>>v>>k;
        arr.update(u, v, k);
    }
    arr.update2();
    cin>>p;
    for(int i = 0; i < p; i++){
        cin>>u>>v;
        cout<<arr.maxValue(u, v)<<endl;
    }
    return 0;
}