BEGIN {
  s = 0
}
{
  s = $1 + $2
  print s
  
}
 END{
  
}
