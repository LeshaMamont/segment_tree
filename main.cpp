
#include <bits/stdc++.h>

using namespace std;

int n, pos;
vector <int> a;
vector <int> sum, rson;

void construct_tree(int l, int r){
    if(l != r){
        int cur = pos;
        pos++;
        construct_tree(l, (l+r)/2);
        pos++;
        rson[cur] = pos;
        construct_tree((l+r)/2 + 1, r);
    }
}

int count_sum(int l, int r, int pos){
    if(l != r){
        sum[pos] = count_sum(l, (r+l)/2, pos + 1) + count_sum((l+r)/2 + 1, r, rson[pos]);
    }
    if(l == r)
        sum[pos] = a[l];
    return sum[pos];
}

int s_tree(int left, int right, int l, int r, int num){
    if(l >= left && r <= right)
        return (sum[num]);
    if(r < left || l > right)
        return 0;
    return(s_tree(left, right, l,(r+l)/2, num + 1) + s_tree(left, right, (l+r)/2+1, r, rson[num]));
}




int main()
{
    cin >> n;
    a.assign(n+1, 0);
    sum.assign(2*n, 0);
    rson.assign(n*2,0);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    pos = 1;
    construct_tree(1, n);
    count_sum(1, n, 1);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int left, right;
        cin >> left >> right;
        cout << s_tree(left, right, 1, n, 1) << endl;
    }


    return 0;
}


