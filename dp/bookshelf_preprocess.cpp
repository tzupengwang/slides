int SUM[ MAXLEN + 5 ][ MAXLEN + 5 ] ;
int MAX[ MAXLEN + 5 ][ MAXLEN + 5 ] ;
int solve() {
  dp[ 0 ] = 0 ;
  for ( int i = 1 ; i <= n ; i ++ )
    SUM[ i ][ i ] = W[ i ] , MAX[ i ][ i ] = H[ i ] ;
  for ( int i = 1 ; i <= n ; i ++ )
    for ( int j = i + 1 ; j <= n ; j ++ )
      SUM[ i ][ j ] = SUM[ i ][ j - 1 ] + W[ j ] ,
      MAX[ i ][ j ] = max( MAX[ i ][ j - 1 ] , H[ j ] ) ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    dp[ i ] = INF ;
    for ( int j = 0 ; j < i ; j ++ ) {
      if ( SUM[ j + 1 ][ i ] <= L ) 
       dp[ i ]=min( dp[ i ], dp[ j ] + MAX[ j + 1 ][ i ] ) ;
    }
  }
  return dp[ n ] ;
}