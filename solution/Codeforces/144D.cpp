int ans = 0;
for( int i =0; i < m; i ++ ){
   long long A1 = -1, A2 = -1;
   if( dist[u[i]] < l && l < dist[u[i]] + w[i] && l <= dist[v[i]] + (dist[u[i]] + w[i] - l) )
      A1 = l - dist[u[i]];
   if( dist[v[i]] < l && l < dist[v[i]] + w[i] && l <= dist[u[i]] + (dist[v[i]] + w[i] - l) )
      A2 = (dist[v[i]] + w[i] - l);
   if( A1 >= 0 ) ++ ans;
   if( A2 >= 0 && A2 != A1 ) ++ ans;
}

for( int i = 0; i < n; i ++ ){
   if( dist[i] == l )
   ++ ans;
}
cout << ans << endl;
